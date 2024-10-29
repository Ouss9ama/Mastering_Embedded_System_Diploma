/*
 * Pb_8_main.c
 *
 *  Created on: Oct 6, 2024
 *      Author: oussa
 */


#include<stdio.h>

void print_rev(int a[],int s);
int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int n;// arr should be define only after knowing the size n

	printf("Enter the size of the array:\n");
	scanf("%d", &n);
	int arr[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	print_rev(arr,n);
}

void print_rev(int a[], int s)
{
	int b[s];
	for(int j=s-1,i=0;j>=0;j--,i++)
	{
		b[j]=a[i];
	}
	for(int j=0;j<s;j++)
	{
		printf("%d ",b[j]);
	}
}
