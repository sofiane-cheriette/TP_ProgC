#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int tableau[100];
    int min, max;

    // Initialisation du générateur aléatoire
    srand(time(NULL));

    // Remplissage
    printf("Tableau généré (extrait) : ");
    for (int i = 0; i < 100; i++) {
        tableau[i] = (rand() % 1000) + 1; // Entre 1 et 1000
        if(i < 10) printf("%d ", tableau[i]); // Affiche les 10 premiers pour voir
    }
    printf("...\n");

    // Recherche
    min = tableau[0];
    max = tableau[0];

    for (int i = 1; i < 100; i++) {
        if (tableau[i] > max) {
            max = tableau[i];
        }
        if (tableau[i] < min) {
            min = tableau[i];
        }
    }

    printf("Le numéro le plus grand est : %d\n", max);
    printf("Le numéro le plus petit est : %d\n", min);

    return 0;
}
