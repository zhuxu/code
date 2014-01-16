/*
 * =====================================================================================
 *
 *       Filename:  test_def_three.c
 *
 *    Description:  test define
 *
 *        Version:  1.0
 *        Created:  2014年01月16日 23时06分14秒
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

#define eprintf(format, ...) fprintf(stdout, format, __VA_ARGS__)

int main(int argc, char *argv[])
{
	eprintf("hello, zhuxu!\n%d",8);
	return 0;
}
