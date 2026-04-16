#include <stdio.h>
#include <stdlib.h>

void firstFit(int blocks[], int m, int processes[], int n) {
    int *allocation = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (blocks[j] >= processes[i]) {
                allocation[i] = j;
                blocks[j] -= processes[i];
                break;
            }
        }
    }

    printf("\nFirst Fit Allocation:\n");
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1)
            printf("Process %d (%dK) -> Block %d\n", i + 1, processes[i], allocation[i] + 1);
        else
            printf("Process %d (%dK) -> Not Allocated\n", i + 1, processes[i]);
    }

    free(allocation);
}

void bestFit(int blocks[], int m, int processes[], int n) {
    int *allocation = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++) {
        int bestIdx = -1;

        for (int j = 0; j < m; j++) {
            if (blocks[j] >= processes[i]) {
                if (bestIdx == -1 || blocks[j] < blocks[bestIdx])
                    bestIdx = j;
            }
        }

        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blocks[bestIdx] -= processes[i];
        }
    }

    printf("\nBest Fit Allocation:\n");
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1)
            printf("Process %d (%dK) -> Block %d\n", i + 1, processes[i], allocation[i] + 1);
        else
            printf("Process %d (%dK) -> Not Allocated\n", i + 1, processes[i]);
    }

    free(allocation);
}

void worstFit(int blocks[], int m, int processes[], int n) {
    int *allocation = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++) {
        int worstIdx = -1;

        for (int j = 0; j < m; j++) {
            if (blocks[j] >= processes[i]) {
                if (worstIdx == -1 || blocks[j] > blocks[worstIdx])
                    worstIdx = j;
            }
        }

        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blocks[worstIdx] -= processes[i];
        }
    }

    printf("\nWorst Fit Allocation:\n");
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1)
            printf("Process %d (%dK) -> Block %d\n", i + 1, processes[i], allocation[i] + 1);
        else
            printf("Process %d (%dK) -> Not Allocated\n", i + 1, processes[i]);
    }

    free(allocation);
}

int main() {
    int m = 5, n = 4;

    int blocks1[] = {100, 500, 200, 300, 600};
    int blocks2[] = {100, 500, 200, 300, 600};
    int blocks3[] = {100, 500, 200, 300, 600};

    int processes[] = {212, 417, 112, 426};

    firstFit(blocks1, m, processes, n);
    bestFit(blocks2, m, processes, n);
    worstFit(blocks3, m, processes, n);

    return 0;
}