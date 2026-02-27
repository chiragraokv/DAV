#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex;
sem_t consumed;
sem_t limit;

int item = 0;

void* producer(void* arg) {
    while(1) {
        sem_wait(&limit);      
        sem_wait(&mutex);

        item++;
        printf("Produced: %d\n", item);

        sem_post(&mutex);
        sem_post(&consumed);   
        sleep(1);
    }
}

void* consumer(void* arg) {
    while(1) {
        sem_wait(&consumed);   // Wait for item
        sem_wait(&mutex);

        printf("Consumed: %d\n", item);

        sem_post(&mutex);
        sem_post(&limit);     

        sleep(2);
    }
}

int main() {
    pthread_t p, c;

    sem_init(&mutex, 0, 1);
    sem_init(&consumed, 0, 0);
    sem_init(&limit, 0, 10);   
    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

    return 0;
}









