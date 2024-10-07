#include <stdio.h>
#include <unistd.h>  // Required for fork(), getpid(), and getppid()

int main() {
    // Create a new process
    pid_t pid = fork();  // Using pid_t instead of int
    
    if (pid < 0) {
        // Fork failed
        printf("Fork failed!\n");
        return 1;
    } 
    else if (pid == 0) {
        // Child process
        printf("Child Process:\n");
        printf("PID: %d, Parent PID: %d\n", getpid(), getppid());
    } 
    else {
        // Parent process
        printf("Parent Process:\n");
        printf("PID: %d, Child PID: %d\n", getpid(), pid);
    }
    
    return 0;
}