#include <stdio.h>
#include <stdbool.h>

struct PInfo
{
    int maxi[10];
    int alloc[10];
    int need[10];
};

int n_proc, n_res;

void input(struct PInfo p[], int avail[])
{
    printf("Enter number of processes: ");
    scanf("%d", &n_proc);
    printf("Enter number of resources: ");
    scanf("%d", &n_res);

    printf("Enter maximum requirement:\n");
    for (int i = 0; i < n_proc; i++)
    {
        for (int j = 0; j < n_res; j++)
            scanf("%d", &p[i].maxi[j]);
    }

    printf("Enter allocated matrix:\n");
    for (int i = 0; i < n_proc; i++)
    {
        for (int j = 0; j < n_res; j++)
        {
            scanf("%d", &p[i].alloc[j]);
            p[i].need[j] = p[i].maxi[j] - p[i].alloc[j];
        }
    }

    printf("Enter Resource Vector: ");
    for (int i = 0; i < n_res; i++)
        scanf("%d", &avail[i]);
}

void display(struct PInfo p[])
{
    printf("\nPID\tMax\tAlloc\tNeed\n");
    for (int i = 0; i < n_proc; i++)
    {
        printf("P[%d]\t", i);
        for (int j = 0; j < n_res; j++)
            printf("%d ", p[i].maxi[j]);
        printf("\t");
        for (int j = 0; j < n_res; j++)
            printf("%d ", p[i].alloc[j]);
        printf("\t");
        for (int j = 0; j < n_res; j++)
            printf("%d ", p[i].need[j]);
        printf("\n");
    }
}

bool solve(struct PInfo p[], int avail[], int safeSeq[])
{
    bool finish[10] = {false};
    int work[10];
    for (int i = 0; i < n_res; i++)
        work[i] = avail[i];

    int k = 0;
    bool proceed = true;

    while (proceed)
    {
        proceed = false;
        for (int i = 0; i < n_proc; i++)
        {
            if (!finish[i])
            {
                bool canAllocate = true;
                for (int j = 0; j < n_res; j++)
                {
                    if (p[i].need[j] > work[j])
                    {
                        canAllocate = false;
                        break;
                    }
                }
                if (canAllocate)
                {
                    for (int j = 0; j < n_res; j++)
                        work[j] += p[i].alloc[j];
                    finish[i] = true;
                    safeSeq[k++] = i;
                    proceed = true;
                }
            }
        }
    }

    for (int i = 0; i < n_proc; i++)
    {
        if (!finish[i])
            return false;
    }
    return true;
}

bool isSafe(struct PInfo p[], int avail[], int safeSeq[])
{
    return solve(p, avail, safeSeq);
}

int main()
{
    int avail[10];
    int safeSeq[10];
    struct PInfo p[10];

    input(p, avail);

    if (isSafe(p, avail, safeSeq))
    {
        printf("\nRequest can be fulfilled\n");
        printf("Safe Sequence: ");
        for (int i = 0; i < n_proc; i++)
            printf("P[%d] ", safeSeq[i]);
        printf("\n");
    }
    else
    {
        printf("Request cannot be fulfilled. System is not in safe state.\n");
    }

    return 0;
}
