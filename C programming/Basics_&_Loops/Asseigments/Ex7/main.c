/*
 * main.c
 *
 *  Created on: Mar 27, 2024
 *      Author: oussama
 */

#include <stdio.h>

int main()
{

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int x;
	int y;

	printf("Enter the value of the first number x :\n");
	scanf("%d",&x);
	printf("Enter the value of the second number y :\n");
	scanf("%d",&y);
/**********1st method**********/
//	x= x + y;
//	y= x - y;
//	x= x - y;
/**********2nd method*******/
	x= x ^ y;
	y= x ^ y;
	x= x ^ y;
	printf("x = %d:\n",x);
	printf("y = %d:\n",y);

}
