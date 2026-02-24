#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

int arr[] = {64, 25, 12, 22, 11};

void* bubble_sort(void* arg) {
    clock_t start = clock();

    int n = sizeof(arr) / sizeof(arr[0]);
    int *a = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        a[i] = arr[i];

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }

    clock_t end = clock();
    printf("Bubble Sort Time: %lf sec\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    pthread_exit(a);   
}

void* selection_sort(void* arg) {
    clock_t start = clock();

    int n = sizeof(arr) / sizeof(arr[0]);
    int a[n];

    for (int i = 0; i < n; i++)
        a[i] = arr[i];

    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;

        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }

    clock_t end = clock();
    printf("Selection Sort Time: %lf sec\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    pthread_exit(NULL);
}

int main() {
    pthread_t t1, t2;
    int *sorted;

    int n = sizeof(arr) / sizeof(arr[0]);

    pthread_create(&t1, NULL, bubble_sort, NULL);
    pthread_create(&t2, NULL, selection_sort, NULL);

    pthread_join(t1, (void**)&sorted);
    pthread_join(t2, NULL);

    printf("\nFinal Sorted Array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", sorted[i]);
    printf("\n");

    free(sorted);
    return 0;
}

/*
Selection Sort Time: 0.000001 sec
Bubble Sort Time: 0.000062 sec

Final Sorted Array:
11 12 22 25 64 
*/