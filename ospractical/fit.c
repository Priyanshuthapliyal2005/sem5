#include <stdio.h>
#include <stdbool.h>

void firstFit(int blocks[], int m, int processses[], int n)
{
    int allocation[n];
    for (int i = 0; i < n; i++)
    {
        allocation[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (blocks[i] >= processses[i])
            {
                allocation[i] = j;
                blocks[j] -= processses[i];
                break;
            }
        }
    }
    printf("\nFirst-Fit Allocation:");
    for (int i = 0; i < n; i++)
    {
        if (allocation[i] != -1)
            printf("\nProcess %d allocated to block %d", i + 1, allocation[i] + 1);
        else
            printf("\nProcess %d not allocated", i + 1);
    }
}

void bestFit(int blocks[], int m, int processses[], int n)
{
    int allocation[n];
    for (int i = 0; i < n; i++)
    {
        allocation[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        int idx = -1;
        for (int j = 0; j < m; j++)
        {
            if (blocks[j] >= processses[i])
            {
                if (idx == -1 || blocks[j] < blocks[idx])
                {
                    idx = j;
                }
            }
        }

        if (idx != -1)
        {
            allocation[i] = idx;
            blocks[idx] -= processses[i];
        }
    }
    printf("\nBest-Fit Allocation:");
    for (int i = 0; i < n; i++)
    {
        if (allocation[i] != -1)
            printf("\nProcess %d allocated to block %d", i + 1, allocation[i] + 1);
        else
            printf("\nProcess %d not allocated", i + 1);
    }
}

void worstFit(int blocks[], int m, int processses[], int n)
{
    int allocation[n];
    for (int i = 0; i < n; i++)
    {
        allocation[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        int idx = -1 ;
        for (int j = 0; j < m; j++)
        {
            if (blocks[j] > processses[i])
            {
                if (idx == -1 || blocks[j] > blocks[idx])
                {
                    idx = j;
                }
            }
        }

        if (idx != -1)
        {
            allocation[i] = idx;
            blocks[idx] -= processses[i];
        }
    }

    printf("\nWorst-Fit Allocation:");
    for (int i = 0; i < n; i++)
    {
        if (allocation[i] != -1)
            printf("\nProcess %d allocated to block %d", i + 1, allocation[i] + 1);
        else
            printf("\nProcess %d not allocated", i + 1);
    }
}

void nextFit(int blocks[], int m, int processses[], int n)
{
    int allocation[n];
    for (int i = 0; i < n; i++)
    {
        allocation[i] = -1;
    }

    int lastIdx = 0;

    for (int i = 0; i < n; i++)
    {
        bool allocated = 0;
        for (int j = 0; j < m; j++)
        {
            int idx = (lastIdx + j) % m;
            if (blocks[idx] >= processses[i])
            {
                allocation[i] = idx;
                blocks[idx] -= processses[i];
                lastIdx = idx + 1;
                allocated = 1;
                break;
            }
        }

        if (!allocated)
        {
            lastIdx = 0;
        }
    }

    printf("\nNext-Fit Allocation:");
    for (int i = 0; i < n; i++)
    {
        if (allocation[i] != -1)
            printf("\nProcess %d allocated to block %d", i + 1, allocation[i] + 1);
        else
            printf("\nProcess %d not allocated", i + 1);
    }
}
int main()
{
    int blocks[] = {100, 500, 200, 300, 600};
    int processses[] = {212, 417, 112, 426};
    int m = sizeof(blocks) / sizeof(blocks[0]);
    int n = sizeof(processses) / sizeof(processses[0]);

    int blocksCopy[m];
    // First-Fit
    for (int i = 0; i < m; i++)
        blocksCopy[i] = blocks[i];
    firstFit(blocksCopy, m, processses, n);

    // Best-Fit
    for (int i = 0; i < m; i++)
        blocksCopy[i] = blocks[i];
    bestFit(blocksCopy, m, processses, n);

    // Worst-Fit
    for (int i = 0; i < m; i++)
        blocksCopy[i] = blocks[i];
    worstFit(blocksCopy, m, processses, n);

    // Next-Fit
    for (int i = 0; i < m; i++)
        blocksCopy[i] = blocks[i];
    nextFit(blocksCopy, m, processses, n);
}