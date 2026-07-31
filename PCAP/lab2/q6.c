// Implement a parallel program using OpenMP to perform vector addition, subtraction and multiplication.
// Demonstrate task level parallelism. Analyse the speedup and efficiency of the parallelized code.


#include <stdio.h>
#include <omp.h>

#define N 1000000

int a[N], b[N], add[N], sub[N], mul[N];

int main() {
    printf("Name: Chirag Rao KV\n");
    printf("REG: 240962180\n");
    double t1,t2;
    for(int i=0;i<N;i++){
        a[i]=i;
        b[i]=i*2;
    }
    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp task
            {
                t1=omp_get_wtime();
                for(int i=0;i<N;i++)
                    add[i]=a[i]+b[i];
                t2=omp_get_wtime();
                printf("Addition time: %f sec\n", t2-t1);
            }
            #pragma omp task
            {
                t1=omp_get_wtime();
                for(int i=0;i<N;i++)
                    sub[i]=a[i]-b[i];
                t2=omp_get_wtime();
                printf("Subtraction time: %f sec\n", t2-t1);
            }
            #pragma omp task
            {
                t1=omp_get_wtime();
                for(int i=0;i<N;i++)
                    mul[i]=a[i]*b[i];
                t2=omp_get_wtime();
                printf("Multiplication time: %f sec\n", t2-t1);
            }
        }
    }

    return 0;
}