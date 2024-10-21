/*
 * main.c
 *
 *  Created on: Oct 20, 2024
 *      Author: oussa
 */


#include<stdio.h>


int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int m=29;
	printf("the address of m: %p\n",&m);
	printf("the value of m: %d\n",m);


	int * ab=&m;
	printf("the pointer ab hold the address: %p\n",ab);
	printf("it points to value of: %d\n",*ab);

	m=34;
	printf("the pointer ab hold the address: %p\n",ab);
	printf("it points to value of: %d\n",*ab);

	*ab=7;
	printf("address of m: %p\n",ab);
	printf("the value of m: %d\n",*ab);

}
