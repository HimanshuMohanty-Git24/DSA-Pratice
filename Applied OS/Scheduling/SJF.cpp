#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include<bits/stdc++.h>

using namespace std;

// Process structure
struct Process {
    int pid;  // Process ID
    int at;   // Arrival Time
    int bt;   // Burst Time
    int ct;   // Completion Time
    int tat;  // Turnaround Time
    int wt;   // Waiting Time
};

// Function to sort processes by arrival time and burst time
bool compareByArrival(Process p1, Process p2) {
    if (p1.at == p2.at)
        return p1.bt < p2.bt;
    return p1.at < p2.at;
}

// Function to calculate completion, turnaround, and waiting times
void calculateTimes(vector<Process> &processes) {
    int currentTime = 0;

    for (int i = 0; i < processes.size(); i++) {
        // Find process with the shortest burst time that has arrived
        int shortestIndex = -1;
        int minBT = INT_MAX;
        
        for (int j = 0; j < processes.size(); j++) {
            if (processes[j].at <= currentTime && processes[j].ct == 0 && processes[j].bt < minBT) {
                minBT = processes[j].bt;
                shortestIndex = j;
            }
        }
        
        if (shortestIndex != -1) {
            currentTime += processes[shortestIndex].bt;
            processes[shortestIndex].ct = currentTime;
            processes[shortestIndex].tat = processes[shortestIndex].ct - processes[shortestIndex].at;
            processes[shortestIndex].wt = processes[shortestIndex].tat - processes[shortestIndex].bt;
        } else {
            // If no process is found, increase the current time
            currentTime++;
        }
    }
}

// Function to display Gantt chart
void displayGanttChart(const vector<Process> &processes) {
    cout << "\nGantt Chart:\n";
    cout << "--------------------------------------------------\n";
    int currentTime = 0;
    for (const auto &p : processes) {
        if (p.ct != 0) {
            cout << "| P" << p.pid << " ";
        }
    }
    cout << "|\n--------------------------------------------------\n";

    currentTime = 0;
    for (const auto &p : processes) {
        if (p.ct != 0) {
            cout << setw(2) << currentTime << setw(6);
            currentTime = p.ct;
        }
    }
    cout << setw(2) << currentTime << "\n";
}

// Function to display process table
void displayProcessTable(const vector<Process> &processes) {
    cout << "\nProcess Table:\n";
    cout << "-------------------------------------------------------------\n";
    cout << "| PID | Arrival Time | Burst Time | Completion | TAT  | WT   |\n";
    cout << "-------------------------------------------------------------\n";

    for (const auto &p : processes) {
        cout << "|  " << p.pid << "  |     " << setw(4) << p.at << "      |     " << setw(4) << p.bt
             << "     |     " << setw(4) << p.ct << "     | " << setw(4) << p.tat << " | " << setw(4) << p.wt << " |\n";
    }
    cout << "-------------------------------------------------------------\n";
}

// Function to calculate and display averages
void calculateAndDisplayAverages(const vector<Process> &processes) {
    float totalTAT = 0, totalWT = 0;
    for (const auto &p : processes) {
        totalTAT += p.tat;
        totalWT += p.wt;
    }

    cout << "\nAverage Turnaround Time (ATAT): " << totalTAT / processes.size() << "\n";
    cout << "Average Waiting Time (AWT): " << totalWT / processes.size() << "\n";
}

int main() {
    // Hardcoded input values
    vector<Process> processes = {
        {1, 0, 6, 0, 0, 0},  // Process 1: Arrival time 0, Burst time 6
        {2, 1, 8, 0, 0, 0},  // Process 2: Arrival time 1, Burst time 8
        {3, 2, 7, 0, 0, 0},  // Process 3: Arrival time 2, Burst time 7
        {4, 3, 3, 0, 0, 0}   // Process 4: Arrival time 3, Burst time 3
    };

    // Sort processes by arrival time and burst time
    sort(processes.begin(), processes.end(), compareByArrival);

    // Calculate times for each process
    calculateTimes(processes);

    // Display the Gantt chart
    displayGanttChart(processes);

    // Display process table
    displayProcessTable(processes);

    // Calculate and display averages
    calculateAndDisplayAverages(processes);

    return 0;
}
