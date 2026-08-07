// Imnplement an OpenMp program using C to determin the number of prime numbers within a given range( 1 to N) using the parallel for directive. Since checking weather a number is prime requires a varying of computation depending on the number being tested, this problem exhibits an imbalanced workload across loop iterations. 
// Execute the program seperately using the following OpenMP scheduling policies:
// static
// dynamic 
// guided
// for chace scheduling policy
// Record the thread ID responsible for processing each number
// Measure the execution time using omp_get_wtime().
// Ovserve how loop iterations are distributed among the threads
// compare the load balancing and execution time obtained with each scheduling policy.

#include <stdio.h>
#include <omp.h>

int prime(int n){
    if(n<2) return 0;
    for(int i=2;i*i<=n;i++) if(n%i==0) return 0;
    return 1;
}

int main(){
    int N=300000000,c=0;

    double t=omp_get_wtime();

    #pragma omp parallel for schedule(static) reduction(+:c)
    // Replace static with: dynamic, guided
    for(int i=1;i<=N;i++){
        printf("%2d -> T%d\n",i,omp_get_thread_num());
        if(prime(i)) c++;
    }

    t=omp_get_wtime()-t;
    printf("Primes=%d Time=%f\n",c,t);
    return 0;
}