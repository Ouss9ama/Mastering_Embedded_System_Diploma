/*
 * main.c
 *
 *  Created on: Oct 11, 2024
 *      Author: oussa
 */

#include<stdio.h>
#include<string.h>
struct Sstudent{
	char name[30];
	unsigned int ID;
	double marks;
};

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	struct Sstudent x;
	printf("Enter information of the student:\n");

	printf("Enter Name:");
	fgets(x.name, sizeof(x.name), stdin);//can't use scanf because they mey be some space
	x.name[strcspn(x.name, "\n")] = '\0'; // to find the /n and replace with null charcter

	printf("Enter ID: ");
	scanf("%u",&x.ID);


	printf("Enter the grade: ");
	scanf("%lf",&x.marks);


	printf("\nStudent information\n");
	printf("student Name: %s\n",x.name);
	printf("Student ID: %u\n",x.ID);
	printf("Student grade: %.2lf\n",x.marks);
}
