#include<stdio.h>
#include<stdlib.h>

struct Process{
    int pid;
    int at;
    int bt;
    int ct, st;
    float tat, rt , wt;
};

int compare(const void *p1   , const  void *p2){
    int a = ((struct Process *)p1)->at;
    int b = ((struct Process *)p2)->at;

    int aid= ((struct Process *)p1)->pid;
    int bid= ((struct Process *)p2)->pid;

    //start primarly by arrival time
    if(a<b){
        return -1;
    }

    //if arrival time are equal , sort by process ID
    else if(a==b){
        if(aid <  bid){
            return -1;
        }else{
            return 1;
        }
    }

    else{
        return 1;
    }
}


int main(){
    int n ;
    float swt =0 , stat = 0;
    float cu = 0 , throughput =0 , awt =0 , atat =0;
    int sbt=0;


    printf("Enter the number of processes : ");
    scanf("%d", &n);

    struct Process p[n];

    for(int i=0 ; i<n ; i++){
        printf("For Process %d " , i+1);
        p[i].pid = i+1;
        printf("Enter the value of AT and BT: ");
        scanf("%d %d", &p[i].at , &p[i].bt);
    }

    //sort processes by arrival time 
    qsort((void *)p, n , sizeof(struct Process), compare);

    //calculate timing for each process
    for(int i=0 ; i < n ;i++){

        // for first process
        if(i==0){
            p[i].st = p[i].at;
            p[i].ct = p[i].at + p[i].bt;
        }

        //if there's a gap between processes
        else if ( p[i-1].ct <= p[i].at){
            p[i].st = p[i].at;
            p[i].ct = p[i].at + p[i].bt;
        }

        //if processes are continuous
        else{
            p[i].st = p[i-1].ct;
            p[i].ct = p[i-1].ct + p[i].bt;
        }


        //calculate time for each process
        p[i].rt= p[i].st - p[i].at;  // response time 
        p[i].tat = p[i].ct - p[i].at;  // turn around time 
        p[i].wt = p[i].tat - p[i].bt;   // waiting time 

        sbt += p[i].bt;
        swt += p[i].wt;
        stat += p[i].tat;
    }

    //calculate avgs 
    awt = swt / n;
    atat= stat / n;


    //find maximum completion time
    float max =0 ;
    for( int i =0 ; i < n ; i++){
        if(p[i].ct > max){
            max = p[i].ct;
        }
    }


    //calculate cpu utilization and throughput 
    cu = (sbt/max) * 100; //cpu utilization percentage 
    throughput = n / max; // processes completed per unit time 
    

    //output result

    printf("\nGantt Chart: ");
    for (int i = 0; i < n; i++) {
        printf("P%d ", p[i].pid);
    }
    printf("\n");


    printf("\nPID\tAT\tBT\tST\tCT\tRT\t\tTAT\t\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%f\t%f\t%f\n", 
               p[i].pid, p[i].at, p[i].bt, p[i].st, p[i].ct, 
               p[i].rt, p[i].tat, p[i].wt);
    }

    // Print summary statistics
    printf("\nSum of Turn Around Time: %f\nAverage of Turn Around Time: %f\n", 
           stat, atat);
    printf("Sum of Waiting Time: %f\nAverage of Waiting Time: %f\n"
           "CPU utilization is: %f\nThroughput : %f", 
           swt, awt, cu, throughput);
    
    return 0;



}
