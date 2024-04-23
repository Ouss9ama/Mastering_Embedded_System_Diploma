/*
 * main.c
 *
 *  Created on: Mar 27, 2024
 *      Author: oussama
 */

#include<stdio.h>

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	char x;
	printf("Enter a character:\n");
	scanf("%c",&x);

	if(((x<='z')&&(x>='a'))||((x<='Z')&&(x>='A')))
	{
		printf("%c is a an alphabet\n",x);
	}
	else
	{
		printf("%c is not an alphabet\n",x);
	}
}
