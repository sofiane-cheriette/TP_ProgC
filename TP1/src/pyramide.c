#include <stdio.h>

int main() {
    int n = 5; // Hauteur de la pyramide
    int i, j, k;

    printf("--- GENERATION PYRAMIDE (n=%d) ---\n\n", n);

    // Boucle principale : gère les niveaux (lignes) de 1 à n
    for (i = 1; i <= n; i++) {

        // 1. Boucle pour les ESPACES (pour centrer)
        // Plus on descend (i augmente), moins on a d'espaces
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }

        // 2. Boucle pour les nombres CROISSANTS (de 1 à i)
        for (k = 1; k <= i; k++) {
            printf("%d", k);
        }

        // 3. Boucle pour les nombres DECROISSANTS (de i-1 à 1)
        // On commence à i-1 car le sommet a déjà été écrit par la boucle précédente
        for (k = i - 1; k >= 1; k--) {
            printf("%d", k);
        }

        // Passage à la ligne suivante
        printf("\n");
    }

    printf("\nGeneration terminee !\n");

    return 0;
}
