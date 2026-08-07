// Implement a multithread tokenizer using OpenMP. Assign the lines of text file to threads in a round robin fashion Each thread should printf
// Thread ID
// Tokens extracted from its assigned lines
#include <stdio.h>
#include <string.h>
#include <omp.h>

int main() {
    printf("Name: Chirag Rao KV\n");
    printf("REG: 240962180\n");
    char *line[] = {
        "This is line one",
        "The is the second line to tokenize",
        "third line to get tokenized",
        "last line to get tokenized"
    };
    int n = 4;

    #pragma omp parallel for schedule(static,1)
    for (int i = 0; i < n; i++) {
        char s[100];
        strcpy(s, line[i]);

        #pragma omp critical
        {
            printf("T%d:\n", omp_get_thread_num());
            char *t = strtok(s, " ");
            while (t) {
                printf("%s\n", t);
                t = strtok(NULL, " ");
            }
        }
    }
    return 0;
}