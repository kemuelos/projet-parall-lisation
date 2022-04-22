#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <omp.h>



void tri_insertion(int* tab, int TAILLE)
{
    int en_cours, i, j;

    double start = omp_get_wtime();
    #pragma omp parallel for private(en_cours, i, j)
    
    for (i = 1; i < TAILLE; i++) {
        en_cours = tab[i];
        for (j = i; j > 0 && tab[j - 1] > en_cours; j--) {
            tab[j] = tab[j - 1];
        }
        tab[j] = en_cours;
    }
    
    double end = omp_get_wtime();
    double timer = end - start;
    printf("Temps d'execution du programme : %f\n", timer);
}


void afficher(int* tab, int TAILLE)
{
    int i;
    for (i = 0; i < TAILLE; i++)
        printf("%d ", tab[i]);
        printf("\n");
}




int main(){
    int TAILLE;
    printf("Entrez la taille du tableau : ");
    scanf("%d", &TAILLE);
    int *tab = malloc(sizeof(int)*TAILLE);

    srand(time(NULL));
    for (int i = 0; i < TAILLE; i++)
    {
        tab[i] = rand()%TAILLE;
    }
    
    double start, end;
    
    tri_insertion(tab, TAILLE);


    return 0;
    
    
}