#include <stdlib.h>
#include <assert.h>
#include <errno.h>

#include "slip.h"

static struct slip_ctx drv_ctx;

int slip_init(struct slip_ctx *ctx)
{
	int rc;

	if (!ctx || drv_ctx) {
		rc = EINVAL;
		goto out;
	}

	drv_ctx = *ctx;
	
out:
	return rc;
}

int slip_exit(void)
{
	drv_ctx = NULL;

	return 0;
}

ssize_t raw_to_slip(char *dst, char *src, ssize_t len)
{
	ssize_t bytes = 0;

	assert(dst);
	assert(src);
	assert(len >= 0);

	while (len--) {
		switch (*src) {
		case END:
			*dst++ = ESC;
			*dst++ = ESC_END;
			bytes += 2;
			break;
		case ESC:
			*dst++ = ESC;
			*dst++ = ESC_ESC;
			bytes += 2;
			break;
		default:
			*dst++ = *src;
			bytes++;
			break;
		}

		src++;
	}

	*dst = END;
	bytes++;

	return bytes;
}

ssize_t slip_to_raw(char *dst, char *src, ssize_t len)
{
	ssize_t bytes = 0;

	assert(dst);
	assert(src);
	assert(len >= 0);

	while (len--) {
		switch (*src) {
		case END:
			*dst++ = ESC;
			*dst++ = ESC_END;
			bytes += 2;
			break;
		case ESC:
			*dst++ = ESC;
			*dst++ = ESC_ESC;
			bytes += 2;
			break;
		default:
			*dst++ = *src;
			bytes++;
			break;
		}

		src++;
	}

	return bytes;
}

ssize_t slip_send(char *buf, ssize_t len)
{
	char *slip_buf;
	ssize_t bytes;

	assert(drv_ctx);
	assert(buf);
	assert(len >= 0);

	slip_buf = (char *)malloc(len * 2);
	bytes = raw_to_slip(slip_buf, buf, len);
	drv_ctx->send(buf, bytes);

	free(slip_buf);
}

ssize_t slip_recv(char *buf, ssize_t len)
{
	char *slip_buf;
	ssize_t bytes;

	assert(drv_ctx);
	assert(buf);
	assert(len >= 0);

	slip_buf = (char *)malloc(len * 2);
	drv_ctx->recv(slip_buf, &bytes);
	bytes = slip_to_raw(buf, slip_buf, bytes);

	return bytes;
}
