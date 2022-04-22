#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

int main(int argc, char **argv)
{
    int TAILLE = 900000;
    int *tab = malloc(TAILLE * sizeof(int));
    int count;
    double timer = time(NULL);
    srand(time(NULL));

    for (count = 0; count < TAILLE; count++)
    {
        tab[count] = rand() % TAILLE;
    }

    tri_insertion(tab, TAILLE);
    printf("Temps d'execution : %f \n", time(NULL) - timer);

    return 0;
}

