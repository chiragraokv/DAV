#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to find least recently used page
int findLRU(int *time, int frames) {
    int min = time[0], pos = 0;

    for (int i = 1; i < frames; i++) {
        if (time[i] < min) {
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

// Check if page is present
bool isPresent(int *frame, int frames, int page, int *index) {
    for (int i = 0; i < frames; i++) {
        if (frame[i] == page) {
            *index = i;
            return true;
        }
    }
    return false;
}

int main() {
    // 🔹 Hardcoded Input
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4};
    int n = sizeof(pages) / sizeof(pages[0]);
    int frames = 3;

    int *frame = (int *)malloc(frames * sizeof(int));
    int *time = (int *)malloc(frames * sizeof(int));

    int faults = 0, counter = 0;

    // Initialize frames
    for (int i = 0; i < frames; i++) {
        frame[i] = -1;
        time[i] = 0;
    }

    printf("Page Reference String: ");
    for (int i = 0; i < n; i++)
        printf("%d ", pages[i]);

    printf("\nNumber of Frames: %d\n", frames);

    printf("\nLRU Page Replacement:\n");

    for (int i = 0; i < n; i++) {
        int index;

        if (isPresent(frame, frames, pages[i], &index)) {
            // HIT
            counter++;
            time[index] = counter;
        } else {
            // FAULT
            int pos = findLRU(time, frames);
            frame[pos] = pages[i];

            counter++;
            time[pos] = counter;
            faults++;
        }

        printf("After page %d: ", pages[i]);
        for (int j = 0; j < frames; j++)
            printf("%d ", frame[j]);
        printf("\n");
    }

    float hitRatio = (float)(n - faults) / n;

    printf("\nTotal Page Faults: %d\n", faults);
    printf("Hit Ratio: %.2f\n", hitRatio);

    free(frame);
    free(time);

    return 0;
}