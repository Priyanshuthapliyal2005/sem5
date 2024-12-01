#include <stdio.h> 
int main()
{
    int n;
    printf("Enter number of requests: ");
    scanf("%d", &n);

    int incomingStream[n];
    printf("Enter the reference string (space-separated page numbers):\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &incomingStream[i]);
    }

    int frames;
    printf("Enter number of frames available: ");
    scanf("%d", &frames);

    int temp[frames];
    int lastUsed[frames];
    int pageFaults = 0;
    int pageHits = 0;

    for (int i = 0; i < frames; i++)
    {
        temp[i] = -1;
        lastUsed[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        int isHit = 0;
        int lruIndex = -1;

        for (int j = 0; j < frames; j++)
        {
            if (temp[j] == incomingStream[i])
            {
                isHit = 1;
                pageHits++;
                lastUsed[j] = i;
                break;
            }
        }

        if (!isHit)
        {
            pageFaults++;

            int minTime = i;
            for (int j = 0; j < frames; j++)
            {
                if (temp[j] == -1)
                {
                    lruIndex = j;
                    break;
                }
                if (lastUsed[j] < minTime)
                {
                    minTime = lastUsed[j];
                    lruIndex = j;
                }
            }

            temp[lruIndex] = incomingStream[i];
            lastUsed[lruIndex] = i;
        }

        printf("Frames after request %d: ", incomingStream[i]);
        for (int j = 0; j < frames; j++)
        {
            if (temp[j] != -1)
                printf("%d ", temp[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    float hitRatio = (float)pageHits / n;
    float missRatio = (float)pageFaults / n;

    printf("Total number of page faults: %d\n", pageFaults);
    printf("Page Fault Ratio: %.2f\n", missRatio);
    printf("Page Hit Ratio: %.2f\n", hitRatio);

    return 0;
}
