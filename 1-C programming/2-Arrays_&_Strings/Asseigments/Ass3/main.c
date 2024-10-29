/*
 * main.c
 *
 *  Created on: Apr 21, 2024
 *      Author: oussama
 */
// get the transpose of a matrix with size n
#include<stdio.h>

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int r,c;
	int R,C;
	float M[10][10];
	float T[10][10];
	//get the number of Rows & Columns from the user
	printf("Enter the number of rows:\n");
	scanf("%d",&R);
	printf("Enter the number of columns:\n");
	scanf("%d",&C);
	//get the elements of the matrix
	printf("Enter elements of the matrix:\n");
	for(r=0;r<R;r++)
	{
		for(c=0;c<C;c++)
		{
			printf("Enter the element of M%d%d:\n",r,c);
			scanf("%f",&M[r][c]);
		}
	}
	//print the given matrix
	for(r=0;r<R;r++)
		{
			for(c=0;c<C;c++)
			{
				printf("%.2f\t",M[r][c]);

			}
		printf("\n");
		}

       printf("Transpose of the matrix is:\n");
	//get the transpose and print it
	for(r=0;r<R;r++)
		{
			for(c=0;c<C;c++)
			{
				T[r][c]=M[c][r];
				printf("%.2f\t",T[r][c]);
			}
			printf("\n");
		}

}

