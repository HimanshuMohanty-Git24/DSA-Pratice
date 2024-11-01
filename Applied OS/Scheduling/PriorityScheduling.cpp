#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include<bits/stdc++.h>


using namespace std;

struct Process {
    int pid;     // Process ID
    int at;      // Arrival Time
    int bt;      // Burst Time
    int priority; // Priority
    int ct;      // Completion Time
    int tat;     // Turnaround Time
    int wt;      // Waiting Time
};

// Function to calculate Priority Scheduling
void calculatePriorityScheduling(vector<Process>& processes) {
    int currentTime = 0;
    int completed = 0;
    int n = processes.size();

    while (completed < n) {
        // Select the process with the highest priority (lowest numerical value)
        int index = -1;
        int highestPriority = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (processes[i].at <= currentTime && processes[i].ct == 0) {
                if (processes[i].priority < highestPriority) {
                    highestPriority = processes[i].priority;
                    index = i;
                }
            }
        }

        if (index != -1) {
            // Update process completion details
            currentTime += processes[index].bt;
            processes[index].ct = currentTime;
            processes[index].tat = processes[index].ct - processes[index].at;  // Turnaround time
            processes[index].wt = processes[index].tat - processes[index].bt;  // Waiting time
            completed++;
        } else {
            currentTime++;
        }
    }
}

// Function to display the process table
void displayProcessTable(const vector<Process>& processes) {
    cout << "\nPriority Scheduling:\n";
    cout << "-------------------------------------------------------------\n";
    cout << "| PID | Arrival Time | Burst Time | Priority | Completion | TAT  | WT   |\n";
    cout << "-------------------------------------------------------------\n";

    for (const auto& p : processes) {
        cout << "|  " << p.pid << "  |     " << setw(4) << p.at << "      |     " << setw(4) << p.bt
             << "     |   " << setw(7) << p.priority << "   |     " << setw(4) << p.ct 
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
        {1, 0, 5, 2, 0, 0, 0},  // Process 1: Arrival time 0, Burst time 5, Priority 2
        {2, 1, 3, 1, 0, 0, 0},  // Process 2: Arrival time 1, Burst time 3, Priority 1
        {3, 2, 8, 3, 0, 0, 0},  // Process 3: Arrival time 2, Burst time 8, Priority 3
        {4, 3, 6, 4, 0, 0, 0}   // Process 4: Arrival time 3, Burst time 6, Priority 4
    };

    // Call Priority Scheduling Algorithm
    calculatePriorityScheduling(processes);

    // Display process table
    displayProcessTable(processes);

    // Calculate and display averages
    calculateAndDisplayAverages(processes);

    return 0;
}
