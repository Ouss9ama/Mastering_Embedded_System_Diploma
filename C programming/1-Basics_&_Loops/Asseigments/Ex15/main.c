/*
 * main.c
 *
 *  Created on: Mar 28, 2024
 *      Author: oussama
 */

#include<stdio.h>

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	float x;
	float y;
	char oper;
	printf("Enter operator either + or - or * or / :\n");
	scanf("%c",&oper);
	printf("Enter 2 operands:\n");
	scanf("%f %f", &x, &y);

    if (oper=='+')
    {
    	printf("%.2f + %.2f = %.2f",x, y, x + y);
    }

    else if (oper=='-')
       {
    	printf("%.2f - %.2f = %.2f",x, y, x - y);
       }
    else if (oper=='*')
       {
    	printf("%.2f * %.2f = %.2f",x, y, x * y);
       }
    else if (oper=='/')
           {
    	printf("%.2f / %.2f = %.2f",x, y, x / y);
           }




}
