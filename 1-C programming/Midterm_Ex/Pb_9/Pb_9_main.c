/*
 * Pb_9_main.c
 *
 *  Created on: Oct 6, 2024
 *      Author: oussa
 */

#include<stdio.h>
#include<string.h>
void rev(char c[]);
int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	char strg[100];

	printf("Enter your string:\n");
	fgets(strg, sizeof(strg), stdin);//Read up to n characters into this array." This leaves one space for the null terminator.ensures that there’s room for the null terminator, preventing memory overflow.
	strg[strcspn(strg, "\n")] = '\0';// it it finds the index of '\n'and replace it with '/0'

	rev(strg);
}

void rev(char c[])
{
	int n= strlen(c);
	int start=0;
	int end=0;
	int word_ind[30][2];
	int word_count=0;


	for(int i=0;i<=n;i++)
	{

		if(c[i]==' ' || c[i]=='\0')
		{
			if(start<end)
			{

				word_ind[word_count][0]=start;
				word_ind[word_count][1]=end-1;
				word_count+=1;


			}

			start=i+1;
		}
		else
		{
			end=i+1;
		}
	}

	printf("number of words:\n %d \n",word_count);

	for(int i=word_count-1;i>=0;i--)
	{
		for(int j=word_ind[i][0];j<=word_ind[i][1];j++)
		{
			putchar(c[j]);
		}
		if(i>0)
		{
			putchar(' ');
		}
	}
}



