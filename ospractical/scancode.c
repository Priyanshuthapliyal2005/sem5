/**
 * @file scan.c
 * @brief Disk Scheduling using SCAN Algorithm
 *
 * This program simulates the SCAN disk scheduling algorithm, which services
 * disk requests in one direction until it reaches the end, then reverses
 * direction and services the remaining requests.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Comparator function for sorting integers in ascending order.
 *
 * Used with qsort to sort the disk request array.
 * 
 * @param a Pointer to the first integer.
 * @param b Pointer to the second integer.
 * @return Difference between the integers (*a - *b).
 */
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n, head;

    // Input the number of disk requests
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    // Input the disk requests into an array
    int arr[n];
    printf("Enter the disk requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the initial head position
    printf("Enter the initial head position: ");
    scanf("%d", &head);

    // Sort the array of requests in ascending order
    qsort(arr, n, sizeof(int), compare);

    int total_head_movement = 0; // Initialize total head movement counter
    int idx = 0;

    // Find the first request greater than or equal to the initial head position
    while (idx < n && arr[idx] < head) {
        idx++;
    }

    int curr = head; // Start the head position at the given initial position

    // Process requests in the upward direction
    for (int i = idx; i < n; i++) {
        total_head_movement += (arr[i] - curr); // Calculate movement to the next request
        curr = arr[i]; // Update the current head position
    }

    // Process requests in the downward direction
    for (int i = idx - 1; i >= 0; i--) {
        total_head_movement += abs(arr[i] - curr); // Calculate movement to the next request
        curr = arr[i]; // Update the current head position
    }

    // Output the total head movement
    printf("Total seek Movement: %d\n", total_head_movement);

    return 0;
}
