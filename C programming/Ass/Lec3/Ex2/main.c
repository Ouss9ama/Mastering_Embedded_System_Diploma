/*
 * main.c
 *
 *  Created on: Mar 25, 2024
 *      Author: oussama
 */
//Write C Program to Print a Integer Entered by a User
#include<stdio.h>

int main()
{
	int x;
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	printf("Enter an integer:\n\r");
	scanf("%d",&x);

	printf("You entered:%d",x);
}
