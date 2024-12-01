
#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>

int main(){ 
    printf("Priyanshu Thapliyal\t SECTION-A2\t Roll no: 20\n");

    key_t key;
    int shmid;
    void *ptr;

    key = ftok("srfile", 'A');
    shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    ptr = shmat(shmid, (void *)0, 0);
    printf("\nThe Data stored: %s\n", (char *)ptr);
    shmdt(ptr);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
