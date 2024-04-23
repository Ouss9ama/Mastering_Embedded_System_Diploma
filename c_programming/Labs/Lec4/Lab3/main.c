/*
 * main.c
 *
 *  Created on: Apr 19, 2024
 *      Author: oussama
 */

//calculate the transpose of a matrix
#include <stdio.h>

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	float M[3][3];
	float T[3][3];
	int r;
	int c;
	//receive the inputs
	for(r=0;r<3;r++)
	{
		for(c=0;c<3;c++)
		{
			printf("Enter the parameters of the matrix: M(%d)(%d)\n",r,c);
			scanf("%f",&M[r][c]);
		}
	}
    //print the matrix
	for(r=0;r<3;r++)
	{
		for(c=0;c<3;c++)
		{
			printf("%.2f\t",M[r][c]);
		}
		printf("\n");
	}
	printf("The transpose of the matrix is:\n");
	//set the transpose
	for(r=0;r<3;r++)
	{
		for(c=0;c<3;c++)
		{
			T[c][r]=M[r][c];
		}
	}
    // print the transpose
	for(r=0;r<3;r++)
		{
			for(c=0;c<3;c++)
			{
				printf("%.2f\t",T[r][c]);
			}
			printf("\n");

		}
}
