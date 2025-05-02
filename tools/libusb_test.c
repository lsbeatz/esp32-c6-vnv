#include <libusb-1.0/libusb.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#define VENDOR_ID  0x303a // Espressif
#define PRODUCT_ID 0x1001 // ESP32-c6

#define ESP_IF_ID 0

#define ESP_REQ_TYPE (LIBUSB_REQUEST_TYPE_CLASS | LIBUSB_RECIPIENT_INTERFACE | LIBUSB_ENDPOINT_OUT)
#define ESP_REQ_CMD  0x22

#define EP1_IN 0x81

#define TIMEOUT_IN_MS 2000

#define MAX_BUF_SIZE 1024

static unsigned char rbuf[MAX_BUF_SIZE + 1];

int reset_enter(libusb_device_handle *handle)
{
	int rc;
	uint16_t state;

	state = 0x0; // Clear Download Flag
    rc = libusb_control_transfer(handle, ESP_REQ_TYPE, ESP_REQ_CMD, state, 0, NULL, 0, 0);
    if (rc < 0) {
        printf("Failed to clear download flag: %s\n", libusb_strerror(rc));
		goto out;
    }

	state = 0x2; // Set RTS to reset SoC
    rc = libusb_control_transfer(handle, ESP_REQ_TYPE, ESP_REQ_CMD, state, 0, NULL, 0, 0);
    if (rc < 0) {
        printf("Failed to set DTR: %s\n", libusb_strerror(rc));
		goto out;
    }
	printf("Reset enter\n");

out:
	return rc;
}

int reset_exit(libusb_device_handle *handle)
{
	int rc;
	uint16_t state;

	state = 0x3; // Set to No Action Mode
    rc = libusb_control_transfer(handle, ESP_REQ_TYPE, ESP_REQ_CMD, state, 0, NULL, 0, 0);
    if (rc < 0) {
        printf("Failed to set RTS: %s\n", libusb_strerror(rc));
		goto out;
    }
	printf("Reset exit\n");

out:
	return rc;
}

int reset_soc(libusb_device_handle *handle)
{
	int rc;

	rc = reset_enter(handle);
	if (rc < 0) {
		goto out;
	}

	rc = reset_exit(handle);
	if (rc < 0) {
		goto out;
	}

out:
	return rc;
}

int download_mode_enter(libusb_device_handle *handle)
{
	int rc;
	uint16_t state;

	state = 0x0; // Clear Download Flag
    rc = libusb_control_transfer(handle, ESP_REQ_TYPE, ESP_REQ_CMD, state, 0, NULL, 0, 0);
    if (rc < 0) {
        printf("Failed to clear download flag: %s\n", libusb_strerror(rc));
		goto out;
    }

	state = 0x1; // Set Download Flag
    rc = libusb_control_transfer(handle, ESP_REQ_TYPE, ESP_REQ_CMD, state, 0, NULL, 0, 0);
    if (rc < 0) {
        printf("Failed to set download flag: %s\n", libusb_strerror(rc));
		goto out;
    }

	state = 0x3; // Set RTS
    rc = libusb_control_transfer(handle, ESP_REQ_TYPE, ESP_REQ_CMD, state, 0, NULL, 0, 0);
    if (rc < 0) {
        printf("Failed to set RTS: %s\n", libusb_strerror(rc));
		goto out;
    }

	state = 0x2; // Reset
    rc = libusb_control_transfer(handle, ESP_REQ_TYPE, ESP_REQ_CMD, state, 0, NULL, 0, 0);
    if (rc < 0) {
        printf("Failed to reset SoC: %s\n", libusb_strerror(rc));
		goto out;
    }

	state = 0x0; // Clear Download Flag
    rc = libusb_control_transfer(handle, ESP_REQ_TYPE, ESP_REQ_CMD, state, 0, NULL, 0, 0);
    if (rc < 0) {
        printf("Failed to set DTR: %s\n", libusb_strerror(rc));
		goto out;
    }

	printf("Download mode enter\n");

out:
	return rc;
}

int download_mode_exit(libusb_device_handle *handle)
{
	return reset_soc(handle);
}


int flush_usb_serial(libusb_device_handle *handle, unsigned char *buf, int *received)
{
	int rc;
	
	rc = libusb_bulk_transfer(handle, EP1_IN, buf, MAX_BUF_SIZE, received, TIMEOUT_IN_MS);
	if (rc < 0 && rc != LIBUSB_ERROR_TIMEOUT) {
		printf("Failed to read EP 1: %s\n", libusb_strerror(rc));
		goto out;
	}

out:
	return rc;
}

int main() {
    libusb_device_handle *handle;
	uint16_t state;
	int received;
    int rc;

    rc = libusb_init(NULL);
    if (rc < 0) {
        printf("libusb init failed\n");
        return 1;
    }

    handle = libusb_open_device_with_vid_pid(NULL, VENDOR_ID, PRODUCT_ID);
    if (!handle) {
        printf("Device not found\n");
		goto out;
    }

	rc = libusb_set_auto_detach_kernel_driver(handle, 1);
	if (rc < 0) {
		printf("Failed to detach kernel driver: %s\n", libusb_strerror(rc));
	}

    rc = libusb_claim_interface(handle, ESP_IF_ID);
	if (rc < 0) {
		printf("Failed to claim interface: %s\n", libusb_strerror(rc));
		goto out;
	}

	reset_soc(handle);
	do {
		rc = flush_usb_serial(handle, rbuf, &received);

		fwrite(rbuf, 1, received, stdout);
		fflush(stdout);
	} while (!rc);

	download_mode_enter(handle);
	do {
		rc = flush_usb_serial(handle, rbuf, &received);

		fwrite(rbuf, 1, received, stdout);
		fflush(stdout);
	} while (!rc);

	download_mode_exit(handle);
	do {
		rc = flush_usb_serial(handle, rbuf, &received);

		fwrite(rbuf, 1, received, stdout);
		fflush(stdout);
	} while (!rc);

	libusb_release_interface(handle, ESP_IF_ID);
    libusb_close(handle);

out:
    libusb_exit(NULL);

    return 0;
}
