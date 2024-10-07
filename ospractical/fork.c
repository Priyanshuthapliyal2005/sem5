#include<stdio.h>
// #include<unistd.h>
//required for fork and get pid 


int main(){
    int pid = fork();
    // create a new process

    if(pid<0){
        //fork failed
        printf("fork failed\n");
        return 1;
    }
    else if(pid ==0){
        //child processs
        printf("Hello from the child Process ! : %d \n", getpid());
    }
    else{
        //Parent Process
        printf("Hello from the Parent Process! PID : %d , Child PID : %d\n" , getpid() ,pid);
    }

    return 0 ; 
}