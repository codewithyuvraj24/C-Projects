/*
 * Traffic Light Control System
 * Author: [Your Name]
 * Description: A console-based simulation of a traffic light system using a Finite State Machine (FSM).
 *              Simulates RED -> GREEN -> YELLOW -> RED transitions with time delays.
 */

#include <stdio.h>
#include <windows.h> // For Sleep() function

// ==========================================
// 1. Constants & Enumerations
// ==========================================

// Durations for each light state in milliseconds
#define RED_DURATION    3000  // 3 Seconds
#define GREEN_DURATION  3000  // 3 Seconds
#define YELLOW_DURATION 1000  // 1 Second

// Enum to represent the Traffic Light States
typedef enum {
    RED,
    GREEN,
    YELLOW
} TrafficLightState;

// ==========================================
// 2. Function Prototypes
// ==========================================

void displaySignal(TrafficLightState state);
void delay_ms(int milliseconds);

// ==========================================
// 3. Main Control Loop
// ==========================================

int main() {
    // Start with RED state
    TrafficLightState currentState = RED;

    printf("Starting Traffic Light Control System...\n");
    delay_ms(1000); // Brief pause before starting

    // Infinite loop to simulate continuous operation
    while (1) {
        // 1. Display the current state
        displaySignal(currentState);

        // 2. Handle State Transitions and Timing
        switch (currentState) {
            case RED:
                // Red indicates STOP. Wait for RED_DURATION.
                delay_ms(RED_DURATION);
                // Next state: GREEN (as per requirements)
                currentState = GREEN;
                break;

            case GREEN:
                // Green indicates GO. Wait for GREEN_DURATION.
                delay_ms(GREEN_DURATION);
                // Next state: YELLOW
                currentState = YELLOW;
                break;

            case YELLOW:
                // Yellow indicates CAUTION/PREPARE TO STOP. Wait for YELLOW_DURATION.
                delay_ms(YELLOW_DURATION);
                // Next state: RED
                currentState = RED;
                break;
            
            default:
                // Should not happen, but good practice to handle unknown states
                currentState = RED;
                break;
        }
    }

    return 0;
}

// ==========================================
// 4. Helper Functions
// ==========================================

/**
 * displays the current traffic light signal on the console.
 * Uses ASCII art for a visual representation.
 */
void displaySignal(TrafficLightState state) {
    // Clear the console screen for a fresh update
    system("cls");

    printf("\n=== TRAFFIC LIGHT CONTROL ===\n\n");

    if (state == RED) {
        printf("      [ RED ]    <-- STOP\n");
        printf("      (     )   \n");
        printf("      (     )   \n");
        printf("\nState: STOP (Traffic Halted)\n");
    } 
    else if (state == YELLOW) {
        printf("      (     )   \n");
        printf("      [YELLOW]   <-- READY\n");
        printf("      (     )   \n");
        printf("\nState: CAUTION (Prepare to Stop)\n");
    } 
    else if (state == GREEN) {
        printf("      (     )   \n");
        printf("      (     )   \n");
        printf("      [GREEN ]   <-- GO\n");
        printf("\nState: GO (Traffic Moving)\n");
    }
    
    printf("\n=============================\n");
    printf("Press Ctrl+C to Exit\n");
}

/**
 * Wrapper function for delay to keep logic modular.
 * Uses Windows Sleep() (milliseconds).
 */
void delay_ms(int milliseconds) {
    Sleep(milliseconds);
}
