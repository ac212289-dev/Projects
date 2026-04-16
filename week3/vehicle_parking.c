// vehicle parking managment system
#include <stdio.h>
#include <string.h>

#define MAX 10

// Bitwise flags
#define OCCUPIED 1
#define VIP      2
#define RESERVED 4

// Structure
struct Slot {
    int slotNo;
    char vehicleNo[20];
    int status;
};

// Function prototypes
void parkVehicle(struct Slot *s, int n);
void removeVehicle(struct Slot *s, int n);
void displaySlots(struct Slot *s, int n);
void updateSlotStatus(struct Slot *s, int n);

int main() {
    struct Slot slots[MAX];
    int choice;

    // Initialize slots
    for(int i = 0; i < MAX; i++) {
        slots[i].slotNo = i + 1;
        slots[i].status = 0;
        strcpy(slots[i].vehicleNo, "Empty");
    }

    do {
        printf("\n===== Parking System =====\n");
        printf("1. Park Vehicle\n");
        printf("2. Remove Vehicle\n");
        printf("3. Display Slots\n");
        printf("4. Update Slot Flags\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                parkVehicle(slots, MAX);
                break;
            case 2:
                removeVehicle(slots, MAX);
                break;
            case 3:
                displaySlots(slots, MAX);
                break;
            case 4:
                updateSlotStatus(slots, MAX);
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

// Park vehicle
void parkVehicle(struct Slot *s, int n) {
    int slot;
    printf("Enter slot number (1-%d): ", n);
    scanf("%d", &slot);

    if(slot < 1 || slot > n) {
        printf("Invalid slot!\n");
        return;
    }

    if(s[slot-1].status & OCCUPIED) {
        printf("Slot already occupied!\n");
        return;
    }

    printf("Enter vehicle number: ");
    scanf("%s", s[slot-1].vehicleNo);

    s[slot-1].status |= OCCUPIED;
    printf("Vehicle parked!\n");
}

// Remove vehicle
void removeVehicle(struct Slot *s, int n) {
    int slot;
    printf("Enter slot number: ");
    scanf("%d", &slot);

    if(!(s[slot-1].status & OCCUPIED)) {
        printf("Slot already empty!\n");
        return;
    }

    s[slot-1].status &= ~OCCUPIED;
    strcpy(s[slot-1].vehicleNo, "Empty");

    printf("Vehicle removed!\n");
}

// Display slots
void displaySlots(struct Slot *s, int n) {
    for(int i = 0; i < n; i++) {
        printf("\nSlot %d", s[i].slotNo);
        printf("\nVehicle: %s", s[i].vehicleNo);

        printf("\nStatus: ");
        if(s[i].status & OCCUPIED) printf("O ccupied ");
        else printf("Empty ");

        if(s[i].status & VIP) printf("VIP ");
        if(s[i].status & RESERVED) printf("Reserved ");

        printf("\n-------------------\n");
    }
}

// Update slot flags
void updateSlotStatus(struct Slot *s, int n) {
    int slot, choice;
    printf("Enter slot number:");
    scanf("%d", &slot);

    printf("1. Mark VIP\n");
    printf("2. Mark Reserved\n");
    printf("3. Remove VIP\n");
    printf("4. Remove Reserved\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            s[slot-1].status |= VIP;
            break;
        case 2:
            s[slot-1].status |= RESERVED;
            break;
        case 3:
            s[slot-1].status &= ~VIP;
            break;
        case 4:
            s[slot-1].status &= ~RESERVED;
            break;
        default:
            printf("Invalid choices!\n");
            return;
    }

    printf("Status updated!\n");
}