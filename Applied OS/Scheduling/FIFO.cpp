#include<bits/stdc++.h>
using namespace std;

//Function to find the waiting time for all processes formula of wt = tat - bt
void findWaitingTime(int processes[], int n, int bt[], int wt[], int at[])
{
    int service_time[n];
    service_time[0] = 0;
    wt[0] = 0;
    for (int i = 1; i < n ; i++)
    {
        service_time[i] = service_time[i-1] + bt[i-1];
        wt[i] = service_time[i] - at[i];
        if (wt[i] < 0)
            wt[i] = 0;
    }
}

//Function to calculate turn around time formula tat = bt + wt
void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}

//Function to calculate average time formula avg = total/n
void findavgTime(int processes[], int n, int bt[], int at[])
{
    int wt[n], tat[n];
    findWaitingTime(processes, n, bt, wt, at);
    findTurnAroundTime(processes, n, bt, wt, tat);
    cout << "Processes " << " Burst Time " << " Arrival Time "
         << " Waiting Time " << " Turn-Around Time "
         << " Completion Time \n";
    int total_wt = 0, total_tat = 0;
    for (int i = 0; i < n ; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        int compl_time = tat[i] + at[i];
        cout << " " << i+1 << "\t\t" << bt[i] << "\t\t"
             << at[i] << "\t\t" << wt[i] << "\t\t "
             << tat[i] << "\t\t " << compl_time << endl;
    }
    cout << "Average waiting time = "
         << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n;
}

//Driver code
int main()
{
    int processes[] = { 1, 2, 3};
    int n = sizeof processes / sizeof processes[0];
    int burst_time[] = {10, 5, 8};
    int arrival_time[] = {0, 2, 4};
    findavgTime(processes, n, burst_time, arrival_time);
    return 0;
}
/*
Code Explanantion:
1. We are given with the arrival time and burst time of the processes.
2. We have to find the waiting time, turn around time and average time.
3. We are calculating the waiting time using the formula wt = tat - bt.
4. We are calculating the turn around time using the formula tat = bt + wt.
5. We are calculating the average time using the formula avg = total/n.
6. We are printing the processes, burst time, arrival time, waiting time, turn around time and completion time.
7. We are calculating the total waiting time and total turn around time.
8. We are printing the average waiting time and average turn around time.
Expalantion of terms:
Arrival time : The time at which the process arrives in the ready queue.
Burst time : The time required by a process for execution.
Waiting time : The time for which the process waits in the ready queue.
Turn around time : The total time taken by the process to complete its execution.
Completion time : The time at which the process completes its execution.
Average waiting time : The average time for which the process waits in the ready queue.
Average turn around time : The average time taken by the process to complete its execution.
Time complexity : O(n)
Space complexity : O(n)
*/