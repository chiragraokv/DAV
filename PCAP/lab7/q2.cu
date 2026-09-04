// Given two vectors of length N, implement a program in CUDA that launches 
// two kernel to do the following tasks 
// a. Add two vectors (kernel execution configuration: block size as N)
// b. Dot product of two vectors (kernel execution configuration: N threads)

#include <stdio.h>
#define N 4

__global__ void add(float *a, float *b, float *c) {
    int i = threadIdx.x;
    c[i] = a[i] + b[i];
}

__global__ void dot(float *a, float *b, float *res) {
    __shared__ float s[N];
    int i = threadIdx.x;
    s[i] = a[i] * b[i];
    __syncthreads();
    for (int stride = N / 2; stride > 0; stride >>= 1) {
        if (i < stride) s[i] += s[i + stride];
        __syncthreads();
    }
    if (i == 0) *res = s[0];
}

int main() {
    float h_a[N] = {1, 2, 3, 4}, h_b[N] = {1, 1, 1, 1}, h_c[N], h_res;
    float *d_a, *d_b, *d_c, *d_res;
    printf("Chirag Rao KV\n240962180\n\n");
    cudaMalloc(&d_a, sizeof(h_a)); cudaMalloc(&d_b, sizeof(h_b));
    cudaMalloc(&d_c, sizeof(h_c)); cudaMalloc(&d_res, sizeof(float));

    cudaMemcpy(d_a, h_a, sizeof(h_a), cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, h_b, sizeof(h_b), cudaMemcpyHostToDevice);

    add<<<1, N>>>(d_a, d_b, d_c);
    dot<<<1, N>>>(d_a, d_b, d_res);

    cudaMemcpy(h_c, d_c, sizeof(h_c), cudaMemcpyDeviceToHost);
    cudaMemcpy(&h_res, d_res, sizeof(float), cudaMemcpyDeviceToHost);

    printf("Add[0]: %.0f | Dot: %.0f\n", h_c[0], h_res);

    cudaFree(d_a); cudaFree(d_b); cudaFree(d_c); cudaFree(d_res);
}