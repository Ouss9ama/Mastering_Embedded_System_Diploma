/*
 * main.c
 *
 *  Created on: Oct 11, 2024
 *      Author: oussa
 */

#include<stdio.h>

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	printf("Size of union = 32\n");
	printf("Size of structure = 40\n");
}
