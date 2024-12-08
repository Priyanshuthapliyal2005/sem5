#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

int main(){
    int n ;
    printf("Enter the number of tracks :");
    scanf("%d",&n);

    int tracks[n];
    printf("Enter the tracks :");
    for(int i=0;i<n;i++){
        scanf("%d",&tracks[i]);
    }

    int ans =0 ; 

    for(int i= 1 ; i< n ; i++){
        ans += abs(tracks[i] - tracks[i-1]);
    }
    printf("Total head movement : %d\n",ans);
}