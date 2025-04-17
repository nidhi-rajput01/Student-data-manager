#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
    struct Student* next;
};

struct Student* head = NULL;

// Function to add student
void addStudent(int roll, char name[], float marks) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    newStudent->roll = roll;
    strcpy(newStudent->name, name);
    newStudent->marks = marks;
    newStudent->next = head;
    head = newStudent;
    printf("Student added successfully!\n");
}

// Function to display students
void displayStudents() {
    struct Student* temp = head;
    if (temp == NULL) {
        printf("No student records found.\n");
        return;
    }
    printf("\n--- Student Records ---\n");
    while (temp != NULL) {
        printf("Roll No: %d\n", temp->roll);
        printf("Name   : %s\n", temp->name);
        printf("Marks  : %.2f\n\n", temp->marks);
        temp = temp->next;
    }
}

// Function to delete student by roll number
void deleteStudent(int roll) {
    struct Student *temp = head, *prev = NULL;

    while (temp != NULL && temp->roll != roll) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Student not found!\n");
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
    printf("Student deleted successfully!\n");
}

int main() {
    int choice, roll;
    char name[50];
    float marks;

    do {
        printf("\n===== Student Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Delete Student\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter Roll No: ");
            scanf("%d", &roll);
            printf("Enter Name: ");
            scanf(" %[^\n]s", name);
            printf("Enter Marks: ");
            scanf("%f", &marks);
            addStudent(roll, name, marks);
            break;
        case 2:
            displayStudents();
            break;
        case 3:
            printf("Enter Roll No to delete: ");
            scanf("%d", &roll);
            deleteStudent(roll);
            break;
        case 4:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}