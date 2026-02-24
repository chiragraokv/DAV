#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    int arr[4];

    fd = open("myfifo", O_RDONLY);
    read(fd, arr, sizeof(arr));
    close(fd);

    printf("Integers received:\n");
    for (int i = 0; i < 4; i++)
        printf("%d ", arr[i]);

    printf("\n");
    return 0;
}
