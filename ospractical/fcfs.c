#include<stdio.h>
#include<stdlib.h>

struct Process {
    int pid, st ,rt ,at, bt, ct, tat, wt;
};

typedef struct Process pro;

int compare(const void* p1 , const void* p2) {
    pro *a = (pro*) p1;
    pro *b = (pro*) p2;
    
    if (a->at > b->at) {
        return 1;
    } else if (a->at < b->at) {
        return -1;
    }
    
    return (a->pid < b->pid) ? -1 : 1;
}

int main() {
    int n;
    float totalWT = 0, totalTAT = 0;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    pro p[n];
    
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter arrival time and burst time for process %d: ", p[i].pid);
        scanf("%d %d", &p[i].at, &p[i].bt);
    }
    
    
    qsort(p, n, sizeof(pro), compare);
    
    int currTime = 0;
    
    for (int i = 0; i < n; i++) {
        if (p[i].at > currTime) {
            currTime = p[i].at;
        }
        
        p[i].st = currTime;
        p[i].ct = currTime + p[i].bt;
        
        currTime += p[i].bt;
        
        p[i].tat = p[i].ct - p[i].at;  
        p[i].wt = p[i].tat - p[i].bt;  
        p[i].rt = p[i].st - p[i].at;   
    }

    int sbt = 0;  
    
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", 
               p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);

        sbt += p[i].bt;
    }

    float maxiCt = -1;
    for (int i = 0; i < n; i++) {
        if (p[i].ct > maxiCt) {
            maxiCt = p[i].ct;
        }
    }

    
    printf("\nCPU Utilization: %.2f%%", ((float)sbt / maxiCt) * 100);
    printf("\nThroughput: %.2f processes/unit time\n", (float)n / maxiCt);
    
    return 0;
}
