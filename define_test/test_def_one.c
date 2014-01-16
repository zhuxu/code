/*
 * =====================================================================================
 *
 *       Filename:  test_def_one.c
 *
 *    Description:  test define
 *
 *        Version:  1.0
 *        Created:  2014年01月16日 22时47分41秒
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

#define eprintf(args...) fprintf(stdout,args)

int main(int argc, char *argv[])
{
	eprintf("what is this?\n");
	return 0;
}
