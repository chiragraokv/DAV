#include<omp.h>
#include<stdio.h>

int main(){
    int num;
    #pragma omp parallel
    {
    num = omp_get_num_procs();
    printf("cores: %d\n",num);

    int thread_id = omp_get_thread_num();

    #pragma omp simgle
    {
        printf("Number of threads: %d", num);
    }
    printf("Hello from thread %d ",thread_id);
}

}   