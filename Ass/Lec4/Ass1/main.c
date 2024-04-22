/*
 * main.c
 *
 *  Created on: Apr 20, 2024
 *      Author: oussama
 */
//sum of 2 matrix of order 2
#include<stdio.h>

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	float a[2][2];
	float b[2][2];
	float s[2][2];
	int r,c;
	//get input of 1st M from user
	printf("Enter the element of 1st matrix:\n");
	for(r=0;r<2;r++)
	{
		for(c=0;c<2;c++)
		{
			printf("Enter a%d%d:",r,c);
			scanf("%f",&a[r][c]);
		}
	}
	//get input of 1st M from user
	printf("Enter the element of 2nd matrix:\n");
		for(r=0;r<2;r++)
		{
			for(c=0;c<2;c++)
			{
				printf("Enter %d%d:",r,c);
				scanf("%f",&b[r][c]);
			}
		}
	//print sum
		printf("sum of matrixes:\n");
		for(r=0;r<2;r++)
				{
					for(c=0;c<2;c++)
					{
						s[r][c]=a[r][c]+b[r][c];
						printf("%.2f\t",s[r][c]);
					}
					printf("\n");
				}

}

