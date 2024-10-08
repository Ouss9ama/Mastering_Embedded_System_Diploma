/*
 * main.c
 *
 *  Created on: Jun 21, 2024
 *      Author: oussama
 */

#include<stdio.h>

int prime(int n);
void print(int a,int b);
	int x;
	int y;
	int i,j;
int main()
{

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	printf("Enter the two numbers:\n");
	scanf("%d %d",&x,&y);
	print(x,y);

}

	  int prime(int n)
	  {
		  for(i=2;i<=(n/2);i++)
		  {
			 if(n%i==0)
			 {
				 return 0;

			 }

		  }
		  return 1;
	  }
	void print(int a,int b)
	{

	  for (j=a;j<=b;j++)
	  	{
	  		if(prime(j)==1)
	  		{
	  			printf("%d  ",j);
	  		}

	}

