/*
 * main.c
 *
 *  Created on: Mar 21, 2024
 *      Author: oussama
 */
//summ from 1 to 99
#include<stdio.h>

int main()
{
	int i;
	int summ=0;

	for(i=1;i<100;i++)
	{
		summ += i;
	}
	printf(" the summ of numbers str from 1 to 99 is = %i", summ);
}
