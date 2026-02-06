// consumer.c
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    key_t key = ftok("shmfile", 75);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    char *shm = (char *)shmat(shmid, NULL, 0);

    printf("Data read from shared memory:\n%s\n", shm);

    shmdt(shm);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
