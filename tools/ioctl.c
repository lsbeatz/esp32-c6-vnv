#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>

#define DEVICE_FILE "/dev/ttyACM0"

int main() {
	int fd;
	int status;
	int control;
	int rbytes;
	char buf[4096];

	fd = open(DEVICE_FILE, O_RDWR | O_NOCTTY);
	if (fd < 0) {
		perror("open");
		goto out;
	}

	if (ioctl(fd, TIOCMGET, &status) < 0) {
		perror("ioctl TIOCMGET");
		goto out;
	}
	printf("status = %x\n", status);

	usleep(1000);

	control = TIOCM_DTR;
	if (ioctl(fd, TIOCMBIC, &control) < 0) {
		perror("ioctl TIOCMBIC for DTR");
		goto out;
	}
	printf("Clear DTR\n");

	usleep(1000);
	control = TIOCM_RTS;
	if (ioctl(fd, TIOCMBIC, &control) < 0) {
		perror("ioctl TIOCMBIC for RTS");
		goto out;
	}
	printf("Clear RTS\n");

	usleep(1000);
	control = TIOCM_RTS;
	if (ioctl(fd, TIOCMBIS, &control) < 0) {
		perror("ioctl TIOCMBIS for RTS");
		goto out;
	}
	printf("Set RTS\n");

	while (1) {
		rbytes = read(fd, buf, 4095);
		if (rbytes < 0) {
			goto out;
		}

		if (rbytes == 0) {
			break;
		}

		buf[rbytes] = '\0';
		printf("%s", buf);
	}

	getchar();

	control = TIOCM_RTS;
	if (ioctl(fd, TIOCMBIC, &control) < 0) {
		perror("ioctl TIOCMBIC for RTS");
		goto out;
	}
	printf("Clear RTS\n");

	// flush
	do {
		rbytes = read(fd, buf, 4095);
		if (rbytes < 0) {
			goto out;
		}

		buf[rbytes] = '\0';
		printf("%s", buf);
	} while (1);

out:
	close(fd);

	return 0;
}
