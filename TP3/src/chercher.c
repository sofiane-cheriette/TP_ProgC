#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int tableau[100];
    int cible;
    int trouve = 0;

    srand(time(NULL));

    printf("Tableau (extrait) :\n");
    for (int i = 0; i < 100; i++) {
        tableau[i] = rand() % 20; // Petits nombres pour faciliter le test
        if (i < 20) printf("%d ", tableau[i]);
    }
    printf("...\n");

    printf("\nEntrez l'entier que vous souhaitez chercher : ");
    if (scanf("%d", &cible) != 1) return 1;

    for (int i = 0; i < 100; i++) {
        if (tableau[i] == cible) {
            trouve = 1;
            break; // On arrête dès qu'on trouve
        }
    }

    if (trouve) {
        printf("Résultat : entier présent\n");
    } else {
        printf("Résultat : entier absent\n");
    }

    return 0;
}
