/*
 * main.c
 *
 *  Created on: Mar 25, 2024
 *      Author: oussama
 */

//Write C Program to Add Two Integers
#include <stdio.h>

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int x;
	int y;
	printf("Enter two integers:\n\r ");
	scanf("%d %d",&x,&y);

	printf("Sum : %d",x+y);

}
