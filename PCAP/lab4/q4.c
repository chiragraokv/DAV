// Implement a MPI program using synchronoys send. The process sends a word to the reciever
// The second process recieves the word, toggles each letter of the word and sends it back to the first process.
// Both process use synchronous send operations.
#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    int r; 
    char s[10] = "Hello";
    
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &r);
    
    if (!r) {
        printf("r-0 About to send '%s' to r-1\n", s);
        MPI_Ssend(s, 6, MPI_CHAR, 1, 0, MPI_COMM_WORLD);
        
        MPI_Recv(s, 6, MPI_CHAR, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("r-0 Received back: %s\n", s);
    } else if (r == 1) {
        printf("r-1 Waiting to receive from r-0\n");
        MPI_Recv(s, 6, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        
        for (int i = 0; s[i]; i++) s[i] ^= 32;
        
        printf("r-1 Sending toggled '%s' back to r-0\n", s);
        MPI_Ssend(s, 6, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
    }
    
    MPI_Finalize();
}