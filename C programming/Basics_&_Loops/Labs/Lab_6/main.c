/*
 * main.c
 *
 *  Created on: Mar 21, 2024
 *      Author: oussama
 */

#include <stdio.h>

int main()
{

	int Nb_student;
	int i;
	float Summ=0;
	float grade;
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	printf("Enter the number of students:\r\n");
	scanf("%d", &Nb_student);

	for(i=1;i<=Nb_student;i++)
	{
      printf("Enter student %i grade:\r\n", i);
      scanf("%f", &grade);
      Summ+=grade;
	}
	printf("The average grade is : %f", Summ/Nb_student);
}
