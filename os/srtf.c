#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

struct Process
{
    int pid;   // Process ID
    int at;    // Arrival Time
    int bt;    // Burst Time
    int ct;    // Completion Time
    int st;    // Start Time
    float tat; // Turnaround Time
    float rt;  // Response Time
    float wt;  // Waiting Time
    int rmbt;  // Remaining Burst Time
};
typedef struct Process ps;

int executionOrder[100]; // Array to store the execution order
int orderIndex = 0;      // Index to track execution order

int main()
{
    int n;

    printf("Enter total number of processes: ");
    scanf("%d", &n); // Input the number of processes

    ps p[n];

    // Input arrival time and burst time
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter Process %d Arrival Time and Burst Time: ", i + 1);
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].pid = i + 1; // Assigning Process ID
        p[i].rmbt = p[i].bt; // Initialize remaining burst time
    }

    int currT = 0;
    int completed = 0;
    int isCompleted[n];
    for (int i = 0; i < n; i++)
        isCompleted[i] = 0; // Initialize all processes as not completed

    // Main scheduling loop
    while (completed < n)
    {
        int idx = -1;
        int minBt = INT_MAX;

        // Find process with shortest remaining time that has arrived
        for (int i = 0; i < n; i++)
        {
            if (p[i].at <= currT && !isCompleted[i])
            {
                if (p[i].rmbt < minBt)
                {
                    minBt = p[i].rmbt;
                    idx = i;
                }
                else if (p[i].rmbt == minBt)
                {
                    if (p[i].at < p[idx].at)
                    {
                        idx = i;
                    }
                }
            }
        }

        if (idx == -1)
        {
            currT++; // Increment time if no process is available
        }
        else
        {
            if (p[idx].rmbt == p[idx].bt)
            {
                p[idx].st = currT; // Set start time if process is executed for the first time
            }

            p[idx].rmbt--; // Execute the process for one time unit
            currT++;
            executionOrder[orderIndex++] = p[idx].pid; // Record execution order

            if (p[idx].rmbt == 0)
            {
                completed++;
                isCompleted[idx] = 1; // Mark process as completed

                p[idx].ct = currT;
                p[idx].tat = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;
                p[idx].rt = p[idx].st - p[idx].at;
            }
        }
    }

    // Output results
    printf("\nProcess No.\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t%d\t%d\t%.2f\t%.2f\t%.2f\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt, p[i].rt);
    }

    printf("\nExecution order of processes:\n");
    for (int i = 0; i < orderIndex; i++)
    {
        printf("P%d ", executionOrder[i]);
    }
    printf("\n");

    return 0;
}
