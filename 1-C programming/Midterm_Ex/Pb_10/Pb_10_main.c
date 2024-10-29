/*
 * Pb_10_main.c
 *
 *  Created on: Oct 7, 2024
 *      Author: oussa
 */

#include<stdio.h>

void to_binary(int x);
int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int nb=0;
	printf("Enter the number:\n");
	scanf("%d",&nb);
	to_binary(nb);
}

void to_binary(int x)
{

	int arr[8]={0};

	int i=7;


	while (x!=0)
	{
		arr[i]= x%2;
		i--;
		x=x/2;
	}

	printf("Binary form: ");
	for(int j=0;j<8;j++)
	{
		printf("%d",arr[j]);

	}

	printf("\n");
	int now=0;
	int max=0;
	 for(i=0;i<8;i++)
	 {
		 if(arr[i]==1)
		 {
			 now++;
			 if(now>max)
			 {
				 max=now;
			 }
		 }
		 else
		 {
			 now=0;
		 }
	 }

	 printf("the number of max of ones between zero is: %d",max);





}
