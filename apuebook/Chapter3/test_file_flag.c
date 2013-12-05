/*
 * =====================================================================================
 *
 *       Filename:  test_file_flag.c
 *
 *    Description:  this program takes a single command-line argument that specifies a file descriptor and prints a description of selected file flags for that descriptor
 *
 *        Version:  1.0
 *        Created:  2013年12月05日 22时30分40秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ZHU XU (~_~), splk008@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include "apue.h"
#include <fcntl.h>
#include <errno.h>
#include <stdarg.h>

static void err_doit(int, int, const char *, va_list);

int main(int argc, char *argv[])
{
	int		val;
	if (argc != 2){
		printf("usage: a.out <descriptor#>");
		exit(0);
	}

	if ((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0)
		printf("fcntl error for fd %d\n",atoi(argv[1]));

	switch(val & O_ACCMODE) {
		case O_RDONLY:
			printf("read only\n");
			break;
		case O_WRONLY:
			printf("write only\n");
			break;
		case O_RDWR:
			printf("read write\n");
			break;
		default:
			err_dump("unknow access mode");
	}

	if (val & O_APPEND)
		printf(",append");
	if (val & O_NONBLOCK)
		printf(", nonblocking");
#if defined(O_SYNC)
	if(val & O_SYNC)
		printf(", synchronous writes");
#endif
#if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC)
	if (val & O_FSYNC)
		printf(", synchronous writes");
#endif
	putchar('\n');

	return 0;
}

void err_dump(const char *fmt, ...)
{
	va_list		ap;
	va_start(ap, fmt);
	err_doit(1, errno, fmt, ap);
	va_end(ap);
	abort();
	exit(1);
}

static void err_doit(int errnoflag, int error, const char *fmt, va_list ap)
{
	char	buf[MAXLINE];
	vsnprintf(buf, MAXLINE, fmt, ap);
	if (errnoflag)
		snprintf(buf+strlen(buf), MAXLINE-strlen(buf), ": %s", strerror(error));
	strcat(buf, "\n");
	fflush(stdout);
	fputs(buf, stderr);
	fflush(NULL);
}
