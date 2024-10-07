#include <stdio.h>
#include <limits.h>

struct Process {
    int pid, at, bt, ct, st, rt, wt, tat, py;
    int remBt;
};

typedef struct Process process;

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    process p[n];

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter the arrival time, burst time, and priority of process %d: ", i + 1);
        scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].py);
        p[i].remBt = p[i].bt; // Initialize remaining burst time
    }

    int currTime = 0;
    int completed = 0;
    int isCompleted[n];

    // Initialize all processes as incomplete
    for (int i = 0; i < n; i++) {
        isCompleted[i] = 0;
    }

    while (completed != n) {
        int hpi = -1;
        int maxPriority = INT_MIN;

        // Find the highest priority process that is ready to execute
        for (int i = 0; i < n; i++) {
            if (p[i].at <= currTime && isCompleted[i] == 0) {
                if (p[i].py > maxPriority) {
                    maxPriority = p[i].py;
                    hpi = i;
                }
                else if (p[i].py == maxPriority) {
                    if (p[i].at < p[hpi].at) {
                        hpi = i;
                    }
                }
            }
        }

        // If a valid process is found, execute it
        if (hpi != -1) {
            if (p[hpi].remBt == p[hpi].bt) {
                p[hpi].st = currTime; // Start time
                p[hpi].rt = p[hpi].st - p[hpi].at; // Response time
            }

            currTime++; // Increment current time (1 unit for each execution cycle)
            p[hpi].remBt--; // Decrease the remaining burst time

            // If process finishes, update completion time and mark it as completed
            if (p[hpi].remBt == 0) {
                p[hpi].ct = currTime; // Completion time
                completed++;
                isCompleted[hpi] = 1; // Mark the process as completed
            }
        } else {
            // If no process is ready to execute, increment current time
            currTime++;
        }
    }

    // Calculate and print the turnaround time (TAT), waiting time (WT), etc.
    int sumTAT = 0, sumWT = 0, sumRT = 0;
    for (int i = 0; i < n; i++) {
        p[i].tat = p[i].ct - p[i].at; // Turnaround time
        p[i].wt = p[i].tat - p[i].bt; // Waiting time

        sumTAT += p[i].tat;
        sumWT += p[i].wt;
        sumRT += p[i].rt;

        printf("Process %d: AT = %d, BT = %d, Priority = %d, CT = %d, TAT = %d, WT = %d\n", 
               p[i].pid, p[i].at, p[i].bt, p[i].py, p[i].ct, p[i].tat, p[i].wt);
    }

    // Print average times
    printf("Average Turnaround Time: %.2f\n", (float)sumTAT / n);
    printf("Average Waiting Time: %.2f\n", (float)sumWT / n);
    printf("Average Response Time: %.2f\n", (float)sumRT / n);

    return 0;
}
