#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Enter the number of tracks: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the track numbers: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        ans += abs(arr[i] - arr[i - 1]);
    }
    printf("the total time is: %d", ans);
}
