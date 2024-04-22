/*
 * main.c
 *
 *  Created on: Mar 22, 2024
 *      Author: oussama
 */


#include <stdio.h>

int main()
{

	int Nb_student;
	int i=1;
	float Summ=0;
	float grade;
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	printf("Enter the number of students:\r\n");
	scanf("%d", &Nb_student);

	while (i<=Nb_student)
	{
		printf("the grade of student %d :\r\n", i);
		scanf("%f", &grade);
		Summ+=grade;
		i+=1;

	}

	printf("The average grade is : %f", Summ/Nb_student);


//	for(i=1;i<=Nb_student;i++)
//	{
//      printf("Enter student %i grade:\r\n", i);
//      scanf("%f", &grade);
//      Summ+=grade;
//	}
//	printf("The average grade is : %f", Summ/Nb_student);
}

