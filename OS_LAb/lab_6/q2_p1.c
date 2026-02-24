#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    int fd;
    int arr[4];

    // Create FIFO
    mkfifo("myfifo", 0666);

    printf("Enter 4 integers:\n");
    for (int i = 0; i < 4; i++)
        scanf("%d", &arr[i]);

    fd = open("myfifo", O_WRONLY);
    write(fd, arr, sizeof(arr));
    close(fd);

    return 0;
}
