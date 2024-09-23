#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <queue>
#include<bits/stdc++.h>

using namespace std;

struct Process {
    int pid;       // Process ID
    int at;        // Arrival Time
    int bt;        // Burst Time
    int io;        // I/O Time
    int ct;        // Completion Time
    int tat;       // Turnaround Time
    int wt;        // Waiting Time
    int remainingTime; // Remaining time for the process
};

// Function to calculate I/O based scheduling (SJF)
void calculateIOScheduling(vector<Process>& processes) {
    int currentTime = 0;
    int completed = 0;
    int n = processes.size();

    // Initialize remaining times
    for (auto& p : processes) {
        p.remainingTime = p.bt;
    }

    while (completed < n) {
        // Select the process with the shortest remaining time that has arrived
        int index = -1;
        int minRemainingTime = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (processes[i].at <= currentTime && processes[i].remainingTime > 0) {
                if (processes[i].remainingTime < minRemainingTime) {
                    minRemainingTime = processes[i].remainingTime;
                    index = i;
                }
            }
        }

        if (index != -1) {
            // Simulate the process running for one time unit
            processes[index].remainingTime--;
            currentTime++;

            // If the process finishes its CPU burst
            if (processes[index].remainingTime == 0) {
                currentTime += processes[index].io; // Add I/O time after CPU burst
                processes[index].ct = currentTime;
                processes[index].tat = processes[index].ct - processes[index].at;  // Turnaround time
                processes[index].wt = processes[index].tat - processes[index].bt;  // Waiting time
                completed++;
            }
        } else {
            // If no process is ready, move time forward
            currentTime++;
        }
    }
}

// Function to display the process table
void displayProcessTable(const vector<Process>& processes) {
    cout << "\nI/O Based Scheduling (SJF):\n";
    cout << "-------------------------------------------------------------\n";
    cout << "| PID | Arrival Time | Burst Time | I/O Time | Completion | TAT  | WT   |\n";
    cout << "-------------------------------------------------------------\n";

    for (const auto& p : processes) {
        cout << "|  " << p.pid << "  |     " << setw(4) << p.at << "      |     " << setw(4) << p.bt
             << "     |   " << setw(7) << p.io << "   |     " << setw(4) << p.ct 
             << "     | " << setw(4) << p.tat << " | " << setw(4) << p.wt << " |\n";
    }
    cout << "-------------------------------------------------------------\n";
}

// Function to calculate and display averages
void calculateAndDisplayAverages(const vector<Process>& processes) {
    float totalTAT = 0, totalWT = 0;
    for (const auto& p : processes) {
        totalTAT += p.tat;
        totalWT += p.wt;
    }

    cout << "\nAverage Turnaround Time (ATAT): " << totalTAT / processes.size() << "\n";
    cout << "Average Waiting Time (AWT): " << totalWT / processes.size() << "\n";
}

int main() {
    // Hardcoded input values
    vector<Process> processes = {
        {1, 0, 5, 2, 0, 0, 0},  // Process 1: Arrival time 0, Burst time 5, I/O time 2
        {2, 1, 3, 1, 0, 0, 0},  // Process 2: Arrival time 1, Burst time 3, I/O time 1
        {3, 2, 8, 3, 0, 0, 0},  // Process 3: Arrival time 2, Burst time 8, I/O time 3
        {4, 3, 6, 4, 0, 0, 0}   // Process 4: Arrival time 3, Burst time 6, I/O time 4
    };

    // Call I/O Based Scheduling Algorithm
    calculateIOScheduling(processes);

    // Display process table
    displayProcessTable(processes);

    // Calculate and display averages
    calculateAndDisplayAverages(processes);

    return 0;
}
