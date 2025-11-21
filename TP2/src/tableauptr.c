#include <stdio.h>
#include <stdlib.h> // Pour rand() et srand()
#include <time.h>   // Pour time()

int main() {
    int tabInt[10];
    float tabFloat[10];
    int i;
    
    // Initialisation de l'aléatoire
    srand(time(NULL));

    printf("--- TABLEAUX AVANT MODIF ---\n");
    // Remplissage + Affichage
    for (i = 0; i < 10; i++) {
        // Syntaxe pointeur : *(tab + i) au lieu de tab[i]
        *(tabInt + i) = rand() % 100;       // Entier entre 0 et 99
        *(tabFloat + i) = (float)i * 1.5;   // Valeur float arbitraire
        
        printf("Index %d -> Int: %d | Float: %.2f\n", i, *(tabInt + i), *(tabFloat + i));
    }

    // MODIFICATION (Si index divisible par 2, on multiplie par 3)
    for (i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            *(tabInt + i) = *(tabInt + i) * 3;
            *(tabFloat + i) = *(tabFloat + i) * 3.0;
        }
    }

    printf("\n--- TABLEAUX APRES MODIF (x3 si index pair) ---\n");
    for (i = 0; i < 10; i++) {
        printf("Index %d -> Int: %d | Float: %.2f\n", i, *(tabInt + i), *(tabFloat + i));
    }

    return 0;
}
