#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if page exists in frame
bool isPresent(int *frames, int frameCount, int page) {
    for (int i = 0; i < frameCount; i++) {
        if (frames[i] == page)
            return true;
    }
    return false;
}

// FIFO Algorithm
void FIFO(int *pages, int n, int frameCount) {
    int *frames = (int *)malloc(frameCount * sizeof(int));
    int front = 0, faults = 0;

    for (int i = 0; i < frameCount; i++)
        frames[i] = -1;

    printf("\nFIFO Page Replacement:\n");

    for (int i = 0; i < n; i++) {
        if (!isPresent(frames, frameCount, pages[i])) {
            frames[front] = pages[i];
            front = (front + 1) % frameCount;
            faults++;
        }

        printf("After page %d: ", pages[i]);
        for (int j = 0; j < frameCount; j++)
            printf("%d ", frames[j]);
        printf("\n");
    }

    printf("Total Page Faults (FIFO): %d\n", faults);
    free(frames);
}

// Optimal Algorithm
void Optimal(int *pages, int n, int frameCount) {
    int *frames = (int *)malloc(frameCount * sizeof(int));
    int faults = 0;

    for (int i = 0; i < frameCount; i++)
        frames[i] = -1;

    printf("\nOptimal Page Replacement:\n");

    for (int i = 0; i < n; i++) {
        if (!isPresent(frames, frameCount, pages[i])) {
            int index = -1, farthest = i;

            for (int j = 0; j < frameCount; j++) {
                int k;
                for (k = i + 1; k < n; k++) {
                    if (frames[j] == pages[k])
                        break;
                }

                if (k > farthest) {
                    farthest = k;
                    index = j;
                }
            }

            // If empty frame exists
            if (index == -1) {
                for (int j = 0; j < frameCount; j++) {
                    if (frames[j] == -1) {
                        index = j;
                        break;
                    }
                }
            }

            frames[index] = pages[i];
            faults++;
        }

        printf("After page %d: ", pages[i]);
        for (int j = 0; j < frameCount; j++)
            printf("%d ", frames[j]);
        printf("\n");
    }

    printf("Total Page Faults (Optimal): %d\n", faults);
    free(frames);
}

int main() {
    // 🔹 Hardcoded Input
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4};
    int n = sizeof(pages) / sizeof(pages[0]);
    int frameCount = 3;

    printf("Page Reference String: ");
    for (int i = 0; i < n; i++)
        printf("%d ", pages[i]);

    printf("\nNumber of Frames: %d\n", frameCount);

    FIFO(pages, n, frameCount);
    Optimal(pages, n, frameCount);

    return 0;
}