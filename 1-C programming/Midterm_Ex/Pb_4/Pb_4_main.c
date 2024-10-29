/*
 * Pb_4_main.c
 *
 *  Created on: Oct 6, 2024
 *      Author: oussa
 */


#include<stdio.h>

int reverse(int x);
int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int nb;

	printf("Enter the number:\n");
	scanf("%d", &nb);
	printf("the reverse is:\n%d",reverse(nb));
}

int reverse(int x)
{
	int res=0;
	int rem=0;
	while(x!=0)
	{
		rem=x % 10;
		res= res *10 + rem;
		x=x/10;
	}
	return res;
}
