/*
 * main.c
 *
 *  Created on: Oct 12, 2024
 *      Author: oussa
 */
#include<stdio.h>

#define Fn(fun_name,y) int fun_name(int z){return z*y;}


Fn(fun_double,2);
Fn(fun_quadruple,4);
int main()
{

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int x;
	printf("Enter the value of x:\n");
	scanf("%d",&x);

	printf("the double of %d is: %d\nthe quadruple of %d is: %d",x,fun_double(x),x,fun_quadruple(x));
}
