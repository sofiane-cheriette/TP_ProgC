#include <stdio.h>

int main() {
    // 1. Déclaration des variables (a^b)
    int a = 5;  // La base
    int b = 3;  // L'exposant (puissance)
    
    // 2. Variable pour stocker le résultat
    // IMPORTANT : On initialise à 1 (élément neutre de la multiplication)
    // Si on met 0, tout le calcul fera 0 !
    int resultat = 1;
    
    int i; // Compteur pour la boucle

    printf("Calcul de %d a la puissance %d ...\n", a, b);

    // 3. Boucle de calcul (on multiplie 'a' par lui-même 'b' fois)
    for (i = 0; i < b; i++) {
        resultat = resultat * a;
    }

    // 4. Affichage du résultat
    printf("Resultat : %d\n", resultat);

    return 0;
}
