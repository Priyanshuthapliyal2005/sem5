#include <stdio.h>
#include <unistd.h>
int main()
{
    execlp("ls", "ls", NULL);
    perror("execlp terminated!");
    return 1;
}
