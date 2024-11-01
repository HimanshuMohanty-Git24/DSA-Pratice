#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <climits>

using namespace std;

struct Process {
    int pid;     // Process ID
    int at;      // Arrival Time
    int bt;      // Burst Time
    int bt_remaining; // Remaining Burst Time (for preemptive)
    int ct;      // Completion Time
    int tat;     // Turnaround Time
    int wt;      // Waiting Time
};

// Function to find the process with the shortest remaining time
int findShortestRemainingTimeProcess(vector<Process>& processes, int currentTime) {
    int shortestIndex = -1;
    int minRemainingTime = INT_MAX;
    for (int i = 0; i < processes.size(); i++) {
        if (processes[i].at <= currentTime && processes[i].bt_remaining > 0) {
            if (processes[i].bt_remaining < minRemainingTime) {
                minRemainingTime = processes[i].bt_remaining;
                shortestIndex = i;
            }
        }
    }
    return shortestIndex;
}

// Function to calculate the process completion details
void calculateSRTF(vector<Process>& processes) {
    int currentTime = 0;
    int completed = 0;
    int n = processes.size();
    
    // Gantt chart storage
    vector<pair<int, int>> ganttChart;  // <pid, time>
    
    while (completed != n) {
        int index = findShortestRemainingTimeProcess(processes, currentTime);

        if (index != -1) {
            // Execute the process for 1 unit of time
            processes[index].bt_remaining--;
            ganttChart.push_back({processes[index].pid, currentTime});

            // If the process is completed
            if (processes[index].bt_remaining == 0) {
                completed++;
                processes[index].ct = currentTime + 1;  // Completion time
                processes[index].tat = processes[index].ct - processes[index].at;  // Turnaround time
                processes[index].wt = processes[index].tat - processes[index].bt;  // Waiting time
            }
        }
        currentTime++;
    }

    // Display Gantt Chart
    cout << "\nGantt Chart:\n";
    for (auto g : ganttChart) {
        cout << "| P" << g.first << " ";
    }
    cout << "|\n";

    // Display time markers
    int previousTime = -1;
    for (auto g : ganttChart) {
        if (g.second != previousTime) {
            cout << g.second << "   ";
            previousTime = g.second;
        }
    }
    cout << currentTime << endl;
}

// Function to display the process table
void displayProcessTable(const vector<Process>& processes) {
    cout << "\nProcess Table:\n";
    cout << "-------------------------------------------------------------\n";
    cout << "| PID | Arrival Time | Burst Time | Completion | TAT  | WT   |\n";
    cout << "-------------------------------------------------------------\n";

    for (const auto& p : processes) {
        cout << "|  " << p.pid << "  |     " << setw(4) << p.at << "      |     " << setw(4) << p.bt
             << "     |     " << setw(4) << p.ct << "     | " << setw(4) << p.tat << " | " << setw(4) << p.wt << " |\n";
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
        {1, 0, 7, 7, 0, 0, 0},  // Process 1: Arrival time 0, Burst time 7
        {2, 2, 4, 4, 0, 0, 0},  // Process 2: Arrival time 2, Burst time 4
        {3, 4, 1, 1, 0, 0, 0},  // Process 3: Arrival time 4, Burst time 1
        {4, 5, 4, 4, 0, 0, 0}   // Process 4: Arrival time 5, Burst time 4
    };

    // Call SRTF Scheduling Algorithm
    calculateSRTF(processes);

    // Display process table
    displayProcessTable(processes);

    // Calculate and display averages
    calculateAndDisplayAverages(processes);

    return 0;
}
