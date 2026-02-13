#include <stdio.h>

int main() {
    int n;

    printf("Enter number of processes: ");
    if (scanf("%d", &n) != 1) return 1;

    int burst[n], waiting[n], turnaround[n];

    printf("Enter burst times:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &burst[i]);
    }

    waiting[0] = 0; // First process doesn't wait
    for (int i = 1; i < n; i++) {
        waiting[i] = waiting[i - 1] + burst[i - 1];
    }

    for (int i = 0; i < n; i++) {
        turnaround[i] = waiting[i] + burst[i];
    }

    printf("\nProcess\tBurst\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", 
                i + 1, burst[i], waiting[i], turnaround[i]);
    }

    return 0;
}