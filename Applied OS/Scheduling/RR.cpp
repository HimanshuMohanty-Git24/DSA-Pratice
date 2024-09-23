#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

// Process structure
struct Process {
    int pid;  // Process ID
    int at;   // Arrival Time
    int bt;   // Burst Time
    int bt_remaining;  // Remaining Burst Time
    int ct;   // Completion Time
    int tat;  // Turnaround Time
    int wt;   // Waiting Time
};

// Function to display process table
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

// Round Robin Scheduling Algorithm
void roundRobin(vector<Process>& processes, int quantum) {
    int currentTime = 0;
    queue<int> readyQueue; // Queue to store process indices

    // Push processes that have arrived at time 0
    for (int i = 0; i < processes.size(); i++) {
        if (processes[i].at == 0) {
            readyQueue.push(i);
        }
    }

    while (!readyQueue.empty()) {
        int index = readyQueue.front();
        readyQueue.pop();

        // Check how much burst time to execute
        if (processes[index].bt_remaining > quantum) {
            currentTime += quantum;
            processes[index].bt_remaining -= quantum;
        } else {
            currentTime += processes[index].bt_remaining;
            processes[index].bt_remaining = 0;
            processes[index].ct = currentTime;  // Completion time
            processes[index].tat = processes[index].ct - processes[index].at;  // Turnaround time
            processes[index].wt = processes[index].tat - processes[index].bt;  // Waiting time
        }

        // Push processes that have arrived during this time to the ready queue
        for (int i = 0; i < processes.size(); i++) {
            if (processes[i].at <= currentTime && processes[i].bt_remaining > 0 && i != index) {
                readyQueue.push(i);
            }
        }

        // If the current process hasn't finished, push it back to the queue
        if (processes[index].bt_remaining > 0) {
            readyQueue.push(index);
        }
    }
}

int main() {
    // Hardcoded input values
    vector<Process> processes = {
        {1, 0, 5, 5, 0, 0, 0},  // Process 1: Arrival time 0, Burst time 5
        {2, 1, 3, 3, 0, 0, 0},  // Process 2: Arrival time 1, Burst time 3
        {3, 2, 1, 1, 0, 0, 0},  // Process 3: Arrival time 2, Burst time 1
        {4, 3, 2, 2, 0, 0, 0}   // Process 4: Arrival time 3, Burst time 2
    };

    int quantum = 2;  // Time Quantum for Round Robin

    // Call Round Robin Scheduling Algorithm
    roundRobin(processes, quantum);

    // Display process table
    displayProcessTable(processes);

    // Calculate and display averages
    calculateAndDisplayAverages(processes);

    return 0;
}
