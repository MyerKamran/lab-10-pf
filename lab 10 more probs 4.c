#include <stdio.h>
#include <string.h>

#define MAX_CARS 100

typedef struct {
    char make[50];
    char model[50];
    int year;
    float price;
    float mileage;
} Car;

void addCar(Car cars[], int *count) {
    if (*count >= MAX_CARS) {
        printf("Cannot add more cars. Maximum limit reached.\n");
        return;
    }

    Car newCar;
    printf("Enter car make: ");
    scanf("%s", newCar.make);
    printf("Enter car model: ");
    scanf("%s", newCar.model);
    printf("Enter year: ");
    scanf("%d", &newCar.year);
    printf("Enter price: ");
    scanf("%f", &newCar.price);
    printf("Enter mileage: ");
    scanf("%f", &newCar.mileage);

    cars[*count] = newCar;
    (*count)++;
    printf("Car added successfully!\n");
}

void displayCars(Car cars[], int count) {
    if (count == 0) {
        printf("No cars available.\n");
        return;
    }

    printf("\n--- Available Cars ---\n");
    for (int i = 0; i < count; i++) {
        printf("Make: %s\n", cars[i].make);
        printf("Model: %s\n", cars[i].model);
        printf("Year: %d\n", cars[i].year);
        printf("Price: $%.2f\n", cars[i].price);
        printf("Mileage: %.2f km\n", cars[i].mileage);
        printf("--------------------------\n");
    }
}

void searchCarByMakeOrModel(Car cars[], int count) {
    if (count == 0) {
        printf("No cars available to search.\n");
        return;
    }

    char search[50];
    printf("Enter make or model to search: ");
    scanf("%s", search);

    printf("\n--- Search Results ---\n");
    for (int i = 0; i < count; i++) {
        if (strcmp(cars[i].make, search) == 0 || strcmp(cars[i].model, search) == 0) {
            printf("Make: %s\n", cars[i].make);
            printf("Model: %s\n", cars[i].model);
            printf("Year: %d\n", cars[i].year);
            printf("Price: $%.2f\n", cars[i].price);
            printf("Mileage: %.2f km\n", cars[i].mileage);
            printf("--------------------------\n");
        }
    }
}

int main() {
    Car cars[MAX_CARS];
    int carCount = 0;
    int choice;

    do {
        printf("\n--- Car Dealership Management ---\n");
        printf("1. Add Car\n");
        printf("2. Display Cars\n");
        printf("3. Search Car by Make or Model\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCar(cars, &carCount);
                break;
            case 2:
                displayCars(cars, carCount);
                break;
            case 3:
                searchCarByMakeOrModel(cars, carCount);
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
