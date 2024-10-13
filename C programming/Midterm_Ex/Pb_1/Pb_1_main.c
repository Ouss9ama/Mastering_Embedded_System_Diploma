/*
 * Pb_1_main.c
 *
 *  Created on: Oct 6, 2024
 *      Author: oussama
 */

#include<stdio.h>

int Add(int X);
int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int x,i;
	printf("Enter a number:\n");
	scanf("%d",&x);
	i= Add(x);

	printf("Output:\n%d\n",i);
}

int Add(int X)
{
	int R;
	static int Y=0;
	if (X!=0)
	{
		R = X % 10;
		Y += R;
		Add(X / 10);
	}
	else
		return 0;
	return Y;
}
