#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include<stdlib.h>


int main(){
    int n,m;  
    printf("Enter the number of blocks: ");
    scanf("%d", &n);

    int blocks[n];
    printf("Enter the size of each block: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &blocks[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &m);

    printf("Enter the %d processes\n",m);
    int process[m];

    for(int j=0 ; j< m ;j++){
        scanf("%d", &process[j]);
    }

    int occupied[n];
    for(int i=0 ; i<n ;i++){
        occupied[i]=0;
    }

    int ans[m];
    for(int j=0 ;j <m ;j++){
        ans[j] =-1;
    }


    for(int j=0 ; j < m ; j++){
        int mini = INT_MAX;
        int index = - 1;

        for(int i=0; i < n; i++){
            int diff = blocks[i] - process[j];
            if(!occupied[i] && process[j] < blocks[i] && mini > diff){
                mini = diff;
                index = i;
            }
        }
        if(index != - 1){
            ans[j] = index +1;
            occupied[index] = 1;
        }
    }

    for (int j = 0; j < m; j++) {
        if (ans[j] == -1)
            printf("%d - No free block allocated\n", process[j]);
        else
            printf("%d - %d\n", process[j], ans[j]);
    }

    return 0;
}