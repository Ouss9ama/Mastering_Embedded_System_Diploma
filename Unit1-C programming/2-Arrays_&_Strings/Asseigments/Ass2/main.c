/*
 * main.c
 *
 *  Created on: Apr 20, 2024
 *      Author: oussama
 */

//stores data given by user in an array and calculate its average
#include<stdio.h>

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int i,n;
	float sum,average;
	float A[10];
	//gets number of data from the user
	printf("Enter the numbers of data:\n");
	scanf("%d",&n);
	for(i=0,sum=0;i<n;i++)
	{
      printf("Enter Number %i:\n",i+1);
      scanf("%f",&A[i]);
      sum=sum +A[i];
	}
    average=sum/n;
    printf("Average=%.2f\n",average);
}
