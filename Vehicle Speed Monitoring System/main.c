#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> /* Added for timestamps */

/* Define constants for speed limits */
#define NORMAL_LIMIT 60.0
#define WARNING_LIMIT 80.0

/* Structure to store vehicle data */
typedef struct {
    char vehicleID[20];
    float speed;
    char status[20];
    char timestamp[30]; /* Added to store date/time */
} VehicleRecord;

/* Function Prototypes */
void classifySpeed(float speed, char* status);
void saveRecord(VehicleRecord rec);
void displayLogs();
void searchVehicle(); /* New function for searching */
void getTimestamp(char* buffer, size_t size); /* Helper for time */
void clearInputBuffer();

/**
 * Main function - Entry point of the program
 */
int main() {
    int choice;
    VehicleRecord currentVehicle;

    while (1) {
        /* Menu-driven interface */
        printf("\n=========================================");
        printf("\n   VEHICLE SPEED MONITORING SYSTEM");
        printf("\n=========================================");
        printf("\n1. Enter Vehicle Speed");
        printf("\n2. View Saved Speed Logs");
        printf("\n3. Search Vehicle History"); /* New Option */
        printf("\n4. Exit");
        printf("\nSelect an option: ");

        /* Basic input validation for menu choice */
        if (scanf("%d", &choice) != 1) {
            printf("\n[ERROR] Invalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1:
                printf("\nEnter Vehicle ID (e.g., MH12-AB-1234): ");
                scanf("%s", currentVehicle.vehicleID);

                printf("Enter Speed (km/h): ");
                if (scanf("%f", &currentVehicle.speed) != 1 || currentVehicle.speed < 0) {
                    printf("\n[ERROR] Invalid speed. Please enter a positive value.\n");
                    clearInputBuffer();
                    break;
                }

                /* Classify speed and set status */
                classifySpeed(currentVehicle.speed, currentVehicle.status);

                /* Get current timestamp */
                getTimestamp(currentVehicle.timestamp, sizeof(currentVehicle.timestamp));

                /* Display alert on console */
                printf("\n--- ECU ALERT ---");
                printf("\nTime: %s", currentVehicle.timestamp);
                printf("\nVehicle ID: %s", currentVehicle.vehicleID);
                printf("\nSpeed: %.2f km/h", currentVehicle.speed);
                printf("\nStatus: %s", currentVehicle.status);
                printf("\n-----------------\n");

                /* Save the record to a file */
                saveRecord(currentVehicle);
                break;

            case 2:
                displayLogs();
                break;

            case 3:
                searchVehicle();
                break;

            case 4:
                printf("\nExiting the system. Drive safely!\n");
                exit(0);

            default:
                printf("\n[ERROR] Invalid choice. Select 1-4.\n");
        }
    }

    return 0;
}

/**
 * Function to classify speed based on pre-defined limits
 */
void classifySpeed(float speed, char* status) {
    if (speed < NORMAL_LIMIT) {
        strcpy(status, "NORMAL");
    } else if (speed >= NORMAL_LIMIT && speed <= WARNING_LIMIT) {
        strcpy(status, "WARNING");
    } else {
        strcpy(status, "OVER SPEED");
    }
}

/**
 * Helper function to get the current system time as a string
 */
void getTimestamp(char* buffer, size_t size) {
    time_t now;
    struct tm *timeinfo;

    time(&now);
    timeinfo = localtime(&now);

    strftime(buffer, size, "%Y-%m-%d %H:%M:%S", timeinfo);
}

/**
 * Function to save vehicle record into a text file
 */
void saveRecord(VehicleRecord rec) {
    FILE *fptr;
    fptr = fopen("speed_logs.txt", "a");

    if (fptr == NULL) {
        printf("\n[ERROR] Could not open file for writing.\n");
        return;
    }

    /* Format: Timestamp VehicleID Speed Status */
    fprintf(fptr, "%-20s %-15s %-10.2f %-15s\n", rec.timestamp, rec.vehicleID, rec.speed, rec.status);
    
    fclose(fptr);
    printf("[INFO] Record saved successfully to speed_logs.txt\n");
}

/**
 * Function to display all records from the text file
 */
void displayLogs() {
    FILE *fptr;
    char line[150]; /* Increased buffer size for longer lines */

    fptr = fopen("speed_logs.txt", "r");

    if (fptr == NULL) {
        printf("\n[INFO] No records found yet.\n");
        return;
    }

    printf("\n--- SAVED SPEED LOGS ---");
    printf("\n%-20s %-15s %-10s %-15s", "Timestamp", "Vehicle ID", "Speed", "Status");
    printf("\n----------------------------------------------------------------");

    while (fgets(line, sizeof(line), fptr)) {
        printf("\n%s", line); // line already contains newline from file or ends neatly
        // fgets keeps the newline, but let's be safe with formatting if needed
        // The original logic just printed line.
        // To avoid double newlines if the file has them, print with %s but ensure formatting strictly.
        // Actually, simple printf is fine if the file is clean.
         // Let's trim trailing newline if present for cleaner output if we want, but simple is okay.
         // Actually, let's just print it. Simple is best for student level.
         // Wait, the previous loop printed `\n%s`. Let's stick to that but remove extra newline if fgets has it.
         size_t len = strlen(line);
         if (len > 0 && line[len-1] == '\n') {
             line[len-1] = '\0';
         }
         printf("\n%s", line);
    }
    printf("\n----------------------------------------------------------------\n");

    fclose(fptr);
}

/**
 * Function to search for a specific vehicle by ID
 */
void searchVehicle() {
    FILE *fptr;
    char line[150];
    char searchID[20];
    int found = 0;

    printf("\nEnter Vehicle ID to search: ");
    scanf("%s", searchID);

    fptr = fopen("speed_logs.txt", "r");
    if (fptr == NULL) {
        printf("\n[INFO] No records found to search.\n");
        return;
    }

    printf("\n--- SEARCH RESULTS FOR: %s ---", searchID);
    printf("\n%-20s %-15s %-10s %-15s", "Timestamp", "Vehicle ID", "Speed", "Status");
    printf("\n----------------------------------------------------------------");

    while (fgets(line, sizeof(line), fptr)) {
        if (strstr(line, searchID) != NULL) { /* Simple substring check */
             size_t len = strlen(line);
             if (len > 0 && line[len-1] == '\n') {
                 line[len-1] = '\0';
             }
            printf("\n%s", line);
            found = 1;
        }
    }
    printf("\n----------------------------------------------------------------\n");

    if (!found) {
        printf("[INFO] No records found for Vehicle ID: %s\n", searchID);
    }

    fclose(fptr);
}

/**
 * Utility function to clear the input buffer
 */
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

