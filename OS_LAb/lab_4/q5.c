#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int *fib;     
int n;        

void* generate_fibonacci(void* arg) {
    if (n <= 0)
        pthread_exit(NULL);

    fib[0] = 0;
    if (n > 1)
        fib[1] = 1;

    for (int i = 2; i < n; i++)
        fib[i] = fib[i - 1] + fib[i - 2];

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    n = atoi(argv[1]);
    if (n <= 0) {
        printf("Please enter a positive number\n");
        return 1;
    }

    fib = malloc(n * sizeof(int));

    pthread_t tid;
    pthread_create(&tid, NULL, generate_fibonacci, NULL);

    pthread_join(tid, NULL);

    printf("Fibonacci Series:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", fib[i]);
    printf("\n");

    free(fib);
    return 0;
}
/*
Fibonacci Series:
0 1 1 2 3 5 
*/
