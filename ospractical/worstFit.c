#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int n;
    printf("Enter the number of free blocks: ");
    scanf("%d", &n);

    int blocks[n];
    printf("Enter the size of each block: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &blocks[i]);

    int m;
    printf("Enter the number of pes: ");
    scanf("%d", &m);

    int p[m];
    for (int i = 0; i < m; i++)
        scanf("%d", &p[i]);

    bool occupied[n];
    for (int i = 0; i < n; i++)
        occupied[i] = false;

    int allocated[m];
    for (int i = 0; i < m; i++)
        allocated[i] = -1;

    for (int i = 0; i < m; i++)
    {
        int maxi = INT_MIN;
        int idx = -1;

        for (int j = 0; j < n; j++)
        {
            int diff = blocks[j] - p[i];
            if (!occupied[j] && blocks[j] >= p[i] && diff > maxi)
            {
                maxi = diff;
                idx = j;
            }
        }

        if (idx != -1)
        {
            allocated[i] = idx + 1;
            occupied[idx] = true;
        }
    }
    for (int j = 0; j < m; j++)
    {
        if (allocated[j] == -1)
            printf("%d - No free block allocated\n", p[j]);
        else
            printf("%d - %d\n", p[j], allocated[j]);
    }
    return 0;
}