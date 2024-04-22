/*
 * main.c
 *
 *  Created on: Apr 21, 2024
 *      Author: oussama
 */

//gets the length of a string without using the strlen()

#include<stdio.h>

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	char S [100];
	int counter;

	printf("Enter a string:\n");
	gets(S);

	for(counter=0;S[counter]!='\0';counter++);


	printf("length of the string is:%d",counter);


}
