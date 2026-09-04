#include "device_launch_parameters.h"
#include <stdio.h>
#include <cuda_runtime.h>

__global__ void add(int *a,int *b,int* c){
    *c = *a + *b;
}

int main(void){
    int a,b,c;
    int *d_a,*d_b,*d_c;
    int size = sizeof(int);

    // allocate for device copies of a,b,c
    cudaMalloc((void**)&d_a, size);
    cudaMalloc((void**)&d_b,size);
    cudaMalloc((void**)&d_c,size);
    a = 3;
    b = 5;
    // copy inputs to device 
    cudaMemcpy(d_a,&a,size,cudaMemcpyHostToDevice);
    cudaMemcpy(d_b,&b,size, cudaMemcpyHostToDevice);
    add<<<1,1>>>(d_a,d_b,d_c);
    cudaMemcpy(&c,d_c,size,cudaMemcpyDeviceToHost);
    printf("Chrag Rao K V\n240962180\n\n");
    printf("Result: %d\n",c);
    // cleanup
    cudaFree(d_a);
    cudaFree(d_c);
    cudaFree(d_b);
    return 0;
}