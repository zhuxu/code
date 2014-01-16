/*
 * =====================================================================================
 *
 *       Filename:  test_def_two.c
 *
 *    Description:  test define
 *
 *        Version:  1.0
 *        Created:  2014年01月16日 22时57分29秒
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

#define eprintf(format, args...) fprintf(stdout, format, ##args)

int main(int argc, char *argv[])
{
	int num, count;
	num = 9;
	count = num - 5;
	eprintf("hello, zhuxu!\n%d=%d+5\n",num,count);
	return 0;
}
