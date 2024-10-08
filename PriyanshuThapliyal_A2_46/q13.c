#include <stdio.h>
#include <stdbool.h>
typedef struct process
{
    int max[10], allocated[10], need[10];
} st;
int n, r;

void input(st process[], int available[])
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter Process %d info -\n", i + 1);
        printf("Enter Allocated Resources : ");
        for (int j = 0; j < r; j++)
        {
            scanf("%d", &process[i].allocated[j]);
        }
        printf("Enter Maximum Need : ");
        for (int j = 0; j < r; j++)
        {
            scanf("%d", &process[i].max[j]);
            process[i].need[j] = process[i].max[j] - process[i].allocated[j];
        }
    }
    printf("Enter Available Resources: ");
    for (int i = 0; i < r; i++)
        scanf("%d", &available[i]);
}

void showTheInfo(st process[])
{
    printf("\nPID\tAllocated\tMaximum\t\tNeed\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", i + 1);
        for (int j = 0; j < r; j++)
            printf("%d ", process[i].allocated[j]);
        printf("\t\t");
        for (int j = 0; j < r; j++)
            printf("%d ", process[i].max[j]);
        printf("\t\t");
        for (int j = 0; j < r; j++)
            printf("%d ", process[i].need[j]);
        printf("\n");
    }
}
bool applySafetyAlgo(st process[], int available[], int safeSequence[])
{
    bool finish[n];
    int work[r];

    for (int i = 0; i < r; i++)
    {
        work[i] = available[i];
    }

    for (int i = 0; i < n; i++)
    {
        finish[i] = false;
    }
    bool proceed = true;
    int k = 0;

    while (proceed)
    {
        proceed = false;
        for (int i = 0; i < n; i++)
        {
            bool flag = true;
            if (finish[i] == false)
            {
                for (int j = 0; j < r; j++)
                {
                    if (process[i].need[j] > work[j])
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    for (int j = 0; j < r; j++)
                    {
                        work[j] += process[i].allocated[j];
                    }
                    finish[i] = true;
                    safeSequence[k++] = i;
                    proceed = true;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!finish[i])
        {
            return false;
        }
    }

    return true;
}

bool isSafeState(st process[], int available[], int safeSequence[])
{
    return applySafetyAlgo(process, available, safeSequence);
}
int main()
{
    printf("Enter No of Process: ");
    scanf("%d", &n);

    printf("\nEnter No of Resource Instances in system: ");
    scanf("%d", &r);

    int available[r], safeSequence[n];
    st process[n];

    input(process, available);
    printf("\n");

    showTheInfo(process);
    printf("\n");

    if (isSafeState(process, available, safeSequence))
    {
        printf("Safe Sequence is: ");
        for (int i = 0; i < n; i++)
        {
            printf("P%d ", safeSequence[i] + 1);
        }
        printf("\nNo Dealock Detected \n");
    }
    else
    {
        printf("\nDealock Detected");
    }

    return 0;
}
