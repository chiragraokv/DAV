#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>


int main() {
    pid_t pid = fork();

    if (pid == 0) {
        execl("./q1", "q1", NULL);
        perror("exec failed");
    }
    else {
        printf("Parent waiting...\n");
        wait(NULL);
    }

    return 0;
}

/*
Parent waiting...
Parent Process:
PID = 618547
Child PID = 618548
Child Process:
PID = 618548
PPID = 618547
Child process completed
*/