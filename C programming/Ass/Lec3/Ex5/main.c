/*
 * main.c
 *
 *  Created on: Mar 25, 2024
 *      Author: oussama
 */
//Write C Program to Find ASCII Value of a Character
#include<stdio.h>

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	char x;
	printf("Enter a character :\r\n");
	scanf("%c",&x);

	printf("ASCII value of %c is: %i \n\r ", x,x);

}
