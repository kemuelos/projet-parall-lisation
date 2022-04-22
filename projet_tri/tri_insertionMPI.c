#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>
#include "header.h"

int main(int argc, char **argv)
{
    int TAILLE = 1000000;
    int *tab = malloc(TAILLE * sizeof(int));
    int count;
    srand(time(NULL));

    for (count = 0; count < TAILLE; count++)
    {
        tab[count] = rand() % TAILLE;
    }

    int rank;
    int size;
    double start, end;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int size_local = TAILLE / size;
    int *tab_local = malloc(size_local * sizeof(int));

    if(rank == 0)
    {
        start = MPI_Wtime();
    }
    MPI_Scatter(tab, size_local, MPI_INT, tab_local, size_local, MPI_INT, 0, MPI_COMM_WORLD);
    
    tri_insertion(tab_local, size_local);
    printf("process %d \n", rank);

    MPI_Gather(tab_local, size_local, MPI_INT, tab, size_local, MPI_INT, 0, MPI_COMM_WORLD);
    end = MPI_Wtime();
    
    if (rank == 0)
    {
        tri_insertion(tab, TAILLE);
        printf("Temps d'execution : %f \n", end - start);
    }

    MPI_Finalize();

    return 0;
}