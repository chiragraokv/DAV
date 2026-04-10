#include <stdio.h>
#include <stdlib.h>

// Function for FCFS
int FCFS(int req[], int n, int head) {
    int seek = 0;
    for (int i = 0; i < n; i++) {
        seek += abs(req[i] - head);
        head = req[i];
    }
    return seek;
}

// Function for SSTF
int SSTF(int req[], int n, int head) {
    int seek = 0, visited[100] = {0};

    for (int i = 0; i < n; i++) {
        int min = 9999, index = -1;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && abs(req[j] - head) < min) {
                min = abs(req[j] - head);
                index = j;
            }
        }

        seek += min;
        head = req[index];
        visited[index] = 1;
    }
    return seek;
}

// Function for SCAN
int SCAN(int req[], int n, int head, int disk_size) {
    int seek = 0, temp[100], i, j;

    // Copy requests
    for (i = 0; i < n; i++)
        temp[i] = req[i];

    // Sort requests
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (temp[i] > temp[j]) {
                int t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }

    int pos;
    for (i = 0; i < n; i++) {
        if (temp[i] >= head) {
            pos = i;
            break;
        }
    }

    // Move right
    for (i = pos; i < n; i++) {
        seek += abs(temp[i] - head);
        head = temp[i];
    }

    // Move to end
    seek += abs((disk_size - 1) - head);
    head = disk_size - 1;

    // Move left
    for (i = pos - 1; i >= 0; i--) {
        seek += abs(temp[i] - head);
        head = temp[i];
    }

    return seek;
}

// Function for C-SCAN
int CSCAN(int req[], int n, int head, int disk_size) {
    int seek = 0, temp[100], i, j;

    // Copy requests
    for (i = 0; i < n; i++)
        temp[i] = req[i];

    // Sort requests
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (temp[i] > temp[j]) {
                int t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }

    int pos;
    for (i = 0; i < n; i++) {
        if (temp[i] >= head) {
            pos = i;
            break;
        }
    }

    // Move right
    for (i = pos; i < n; i++) {
        seek += abs(temp[i] - head);
        head = temp[i];
    }

    // Move to end
    seek += abs((disk_size - 1) - head);

    // Jump to start
    seek += (disk_size - 1);
    head = 0;

    // Continue from start
    for (i = 0; i < pos; i++) {
        seek += abs(temp[i] - head);
        head = temp[i];
    }

    return seek;
}

// Main Function
int main() {
    int req[100], n, head, disk_size;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request sequence:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &disk_size);

    printf("\nTotal Seek Operations:\n");
    printf("FCFS  = %d\n", FCFS(req, n, head));
    printf("SSTF  = %d\n", SSTF(req, n, head));
    printf("SCAN  = %d\n", SCAN(req, n, head, disk_size));
    printf("C-SCAN= %d\n", CSCAN(req, n, head, disk_size));

    return 0;
}