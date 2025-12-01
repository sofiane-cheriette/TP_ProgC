#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int tableau[100];
    int temp;

    srand(time(NULL));

    // Remplissage
    printf("Tableau non trié (extrait) :\n");
    for (int i = 0; i < 100; i++) {
        tableau[i] = (rand() % 100) - 50; // Valeurs entre -50 et 49 pour varier
        if (i < 10) printf("%d ", tableau[i]);
    }
    printf("...\n");

    // Tri à bulles
    for (int i = 0; i < 100 - 1; i++) {
        for (int j = 0; j < 100 - i - 1; j++) {
            if (tableau[j] > tableau[j + 1]) {
                // Échange
                temp = tableau[j];
                tableau[j] = tableau[j + 1];
                tableau[j + 1] = temp;
            }
        }
    }

    printf("\nTableau trié par ordre croissant (extrait) :\n");
    for (int i = 0; i < 100; i++) {
        if (i < 10) printf("%d ", tableau[i]);
    }
    printf("...\n");

    return 0;
}
