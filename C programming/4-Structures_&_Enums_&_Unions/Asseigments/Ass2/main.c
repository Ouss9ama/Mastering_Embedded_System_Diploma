/*
 * main.c
 *
 *  Created on: Oct 11, 2024
 *      Author: oussa
 */

#include<stdio.h>
#include <math.h>

struct Sdistance{
	int feet;
	double inches;
};

struct Sdistance F_I(struct Sdistance n1, struct Sdistance n2);

int main()
{


	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	struct Sdistance d1, d2, S;

	printf("Enter information of the 1st distance:\n");
	printf("Enter Feet: ");
	scanf("%d",&d1.feet);
	printf("Enter Inch: ");
	scanf("%lf",&d1.inches);

	printf("Enter information of the 2nd distance:\n");
	printf("Enter Feet: ");
	scanf("%d",&d2.feet);
	printf("Enter Inch: ");
	scanf("%lf",&d2.inches);

	S = F_I(d1,d2);
	printf("Sum of the distances: %d %lf",S.feet,S.inches);
}

struct Sdistance F_I(struct Sdistance n1, struct Sdistance n2)
{
	struct Sdistance z;
	z.feet = n1.feet + n2.feet;
	z.inches = n1.inches + n2.inches;
	if(z.inches>12)
	{
		z.feet+=(int)z.inches/12;
		z.inches= fmod(z.inches,12);
	}

	return z;
}
