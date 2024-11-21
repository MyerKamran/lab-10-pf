#include <stdio.h>
#include <string.h>

#define MAX_PACKAGES 100

typedef struct {
    char packageName[100];
    char destination[100];
    int duration;
    float cost;
    int availableSeats;
} TravelPackage;

void bookPackage(TravelPackage packages[], int *count) {
    char packageName[100];
    printf("Enter package name to book: ");
    scanf("%s", packageName);

    for (int i = 0; i < *count; i++) {
        if (strcmp(packages[i].packageName, packageName) == 0) {
            if (packages[i].availableSeats > 0) {
                packages[i].availableSeats--;
                printf("Package booked successfully. Remaining seats: %d\n", packages[i].availableSeats);
                return;
            } else {
                printf("No seats available for this package.\n");
                return;
            }
        }
    }

    printf("Package not found.\n");
}

void displayPackages(TravelPackage packages[], int count) {
    if (count == 0) {
        printf("No travel packages available.\n");
        return;
    }

    printf("\n--- Available Travel Packages ---\n");
    for (int i = 0; i < count; i++) {
        printf("Package Name: %s\n", packages[i].packageName);
        printf("Destination: %s\n", packages[i].destination);
        printf("Duration: %d days\n", packages[i].duration);
        printf("Cost: $%.2f\n", packages[i].cost);
        printf("Available Seats: %d\n", packages[i].availableSeats);
        printf("-------------------------------\n");
    }
}

int main() {
    TravelPackage packages[MAX_PACKAGES];
    int packageCount = 0;
    int choice;

    do {
        printf("\n--- Travel Package Management ---\n");
        printf("1. Add Travel Package\n");
        printf("2. Display Available Packages\n");
        printf("3. Book a Travel Package\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter package name: ");
                scanf("%s", packages[packageCount].packageName);
                printf("Enter destination: ");
                scanf("%s", packages[packageCount].destination);
                printf("Enter duration (in days): ");
                scanf("%d", &packages[packageCount].duration);
                printf("Enter cost: ");
                scanf("%f", &packages[packageCount].cost);
                printf("Enter available seats: ");
                scanf("%d", &packages[packageCount].availableSeats);
                packageCount++;
                break;
            case 2:
                displayPackages(packages, packageCount);
                break;
            case 3:
                bookPackage(packages, &packageCount);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
