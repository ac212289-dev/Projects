#include <stdio.h>
#include <string.h>

#define MAX 100

// Bitwise flags
#define ATTENDANCE 1   // 0001
#define FEES_PAID  2   // 0010

// Structure
struct Student {
    int id;
    char name[50];
    int marks;
    int status; // stores flags
};

// Function prototypes
void addStudent(struct Student *s, int *count);
void displayStudents(struct Student *s, int count);
void updateMarks(struct Student *s, int count);
void updateStatus(struct Student *s, int count);

int main() {
    struct Student students[MAX];
    int count = 0, choice;

    do {
        printf("\n===== Student Record Manager =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Update Marks\n");
        printf("4. Update Status (Flags)\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                updateMarks(students, count);
                break;
            case 4:
                updateStatus(students, count);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 5);

    return 0;
}

// Add student
void addStudent(struct Student *s, int *count) {
    printf("Enter ID: ");
    scanf("%d", &s[*count].id);

    printf("Enter Name: ");
    scanf("%s", s[*count].name);

    printf("Enter Marks: ");
    scanf("%d", &s[*count].marks);

    s[*count].status = 0; // initially no flags

    (*count)++;
    printf("Student added successfully!\n");
}

// Display students
void displayStudents(struct Student *s, int count) {
    for(int i = 0; i < count; i++) {
        printf("\nID: %d", s[i].id);
        printf("\nName: %s", s[i].name);
        printf("\nMarks: %d", s[i].marks);

        printf("\nAttendance: ");
        if(s[i].status & ATTENDANCE)
            printf("Present");
        else
            printf("Absent");

        printf("\nFees: ");
        if(s[i].status & FEES_PAID)
            printf("Paid");
        else
            printf("Not Paid");

        printf("\n------------------------\n");
    }
}

// Update marks
void updateMarks(struct Student *s, int count) {
    int id;
    printf("Enter ID to update marks: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++) {
        if(s[i].id == id) {
            printf("Enter new marks: ");
            scanf("%d", &s[i].marks);
            printf("Marks updated!\n");
            return;
        }
    }
    printf("Student not found!\n");
}

// Update status using bitwise operations
void updateStatus(struct Student *s, int count) {
    int id, choice;
    printf("Enter ID: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++) {
        if(s[i].id == id) {

            printf("1. Mark Attendance\n");
            printf("2. Pay Fees\n");
            printf("Enter choice: ");
            scanf("%d", &choice);

            if(choice == 1) {
                s[i].status |= ATTENDANCE; // set bit
                printf("Attendance marked!\n");
            }
            else if(choice == 2) {
                s[i].status |= FEES_PAID; // set bit
                printf("Fees updated!\n");
            }
            else {
                printf("Invalid choice!\n");
            }
            return;
        }
    }
    printf("Student not found!\n");
}