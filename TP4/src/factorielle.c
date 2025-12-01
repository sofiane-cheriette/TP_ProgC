#include <stdio.h>

// Fonction récursive
// On utilise "unsigned long long" pour gérer des grands nombres
unsigned long long factorielle(int n) {
    if (n == 0 || n == 1) {
        printf("   [Base atteinte] fact(%d) vaut 1. On remonte !\n", n);
        return 1;
    } else {
        printf(" -> Calcul de %d * fact(%d)...\n", n, n - 1);
        unsigned long long resultat = n * factorielle(n - 1);
        return resultat;
    }
}

int main() {
    int n;

    printf("\n==============================================\n");
    printf("      EXERCICE 4.5 : FACTORIELLE RECURSIVE    \n");
    printf("==============================================\n");
    printf("Entrez un nombre entier petit (ex: 5 ou 10).\n");
    printf("Attention : au-delà de 20, le résultat dépasse la mémoire !\n");
    printf("Votre nombre : ");
    
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("(!) Erreur : Veuillez entrer un entier positif.\n");
        return 1;
    }

    printf("\n--- Trace de l'exécution ---\n");
    unsigned long long res = factorielle(n);
    
    printf("\n----------------------------------------------\n");
    printf("   RESULTAT FINAL : %d! = %llu\n", n, res);
    printf("----------------------------------------------\n");

    return 0;
}
