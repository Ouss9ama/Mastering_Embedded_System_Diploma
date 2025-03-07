/*
 * main.c
 *
 *  Created on: Apr 17, 2024
 *      Author: oussama
 */


// store and prints the degree of 10 students using arrays
#include <stdio.h>

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
int i;
float degree[10];
for(i=1;i<11;i++)
{
	printf("Enter student %d degree:\n\r",i);
	scanf("%f",&degree[i]);
}
for(i=1;i<11;i++)
{
	printf("student %d degree:%f\n\r",i,degree[i]);
}

}
