#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    key_t key = ftok("shmfile", 75);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    char *shm = (char *)shmat(shmid, NULL, 0);

    printf("Enter words (end with 'end'):\n");
    fgets(shm, 1024, stdin);

    printf("Data written to shared memory.\n");

    shmdt(shm);
    return 0;
}
