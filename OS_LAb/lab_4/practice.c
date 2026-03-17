#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

void * thread_function_0(void * args){
    printf("inside first function");
    pthread_exit(0);
}

void * thread_function_1(void* args){
    printf("this is function second");
    pthread_exit(0);
}

void main(){
    pthread_t t,t1;

    pthread_create(&t,NULL,thread_function_0,NULL);
    pthread_create(&t1,NULL,thread_function_1,NULL);
    pthread_join(t1,NULL);
    printf("IN main");
    return 0;

}