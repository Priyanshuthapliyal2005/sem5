#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
int main() {
    int n, head;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the track numbers: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the initial position of the head: ");
    scanf("%d", &head);
    qsort(arr, n, sizeof(int), compare);
    int total_seek = 0, idx = 0;
    while (idx < n && arr[idx] < head) {
        idx++;
    }
    int current = head;

    for (int i = idx; i < n; i++) {
        total_seek += abs(arr[i] - current);
        current = arr[i];
    }

    for (int i = idx - 1; i >= 0; i--) {
        total_seek += abs(arr[i] - current);
        current = arr[i];
    }

    printf("Total seek movement: %d\n", total_seek);

    return 0;
}
