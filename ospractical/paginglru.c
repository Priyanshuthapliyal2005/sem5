#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

// Function to find the least recently used (LRU) page
// Parameters:
// - last[]: Array storing the last usage times of pages in memory
// - size: Number of frames in memory
// Returns the index of the LRU page
int find(int last[], int size)
{
    int minTime = INT_MAX; // Initialize with maximum possible value
    int lru = -1;          // Variable to store the index of LRU page
    for (int i = 0; i < size; i++)
    {
        // Check for the smallest time (least recently used)
        if (last[i] < minTime)
        {
            minTime = last[i];
            lru = i;
        }
    }
    return lru; // Return the index of the LRU page
}

// Function to print the current state of memory frames
// Parameters:
// - frames[]: Array storing the current pages in memory
// - size: Number of frames
void printFrames(int frames[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (frames[i] != -1) // If the frame is occupied, print the page number
            printf("%d ", frames[i]);
        else // If the frame is empty, print '-'
            printf("- ");
    }
    printf("\n");
}

int main()
{
    // Step 1: Input the number of page requests
    int n;
    printf("Enter the number of requests: ");
    scanf("%d", &n);

    // Step 2: Input the reference string (page requests)
    int reference[n];
    printf("Enter the reference string: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &reference[i]); // Read each page request
    }

    // Step 3: Input the number of frames (memory slots)
    int frames;
    printf("Enter the number of frames available: ");
    scanf("%d", &frames);

    // Step 4: Initialize memory frames and last used times
    int curr[frames], lastUsed[frames];
    for (int i = 0; i < frames; i++) {
        curr[i] = -1;      // Initialize frames to -1 (empty)
        lastUsed[i] = -1;  // Initialize last used times to -1 (not used yet)
    }

    // Step 5: Initialize counters for page faults and page hits
    int pageFault = 0, pageHits = 0;

    // Step 6: Process each page request in the reference string
    for (int i = 0; i < n; i++)
    {
        int isHit = 0;            // Flag to check if the page is already in memory
        int currPage = reference[i]; // Current page being requested

        // Check if the current page is already in memory (page hit)
        for (int j = 0; j < frames; j++)
        {
            if (curr[j] == currPage) // If found in memory
            {
                isHit = 1;         // Mark as a hit
                pageHits++;        // Increment the page hit counter
                lastUsed[j] = i;   // Update the last used time for this page
                break;             // No need to check further
            }
        }

        // If it's a page fault (page not found in memory)
        if (!isHit)
        {
            pageFault++; // Increment the page fault counter

            // Find the least recently used page to replace
            int lru = find(lastUsed, frames);

            // Replace the LRU page with the current page
            curr[lru] = currPage;

            // Update the last used time for the new page
            lastUsed[lru] = i;
        }

        // Step 7: Print the current state of frames after each request
        printf("Frames after request %d: ", reference[i]);
        printFrames(curr, frames);
    }

    // Step 8: Output the total number of page faults, page fault ratio, and page hit ratio
    printf("\nTotal Page Faults: %d\n", pageFault);
    printf("Page Fault Ratio: %.2f\n", (float)pageFault / n);
    printf("Page Hit Ratio: %.2f\n", (float)pageHits / n);

    return 0; // End of the program
}
