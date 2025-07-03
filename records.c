#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    int roll;
    float marks;
};

void addStudent() {
    FILE *fp = fopen("students.txt", "a");
    struct Student s;

    printf("Enter Name: ");
    scanf("%s", s.name);
    printf("Enter Roll No: ");
    scanf("%d", &s.roll);
    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
    printf("Student added!\n");
}

void viewStudents() {
    FILE *fp = fopen("students.txt", "r");
    struct Student s;

    printf("\n--- All Students ---\n");
    while (fread(&s, sizeof(s), 1, fp)) {
        printf("Name: %s, Roll: %d, Marks: %.2f\n", s.name, s.roll, s.marks);
    }
    fclose(fp);
}

void searchStudent() {
    FILE *fp = fopen("students.txt", "r");
    struct Student s;
    int roll, found = 0;

    printf("Enter roll number to search: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.roll == roll) {
            printf("Found: %s - Marks: %.2f\n", s.name, s.marks);
            found = 1;
            break;
        }
    }
    fclose(fp);

    if (!found) printf("Student not found.\n");
}

int main() {
    int choice;

    do {
        printf("\n--- Student Record System ---\n");
        printf("1. Add Student\n2. View All Students\n3. Search by Roll Number\n4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while(choice != 4);

    return 0;
}
