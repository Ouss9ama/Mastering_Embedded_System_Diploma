/*
 * Pb_7_main.c
 *
 *  Created on: Oct 6, 2024
 *      Author: oussa
 */

#include<stdio.h>
int fun_sum(int x);
int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int a=1;
	int sum;
	sum=fun_sum(a);
	printf("%d",sum);

}

int fun_sum(int x)
{

	if(x>100)
	{
	return 0;
	}
	else
	{
	return x + fun_sum(x+1);
	}

}
