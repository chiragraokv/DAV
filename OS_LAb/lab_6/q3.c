// parent_child_shared_memory.c
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, sizeof(char), 0666 | IPC_CREAT);

    char *shm = (char *)shmat(shmid, NULL, 0);

    pid_t pid = fork();

    if (pid > 0) {
        char ch;
        printf("Enter an English alphabet: ");
        scanf(" %c", &ch);

        *shm = ch;     
        wait(NULL);    

        printf("Reply from child: %c\n", *shm);

        shmdt(shm);
        shmctl(shmid, IPC_RMID, NULL);
    } 
    else {
        sleep(5);      

        char ch = *shm;
        printf("in child");
        if (ch == 'z' || ch == 'Z')
            ch = ch - 25;
        else
            ch = ch + 1;

        *shm = ch;      // Send back to parent
        shmdt(shm);
    }

    return 0;
}
