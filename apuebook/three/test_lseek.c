/*
 * =====================================================================================
 *
 *       Filename:  test_lseek.c
 *
 *    Description:  example of chapter3 apue book
 *
 *        Version:  1.0
 *        Created:  2013年12月05日 15时31分16秒
 *       Revision:  none  
 *       Compiler:  gcc
 *
 *         Author:  ZHU XU (~_~), splk008@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "apue.h"

int main(int argc, char *argv[])
{
	if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
		printf("cannot seek\n");
	else
		printf("seek OK\n");

	return 0;
}

