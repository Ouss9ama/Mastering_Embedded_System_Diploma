/*
 * main.c
 *
 *  Created on: Apr 21, 2024
 *      Author: oussama
 */
//reverse a given string
#include<stdio.h>

int main()
{

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	char S [50];
	char I [50];
	int i,l;
	printf("Enter the string:\n");
	gets(S);

	//get the length of the given string
	for(l=0;S[l]!='\0';l++);//

	//reverse the string based on the length
	for(i=0;i<l;i++)
	{
		 I[i]=S[l-1-i];//l-1 because the l is a null
	}
	I[l]='\0';//add null to the reverse array because the complier did not do it
	printf("Reverse of the string is: %s",I);
}
