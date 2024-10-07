#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

struct Process
{
    int pid;  // Process ID
    int at;   // Arrival Time
    int bt;   // Burst Time
    int ct;   // Completion Time
    int st;   // Start Time
    float tat; // Turnaround Time
    float rt;  // Response Time
    float wt;  // Waiting Time
} ps[100]; // Array to store the processes

int executionOrder[100]; // Array to store the execution order
int orderIndex = 0;      // Index to track execution order

// Utility functions to find max and min
int findMax(int a, int b) {
    return a > b ? a : b;
}

int findMin(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n;
    bool isCompleted[100] = {false};  // Array to keep track of completed processes
    bool isFirstProcess = true;       // To handle the first process differently

    int currT = 0;       // Current time
    int completed = 0;   // Count of completed processes

    printf("Enter total number of processes: ");
    scanf("%d", &n);     // Input the number of processes

    int stat = 0, swt = 0, srt = 0, totalTime = 0, prev = 0, lengthCycle;
    float cpu;
    int maxCt = 0, minAt = INT_MAX;

    // Input arrival time
    for (int i = 0; i < n; i++) {
        printf("\nEnter Process %d Arrival Time: ", i + 1);
        scanf("%d", &ps[i].at);
        ps[i].pid = i + 1;  // Assigning Process ID
    }

    // Input burst time
    for (int i = 0; i < n; i++) {
        printf("\nEnter Process %d Burst Time: ", i + 1);
        scanf("%d", &ps[i].bt);
    }

    while (completed != n) {
        // Find process with the minimum burst time that is ready
        int minIndex = -1;
        int minimum = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (ps[i].at <= currT && !isCompleted[i]) {  // Check if process is ready and not completed
                if (ps[i].bt < minimum) {
                    minimum = ps[i].bt;
                    minIndex = i;
                }

                if (ps[i].bt == minimum) {  // If burst times are the same, prefer earlier arrival time
                    if (ps[i].at < ps[minIndex].at) {
                        minimum = ps[i].bt;
                        minIndex = i;
                    }
                }
            }
        }

        // No process is ready at current time
        if (minIndex == -1) {
            currT++;
        } else {
            // Process the selected task
            ps[minIndex].st = currT;                     // Start time is the current time
            ps[minIndex].ct = ps[minIndex].st + ps[minIndex].bt;  // Completion time is start time + burst time
            ps[minIndex].tat = ps[minIndex].ct - ps[minIndex].at; // Turnaround time is completion time - arrival time
            ps[minIndex].wt = ps[minIndex].tat - ps[minIndex].bt; // Waiting time is TAT - burst time
            ps[minIndex].rt = ps[minIndex].st - ps[minIndex].at;  // Response time is start time - arrival time

            stat += ps[minIndex].tat;  // Sum of turnaround times
            swt += ps[minIndex].wt;    // Sum of waiting times
            srt += ps[minIndex].rt;    // Sum of response times

            totalTime += isFirstProcess ? 0 : (ps[minIndex].st - prev);  // Handle idle time between processes
            completed++;               // Increment the count of completed processes

            isCompleted[minIndex] = true;  // Mark the process as completed
            currT = ps[minIndex].ct;       // Update current time to the completion time of the current process
            prev = currT;                  // Set previous time for next iteration
            isFirstProcess = false;        // No longer the first process

            // Store the process in execution order
            executionOrder[orderIndex++] = ps[minIndex].pid;
        }
    }

    // Calculate CPU Utilization
    maxCt = currT;
    for (int i = 0; i < n; i++) {
        if (ps[i].at < minAt) {
            minAt = ps[i].at;  // Find the minimum arrival time
        }
    }
    lengthCycle = maxCt - minAt;
    cpu = (float)(lengthCycle - totalTime) / lengthCycle * 100;  // CPU utilization

    // Print the Gantt Chart based on the execution order
    printf("\nGantt Chart: ");
    for (int i = 0; i < orderIndex; i++) {
        printf("P%d ", executionOrder[i]);
    }

    // Display the process table
    printf("\nProcess No.\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t%d\t%d\t%.2f\t%.2f\t%.2f\n", ps[i].pid, ps[i].at, ps[i].bt, ps[i].ct, ps[i].tat, ps[i].wt, ps[i].rt);
    }

    // Display average times and CPU utilization
    printf("\nAverage Turnaround Time: %.2f", (float)stat / n);
    printf("\nAverage Waiting Time: %.2f", (float)swt / n);
    printf("\nAverage Response Time: %.2f", (float)srt / n);
    printf("\nCPU Utilization: %.2f%%\n", cpu);

    return 0;
}
