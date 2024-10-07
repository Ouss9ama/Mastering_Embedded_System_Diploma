/*
 * main.c
 *
 *  Created on: Mar 23, 2024
 *      Author: oussama
 */

//0 1 2 3 4 5 6 7 8 9
//1 2 3 4 5 6 7 8 9
//2 3 4 5 6 7 8 9
//3 4 5 6 7 8 9
//4 5 6 7 8 9
//5 6 7 8 9
//6 7 8 9
//7 8 9
//8 9b
//9
#include<stdio.h>

int main()
{

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int i,j;

	for(i=0; i<10 ; i++)
	{
		for(j=i; j<10; j++)
		{
			printf("%d",j);
		}
		printf("\n");
	}

}
