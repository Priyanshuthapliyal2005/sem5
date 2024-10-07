#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

struct Process {
    int pid;    // Process ID
    int at;     // Arrival Time
    int bt;     // Burst Time
    int st;     // Start Time
    int ct;     // Completion Time
    int rt;     // Response Time
    int wt;     // Waiting Time
    int tat;    // Turnaround Time
} ps[100];     // Array to store processes

int executionOrder[1000]; // Array to track execution order (up to 1000 time units)
int executionIndex = 0;   // Index to track the current execution in the Gantt chart

int findMax(int a, int b) {
    return a > b ? a : b;
}

int findMin(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n;
    float btRem[100]; // Remaining Burst Time
    bool isCompleted[100] = {false}; // Track whether a process is completed
    int currTime = 0;  // Current time
    int completed = 0; // Number of processes completed
    int prev = 0;      // Previous process time (for tracking idle time)
    bool isFirstProcess = true;

    printf("Enter the total number of processes: ");
    scanf("%d", &n);

    printf("\nEnter the arrival time of %d processes: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ps[i].at);
        ps[i].pid = i + 1; // Assign Process ID (starting from 1)
    }

    printf("\nEnter the burst time of %d processes: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ps[i].bt);
        btRem[i] = ps[i].bt; // Initialize remaining burst time
    }

    // Main scheduling loop
    while (completed != n) {
        int minIndex = -1;
        int minimum = INT_MAX;

        // Find the process with the minimum remaining burst time
        for (int i = 0; i < n; i++) {
            if (ps[i].at <= currTime && isCompleted[i] == false) {
                if (btRem[i] < minimum) {
                    minIndex = i;
                    minimum = btRem[i];
                }
                // If burst times are equal, choose the one with the earlier arrival time
                if (btRem[i] == minimum) {
                    if (ps[i].at < ps[minIndex].at) {
                        minIndex = i;
                    }
                }
            }
        }

        // If no process is ready, increment the current time
        if (minIndex == -1) {
            currTime++;
        } else {
            // First time scheduling this process
            if (btRem[minIndex] == ps[minIndex].bt) {
                ps[minIndex].st = currTime; // Start time of the process
                ps[minIndex].rt = ps[minIndex].st - ps[minIndex].at; // Response time
            }

            btRem[minIndex] -= 1; // Decrease remaining burst time by 1
            currTime++;           // Increment current time

            // Record the execution for Gantt chart
            executionOrder[executionIndex++] = ps[minIndex].pid;

            // Process has finished execution
            if (btRem[minIndex] == 0) {
                ps[minIndex].ct = currTime; // Completion time
                ps[minIndex].tat = ps[minIndex].ct - ps[minIndex].at; // Turnaround time
                ps[minIndex].wt = ps[minIndex].tat - ps[minIndex].bt; // Waiting time
                isCompleted[minIndex] = true; // Mark process as completed
                completed++; // Increment the number of completed processes
            }
        }
    }

    // Calculate and print the results
    float sumTat = 0, sumWt = 0;
    printf("\nProcess\tAT\tBT\tST\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", ps[i].pid, ps[i].at, ps[i].bt, ps[i].st, ps[i].ct, ps[i].tat, ps[i].wt, ps[i].rt);
        sumTat += ps[i].tat;
        sumWt += ps[i].wt;
    }

    // Print average times
    printf("\nAverage Turnaround Time: %.2f", sumTat / n);
    printf("\nAverage Waiting Time: %.2f", sumWt / n);

    // Print Gantt Chart
    printf("\nGantt Chart: ");
    for (int i = 0; i < executionIndex; i++) {
        printf("P%d ", executionOrder[i]);
    }
    printf("\n");

    return 0;
}
