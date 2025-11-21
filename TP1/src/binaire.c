#include <stdio.h>

// Fonction pour convertir et afficher un nombre en binaire
void afficherEnBinaire(int nombre) {
    int tab[32]; // Tableau pour stocker les bits (32 est suffisant pour un int)
    int i = 0;
    int n = nombre; // Copie du nombre pour le manipuler

    printf("Nombre : %d \t -> Binaire : ", nombre);

    // Cas spécial pour 0
    if (n == 0) {
        printf("0\n");
        return;
    }

    // ALGORITHME DE DIVISION
    // Tant que le nombre est supérieur à 0
    while (n > 0) {
        tab[i] = n % 2; // On stocke le reste (0 ou 1)
        n = n / 2;      // On divise le nombre par 2
        i++;
    }

    // AFFICHAGE INVERSE
    // On a rempli le tableau à l'endroit, mais le binaire se lit à l'envers.
    // On part de la fin (i-1) jusqu'à 0.
    int j;
    for (j = i - 1; j >= 0; j--) {
        printf("%d", tab[j]);
    }
    printf("\n");
}

int main() {
    printf("--- CONVERTISSEUR BINAIRE ---\n");

    // Test des valeurs demandées dans l'exercice
    afficherEnBinaire(0);
    afficherEnBinaire(4096);
    afficherEnBinaire(65536); // Attention: dépasse peut-être 16 bits
    afficherEnBinaire(65535);
    afficherEnBinaire(1024);

    return 0;
}
