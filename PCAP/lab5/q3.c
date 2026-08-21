// Impelement a MPI program to read a string. Using N processes ( string
//  length is evenly divisible by N), find the number of non vowels in the string. 
// In the root process print the number of non vowels found by each processes 
// and print the total number of vowels.
#include <stdio.h>
#include <string.h>
#include <mpi.h>

int is_vowel(char c) {
    char lower = (c >= 'A' && c <= 'Z') ? c + 32 : c;
    return (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u');
}

int main(int argc, char** argv) {
    int r, size, local_non_vowels = 0;
    char str[] = "PROGRAMMING";

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &r);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int local_len = strlen(str) / size;
    char local_str[local_len + 1];
    MPI_Scatter(str, local_len, MPI_CHAR, local_str, local_len, MPI_CHAR, 0, MPI_COMM_WORLD);
    local_str[local_len] = '\0';
    for (int i = 0; i < local_len; i++) {
        if (!is_vowel(local_str[i])) local_non_vowels++;
    }
    int counts[size];
    MPI_Gather(&local_non_vowels, 1, MPI_INT, counts, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (r == 0) {
        printf("Chirag Rao KV\n");
        printf("240962180\n");
        printf("%s\n",str);
        int total_non_vowels = 0;
        for (int i = 0; i < size; i++) {
            printf("Process %d non-vowels: %d\n", i, counts[i]);
            total_non_vowels += counts[i];
        }
        printf("Total vowels: %d\n", (int)strlen(str) - total_non_vowels);
    }

    MPI_Finalize();
    return 0;
}