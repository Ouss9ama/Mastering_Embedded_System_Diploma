/*
 * main.c
 *
 *  Created on: Jun 21, 2024
 *      Author: oussama
 */
#include<stdio.h>
int numb;
int fact(int x);
int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	printf("Enter a positive integer:\n");
	scanf("%d",&numb);
	fact(numb);
	printf("factorial of %d : %d",numb,fact(numb));
}
int fact(int x)
{
	if(x==0||x==1)
	{
		return 1;
	}
	else
	{
		return (x * fact(x-1));
	}


}
