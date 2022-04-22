void tri_insertion(int* tab, int TAILLE)
{
    int en_cours, i, j;
 
    for (i = 1; i < TAILLE; i++) {
        en_cours = tab[i];
        for (j = i; j > 0 && tab[j - 1] > en_cours; j--) {
            tab[j] = tab[j - 1];
        }
        tab[j] = en_cours;
    }
}

void afficher(int* tab, int TAILLE)
{
    int i;
    for (i = 0; i < TAILLE; i++)
        printf("%d ", tab[i]);
        printf("\n");
}