/*
 * main.c
 *
 *  Created on: Oct 21, 2024
 *      Author: oussa
 */

#include<stdio.h>
#include<string.h>
int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	char str[60];
	printf("Enter the string:\n");
	fgets(str, sizeof(str), stdin);
	str[strcspn(str, "\n")] = '\0';

	char* ptr=&str[strlen(str)-1];

	for(int i= strlen(str)-1;i>=0;i--)
	{
		printf("%c",*ptr--);
	}
}
