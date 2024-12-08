/**
 * @file scan.c
 * @brief Disk Scheduling using SCAN Algorithm
 * 
 * This program simulates the SCAN disk scheduling algorithm, which services
 * disk requests in one direction until it reaches the end, then reverses
 * direction and services the remaining requests.
 * 
 * The program takes the number of disk requests, the disk request queue, and
 * the initial head position as input, sorts the request queue, and calculates
 * the total head movement required to service all requests.
 * 
 * Functions:
 * - compare: Comparator function for qsort to sort the disk requests.
 * - main: Main function to execute the SCAN disk scheduling algorithm.
 * 
 * Usage:
 * Compile the program and run the executable. Follow the prompts to enter the
 * number of disk requests, the disk request queue, and the initial head position.
 * The program will output the total seek movement.
 * 
 * Example:
 * Enter the number of disk requests: 5
 * Enter the disk requests: 98 183 37 122 14
 * Enter the initial head position: 53
 * Total seek Movement: 236
 * 
 * @author
 * @date
 */
#include<stdio.h>
#include<stdlib.h>


int compare ( const void *a , const void *b){
    return (*(int*)a - *(int*)b);
}
9

int main(){
    int  n , head;

    printf("Enter the number of disk requests :");
    scanf("%d" ,&n);

    int arr[n];
    printf("Enter the disk requests :");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }


    printf("Enter the initial head position :");
    scanf("%d",&head);

    qsort(arr,n ,sizeof(int), compare);

    int total_head_movement = 0, idx =0 ;
    while(idx < n && arr[idx] <head){
        idx++;
    }

    int curr = head;
    
    for(int i = idx ; i< n ; i++){
        total_head_movement += (arr[i]- curr);
        curr = arr[i];
    }

    for(int i = idx -1 ; i >=0 ; i--){
        total_head_movement += abs(arr[i]- curr);
        curr = arr[i];
    }

    printf("Total seek Movement : %d",total_head_movement);
}