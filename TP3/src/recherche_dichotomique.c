#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fonction de comparaison pour qsort
int comparer(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int tableau[100];
    int cible;
    int gauche = 0, droite = 99, milieu;
    int trouve = 0;

    srand(time(NULL));

    // Remplissage
    for (int i = 0; i < 100; i++) {
        tableau[i] = rand() % 100;
    }

    // Tri rapide (nécessaire pour la dichotomie)
    qsort(tableau, 100, sizeof(int), comparer);

    printf("Tableau trié (extrait) :\n");
    for (int i = 0; i < 20; i++) printf("%d ", tableau[i]);
    printf("...\n");

    printf("\nEntrez l'entier que vous souhaitez chercher : ");
    if (scanf("%d", &cible) != 1) return 1;

    // Algorithme de recherche dichotomique
    while (gauche <= droite) {
        milieu = gauche + (droite - gauche) / 2;

        if (tableau[milieu] == cible) {
            trouve = 1;
            break;
        }

        if (tableau[milieu] < cible) {
            gauche = milieu + 1;
        } else {
            droite = milieu - 1;
        }
    }

    if (trouve) {
        printf("Résultat : entier présent\n");
    } else {
        printf("Résultat : entier absent\n");
    }

    return 0;
}
