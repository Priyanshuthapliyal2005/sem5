#include <stdio.h>
#include <stdlib.h>

struct Process {
    int pid, at, bt, st, ct, wt, rt, tat;
    int py; // priority
};

typedef struct Process process;

int main() {
    int n;
    printf("Enter the number of Processes: ");
    scanf("%d", &n);
    
    process p[n]; // Array of processes
    
    // Input for processes
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter the arrival time, burst time, and priority of Process %d: ", i + 1);
        scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].py);
    }
    
    int currTime = 0, completed = 0;
    int isCompleted[n];
    for (int i = 0; i < n; i++) {
        isCompleted[i] = 0; // Mark all processes as incomplete
    }
    
    while (completed < n) {
        int idx = -1;
        int maximum = -1;
        
        // Find process with the highest priority
        for (int i = 0; i < n; i++) {
            if (p[i].at <= currTime && !isCompleted[i]) {
                if (p[i].py > maximum) {
                    idx = i;
                    maximum = p[i].py;
                }
                // If priorities are equal, select the one with the earlier arrival time
                else if (p[i].py == maximum && p[i].at < p[idx].at) {
                    idx = i;
                }
            }
        }
        
        if (idx == -1) {
            currTime++; // If no process is ready, increase current time
        } else {
            // Update the process details
            p[idx].st = currTime;
            p[idx].ct = currTime + p[idx].bt;
            currTime += p[idx].bt;
            
            // Calculate waiting time, turnaround time, response time
            p[idx].rt = p[idx].st - p[idx].at;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            
            isCompleted[idx] = 1; // Mark the process as completed
            completed++;
        }
    }
    
    // Print the process table
    printf("\nPID\tAT\tBT\tST\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", 
               p[i].pid, p[i].at, p[i].bt, p[i].st, p[i].ct, p[i].tat, p[i].wt, p[i].rt);
    }
    
    return 0;
}
