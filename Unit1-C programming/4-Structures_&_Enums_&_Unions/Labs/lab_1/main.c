/*
 * main.c
 *
 *  Created on: Oct 10, 2024
 *      Author: oussa
 */

#include<stdio.h>


struct Scomplex {
	double m_R;
	double m_I;
};

struct Scomplex Add(struct Scomplex num1, struct Scomplex num2);
int main ()
{
	struct Scomplex X,Y,sum;
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	printf("Enter the real part and imaginery part of the first number:\n");
	scanf("%lf %lf",&X.m_R,&X.m_I);

	printf("Enter the real part and imaginery part of the Second number:\n");
	scanf("%lf %lf",&Y.m_R,&Y.m_I);

	sum = Add(X,Y);

	printf("the sum of real number is: %.3lf\n the sum of the imaginary numbers is %.3lfi\n",sum.m_R,sum.m_I);
}

struct Scomplex Add(struct Scomplex num1, struct Scomplex num2)
{
	struct Scomplex Z;
	Z.m_R = num1.m_R + num2.m_R;
	Z.m_I = num1.m_I + num2.m_I;
	return Z;
}
