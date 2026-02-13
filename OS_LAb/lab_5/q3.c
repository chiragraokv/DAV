#include <stdio.h>
#include <math.h>

typedef struct {
    int id;
    float execution_time;
    float period;
} Task;

int main() {
    int n;
    float utilization = 0;

    printf("Enter the number of tasks: ");
    scanf("%d", &n);

    Task tasks[n];

    for (int i = 0; i < n; i++) {
        tasks[i].id = i + 1;
        printf("\nTask %d\n", tasks[i].id);
        printf("Enter Execution Time: ");
        scanf("%f", &tasks[i].execution_time);
        printf("Enter Period: ");
        scanf("%f", &tasks[i].period);
        
        utilization += (tasks[i].execution_time / tasks[i].period);
    }

    float bound = n * (pow(2, 1.0/n) - 1);

    printf("total cpu util: %.4f\n", utilization);
    printf("Bound: %.4f\n", bound);

    if (utilization > 1.0) {
        printf("Result: Not schedulable.\n");
    } else if (utilization <= bound) {
        printf("Result: The task set is schedulable\n");
    } else {
        printf("Result: The task set is UNKNOWN ");
    }

    return 0;
}