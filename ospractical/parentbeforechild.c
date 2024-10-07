#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid1, pid2;
    
    // Create first child process
    pid1 = fork();
    
    if (pid1 < 0) {
        printf("Fork failed!\n");
        return 1;
    } 
    else if (pid1 == 0) {
        // First child process
        printf("Child Process 1 (PID: %d): Listing files...\n", getpid());
        execlp("ls", "ls", "-l", (char *)NULL);  // Replace process with 'ls -l' command
        exit(0);  // This line only executes if execlp fails
    } 
    else {
        // Parent process
        wait(NULL);  // Wait for first child to complete
        printf("Parent Process (PID: %d): First child completed.\n", getpid());
        
        // Create second child process
        pid2 = fork();
        
        if (pid2 < 0) {
            printf("Fork failed!\n");
            return 1;
        } 
        else if (pid2 == 0) {
            // Second child process
            printf("Child Process 2 (PID: %d): I am the second child.\n", getpid());
            sleep(5);  // Sleep for 5 seconds
            printf("Child Process 2 (PID: %d): Work done.\n", getpid());
            exit(0);
        } 
        else {
            // Parent process exits immediately
            printf("Parent Process (PID: %d): Exiting now.\n", getpid());
            exit(0);
        }
    }
}