/*
 * =====================================================================================
 *
 *       Filename:  test_create_hole.c
 *
 *    Description:  creates a file with a hole in it
 *
 *        Version:  1.0
 *        Created:  2013年12月05日 15时36分57秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ZHU XU (~_~), splk008@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <fcntl.h>
#include "apue.h"

char	buf1[] = "abcdefghij";
char	buf2[] = "ABCDEFGHIJ";

int main(int argc, char *argv[])
{
	int fd;    /* file descriptor*/

	if ((fd = creat("file.hole", FILE_MODE)) < 0)
		printf("creat error");

	if (write(fd, buf1, 10) != 10)
		printf("buf1 write error");

	/* offset now  = 10 */
	if (lseek(fd, 16384, SEEK_SET) == -1)
		printf("lseek error");
	/* offset now  = 16384 */

	if (write(fd, buf2, 10) != 10)
		printf("buf2 write error");

	/* offset now  = 16394 */

	return 0;
}
