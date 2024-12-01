#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max(a, b) ((a) >= (b) ? (a) : (b))

struct process_struct
{
    int pid;
    int at, bt;
    int st, ct;
    int rt, tat, wt;
} process[100];

int ComparatorAT(const void *a, const void *b)
{
    int at1 = ((struct process_struct *)a)->at;
    int at2 = ((struct process_struct *)b)->at;
    return (at1 < at2) ? -1 : 1;
}

int main()
{
    int n;
    int remaining_bt[100];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Process %d | Enter the Arrival and Burst time of the Process: ", i + 1);
        scanf("%d%d", &process[i].at, &process[i].bt);
        process[i].pid = i + 1;
        remaining_bt[i] = process[i].bt;
    }

    int quantum;
    printf("Enter the quantum time: ");
    scanf("%d", &quantum);

    // Sort processes by arrival time
    qsort((void *)process, n, sizeof(struct process_struct), ComparatorAT);

    bool visited[100] = {false}, first_process = true, is_completed[100] = {false};
    int queue[100], front = -1, rear = -1;
    int sum_rt = 0, sum_tat = 0, sum_wt = 0, start_time = 0, life_cycle, current = 0, idle_time = 0, completed = 0;

    // Add the first process into the queue
    queue[++rear] = 0;
    visited[0] = true;

    while (completed != n)
    {
        int index = queue[++front];

        // First time a process starts
        if (remaining_bt[index] == process[index].bt)
        {
            process[index].st = max(process[index].at, current);

            idle_time += first_process ? 0 : (process[index].st - current); // Idle time between processes
            current = process[index].st;
            if (first_process)
            {
                start_time = process[index].st;
                first_process = false;
            }
        }

        // If the process has more burst time than quantum
        if (remaining_bt[index] > quantum)
        {
            current += quantum;
            remaining_bt[index] -= quantum;
        }
        else
        {
            current += remaining_bt[index]; // Time taken to complete the process
            remaining_bt[index] = 0;
            is_completed[index] = true;

            // Completion time and turnaround/waiting time calculations
            process[index].ct = current;
            process[index].rt = process[index].st - process[index].at;
            process[index].tat = process[index].ct - process[index].at;
            process[index].wt = process[index].tat - process[index].bt;

            // Accumulate sums for average calculations
            sum_rt += process[index].rt;
            sum_tat += process[index].tat;
            sum_wt += process[index].wt;
            completed++;
        }

        // Add new processes into the queue if they have arrived and are not visited
        for (int i = 1; i < n; i++)
        {
            if (process[i].at <= current && visited[i] == false)
            {
                queue[++rear] = i;
                visited[i] = true;
            }
        }

        // If the current process is not finished, re-add it to the queue
        if (is_completed[index] == false)
        {
            queue[++rear] = index;
        }
    }

    // Output process data and performance metrics
    printf("Processes\tAt\tBt\tSt\tCt\tRt\tTat\tWt\n");
    life_cycle = current - start_time;
    float CPU_efficiency = ((float)(life_cycle - idle_time) / life_cycle) * 100;

    for (int i = 0; i < n; i++)
    {
        printf("P%d\t\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", process[i].pid, process[i].at, process[i].bt, process[i].st, process[i].ct, process[i].rt, process[i].tat, process[i].wt);
    }

    printf("Average Turn Around Time : %.2f\n", (float)sum_tat / n);
    printf("Average Response Time : %.2f\n", (float)sum_rt / n);
    printf("Average Waiting Time : %.2f\n", (float)sum_wt / n);
    printf("CPU Efficiency : %.2f%%\n", CPU_efficiency);

    return 0;
}
