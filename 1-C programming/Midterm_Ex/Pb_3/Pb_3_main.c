/*
 * Pb_3_main.c
 *
 *  Created on: Oct 6, 2024
 *      Author: oussa
 */

#include<stdio.h>

int Prime(int in);
void print(int x, int y);
int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int A,Z;
	printf("Enter a number:\n");
	scanf("%d %d",&A,&Z);
	print(A, Z);
}

int Prime(int in)

{
	if(in==1)
	{
		return 1;
	}
	for(int j=2;j<in;j++)
	{
		if (in % j==0)
		{
			return 0;
		}


	}
	return 1;
}

void print(int x, int y)
{
	for(int i=x;i<=y;i++)
	{
		if (Prime(i)==1)
		{
			printf("%d ",i);
		}
	}

}
