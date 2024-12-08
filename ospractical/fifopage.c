// \#include <stdio.h>
// #include <stdbool.h>
// #include <string.h>

// // Structure to represent a page in the page table
// struct PageTable {
//     int frame_no;
//     bool valid;
// };

// // Function to check if a page is present in the page table
// bool isPagePresent(struct PageTable PT[], int page) {
//     return PT[page].valid;
// }

// // Function to update the page table with the given page details
// void updatePageTable(struct PageTable PT[], int page, int frame_no, int status) {
//     PT[page].valid = status;
//     PT[page].frame_no = frame_no;
// }

// // Function to print the contents of the frame array
// void printFrameContents(int frame[], int no_of_frames) {
//     for (int i = 0; i < no_of_frames; i++) {
//         if (frame[i] != -1) {
//             printf("%d ", frame[i]);
//         } else {
//             printf("- "); // To represent empty slots
//         }
//     }
//     printf("\n");
// }

// int main() {
//     int n, no_of_frames;
//     int pageFault = 0, current_frame = 0;
//     bool all_frames_filled = false;

//     // Input the number of pages
//     printf("Enter the number of pages: ");
//     scanf("%d", &n);

//     // Input the reference string
//     int reference_string[n];
//     printf("Enter the reference string (page numbers): ");
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &reference_string[i]);
//     }

//     // Input the number of frames
//     printf("Enter the number of frames: ");
//     scanf("%d", &no_of_frames);

//     // Initialize frame array and page table
//     int frame[no_of_frames];
//     memset(frame, -1, no_of_frames * sizeof(int)); // Fill frames with -1 (empty)
//     struct PageTable PT[n];
//     memset(PT, 0, sizeof(PT)); // Initialize page table with valid = 0

//     printf("\nContents of Frame at Different Time Steps:\n");

//     // FIFO Page Replacement Algorithm
//     for (int i = 0; i < n; i++) {
//         int current_page = reference_string[i];

//         // If the page is not present in the frame
//         if (!isPagePresent(PT, current_page)) {
//             // If there is space in the frame
//             if (!all_frames_filled && current_frame < no_of_frames) {
//                 frame[current_frame] = current_page;
//                 printFrameContents(frame, no_of_frames);
//                 updatePageTable(PT, current_page, current_frame, 1);
//                 current_frame++;

//                 // Check if all frames are filled
//                 if (current_frame == no_of_frames) {
//                     current_frame = 0; // Reset to 0 for circular replacement
//                     all_frames_filled = true;
//                 }
//             } else { // If frames are full, replace the oldest page (FIFO)
//                 updatePageTable(PT, frame[current_frame], -1, 0); // Invalidate the oldest page
//                 frame[current_frame] = current_page;
//                 printFrameContents(frame, no_of_frames);
//                 updatePageTable(PT, current_page, current_frame, 1);
//                 current_frame = (current_frame + 1) % no_of_frames; // Move to the next frame
//             }

//             // Increment page fault count
//             pageFault++;
//         }
//     }

//     // Display statistics
//     printf("\nTotal Page Faults: %d\n", pageFault);
//     printf("Page Fault Ratio: %.2f\n", (float)pageFault / n);
//     printf("Page Hit Ratio: %.2f\n", 1.0 - ((float)pageFault / n));

//     return 0;
// }


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct pageTable {
    int frameNo;
    bool valid;
}pt;

bool isPagePresent(pt pt[] , int curr){
    if(!pt[curr].valid){
        return false;
    }
    return true;
}

void update(pt pt[] , int page , int frameNum , int status ){
    pt[page].valid = status;
    pt[page].frameNo = frameNum;
}

void printFrameContents(int frame[], int no_of_frames) {
    for (int i = 0; i < no_of_frames; i++) {
        if (frame[i] != -1) {
            printf("%d ", frame[i]);
        } else {
            printf("- "); // To represent empty slots
        }
    }
    printf("\n");
}

int main(){
    int n , numFrames;
    int currFrame=0, pageFault= 0;
    printf("Enter the number of pages: ");
    scanf("%d" ,&n);

    bool isFull =0;

    int reference[n];
    printf("Enter the reference string :");
    for(int i=0 ; i < n ; i++){
        scanf("%d",&reference[i]);
    }

    printf("Enter the number of frames :");
    scanf("%d", &numFrames);


    int frame[numFrames];
    for(int i=0 ; i< numFrames; i++){
        frame[i]=-1;
    }

    pt pt[n];
    for(int i=0 ;i < n ; i++){
        pt[i].frameNo= 0;
        pt[i].valid =0;
    }

    for(int i=0 ; i< n ;i++){
        int currPage = reference[i];

        if(!isPagePresent(pt , currPage)){
            if(!isFull && currPage < numFrames ){
                frame[currFrame] = currPage;
                printFrameContents(frame, numFrames);
                update(pt , currPage,  currFrame , 1);
                currFrame++;

                if(currFrame == numFrames){
                    isFull = 1;
                    currFrame =0;
                }
            }else{
                update(pt , frame[currFrame],-1 ,0 );
                frame[currFrame] = currPage;
                printFrameContents(frame , numFrames);
                update(pt,currPage, currFrame ,-1);
                currFrame = (currFrame+1) % numFrames;
            }
            pageFault++;
        }
    }
    printf("\nTotal Page Faults: %d\n", pageFault);
    printf("Page Fault Ratio: %.2f\n", (float)pageFault / n);
    printf("Page Hit Ratio: %.2f\n", 1.0 - ((float)pageFault / n));

    return 0;
}