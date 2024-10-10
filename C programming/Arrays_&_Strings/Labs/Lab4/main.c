/*
 * main.c
 *
 *  Created on: Apr 20, 2024
 *      Author: oussama
 */
#include<stdio.h>
#include<string.h>

int main()
{

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	char Names[4][10]={"oussama","ahmed","ousous","sadia"};
	char input[10];
	int i;
	printf("Enter the usernam:\n");
	scanf("%s",input);

	for(i=0;i<4;i++)
	{
		if(stricmp(input,Names[i])==0)
		{
			printf("logging succesfully\n");
			break;
		}
	}
}

