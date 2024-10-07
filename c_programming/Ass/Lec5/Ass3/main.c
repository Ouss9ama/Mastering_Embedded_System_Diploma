/*
 * main.c
 *
 *  Created on: Jun 21, 2024
 *      Author: oussama
 */

#include<stdio.h>
char revsen[50];//the reversed sentence
char sentence[50];
int l;
int i=0;
int len(char b[]);//not using strln function
char reverse(char a[]);
int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	printf("Enter a sentence:\n");

	gets(sentence);

	l=len(sentence);
	reverse(sentence);

	printf("%s",revsen);

}
int len(char b[])
{
	for(l=0;b[l]!='\0';l++)
	{
	}

		return l;
}
char reverse(char a[])
{


	if(i<l)
	{
		revsen[i]=a[l-i-1];
		i++;
		reverse (a);
	}
	else
	{
		revsen[l]='\0';
	}
//	for(int i=0;i<l;i++)
//	{
//		revsen[i]=a[l-i-1];
//	}
//	revsen[l]='\0';
	return revsen[50];
}


