/*
 * main.c
 *
 *  Created on: Oct 21, 2024
 *      Author: oussa
 */

#include<stdio.h>

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	char x[26];
	x[0]=65;
	char* ptr=x;

	for(int i=1;i<26;i++)
	{
		x[i]=*ptr+i;
	}
	for(int i=0;i<26;i++)
	{
		 printf("%c ",*ptr++);
	}
}


