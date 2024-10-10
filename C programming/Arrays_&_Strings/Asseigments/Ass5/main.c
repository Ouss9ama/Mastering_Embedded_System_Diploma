/*
 * main.c
 *
 *  Created on: Apr 21, 2024
 *      Author: oussama
 */
//search for an item in an array
#include<stdio.h>

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int M[50];
	int n,i,x,counter;
	printf("Enter number of elements:\n");
	scanf("%d",&n);
	//get the elements from the user
	printf("Enter the elements:\n");
		for(i=0;i<n;i++)
		{
			scanf("%d",&M[i]);
		}


	//print the array
	for(i=0;i<n;i++)
	{
		printf("%d\t",M[i]);
	}
	//get the number to be searched
	printf("\nEnter the element to be searched:\n");
	scanf("%d",&x);

	//see if the number exist
	for(i=0,counter=0;i<n;i++)
	{
		if (x==M[i])
		{
			printf("Number found at location %d\n",i+1);

//counter that will help us to know if the number does not exist
		}
		else
		{
			counter++;
		}

	}

	if (counter==i)
	{
		printf("the number does not exist\n");
	}

}

