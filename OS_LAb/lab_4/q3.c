#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child exiting...\n");
        exit(0);
    }
    else {
        printf("Parent sleeping...\n");
        sleep(30);
    }

    return 0;
}
/*
[1] 619902
Parent sleeping...
Child exiting...
*/