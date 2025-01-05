#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct pageTable
{
    int frameNum;
    bool valid;
} pt;

bool isPagePresent(pt pt[], int curr)
{
    if (!pt[curr].valid)
    {
        return false;
    }
    return true;
}

void update(pt pt[], int page, int frameNum, int status)
{
    pt[page].valid = status;
    pt[page].frameNum = frameNum;
}

void printFrame(int frame[], int numFrames)
{
    for (int i = 0; i < numFrames; i++)
    {
        if (frame[i] != -1)
        {
            printf("%d", frame[i]);
        }
        else
        {
            printf("- ");
        }
    }
    printf("\n");
}

int main()
{
    int n, numFrames;
    int currFrame = 0, pageFault = 0;
    printf("Enter the number of pages : ");
    scanf("%d", &n);

    bool isFull = 0;
    int reference[n];
    printf("Enter the reference string : ");
    for (int i = 0; i < n; i++)
        scanf("%d", &reference[i]);

    printf("Enter the number of frames : ");
    scanf("%d", &numFrames);

    int frames[numFrames];
    for (int i = 0; i < numFrames; i++)
    {
        frames[i] = -1;
    }

    pt pt[n];

    for (int i = 0; i < n; i++)
    {
        pt[i].frameNum = 0;
        pt[i].valid = 0;
    }

    for (int i = 0; i < n; i++)
    {
        int currPage = reference[i];

        if (!isPagePresent(pt, currPage))
        {
            if (!isFull && currPage < numFrames)
            {
                frames[currFrame] = currPage;
                printFrame(frames, numFrames);
                update(pt, currPage, currFrame, 1);
                currFrame++;

                if (currFrame == numFrames)
                {
                    isFull = 1;
                    currFrame = 0;
                }
            }
            else
            {
                update(pt, frames[currFrame], -1, 0);
                frames[currFrame] = currPage;
                printFrame(frames, numFrames);
                update(pt, currPage, currFrame, -1);
                currFrame = (currFrame + 1) % numFrames;
            }
            pageFault++;
        }
    }
    printf("\nTotal Page Faults: %d\n", pageFault);
    printf("Page Fault Ratio: %.2f\n", (float)pageFault / n);
    printf("Page Hit Ratio: %.2f\n", 1.0 - ((float)pageFault / n));

    return 0;
}