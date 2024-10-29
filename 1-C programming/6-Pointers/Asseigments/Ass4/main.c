/*
 * main.c
 *
 *  Created on: Oct 21, 2024
 *      Author: oussa
 */

#include<stdio.h>

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int arr[15];
	int x=0;
	printf("Input the number of elements to store in the array (max 15): \n");
	scanf("%d",&x);
	int*ptr=arr;
	printf("Input %d number of elements in the array :\n",x);
	for(int i=0;i<x;i++)
	{
		printf("element %d: \n",i);
		scanf("%d",ptr++);
	}

	printf("The elements of array in reverse order are :\n");

	 ptr=&arr[x-1];
	for(int i=x-1;i>=0;i--)
	{
		printf("the element %d: %d \n",i,*ptr--);
	}

}
