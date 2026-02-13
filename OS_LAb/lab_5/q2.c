#include <stdio.h>
#include <stdbool.h>

struct Process {
    int id;
    int arrival;
    int burst;
    int waiting;
    int turnaround;
    bool completed;
};

int main() {
    int n, completed_count = 0, current_time = 0;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("P%d Arrival Time: ", i + 1);
        scanf("%d", &p[i].arrival);
        printf("P%d Burst Time: ", i + 1);
        scanf("%d", &p[i].burst);
        p[i].completed = false;
    }

    printf("\nGantt Chart: ");

    while (completed_count < n) {
        int idx = -1;
        int min_burst = 1e9; 
        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= current_time && !p[i].completed) {
                if (p[i].burst < min_burst) {
                    min_burst = p[i].burst;
                    idx = i;
                }
                if (p[i].burst == min_burst) {
                    if (idx != -1 && p[i].arrival < p[idx].arrival) {
                        idx = i;
                    }
                }
            }
        }

        if (idx != -1) {
            // Process the shortest job
            printf("| P%d ", p[idx].id);
            p[idx].waiting = current_time - p[idx].arrival;
            current_time += p[idx].burst;
            p[idx].turnaround = p[idx].waiting + p[idx].burst;
            p[idx].completed = true;
            completed_count++;
        } else {
            // CPU is idle if no process has arrived yet
            current_time++;
        }
    }
    printf("|\n");

    printf("\nID\tArrival\tBurst\tWaiting\tTurnaround\n");
    float total_wait = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wait += p[i].waiting;
        total_tat += p[i].turnaround;
        printf("P%d\t%d\t%d\t%d\t%d\n", 
                p[i].id, p[i].arrival, p[i].burst, p[i].waiting, p[i].turnaround);
    }

    printf("\nAverage Waiting Time: %.2f", total_wait / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_tat / n);

    return 0;
}