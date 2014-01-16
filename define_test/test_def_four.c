/*
 * =====================================================================================
 *
 *       Filename:  test_def_four.c
 *
 *    Description:  test define
 *
 *        Version:  1.0
 *        Created:  2014年01月16日 23时11分22秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ZHU XU (~_~), splk008@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>

#define eprintf(format, args...) fprintf(stdout, #format, ##args)

int main(int argc, char *argv[])
{
	eprintf(success!\n);
	return 0;
}
