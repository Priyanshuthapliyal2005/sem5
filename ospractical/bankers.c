// #include <stdio.h>
// #include <stdbool.h>

// int main() {
//     int n, m, i, j, k;

//     printf("Enter the number of processes: ");
//     scanf("%d", &n);

//     printf("Enter the number of resources: ");
//     scanf("%d", &m);

//     int allocated[n][m];
//     int max[n][m];
//     int avail[m];
//     int need[n][m];
//     int finished[n];
//     int safeSequence[n];

//     // Initialize finished array to false (0)
//     for (i = 0; i < n; i++) {
//         finished[i] = 0;
//     }

//     // Input the maximum demand matrix
//     printf("Enter the maximum matrix:\n");
//     for (i = 0; i < n; i++) {
//         for (j = 0; j < m; j++) {
//             scanf("%d", &max[i][j]);
//         }
//     }

//     // Input the allocation matrix
//     printf("Enter the allocated matrix:\n");
//     for (i = 0; i < n; i++) {
//         for (j = 0; j < m; j++) {
//             scanf("%d", &allocated[i][j]);
//         }
//     }

//     // Input available resources
//     printf("Enter available resources:\n");
//     for (j = 0; j < m; j++) {
//         scanf("%d", &avail[j]);
//     }

//     // Calculate the need matrix
//     for (i = 0; i < n; i++) {
//         for (j = 0; j < m; j++) {
//             need[i][j] = max[i][j] - allocated[i][j];
//         }
//     }

//     // Banker's algorithm to find a safe sequence
//     int processCnt = 0;

//     while (processCnt < n) {
//         bool found = false;

//         for (i = 0; i < n; i++) {
//             if (!finished[i]) {
//                 bool canAllocate = true;

//                 // Check if resources can be allocated to process i
//                 for (j = 0; j < m; j++) {
//                     if (need[i][j] > avail[j]) {
//                         canAllocate = false;
//                         break;
//                     }
//                 }

//                 // If resources can be allocated
//                 if (canAllocate) {
//                     // Allocate resources to process i and mark it as finished
//                     for (k = 0; k < m; k++) {
//                         avail[k] += allocated[i][k];  // Release resources
//                     }

//                     safeSequence[processCnt++] = i;
//                     finished[i] = 1;
//                     found = true;  // Mark that we found at least one process that can be allocated
//                 }
//             }
//         }

//         // If no process could be allocated resources in this round, declare unsafe state
//         if (!found) {
//             printf("The system is in an unsafe state.\n");
//             return 0;
//         }
//     }

//     // Print the safe sequence
//     printf("The system is in a safe state.\nSafe sequence is: ");
//     for (i = 0; i < processCnt; i++) {
//         printf("P%d ", safeSequence[i]);
//     }
//     printf("\n");

//     return 0;
// }


#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int  n , m ;
    printf("Enter the  num of processes : ");
    scanf("%d", &n);

    printf("Enter the num of resources : ");
    scanf("%d",&m);

    int max[n][m];
    int need[n][m];
    int alloc[n][m];
    int avail[m];


    printf("Enter the max i/p :");
    for(int i=0 ; i < n ; i++){
        for(int j=0 ; j<m ;j ++){
            scanf("%d", &max[i][j]);
        }
    }
    printf("\nEnter the alloc i/p :");
    for(int i=0 ; i < n ; i++){
        for(int j=0 ; j<m ;j ++){
            scanf("%d", &alloc[i][j]);
        }
    }

    for(int i=0 ; i < n ; i++){
        for(int j=0 ; j<m ;j ++){
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }


    printf("Enter the curr avail resources : ");
    for(int i=0 ; i < n ; i++){
        scanf("%d", &avail[i]);
    }


    int finished[n] , safe[n];


    memset(finished , 0 , n * sizeof(int));

    int proCnt =0;

    while(proCnt < n ){
        bool found =0;
        for(int i=0 ; i< n ; i++){
            if(!finished[i]){
                bool allocated = 1;
                for(int j=0 ; j < m ; j++){
                    if(need[i][j]> avail[j]){
                        allocated=0;
                        break;
                    }
                }

                if(allocated){
                    for(int j=0 ; j < m ; j++){
                        avail[j] += alloc[i][j];
                    }

                    finished[i]=1;
                    safe[proCnt]= i;
                    proCnt++;
                    found = 1;
                }
            }
        }


        if(!found){
            printf("Deadlock detected.");
            return 0;
        }
    }


    printf("The system is in safe state .\n");
    for(int i=0 ; i < n ; i++){
        printf("%d -> ", safe[i]);
    }
    return 0 ; 
}