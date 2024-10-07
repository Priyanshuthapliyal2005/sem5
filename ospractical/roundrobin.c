#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

struct Process {
    int pid, at, bt, ct, st, rt, wt, tat;
    int remBt;
};

typedef struct Process process;

int main() {
    int n, tq;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the time quantum: ");
    scanf("%d", &tq);

    process p[n];

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter the arrival time and burst time of process %d: ", i + 1);
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].remBt = p[i].bt;  // Initialize remaining burst time
    }

    int currTime = 0;
    int completed = 0;
    int queue[n];
    int front = 0, rear = 0;
    int isInQueue[n];

    for (int i = 0; i < n; i++) {
        isInQueue[i] = 0;
    }

    // Add processes that arrive at time 0 to the queue
    for (int i = 0; i < n; i++) {
        if (p[i].at == currTime) {
            queue[rear++] = i;
            isInQueue[i] = 1;
        }
    }

    while (completed != n) {
        if (front == rear) {
            currTime++;
            for (int i = 0; i < n; i++) {
                if (p[i].at == currTime && isInQueue[i] == 0) {
                    queue[rear++] = i;
                    isInQueue[i] = 1;
                }
            }
            continue;
        }

        int idx = queue[front++];  // Dequeue process

        if (p[idx].remBt == p[idx].bt) {
            p[idx].st = currTime;              // Start time
            p[idx].rt = p[idx].st - p[idx].at; // Response time
        }

        if (p[idx].remBt <= tq) {
            currTime += p[idx].remBt;  // Add remaining burst time
            p[idx].remBt = 0;
            p[idx].ct = currTime;  // Completion time
            completed++;
        } else {
            currTime += tq;
            p[idx].remBt -= tq;
        }

        // Enqueue arriving processes during the current time slice
        for (int i = 0; i < n; i++) {
            if (p[i].at <= currTime && isInQueue[i] == 0 && p[i].remBt > 0) {
                queue[rear++] = i;
                isInQueue[i] = 1;
            }
        }

        if (p[idx].remBt > 0) {
            queue[rear++] = idx;  // Re-add process if it's not yet finished
        }
    }

    int sumrt = 0, sumtat = 0, sumwt = 0;
    float avgrt, avgtat, avgwt;

    for (int i = 0; i < n; i++) {
        p[i].tat = p[i].ct - p[i].at;
        sumtat += p[i].tat;

        p[i].wt = p[i].tat - p[i].bt;
        sumwt += p[i].wt;

        sumrt += p[i].rt;
    }

    // Print results
    printf("\nPID\tAT\tBT\tST\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt, p[i].st, p[i].ct, 
               p[i].tat, p[i].wt, p[i].rt);
    }

    avgtat = (float)sumtat / n;
    avgwt = (float)sumwt / n;
    avgrt = (float)sumrt / n;

    printf("\nAverage Turnaround Time: %.2f", avgtat);
    printf("\nAverage Waiting Time: %.2f", avgwt);
    printf("\nAverage Response Time: %.2f", avgrt);

    return 0;
}
