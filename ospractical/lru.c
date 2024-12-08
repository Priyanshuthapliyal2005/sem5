#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

int find(int last[], int size)
{
    int minTime = INT_MAX, lru = -1;
    for (int i = 0; i < size; i++)
    {
        if (last[i] < minTime)
        {
            minTime = last[i];
            lru = i;
        }
    }
    return lru;
}

void printFrames(int frames[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (frames[i] != -1)
            printf("%d ", frames[i]);
        else
            printf("- ");
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the number of requests");
    scanf("%d", &n);

    int reference[n];
    printf("Enter the referebce string ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &reference[i]);
    }

    int frames;
    printf("Enter the number of frames available:");
    scanf("%d", &frames);
    int curr[frames], lastUsed[frames];
    for (int i = 0; i < frames; i++) {
        curr[i] = -1;
        lastUsed[i] = -1;
    }

    int pageFault = 0, pageHits = 0;

    for (int i = 0; i < n; i++)
    {
        int isHit = 0;
        int currPage = reference[i];
        for (int j = 0; j < frames; j++)
        {
            if (curr[j] == currPage)
            {
                isHit = 1;
                pageHits ++ ;
                lastUsed[j] = i;
                break;
            }
        }

        if (!isHit)
        {
            pageFault++;
            int lru = find(lastUsed, frames);
            curr[lru] = currPage;
            lastUsed[lru] = i;
        }
        printf("Frames after request %d: ", reference[i]);
        printFrames(curr, frames);
    }

    printf("\nTotal Page Faults: %d\n", pageFault);
    printf("Page Fault Ratio: %.2f\n", (float)pageFault / n);
    printf("Page Hit Ratio: %.2f\n", (float)pageHits / n);
    return 0;
}