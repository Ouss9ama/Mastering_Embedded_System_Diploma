/*
 * main.c
 *
 *  Created on: May 22, 2024
 *      Author: oussama
 */


#include<stdio.h>
void row(int x);
int g;
int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int i;
	printf("Enter the how many numbers you want\n");
	scanf("%d",&g);
	for(i=0;i<=g;i++)
	{
		row(i);
		printf("\n");
	}

}

void row(int x)
{
	int j;
	for(j=x;j<=g;j++)
	{
		printf("%d ",j);
	}
}
