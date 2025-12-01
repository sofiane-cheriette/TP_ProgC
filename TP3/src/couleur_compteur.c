#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
} Couleur;

// Structure pour stocker les couleurs uniques et leur compte
typedef struct {
    Couleur couleur;
    int compte;
} CouleurCompteur;

// Fonction pour comparer deux couleurs
int couleurs_egales(Couleur c1, Couleur c2) {
    return (c1.r == c2.r && c1.g == c2.g && c1.b == c2.b && c1.a == c2.a);
}

int main() {
    Couleur tableau[100];
    CouleurCompteur distinctes[100];
    int nb_distinctes = 0;

    srand(time(NULL));

    // Remplissage avec moins de variabilité pour avoir des doublons
    for (int i = 0; i < 100; i++) {
        tableau[i].r = rand() % 3; // Seulement 0, 1 ou 2
        tableau[i].g = rand() % 3;
        tableau[i].b = rand() % 3;
        tableau[i].a = 255;
    }

    // Comptage
    for (int i = 0; i < 100; i++) {
        int trouve = 0;
        // Vérifier si la couleur est déjà listée
        for (int j = 0; j < nb_distinctes; j++) {
            if (couleurs_egales(tableau[i], distinctes[j].couleur)) {
                distinctes[j].compte++;
                trouve = 1;
                break;
            }
        }
        
        // Si c'est une nouvelle couleur
        if (!trouve) {
            distinctes[nb_distinctes].couleur = tableau[i];
            distinctes[nb_distinctes].compte = 1;
            nb_distinctes++;
        }
    }

    // Affichage
    printf("Couleurs distinctes et occurrences :\n");
    for (int i = 0; i < nb_distinctes; i++) {
        printf("R:%02x G:%02x B:%02x A:%02x : %d\n",
               distinctes[i].couleur.r,
               distinctes[i].couleur.g,
               distinctes[i].couleur.b,
               distinctes[i].couleur.a,
               distinctes[i].compte);
    }

    return 0;
}
