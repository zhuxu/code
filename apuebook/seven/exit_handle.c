/*
 * =====================================================================================
 *
 *       Filename:  exit_handle.c
 *
 *    Description:  examle of exit handlers
 *
 *        Version:  1.0
 *        Created:  2014年01月13日 21时52分16秒
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

static void my_exit1(void);
static void my_exit2(void);

int main(void)
{
	if (atexit(my_exit2) != 0)
		err_sys("Can't register my_exit2");
	if (atexit(my_exit1) != 0)
		err_sys("Can't register my_exit1");
	if (atexit(my_exit1) != 0)
		err_sys("Can't register my_exit1");

	printf("main is done\n");

	return 0;
}

static void my_exit1(void)
{
	printf("first exit handler\n");
}

static void my_exit2(void)
{
	printf("second exit handler\n");
}
