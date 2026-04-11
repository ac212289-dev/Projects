#include <stdio.h>
#include <string.h>

#define MAX 100

// Permission flags
#define READ  4   // 100
#define WRITE 2   // 010
#define EXEC  1   // 001

// Structure
struct File {
    char name[50];
    int size;
    int perm; // stores permission flags
};

// Function prototypes
void createFile(struct File *f, int *count);
void displayFiles(struct File *f, int count);
void changePermission(struct File *f, int count);
void checkPermission(struct File *f, int count);

int main() {
    struct File files[MAX];
    int count = 0, choice;

    do {
        printf("\n===== File Permission System =====\n");
        printf("1. Create File\n");
        printf("2. Display Files\n");
        printf("3. Change Permissions\n");
        printf("4. Check Permissions\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                createFile(files, &count);
                break;
            case 2:
                displayFiles(files, count);
                break;
            case 3:
                changePermission(files, count);
                break;
            case 4:
                checkPermission(files, count);
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

// Create file
void createFile(struct File *f, int *count) {
    printf("Enter file name: ");
    scanf("%s", f[*count].name);

    printf("Enter file size: ");
    scanf("%d", &f[*count].size);

    f[*count].perm = 0; // no permission initially

    (*count)++;
    printf("File created!\n");
}

// Display files
void displayFiles(struct File *f, int count) {
    for(int i = 0; i < count; i++) {
        printf("\nFile: %s", f[i].name);
        printf("\nSize: %d KB", f[i].size);

        printf("\nPermissions: ");
        if(f[i].perm & READ) printf("r");
        if(f[i].perm & WRITE) printf("w");
        if(f[i].perm & EXEC) printf("x");
        if(f[i].perm == 0) printf("None");

        printf("\n----------------------\n");
    }
}

// Change permissions
void changePermission(struct File *f, int count) {
    char name[50];
    int choice;

    printf("Enter file name: ");
    scanf("%s", name);

    for(int i = 0; i < count; i++) {
        if(strcmp(f[i].name, name) == 0) {

            printf("1. Add Read\n");
            printf("2. Add Write\n");
            printf("3. Add Execute\n");
            printf("4. Remove Read\n");
            printf("5. Remove Write\n");
            printf("6. Remove Execute\n");
            printf("Enter choice: ");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    f[i].perm |= READ;
                    break;
                case 2:
                    f[i].perm |= WRITE;
                    break;
                case 3:
                    f[i].perm |= EXEC;
                    break;
                case 4:
                    f[i].perm &= ~READ;
                    break;
                case 5:
                    f[i].perm &= ~WRITE;
                    break;
                case 6:
                    f[i].perm &= ~EXEC;
                    break;
                default:
                    printf("Invalid choice!\n");
                    return;
            }

            printf("Permission updated!\n");
            return;
        }
    }
    printf("File not found!\n");
}

// Check permissions
void checkPermission(struct File *f, int count) {
    char name[50];

    printf("Enter file name: ");
    scanf("%s", name);

    for(int i = 0; i < count; i++) {
        if(strcmp(f[i].name, name) == 0) {

            printf("\nPermissions for %s:\n", f[i].name);

            if(f[i].perm & READ)
                printf("Read allowed\n");
            else
                printf("Read not allowed\n");

            if(f[i].perm & WRITE)
                printf("Write allowed\n");
            else
                printf("Write not allowed\n");

            if(f[i].perm & EXEC)
                printf("Execute allowed\n");
            else
                printf("Execute not allowed.\n");

            return;
        }
    }
    printf("File not found!\n");
}