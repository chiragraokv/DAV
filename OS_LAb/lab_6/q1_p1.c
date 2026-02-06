/*
Write a cpp program to imlimen =t fcfs algo
*/
// sender.c
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg_buffer {
    long msg_type;
    int number;
};

int main() {
    key_t key = ftok("progfile", 65);
    int msgid = msgget(key, 0666 | IPC_CREAT);

    struct msg_buffer msg;
    msg.msg_type = 1;

    printf("Enter a number: ");
    scanf("%d", &msg.number);

    msgsnd(msgid, &msg, sizeof(msg.number), 0);
    printf("Number sent to Process B\n");

    return 0;
}
