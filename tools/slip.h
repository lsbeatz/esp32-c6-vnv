#ifndef SLIP_H
#define SLIP_H

#include <sys/types.h>

#define END             0300    /* indicates end of packet */
#define ESC             0333    /* indicates byte stuffing */
#define ESC_END         0334    /* ESC ESC_END means END data byte */
#define ESC_ESC         0335    /* ESC ESC_ESC means ESC data byte */

struct slip_ctx {
	int (*send_char)(char *buf);
	int (*recv_char)(char *buf);
};

int slip_init(struct slip_ctx *ctx);
int slip_exit(void);

ssize_t slip_send(char *buf, ssize_t len);
ssize_t slip_recv(char *buf, ssize_t len);

#endif /* SLIP_H */
