#include <stdio.h> 
#include <stdbool.h>

int main()
{
    printf("Enter number of free blocks : ");
    int n;
    scanf("%d", &n);

    int block[n];
    printf("Enter %d blocks\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &block[i]);

    printf("Enter number of processes : ");
    int m;
    scanf("%d", &m);

    printf("Enter %d processes\n", m);
    int process[m];
    for (int j = 0; j < m; j++)
        scanf("%d", &process[j]);

    // Initialize occupied array
    bool occupied[n];
    for (int i = 0; i < n; i++)
        occupied[i] = false;
    // Initialize answer array
    int ans[m];
    for (int j = 0; j < m; j++)
        ans[j] = -1;

    // First-fit allocation
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (!occupied[i] && process[j] <= block[i])
            {
                ans[j] = i + 1; // Allocate block i (1-based indexing)
                occupied[i] = true;
                break;
            }
        }
    }

    // Output the allocation results
    for (int j = 0; j < m; j++)
    {
        if (ans[j] == -1)
            printf("Process %d - No free block allocated\n", process[j]);
        else
            printf("Process %d - Block %d\n", process[j], ans[j]);
    }

    return 0;
}
