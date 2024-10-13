/*
 * Pb_5_main.c
 *
 *  Created on: Oct 6, 2024
 *      Author: oussa
 */


#include<stdio.h>
int bit(int x);
int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int nb;

	printf("Enter the number:\n");
	scanf("%d", &nb);
	printf("The output is:\n%d",bit(nb));

}

int bit(int x)
{
	int counter=0;
	while(x!=0)
	{
		if ((x%2)!=0)
		{
			counter++;
		}
		x=x/2;
	}
	return counter;
}
