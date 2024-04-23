/*
 * main.c
 *
 *  Created on: Apr 21, 2024
 *      Author: oussama
 */
//gets the frequency of a letter in a string
#include<stdio.h>
#include<string.h>
int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	char x[50];
	char l;
	int i,counter;

	printf("Enter a string:\n");
	gets(x);

	printf("Enter a character to find its frequency:\n ");
	scanf(" %c",&l);
	for(i=0,counter=0;i<50;i++)
	{
		if (l==x[i])
		{
			counter++;
		}

	}

	printf("The frequency of letter %c is %d\n",l,counter);

}
