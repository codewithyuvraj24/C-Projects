# Vehicle Speed Monitoring System

A beginner-friendly C project designed to simulate an automotive ECU (Electronic Control Unit) logic for monitoring and recording vehicle speeds. This project is ideal for students aiming for roles in Embedded Systems or the Automotive industry.

## 1. Project Logic
The system works by mimicking a simplified ECU monitor. It takes real-time inputs (Vehicle ID and Speed) and processes them based on predefined safety thresholds:
- **Normal Zone (< 60 km/h):** Indicates safe driving conditions.
- **Warning Zone (60 - 80 km/h):** Prompts the driver to be cautious.
- **Over Speed Zone (> 80 km/h):** Triggers a critical alert for high-speed violations.

The data is stored using **C Structures**, and persistence is achieved through **File Handling**. The system also includes:
- **Real-Time Timestamps:** Captures the exact date and time of the event using `<time.h>`.
- **Search Functionality:** Allows users to retrieve history for a specific vehicle ID.

## 2. Flow of Execution
1.  **Initialization:** The program displays a menu using a `while(1)` loop.
2.  **Input:** The user enters the vehicle identification and current speed.
3.  **Validation:** Basic checks ensure that the speed is a positive numerical value.
4.  **Classification:** The `classifySpeed()` function applies the ECU logic to determine the status.
5.  **Timestamping:** The system captures the current system time.
6.  **Output/Alert:** The console displays a formatted alert with the timestamp, ID, speed, and status.
7.  **Persistence:** The `saveRecord()` function saves this detailed log to `speed_logs.txt`.
8.  **Search/View:** Users can view all logs or search for a specific vehicle using the menu options.

## 3. Sample Output
```text
=========================================
   VEHICLE SPEED MONITORING SYSTEM
=========================================
1. Enter Vehicle Speed
2. View Saved Speed Logs
3. Search Vehicle History
4. Exit
Select an option: 1

Enter Vehicle ID (e.g., MH12-AB-1234): KA-01-MJ-5566
Enter Speed (km/h): 85

--- ECU ALERT ---
Time: 2026-02-02 13:35:47
Vehicle ID: KA-01-MJ-5566
Speed: 85.00 km/h
Status: OVER SPEED
-----------------
[INFO] Record saved successfully to speed_logs.txt
```


