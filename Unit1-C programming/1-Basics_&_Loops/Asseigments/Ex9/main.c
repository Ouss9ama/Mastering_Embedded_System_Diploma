/*
 * main.c
 *
 *  Created on: Mar 27, 2024
 *      Author: oussama
 */

#include<stdio.h>

int main()
{

	char input;
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	printf("Enter an alphabet: \n");
	scanf("%c", &input);
	if (input=='a')
	{
		printf("%c is a vowel",input);
	}
	else if(input=='u')
				{
		          printf("%c is a vowel",input);
				}
	else if(input=='u')
				{
		printf("%c is a vowel",input);
				}
	else if(input=='e')
					{
		printf("%c is a vowel",input);
					}
	else if(input=='i')
					{
		printf("%c is a vowel",input);
					}
	else if		(input=='o')
					{
		printf("%c is a vowel",input);
					}
	else
	{
		printf("%c is a constant",input);
	}
}
