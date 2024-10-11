/*
 * main.c
 *
 *  Created on: Oct 11, 2024
 *      Author: oussa
 */

#include<stdio.h>
#include<string.h>//to use strcspn

struct Sdata{
	char name[30];
	float mark;
};

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	struct Sdata ID[10];
	printf("Enter the information of the student\n");

	for (int i=0;i<10;i++)
	{
		printf("for ID number %d \n",i+1);
		printf("Enter Name: ");
		fgets(ID[i].name, sizeof(ID[i].name), stdin);//can't use scanf because they mey be some space
		ID[i].name[strcspn(ID[i].name, "\n")] = '\0'; // to find the /n and replace with null charcter
		printf("Enter the mark: ");
		scanf("%f",&ID[i].mark);
		getchar(); // Consume the newline character
	}

	printf("Displaying informations of students:\n\n");

	for (int i=0;i<10;i++)
	{
		printf("information for ID number: %d\n",i+1);
		printf("Name is %s\n",ID[i].name);
		printf("Mark is %.2f\n\n",ID[i].mark);
	}

}
