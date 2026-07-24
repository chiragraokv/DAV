#include<stdio.h>
#include<omp.h>
int main()
{
#pragma omp parallel
{
    int op = omp_get_thread_num();
    printf("Hello OpenMP! form %d\n",op);
}
return 0;
}