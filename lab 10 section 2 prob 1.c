#include <stdio.h>
#include <string.h>

#define MAX_FLIGHTS 100

typedef struct {
    int flightNumber;
    char departureCity[50];
    char destinationCity[50];
    char date[15];
    int availableSeats;
} Flight;

void addFlight(Flight flights[], int *count);
void displayFlights(Flight flights[], int count);
void bookSeat(Flight flights[], int count);

int main() {
    Flight flights[MAX_FLIGHTS];
    int flightCount = 0;
    int choice;

    do {
        printf("\n--- Flight Management System ---\n");
        printf("1. Add Flight\n");
        printf("2. Display Flights\n");
        printf("3. Book a Seat\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addFlight(flights, &flightCount);
                break;
            case 2:
                displayFlights(flights, flightCount);
                break;
            case 3:
                bookSeat(flights, flightCount);
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

void addFlight(Flight flights[], int *count) {
    if (*count >= MAX_FLIGHTS) {
        printf("Cannot add more flights. Maximum limit reached.\n");
        return;
    }

    Flight newFlight;
    printf("Enter flight number: ");
    scanf("%d", &newFlight.flightNumber);
    printf("Enter departure city: ");
    scanf("%s", newFlight.departureCity);
    printf("Enter destination city: ");
    scanf("%s", newFlight.destinationCity);
    printf("Enter date (dd/mm/yyyy): ");
    scanf("%s", newFlight.date);
    printf("Enter available seats: ");
    scanf("%d", &newFlight.availableSeats);

    flights[*count] = newFlight;
    (*count)++;
    printf("Flight added successfully!\n");
}

void displayFlights(Flight flights[], int count) {
    if (count == 0) {
        printf("No flights available.\n");
        return;
    }

    printf("\n--- Available Flights ---\n");
    for (int i = 0; i < count; i++) {
        printf("Flight Number: %d\n", flights[i].flightNumber);
        printf("Departure City: %s\n", flights[i].departureCity);
        printf("Destination City: %s\n", flights[i].destinationCity);
        printf("Date: %s\n", flights[i].date);
        printf("Available Seats: %d\n", flights[i].availableSeats);
        printf("--------------------------\n");
    }
}

void bookSeat(Flight flights[], int count) {
    if (count == 0) {
        printf("No flights available for booking.\n");
        return;
    }

    int flightNumber, i;
    printf("Enter the flight number to book a seat: ");
    scanf("%d", &flightNumber);

    for (i = 0; i < count; i++) {
        if (flights[i].flightNumber == flightNumber) {
            if (flights[i].availableSeats > 0) {
                flights[i].availableSeats--;
                printf("Seat booked successfully! Remaining seats: %d\n", flights[i].availableSeats);
            } else {
                printf("No seats available on this flight.\n");
            }
            return;
        }
    }

    printf("Flight not found.\n");
}
