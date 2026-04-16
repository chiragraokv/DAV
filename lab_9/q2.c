#include <stdio.h>

int main() {
    int pageSize = 32;
    int addresses[] = {204, 56};

    for (int i = 0; i < 2; i++) {
        int addr = addresses[i];
        int pageNumber = addr / pageSize;
        int offset = addr % pageSize;

        printf("Address: %d -> Page: %d, Offset: %d\n",
               addr, pageNumber, offset);
    }

    return 0;
}