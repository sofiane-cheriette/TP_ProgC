#include <stdio.h>

int main() {
    int compteur = 5; // Taille du triangle
    int i, j;

    printf("--- TRIANGLE (Version FOR) ---\n");

    // 1. Boucle pour les LIGNES (de 1 à 5)
    for (i = 1; i <= compteur; i++) {
        
        // 2. Boucle pour les COLONNES (de 1 à i)
        // Ex: ligne 3 -> on écrit 3 caractères
        for (j = 1; j <= i; j++) {
            
            // Si c'est le premier caractère, le dernier, ou la dernière ligne
            if (j == 1 || j == i || i == compteur) {
                printf("* ");
            } 
            // Sinon, on met un dièse
            else {
                printf("# ");
            }
        }
        // Retour à la ligne à la fin de la boucle colonnes
        printf("\n");
    }

    return 0;
}
