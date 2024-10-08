#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

struct Process
{
    int pid;  // Process ID
    int at;   // Arrival Time
    int bt;   // Burst Time
    int ct;   // Completion Time
    int st;   // Start Time
    float tat; // Turnaround Time
    float rt;  // Response Time
    float wt;  // Waiting Time
    int rmbt;
} ;
typedef struct Process ps;

int executionOrder[100]; // Array to store the execution order
int orderIndex = 0;      // Index to track execution order

// Utility functions to find max and min
int findMax(int a, int b) {
    return a > b ? a : b;
}

int findMin(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n;

    printf("Enter total number of processes: ");
    scanf("%d", &n);     // Input the number of processes
    
    ps p[n];

    // Input arrival time
    for (int i = 0; i < n; i++) {
        printf("\nEnter Process %d Arrival Time  and bt : ", i + 1);
        scanf("%d", &p[i].at);
        scanf("%d", &p[i].bt);
        p[i].pid = i + 1;  // Assigning Process ID
        p[i].rmbt = p[i].bt;
    }
    
    
    int currT = 0;       // Current time
    int completed = 0;   // Count of completed processes
    
    int isCompleted[n];
    for(int i=0; i< n ;i++){
        isCompleted[i]=0;
    }
    
    
    while(completed < n){
        int idx =-1;
        int minBt = INT_MAX;
        
        for(int i=0 ; i< n ; i++){
            if(p[i].at <= currT && !isCompleted[i]){
                if(p[i].rmbt < minBt){
                    idx = i;
                    minBt= p[i].rmbt;
                }
                else if(p[i].rmbt == p[idx].bt){
                    if(p[i].at < p[idx].at){
                        idx =i;
                    }
                }
            }
        }
        
        if(idx == -1){
            currT++;
        }
        else{
            if(p[idx].rmbt == p[idx].bt){
                p[idx].st = currT;
            }
            
            p[idx]. rmbt --;
            currT++;

            executionOrder[orderIndex++]=p[idx].pid;
            
            if(p[idx].rmbt==0){
                completed++;
                isCompleted[idx]=1;
                
                p[idx].ct = currT;
                p[idx].tat = p[idx].ct - p[idx].at;
                p[idx].rt = p[idx].st - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;
                
            }
            

        }
    }
     printf("\nProcess No.\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t%d\t%d\t%.2f\t%.2f\t%.2f\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt, p[i].rt);
    }

    printf("\nExecution order of processes:\n");
    for (int i = 0; i < orderIndex; i++) {
        printf("P%d ", executionOrder[i]);
    }
    printf("\n");

    
    
}
    
    
    
    
    