#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Process
{
    int pid, at, bt, st, ct, priority;
    float rt, tat, wt;
    bool isCompleted;
};
int findNextProcess(struct Process p[], int n, int currentTime)
{
    int idx = -1;
    int highestPriority = 9999;
    for (int i = 0; i < n; i++)
    {
        if (p[i].at <= currentTime && !p[i].isCompleted)
        {
            if (p[i].priority < highestPriority)
            {
                highestPriority = p[i].priority;
                idx = i;
            }
            else if (p[i].priority == highestPriority && p[i].at < p[idx].at)
            {
                idx = i;
            }
        }
    }

    return idx;
}
int main()
{
    int n;
    float swt = 0, stat = 0;
    float cu = 0, throughput = 0;
    float awt = 0, atat = 0;
    int sbt = 0;

    printf("Enter the number of processes : ");
    scanf("%d", &n);
    struct Process p[n];

    for (int i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        printf("Process %d | Enter the value of AT, BT, and Priority: ", i + 1);
        scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].priority);
        p[i].isCompleted = false;
    }
    int completed = 0;
    int currentTime = 0;

    while (completed < n)
    {
        int idx = findNextProcess(p, n, currentTime);

        if (idx != -1)
        {
            // Start time is the current time or the arrival time, whichever is later
            p[idx].st = (currentTime < p[idx].at) ? p[idx].at : currentTime;
            p[idx].ct = p[idx].st + p[idx].bt;
            p[idx].rt = p[idx].st - p[idx].at;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;

            sbt += p[idx].bt;
            swt += p[idx].wt;
            stat += p[idx].tat;

            p[idx].isCompleted = true;
            completed++;
            currentTime = p[idx].ct;
        }
        else
        {
            currentTime++;
        }
    }

    awt = swt / n;
    atat = stat / n;
    float maxCT = 0;
    for (int i = 0; i < n; i++)
    {
        if (p[i].ct > maxCT)
        {
            maxCT = p[i].ct;
        }
    }
    cu = (sbt / maxCT) * 100;
    throughput = (float)n / maxCT;
    printf("\nPID\tAT\tBT\tPriority\tST\tCT\tRT\t\tTAT\t\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\t%f\t%f\t%f\n", p[i].pid, p[i].at, p[i].bt, p[i].priority, p[i].st, p[i].ct, p[i].rt, p[i].tat, p[i].wt);
    }

    printf("\nSum of Turn Around Time: %f\nAverage of Turn Around Time: %f\n", stat, atat);
    printf("Sum of Waiting Time: %f\nAverage of Waiting Time: %f\nCPU utilization is: %f\nThroughput: %f\n", swt, awt, cu, throughput);

    return 0;
}
