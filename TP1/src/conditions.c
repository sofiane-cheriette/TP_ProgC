#include <stdio.h>

int main() {
    int somme = 0;
    int i;

    printf("--- Debut de la boucle ---\n");

    // On parcourt les nombres de 1 à 1000
    for (i = 1; i <= 1000; i++) {

        // REGLE 1 : Si divisible par 11, on saute ce tour
        if (i % 11 == 0) {
            continue; // Passe direct au 'i' suivant sans exécuter la suite
        }

        // REGLE 2 : Si divisible par 5 OU 7, on ajoute
        if (i % 5 == 0 || i % 7 == 0) {
            somme = somme + i; // ou somme += i;
            // printf("Ajout de %d, Somme actuelle = %d\n", i, somme); // (Décommente pour voir le détail)
        }

        // REGLE 3 : Si la somme dépasse 5000, on stoppe tout
        if (somme > 5000) {
            printf("STOP ! La somme a depasse 5000 au nombre : %d\n", i);
            break; // Sort complétement de la boucle for
        }
    }

    printf("--- Fin du programme ---\n");
    printf("Somme finale : %d\n", somme);

    return 0;
}
