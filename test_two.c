/*
 * =====================================================================================
 *
 *       Filename:  test_two.c
 *
 *    Description:  基于正交多项式的最小二乘曲线拟合
 *
 *        Version:  1.0
 *        Created:  2013年12月21日 11时50分36秒
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
#include <math.h>

int calculate(double *input_x, double *input_y, int n, int m, double *ans);

int main(int argc, char *argv[])
{
	int i;
	double x[6] = {4.0, 10.6, 17.0, 33.1, 52.2, 70.8};
	double y[6] = {1.5, 2.0, 2.3, 2.8, 3.2, 3.5};
	double ans[3];
	calculate(&x[0], &y[0],6,3,&ans[0]);

	for (i = 0; i < 3; i++)
		printf("ans[%d] = %f\n", i, ans[i]);
	printf("\n");
	return 0;
}

int calculate(double *input_x, double *input_y, int n, int m, double *ans)
{
	int       i,j,k;    /*循环变量*/
	double    alpha, beta;
	double    avg_x, avg_y;    /* 观测值x，y的平均值 */
	double    num_old, num_new;    /* 公式中的sumQ^2(x) */
	double    qx_temp;    /* Q(x)的中间值 */
	double    q_ans;
	double    g_ans;
	double    s_ratio[20], t_ratio[20], b_ratio[20];

	/* 计算j=0时，各个系数的值 */
	avg_x = 0.0;
	avg_y = 0.0;
	for (i = 0; i < n; i++){
		avg_x += input_x[i] / n;
		avg_y += input_y[i] / n;
	}
	for (j = 0; j < m; j++)
		ans[j] = 0.0;
	num_old = n;      //d0
	for (i = 0 ; i < n; i++)
		g_ans += (input_x[i] - avg_x);    //a0
	q_ans = avg_y;    //q0
	alpha = g_ans/num_old;
	b_ratio[0] = 1.0;
	ans[0] = q_ans*b_ratio[0];

	printf("q_ans=%f\n",q_ans);
	printf("avg_x=%f", avg_x);
	printf("alpha=%f\n",alpha);
	printf("ans[0]=%f\n",ans[0]);

	/* 计算j = 1时的值 */
	t_ratio[0] = -alpha;
	t_ratio[1] = 1.0;
	num_new = 0.0;
	q_ans = 0.0;
	g_ans = 0.0;
	for (i = 0; i < n; i++){
		qx_temp = input_x[i] - avg_x - alpha;
		num_new += qx_temp*qx_temp;    // d1
		q_ans += input_y[i] * qx_temp;    // q1
		g_ans += (input_x[i]-avg_x)*qx_temp*qx_temp;    // new alpha
	}
	q_ans /= num_new;    // q1
	alpha = g_ans/num_new;    // a1
	beta = num_new / num_old;
	num_old = num_new;
	ans[1] = q_ans*t_ratio[1];
	ans[0] += q_ans*t_ratio[0];

	printf("here j=1\n");
	printf("q_ans=%f\n",q_ans);
	printf("alpha=%f\n",alpha);
	printf("beta=%f\n",beta);
	printf("num_new=%f",num_new);
	printf("ans[0]=%f ans[1]=%f\n",ans[0],ans[1]);

	/* j = 2, ..., m-1 */
	for (j = 2; j < m; j++){
		s_ratio[j] = t_ratio[j-1];
		s_ratio[j-1] = -alpha*t_ratio[j-1] + t_ratio[j-2];
		if (j > 3)
		    for (k = j-2; k >= 1; k--){
			    s_ratio[k] = -alpha*t_ratio[k] + t_ratio[k-1] - beta*b_ratio[k];
		    }
		s_ratio[0] = -alpha*t_ratio[0] - beta*b_ratio[0];

		num_new = 0.0;
		q_ans = 0.0;
		g_ans = 0.0;
		for (i = 0; i < n; i++){
			qx_temp = s_ratio[j];
			for (k = j-1; k >= 0; k--){
				qx_temp = qx_temp*(input_x[i] - avg_x) + s_ratio[k];
			}
			num_new += qx_temp*qx_temp;    // dj
			g_ans += (input_x[i] - avg_x)*qx_temp*qx_temp;
			q_ans += input_y[i]*qx_temp;
		}

		alpha = g_ans/num_new;
		q_ans /= num_new;
		beta = num_new / num_old;
		num_old = num_new;
		ans[j] = q_ans*s_ratio[j];
		t_ratio[j] = s_ratio[j];

		for (k = j-1; k >= 0; k--){
			ans[k] += q_ans*s_ratio[k];
			b_ratio[k] = t_ratio[k];
			t_ratio[k] = s_ratio[k];
		}
	}
	printf("the ans is \n");
	printf("ans[0]=%f,ans[1]=%f,ans[2]=%f\n",ans[0],ans[1],ans[2]);
	printf("s[0]=%f,s[1]=%f,s[2]=%f\n",s_ratio[0],s_ratio[1],s_ratio[2]);
	printf("t[0]=%f,t[1]=%f,t[2]=%f\n",t_ratio[0],t_ratio[1],t_ratio[2]);
	printf("b[0]=%f,b[1]=%f,b[2]=%f\n",b_ratio[0],b_ratio[1],b_ratio[2]);

	return 0;
}
