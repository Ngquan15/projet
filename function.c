#include <stdio.h>
#include <string.h>
#include "function.h"

void addStudent() {
    FILE *file = fopen("student.bin", "ab");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return;
    }
    int numberStudents;
    printf("Enter the number of students you want to add: ");
    scanf("%d", &numberStudents);
    getchar();
    int i;
    for (i = 0; i < numberStudents; i++) {
        Student student;
        printf("\nStudent %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &student.id);
        getchar();
        printf("Name: ");
        fgets(student.name, sizeof(student.name), stdin);
        student.name[strcspn(student.name, "\n")] = '\0';
        printf("Email: ");
        fgets(student.email, sizeof(student.email), stdin);
        student.email[strcspn(student.email, "\n")] = '\0';
        printf("Phone: ");
        fgets(student.phone, sizeof(student.phone), stdin);
        student.phone[strcspn(student.phone, "\n")] = '\0';
        fwrite(&student, sizeof(Student), 1, file);
    }
    fclose(file);
    printf("\n%d students added successfully.\n", numberStudents);
}

void displayStudents() {
    FILE *file = fopen("student.bin", "rb");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return;
    }
    
    Student student;
    printf("\nStudent list:\n");
    printf("=======================================================================\n");
    printf("|    ID    |        Name        |       Email        |      Phone      |\n");
    printf("=======================================================================\n");
    
    while (fread(&student, sizeof(Student), 1, file)) {
        printf("| %-4d | %-20s | %-25s | %-15s |\n",student.id, student.name, student.email, student.phone);
    }
    printf("-----------------------------------------------------------------------\n");
    fclose(file);
}
void updateStudents() {
	printf("\n === Update Student Information ===\n");
    FILE *file = fopen("student.bin", "rb+");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return;
    }
    Student student;
    int id; 
	int found = 0; 
    printf("Enter the ID of the student to update: ");
    scanf("%d",&id);
	getchar();
    while (fread(&student, sizeof(Student), 1, file)) {
        if (student.id == id) {
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student with this ID was not found.\n");
        fclose(file);
        return;
    }

    printf("Current information:\n");
    printf("ID: %d\n", student.id);
    printf("Name: %s\n", student.name);
    printf("Email: %s\n", student.email);
    printf("Phone: %s\n", student.phone);

    printf("New Name: ");
    fgets(student.name, sizeof(student.name), stdin);
    student.name[strcspn(student.name, "\n")] = '\0'; 
    
    printf("New Email: ");
    fgets(student.email, sizeof(student.email), stdin);
    student.email[strcspn(student.email, "\n")] = '\0';

    printf("New Numberphone: ");
    fgets(student.phone, sizeof(student.phone), stdin);
    student.phone[strcspn(student.phone, "\n")] = '\0';

    fseek(file, -sizeof(Student), SEEK_CUR);
    fwrite(&student, sizeof(Student), 1, file);

    printf("Student information updated successfully!\n");
    fclose(file);
    pressToExitOrReturn();
}

void pressToExitOrReturn() {
    char choice;
    printf("\n         -[0]- Exit      -[B]- Back to menu\n");
    scanf("%c", &choice);  
    getchar();  

    if (choice == '0') {
        printf("Exiting...\n");
        return 0; 
    } else if (choice == 'b') {
        return;
    } else {
        printf("Invalid choice. Returning to menu...\n");
        return;
    }
}

    
