/*
 * main.c
 *
 *  Created on: Mar 6, 2025
 *      Author: oussa
 */

#include "linked_list.h"
#define  DPRINTF(...)       {fflush(stdout);\
						   fflush(stdin);\
						   printf(__VA_ARGS__);\
						   fflush(stdout);\
						   fflush(stdin);}
void main(){

	char temp_text[40];

	while(1){
		DPRINTF("\n=========================\n");
		DPRINTF("\t Choose One of the following options:\n");
		DPRINTF("1: AddStudent \n");
		DPRINTF("2: Delete_student \n");
		DPRINTF("3: View_students \n");
		DPRINTF("4: Delete_all \n");
		DPRINTF("5: View student data of a certain index \n");
		DPRINTF("6: View number of student records in the list1 \n");
		DPRINTF("7: View student data of a certain index from reverse \n");
		DPRINTF("8: View the reversed student data \n");
		DPRINTF("Enter the option number: \n");
		gets(temp_text);

		DPRINTF("\n=========================\n");
		switch(atoi(temp_text))
		{
		case 1:
			ADD_STUDENT();
			break;
		case 2:
			DELETE_STUDENT();
			break;
		case 3:
			VIEW_STUDENTS();
			break;
		case 4:
			DELETE_ALL();
			break;
		case 5:
			GET_DATA_FROM_INDEX();
			break;
		case 6:
			NB_RECORDS();
			break;
		case 7:
			GET_DATA_FROM_INDEX_REVERSE();
			break;
		case 8:
			INVERSE_THE_LIST();
			break;
		default:
			DPRINTF("WRONG OPTION \n");
			break;
		}




	}
}
