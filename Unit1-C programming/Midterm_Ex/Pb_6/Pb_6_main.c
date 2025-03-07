/*
 * Pb_6_main.c
 *
 *  Created on: Oct 6, 2024
 *      Author: oussa
 */

#include<stdio.h>

int main()
{

	int n;
	int x;
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	printf("Enter the size of the array:\n");
	scanf("%d",&n);
	int a[n];

	printf("Enter the elements of the array:\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}

	for(int i=0;i<n;i++)
	{
         x=0;
		 for(int j=0;j<n;j++)
		 {
			 if((a[i]==a[j]) && i!=j)
			 {
				 x=1;
				 break;
			 }
		 }
		 if(!x)
		 		printf("%d ",a[i]);
	}


}

