/*
 * main.c
 *
 *  Created on: Oct 12, 2024
 *      Author: oussa
 */
#define Pi 3.14159
#define circle_a(a) a*Pi*2

#include<stdio.h>

int main()
{

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int radius;
	printf("Enter the radius of the circle:\n");
	scanf("%d",&radius);
	printf("the area of the circle is: %.2lf ",circle_a(radius));

}
