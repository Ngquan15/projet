#include <stdio.h>
#include <stdlib.h>
#include "function.h"


int main(int argc, char *argv[]){
	int choice;
	do{
		printf("\n===Student Management System Using C===\n");
		printf(" \n");
		printf("         =========MENU=========\n");
		printf("         [1] Add A New Student.\n");
		printf("         [2] Show All Students.\n");
		printf("         [3] Search A Student.\n");
		printf("         [4] Edit A Student.\n");
		printf("         [5] Delete A Student.\n");
		printf("         [6] Arrange students\n");
		printf("         [0] Exit Program.\n");
		printf("         ======================\n");
		printf("         Enter Your Choice: ");
		scanf("%d",&choice);
		getchar();
		
		switch (choice){
			case 1:{
				addStudent();
				break;
			}
			case 2:{
				displayStudents();
				break;
			}
			case 3:{
				updateStudents();
				break;
			}
			case 0:{
				printf("Exit to program");
				break;
			}
			default:
            printf("Invalid selection. Please try again.\n");
		}
	}while(choice!=0);
	
	return 0;
}
