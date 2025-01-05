#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int main()
{
    int n, head, diskSize;

    // Step 1: Input the number of disk requests
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int requests[n];

    // Step 2: Input the disk requests into an array
    printf("Enter the disk requests: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &requests[i]);
    }

    // Step 3: Input the initial head position
    printf("Enter the initial head position: ");
    scanf("%d", &head);

    // Step 4: Input the total size of the disk
    printf("Enter the total disk size: ");
    scanf("%d", &diskSize);

    int totalMove = 0; // Variable to store total head movement
    int curr = head;   // Current head position

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (requests[j] > requests[j + 1])
            {
                int temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }
        }
    }

    int idx = 0 ;
    for (int i = 0; i < n; i++)
    {
        if (requests[i] > head)
        {
            idx = i;
            break;
        }
    }

    printf("\n Sequence of disk access : %d", head);
    for (int i = idx; i < n; i++)
    {
        totalMove += abs(curr - requests[i]);
        curr = requests[i];
        printf("->%d", requests[i]);
    }

    totalMove += abs(curr - (diskSize - 1));
    curr = diskSize - 1;
    printf("->%d", curr);

    totalMove += abs(curr - 0);
    curr = 0;
    printf("->0");

    for (int i = 0; i < idx; i++)
    {
        totalMove += abs(curr - (requests[i]));
        curr = requests[i];
        printf("->%d", requests[i]);
    }
    printf("\n\nTotal head movement: %d\n", totalMove);
    return 0;
}