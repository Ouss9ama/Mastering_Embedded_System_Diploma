/*
 * main.c
 *
 *  Created on: Oct 21, 2024
 *      Author: oussa
 */

#include<stdio.h>
#include<string.h>

struct info{
	char name[30];
	int ID;
};

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	//struct variables
	struct info x,y;
	struct info *ptrx= &x; //pointer to x
	struct info *ptry= &y; // pointer to y

	struct info*arr[2]={ptrx,ptry};//

	struct info**ptr_b= arr;

    ptrx->ID=1;
    strcpy(ptrx->name, "Oussama");

    ptry->ID=2;
    strcpy(ptry->name,"Mohamed");

    for(int i=0;i<2;i++)
    {
    printf("\tMember number %d\n",i+1);
    printf("Employee name: %s \n",ptr_b[i]->name);
    printf("Employee ID: %d\n",ptr_b[i]->ID);
    }

}
