/*
 * =====================================================================================
 *
 *       Filename:  testjmp.c
 *
 *    Description:  test nonlocal jump
 *
 *        Version:  1.0
 *        Created:  2014年01月13日 22时07分44秒
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
#include <setjmp.h>

static jmp_buf   jmpbuffer;
static int		 globval;

static void f2(void);
static void f1(int i, int j, int k, int l);

int main(void)
{
	int				autoval;
	register int    regival;
	volatile int    volaval;
	static int      statval;

	globval = 1;
	autoval = 2;
	regival = 3;
	volaval = 4;
	statval = 5;

	if (setjmp(jmpbuffer) != 0){
		printf("after longjmp:\n");
		printf("globval = %d, autoval = %d, regival = %d,"
				" volaval = %d, statval = %d\n",
				globval, autoval, regival, volaval, statval);
		exit(0);
	}

	/*
 	 * Change variables after setjmp , but before longjmp
	 */
	globval = 95;
	autoval = 96;
	regival = 97;
	volaval = 98;
	statval = 99;

	f1(autoval, regival, volaval, statval);

	exit(0);
}

static void f1(int i, int j, int k, int l)
{
	printf("in f1():\n");
	printf("globval = %d, autoval = %d, regival = %d,"
			" volaval = %d, statval = %d\n", globval, i, j, k, l);
	f2();
}

static void f2(void)
{
	longjmp(jmpbuffer, 1);
}
