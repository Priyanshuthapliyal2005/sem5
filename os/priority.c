#include <stdio.h>
#include <limits.h>

struct Process
{
    int pid, at, bt, ct, st, rt, wt, tat, py;
    int remBt;
};

typedef struct Process process;

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    process p[n];

    for (int i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        printf("Enter the arrival time, burst time, and priority of process %d: ", i + 1);
        scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].py);
        p[i].remBt = p[i].bt; // Initialize remaining burst time
    }

    int currT = 0;
    int completed = 0;
    int isCompleted[n];

    for (int i = 0; i < n; i++)
    {
        isCompleted[i] = 0; // Mark all processes as incomplete
    }

    while (completed != n)
    {
        int hpi = -1;
        int maxPriority = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            if (p[i].at <= currT && isCompleted[i] == 0)
            {
                if (p[i].py > maxPriority || (p[i].py == maxPriority && p[i].at < p[hpi].at))
                {
                    maxPriority = p[i].py;
                    hpi = i;
                }
            }
        }

        if (hpi == -1)
        {
            currT++; // Increment time if no process is ready
        }
        else
        {
            if (p[hpi].remBt == p[hpi].bt)
            {
                p[hpi].st = currT; // Start time for the first execution
                p[hpi].rt = p[hpi].st - p[hpi].at; // Response time
            }

            currT++;
            p[hpi].remBt--; // Execute process for one unit of time

            if (p[hpi].remBt == 0)
            {
                p[hpi].ct = currT; // Completion time
                completed++;
                isCompleted[hpi] = 1; // Mark process as completed
            }
        }
    }

    int sumTAT = 0, sumWT = 0, sumRT = 0;
    for (int i = 0; i < n; i++)
    {
        p[i].tat = p[i].ct - p[i].at; // Turnaround time
        p[i].wt = p[i].tat - p[i].bt; // Waiting time

        sumTAT += p[i].tat;
        sumWT += p[i].wt;
        sumRT += p[i].rt;

        printf("Process %d: AT = %d, BT = %d, Priority = %d, CT = %d, TAT = %d, WT = %d, RT = %d\n",
               p[i].pid, p[i].at, p[i].bt, p[i].py, p[i].ct, p[i].tat, p[i].wt, p[i].rt);
    }

    // Print average times
    printf("Average Turnaround Time: %.2f\n", (float)sumTAT / n);
    printf("Average Waiting Time: %.2f\n", (float)sumWT / n);
    printf("Average Response Time: %.2f\n", (float)sumRT / n);

    return 0;
}
