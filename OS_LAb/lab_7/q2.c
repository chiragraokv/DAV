#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex, wrt;
int readcount = 0;
int data = 0;   // shared resource

void* reader(void* arg) {
    int id = *((int*)arg);

    while(1) {
        sem_wait(&mutex);
        readcount++;

        if(readcount == 1)
            sem_wait(&wrt);   // First reader blocks writers

        sem_post(&mutex);

        // Reading Section
        printf("Reader %d is reading data = %d\n", id, data);
        sleep(1);

        sem_wait(&mutex);
        readcount--;

        if(readcount == 0)
            sem_post(&wrt);   // Last reader releases writer

        sem_post(&mutex);

        sleep(1);
    }
}

void* writer(void* arg) {
    int id = *((int*)arg);

    while(1) {
        sem_wait(&wrt);

        // Writing Section
        data++;
        printf("Writer %d is writing data = %d\n", id, data);
        sleep(2);

        sem_post(&wrt);

        sleep(2);
    }
}

int main() {
    pthread_t r[5], w[2];
    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);

    int i, id[5];

    // Create Reader Threads
    for(i = 0; i < 5; i++) {
        id[i] = i+1;
        pthread_create(&r[i], NULL, reader, &id[i]);
    }

    // Create Writer Threads
    for(i = 0; i < 2; i++) {
        id[i] = i+1;
        pthread_create(&w[i], NULL, writer, &id[i]);
    }

    for(i = 0; i < 5; i++)
        pthread_join(r[i], NULL);

    for(i = 0; i < 2; i++)
        pthread_join(w[i], NULL);

    return 0;
}