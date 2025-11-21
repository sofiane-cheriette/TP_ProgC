#include <stdio.h>

int main() {
    int compteur = 5;
    int i = 1; // Initialisation de i avant la boucle
    int j;

    printf("--- TRIANGLE (Version WHILE) ---\n");

    // Boucle externe (Lignes)
    while (i <= compteur) {
        
        j = 1; // IMPORTANT : On remet j à 1 au début de chaque nouvelle ligne
        
        // Boucle interne (Colonnes)
        while (j <= i) {
            
            if (j == 1 || j == i || i == compteur) {
                printf("* ");
            } else {
                printf("# ");
            }
            
            j++; // Incrémentation de j
        }
        
        printf("\n"); // Retour à la ligne
        i++; // Incrémentation de i
    }

    return 0;
}
