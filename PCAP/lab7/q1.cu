// Implement CUDA program to determine the number of CUDA capable devices in the system.
// For each device, examine the following device's properties:
// a. Device name
// b. Number of Streaming Multiprocessors
// c. Maximum number of threads per block
// d. Maximum thread dimensions (x,y,z)
// e. Maximum grid dimensions (x,y,z)
// f. The device clock frequency

#include <stdio.h>
#include <cuda_runtime.h>

#include <stdio.h>
#include <cuda_runtime.h>

int main() {
    int count;
    if (cudaGetDeviceCount(&count) != cudaSuccess || count == 0) {
        printf("No CUDA devices found.\n");
        return 0;
    }

    for (int i = 0; i < count; i++) {
        cudaDeviceProp p;
        printf("Chirag Rao KV\n240962180\n\n");
        cudaGetDeviceProperties(&p, i);
        printf("Device %d: %s\n", i, p.name);
        printf("  a. SMs: %d\n", p.multiProcessorCount);
        printf("  b. Max threads/block: %d\n", p.maxThreadsPerBlock);
        printf("  c. Thread dims: (%d, %d, %d)\n", p.maxThreadsDim[0], p.maxThreadsDim[1], p.maxThreadsDim[2]);
        printf("  d. Grid dims: (%d, %d, %d)\n", p.maxGridSize[0], p.maxGridSize[1], p.maxGridSize[2]);
        printf("  e. Clock freq: %.1f MHz\n", p.clockRate / 1000.0);
    }
    return 0;
}