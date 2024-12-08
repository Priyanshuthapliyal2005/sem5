#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int n;
    printf("Enter the number of free blocks :");
    scanf("%d", &n);

    int blocks[n];
    printf("Enter the size of each block :");
    for (int i = 0; i < n; i++)
        scanf("%d", &blocks[i]);

    int m;
    printf("Enter the number of processes :");
    scanf("%d", &m);

    int processes[m];
    printf("Enter %d processes \n", m);
    for (int i = 0; i < m; i++)
        scanf("%d", &processes[i]);

    bool occupied[n];
    for (int i = 0; i < n; i++)
        occupied[i] = false;

    int allocated[m];
    for (int j = 0; j < m; j++)
        allocated[j] = -1;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!occupied[j] && blocks[j] >= processes[i])
            {
                allocated[i] = j + 1;
                occupied[j] = true;
                break;
            }
        }
    }

    for (int j = 0; j < m; j++)
    {
        if (allocated[j] == -1)
            printf("Processes %d - No free block allocated\n", processes[j]);
        else
            printf("Processes %d - Block %d\n", processes[j], allocated[j]);
    }
    return 0;
}