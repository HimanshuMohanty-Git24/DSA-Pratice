#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Process {
    int pid;     // Process ID
    int at;      // Arrival Time
    int bt;      // Burst Time
    int ct;      // Completion Time
    int tat;     // Turnaround Time
    int wt;      // Waiting Time
    bool isCompleted;  // Flag to indicate if the process is completed
};

// Function to find the process with the highest response ratio
int findHighestResponseRatioProcess(vector<Process>& processes, int currentTime) {
    int selectedIndex = -1;
    double highestRR = -1;

    for (int i = 0; i < processes.size(); i++) {
        if (!processes[i].isCompleted && processes[i].at <= currentTime) {
            int waitingTime = currentTime - processes[i].at;
            double responseRatio = (double)(waitingTime + processes[i].bt) / processes[i].bt;

            if (responseRatio > highestRR) {
                highestRR = responseRatio;
                selectedIndex = i;
            }
        }
    }

    return selectedIndex;
}

// Function to calculate HRRN Scheduling
void calculateHRRN(vector<Process>& processes) {
    int currentTime = 0;
    int completed = 0;
    int n = processes.size();

    while (completed != n) {
        int index = findHighestResponseRatioProcess(processes, currentTime);

        if (index != -1) {
            // Update process completion details
            currentTime += processes[index].bt;
            processes[index].ct = currentTime;
            processes[index].tat = processes[index].ct - processes[index].at;  // Turnaround time
            processes[index].wt = processes[index].tat - processes[index].bt;  // Waiting time
            processes[index].isCompleted = true;
            completed++;
        } else {
            currentTime++;
        }
    }
}

// Function to display the process table
void displayProcessTable(const vector<Process>& processes) {
    cout << "\nHighest Response Ratio Next (HRRN) Scheduling:\n";
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
        {1, 0, 4, 0, 0, 0, false},  // Process 1: Arrival time 0, Burst time 4
        {2, 1, 3, 0, 0, 0, false},  // Process 2: Arrival time 1, Burst time 3
        {3, 2, 2, 0, 0, 0, false},  // Process 3: Arrival time 2, Burst time 2
        {4, 3, 1, 0, 0, 0, false}   // Process 4: Arrival time 3, Burst time 1
    };

    // Call HRRN Scheduling Algorithm
    calculateHRRN(processes);

    // Display process table
    displayProcessTable(processes);

    // Calculate and display averages
    calculateAndDisplayAverages(processes);

    return 0;
}
