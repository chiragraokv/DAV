#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    }
    else if (pid == 0) {
        printf("Child Process:\n");
        printf("PID = %d\n", getpid());
        printf("PPID = %d\n", getppid());
    }
    else {
        printf("Parent Process:\n");
        printf("PID = %d\n", getpid());
        printf("Child PID = %d\n", pid);

        wait(NULL);
        printf("Child process completed\n");
    }

    return 0;
}

/*
Parent Process:
PID = 617701
Child PID = 617702
Child Process:
PID = 617702
PPID = 617701
Child process completed
*/