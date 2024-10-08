/*
 * main.c
 *
 *  Created on: Mar 23, 2024
 *      Author: oussama
 */

#include<stdio.h>
//1 2 3
//1 2 3
//1 2 3

int main()
{

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int i,j;


	for(i=1; i<4; i++) // for column
	{
		for(j=1; j<4; j++)
		{
			printf("%d",j);
		}
		printf("\n");
	}


}





