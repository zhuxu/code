/*
 * =====================================================================================
 *
 *       Filename:  test_copy_stdin_stdou.c
 *
 *    Description:  test copy standard input to standard output
 *
 *        Version:  1.0
 *        Created:  2013年12月05日 16时28分39秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ZHU XU (~_~), splk008@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "apue.h"

#define BUFFSIZE	4096

int main(int argc, char *argv[])
{
	int		n;
	char	buf[BUFFSIZE];

	while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
		if (write(STDOUT_FILENO, buf, n) != n)
			printf("write error\n");

	if (n < 0)
		printf("read error\n");
	return 0;
}
