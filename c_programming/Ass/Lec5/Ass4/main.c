/*
 * main.c
 *
 *  Created on: Jun 22, 2024
 *      Author: oussama
 */

 #include<stdio.h>

int base;
int power;
int oss(int nb,int p);
int main()
{

	int result;
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	printf("Enter base number:\n");
	scanf("%d",&base);
	printf("Enter power number:\n");
	scanf("%d",&power);
	result=oss(base,power);
	printf("%d^%d=%d",base,power,result);
}

int oss(int nb, int p)
{

	if(p==0)
	{
		return 1;
	} 
	if(p==1)
	{
		return nb;
	}
 
	return nb*oss(nb,p-1);
}

