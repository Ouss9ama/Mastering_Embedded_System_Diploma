/*
 * main.c
 *
 *  Created on: Apr 21, 2024
 *      Author: oussama
 */


#include<stdio.h>
int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int M[10];
	int n,i,x,A;
	printf("Enter no of elements:\n");
	scanf("%d",&n);
	//gets the elements of the array from thr user
//	printf("Enter the values\n");
//	for(i=0;i<n;i++)
//	{
//		scanf("%d",&M[i]);
//	}
	//display the elements of the array
	for(i=0;i<n;i++)
	{
		printf("%d\t",M[i]);
	}
	//gets the elements to be inserted
	printf("\nEnter the element to be inserted:\n");
	scanf("%d",&x);
	//gets the location of replaced value
	printf("Enter the the location:\n");
	scanf("%d",&A);
	//replace the value
	for(i=0;i<n;i++)
	{
		if(i+1==A)
		{
			M[i]=x;
		}
	}
	//display the new matrix
	for(i=0;i<n;i++)
		{
			printf("%d\t",M[i]);
		}

}
