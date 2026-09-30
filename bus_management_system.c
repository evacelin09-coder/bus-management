#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUSES 100

struct Bus {
    int busNo;
    char driverName[50];
    char source[50];
    char destination[50];
    int totalSeats;
    int availableSeats;
};

struct Bus buses[MAX_BUSES];
int busCount = 0;

void addBus() {
    if (busCount >= MAX_BUSES) {
        printf("\nBus limit reached!\n");
        return;
    }

    printf("\nEnter Bus Number: ");
    scanf("%d", &buses[busCount].busNo);

    printf("Enter Driver Name: ");
    scanf(" %[^\n]", buses[busCount].driverName);

    printf("Enter Source: ");
    scanf(" %[^\n]", buses[busCount].source);

    printf("Enter Destination: ");
    scanf(" %[^\n]", buses[busCount].destination);

    printf("Enter Total Seats: ");
    scanf("%d", &buses[busCount].totalSeats);

    buses[busCount].availableSeats = buses[busCount].totalSeats;
    busCount++;

    printf("\nBus added successfully!\n");
}

void displayBuses() {
    if (busCount == 0) {
        printf("\nNo buses available.\n");
        return;
    }

    printf("\n================ BUS DETAILS ================\n");

    for (int i = 0; i < busCount; i++) {
        printf("\nBus Number       : %d", buses[i].busNo);
        printf("\nDriver Name      : %s", buses[i].driverName);
        printf("\nSource           : %s", buses[i].source);
        printf("\nDestination      : %s", buses[i].destination);
        printf("\nTotal Seats      : %d", buses[i].totalSeats);
        printf("\nAvailable Seats  : %d\n", buses[i].availableSeats);
    }
}

void searchBus() {
    int busNo;
    int found = 0;

    printf("\nEnter Bus Number to Search: ");
    scanf("%d", &busNo);

    for (int i = 0; i < busCount; i++) {
        if (buses[i].busNo == busNo) {
            printf("\nBus Found!\n");
            printf("Bus Number      : %d\n", buses[i].busNo);
            printf("Driver Name     : %s\n", buses[i].driverName);
            printf("Source          : %s\n", buses[i].source);
            printf("Destination     : %s\n", buses[i].destination);
            printf("Total Seats     : %d\n", buses[i].totalSeats);
            printf("Available Seats : %d\n", buses[i].availableSeats);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nBus not found!\n");
}

void bookSeat() {
    int busNo, seats;

    printf("\nEnter Bus Number: ");
    scanf("%d", &busNo);

    for (int i = 0; i < busCount; i++) {
        if (buses[i].busNo == busNo) {
            printf("Enter number of seats to book: ");
            scanf("%d", &seats);

            if (seats <= 0)
                printf("\nInvalid number of seats!\n");
            else if (seats <= buses[i].availableSeats) {
                buses[i].availableSeats -= seats;
                printf("\n%d seat(s) booked successfully!\n", seats);
                printf("Remaining Seats: %d\n", buses[i].availableSeats);
            } else {
                printf("\nNot enough seats available!\n");
            }
            return;
        }
    }

    printf("\nBus not found!\n");
}

void cancelBooking() {
    int busNo, seats;

    printf("\nEnter Bus Number: ");
    scanf("%d", &busNo);

    for (int i = 0; i < busCount; i++) {
        if (buses[i].busNo == busNo) {
            printf("Enter number of seats to cancel: ");
            scanf("%d", &seats);

            if (seats <= 0)
                printf("\nInvalid number of seats!\n");
            else if (buses[i].availableSeats + seats <= buses[i].totalSeats) {
                buses[i].availableSeats += seats;
                printf("\nBooking cancelled successfully!\n");
                printf("Available Seats: %d\n", buses[i].availableSeats);
            } else {
                printf("\nInvalid cancellation!\n");
            }
            return;
        }
    }

    printf("\nBus not found!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n\n====================================");
        printf("\n       BUS MANAGEMENT SYSTEM");
        printf("\n====================================");
        printf("\n1. Add Bus");
        printf("\n2. Display All Buses");
        printf("\n3. Search Bus");
        printf("\n4. Book Seat");
        printf("\n5. Cancel Booking");
        printf("\n6. Exit");
        printf("\n====================================");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBus();
                break;
            case 2:
                displayBuses();
                break;
            case 3:
                searchBus();
                break;
            case 4:
                bookSeat();
                break;
            case 5:
                cancelBooking();
                break;
            case 6:
                printf("\nThank you for using Bus Management System!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}
