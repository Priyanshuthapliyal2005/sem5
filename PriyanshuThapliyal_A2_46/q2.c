#include <stdio.h>
#include <unistd.h>
int main()
{
    pid_t pid = fork();
    if (pid < 0)
    {
        printf("Fork failed!\n");
        return 1;
    }
    else if (pid == 0)
    {
        printf("Child Process:\n");
        printf("PID: %d, Parent PID: %d\n", getpid(), getppid());
    }
    else
    {
        printf("Parent Process:\n");
        printf("PID: %d, Child PID: %d\n", getpid(), pid);
    }
    return 0;
}
