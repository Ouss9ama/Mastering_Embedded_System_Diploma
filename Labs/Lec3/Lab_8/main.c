/*
 * main.c
 *
 *  Created on: Mar 22, 2024
 *      Author: oussama
 */


#include <stdio.h>

int main()
{

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int sum=0;
	int i=1;

	while(i<100)
	{

		sum+=i;
		i+=2;
	}
	printf("sum is %d",sum);

}
