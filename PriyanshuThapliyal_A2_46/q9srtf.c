#include <stdio.h>
#include <stdlib.h>
struct Process
{
    int pid, at, bt, st, ct;
    float rt, tat, wt;
};

int main()
{
    int n;
    float swt = 0, stat = 0, sbt = 0;
    float cu = 0, throughput = 0;
    float awt = 0, atat = 0;
    printf("Enter the number of processes : ");
    scanf("%d", &n);
    struct Process p[n];
    int ogBT[n];

    for (int i = 0; i < n; i++)
    {
        printf("For Process %d ", i + 1);
        p[i].pid = i + 1;
        printf("Enter the value of AT and BT: ");
        scanf("%d %d", &p[i].at, &p[i].bt);
        ogBT[i] = p[i].bt;
    }
    int started[n], completed[n];
    for (int i = 0; i < n; i++)
    {
        started[i] = 0;
        completed[i] = 0;
    }
    int curtime = 0, complete = 0;
    while (complete != n)
    {
        int empty = 1;
        int minBurst = 1e9;
        int toRun = 0;
        for (int i = 0; i < n; i++)
        {
            if (completed[i] == 0 && p[i].at <= curtime && p[i].bt < minBurst)
            {
                minBurst = p[i].bt;
                toRun = i;
                empty = 0;
            }
        }
        if (empty == 1)
        {
            curtime++;
        }
        else
        {
            if (started[toRun] == 0)
            {
                p[toRun].st = curtime;
                started[toRun] = 1;
            }
            p[toRun].bt -= 1;
            curtime++;

            if (p[toRun].bt == 0)
            {
                p[toRun].ct = curtime;
                p[toRun].rt = p[toRun].st - p[toRun].at;
                p[toRun].tat = p[toRun].ct - p[toRun].at;
                p[toRun].wt = p[toRun].tat - ogBT[toRun];
                p[toRun].bt = ogBT[toRun];
                sbt += p[toRun].bt;
                completed[toRun] = 1;
                complete++;
            }
        }
    }
    printf("\nPID\tAT\tBT\tST\tCT\tTAT\t\tWT\t\tRT\n");
    for (int i = 0; i < n; i++)
    {
        swt += p[i].wt;
        stat += p[i].tat;
        printf("P%d\t%d\t%d\t%d\t%d\t%f\t%f\t%f\n", p[i].pid, p[i].at, p[i].bt, p[i].st, p[i].ct, p[i].tat, p[i].wt, p[i].rt);
    }
    awt = swt / n;
    atat = stat / n;
    throughput = (float)n / curtime;
    float cpu = (sbt / curtime) * 100;
    printf("\nSum of Turn Around Time: %f\nAverage of Turn Around Time: %f\n", stat, atat);
    printf("Sum of Waiting Time: %f\nAverage of Waiting Time: %f\nCPU utilisation is : %f\nThroughput :%f", swt, awt, cpu, throughput);
    return 0;
}
