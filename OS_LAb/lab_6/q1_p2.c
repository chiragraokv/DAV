// receiver.c
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg_buffer {
    long msg_type;
    int number;
};

int isPalindrome(int n) {
    int rev = 0, temp = n;
    while (temp > 0) {
        rev = rev * 10 + temp % 10;
        temp /= 10;
    }
    return (rev == n);
}

int main() {
    key_t key = ftok("progfile", 65);
    int msgid = msgget(key, 0666 | IPC_CREAT);

    struct msg_buffer msg;
    msgrcv(msgid, &msg, sizeof(msg.number), 1, 0);

    if (isPalindrome(msg.number))
        printf("Number %d is a palindrome\n", msg.number);
    else
        printf("Number %d is not a palindrome\n", msg.number);

    msgctl(msgid, IPC_RMID, NULL); // delete queue
    return 0;
}
