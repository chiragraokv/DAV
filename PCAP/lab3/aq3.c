// Implement an OpenMP program to compute the factorial of N numbers using:
// Critical section 
// Atomic 
// Reduction 
// Master
// Locks
// Compare the execution time for each construct.
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 10000000

int main() {
    printf("Name: Chirag Rao KV\n");
    printf("REG: 240962180\n");
    double t, p;
    int th = omp_get_max_threads();
    double *lp = malloc(th * sizeof(double));
    omp_lock_t lck; omp_init_lock(&lck);

    p = 1.0; t = omp_get_wtime();
    #pragma omp parallel for reduction(*:p)
    for(long i=0; i<N; i++) p *= 1.0000001;
    double tr = omp_get_wtime() - t;

    p = 1.0; t = omp_get_wtime();
    #pragma omp parallel for
    for(long i=0; i<N; i++) {
        #pragma omp atomic
        p *= 1.0000001;
    }
    double ta = omp_get_wtime() - t;

    p = 1.0; t = omp_get_wtime();
    #pragma omp parallel for
    for(long i=0; i<N; i++) {
        #pragma omp critical
        p *= 1.0000001;
    }
    double tc = omp_get_wtime() - t;

    t = omp_get_wtime();
    #pragma omp parallel
    {
        double loc = 1.0;
        #pragma omp for
        for(long i=0; i<N; i++) loc *= 1.0000001;
        lp[omp_get_thread_num()] = loc;
        #pragma omp barrier
        #pragma omp master
        { p = 1.0; for(int i=0; i<th; i++) p *= lp[i]; }
    }
    double tm = omp_get_wtime() - t;

    p = 1.0; t = omp_get_wtime();
    #pragma omp parallel for
    for(long i=0; i<N; i++) {
        omp_set_lock(&lck); p *= 1.0000001; omp_unset_lock(&lck);
    }
    double tl = omp_get_wtime() - t;

    printf("Red: %.4fs \n Atm: %.4fs \n Crt: %.4fs \n Mst: %.4fs \n Lck: %.4fs\n", tr, ta, tc, tm, tl);

    omp_destroy_lock(&lck); free(lp);
    return 0;
}