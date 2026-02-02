# Traffic Light Control System

A console-based simulation of a Traffic Light Control System written in C. This project demonstrates the implementation of a Finite State Machine (FSM) to manage signal transitions and time-based logic, a fundamental concept in Embedded Systems and Automotive software development.

## Project Overview

- **Language**: C
- **Key Concepts**: Finite State Machines (FSM), deterministic timing, console I/O, tabular state logic.
- **Platform**: Windows (Console Application)

---

## 🚀 Resume-Ready Description

**Project: Traffic Light Control System Simulation (C)**
> Designed and implemented a deterministic Finite State Machine (FSM) in C to simulate a Traffic Light Control System. Utilized timing primitives and console I/O to model real-world signal transitions (Red → Green → Yellow) with precise delay handling. This project demonstrates proficiency in structured C programming, state-based control flow, and modular software design logic used in embedded automotive applications.

---

## 🧠 Interview Explanation (Embedded Systems Focus)

When discussing this project in an interview, focus on these engineering concepts:

### 1. Finite State Machine (FSM)
**Concept**: The system is not just a bunch of `if-else` statements; it implements a **State Machine**.
**Explanation**: "I used an `enum` to define distinct states (RED, GREEN, YELLOW). A central loop handles the logic: 'In State X, perform Action Y, wait Z seconds, then transition to State W'. This ensures the system is always in a known, valid state."

### 2. Deterministic Execution
**Concept**: Predictability in control systems.
**Explanation**: "The system uses a sequential flow where timing is fixed (e.g., 3 seconds for RED). In a real embedded system, we would replace the blocking `Sleep()` function with a non-blocking hardware timer (like a SysTick timer) to allow the CPU to perform other tasks while waiting."

### 3. Modularity
**Concept**: Clean, maintainable code.
**Explanation**: "I separated the 'Business Logic' (state switching) from the 'Driver' (display output). This means if I wanted to switch from printing to the console to actually turning on LEDs on a microcontroller, I would only need to rewrite the `displaySignal` function, not the entire logic."

---

## 🛠️ How to Compile and Run

### Prerequisites
You need a C compiler installed on your system. Common options for Windows:
- **MinGW (GCC)**
- **Visual Studio (MSVC)**
- **Tiny C Compiler (TCC)**

### Steps
1. Open your terminal or command prompt.
2. Navigate to the project directory:
   ```cmd
   cd "d:\C Projects\Traffic Light Control System"
   ```
3. Compile the code (assuming GCC):
   ```cmd
   gcc main.c -o traffic_light.exe
   ```
4. Run the application:
   ```cmd
   .\traffic_light.exe
   ```
5. To stop the simulation, press `Ctrl + C`.
