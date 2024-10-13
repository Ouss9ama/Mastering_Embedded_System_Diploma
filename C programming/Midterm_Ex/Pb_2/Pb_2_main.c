/*
 * Pb_2_main.c
 *
 *  Created on: Oct 6, 2024
 *      Author: oussa
 */


#include<stdio.h>
#include<math.h>

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	double x,y;

	printf("Enter a number:\n");
	scanf("%lf",&x);

	y=sqrt(x);
	printf("The output is:\n %lf", y);
}
