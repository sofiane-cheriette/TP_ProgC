#include <stdio.h>
#include <string.h> // Nécessaire pour strcpy

// Définition de la structure
struct Etudiant {
    char nom[50];
    char prenom[50];
    char adresse[100];
    float noteC;
    float noteOS;
};

int main() {
    struct Etudiant promo[5]; // Tableau de 5 structures
    int i;

    // Remplissage des données (simulation d'une saisie)
    // Etudiant 1
    strcpy(promo[0].nom, "Dupont");
    strcpy(promo[0].prenom, "Marie");
    strcpy(promo[0].adresse, "20, Blvd Niels Bohr, Lyon");
    promo[0].noteC = 16.5;
    promo[0].noteOS = 12.1;

    // Etudiant 2
    strcpy(promo[1].nom, "Martin");
    strcpy(promo[1].prenom, "Pierre");
    strcpy(promo[1].adresse, "Paris");
    promo[1].noteC = 14.0;
    promo[1].noteOS = 14.1;

    // (Pour gagner du temps, on initialise les autres rapidement)
    for(i=2; i<5; i++) {
        strcpy(promo[i].nom, "Inconnu");
        strcpy(promo[i].prenom, "X");
        strcpy(promo[i].adresse, "N/A");
        promo[i].noteC = 10.0;
        promo[i].noteOS = 10.0;
    }

    // Affichage
    printf("--- LISTE DES ETUDIANTS (Structures) ---\n");
    for (i = 0; i < 5; i++) {
        printf("Etudiant %d :\n", i + 1);
        printf("Nom : %s\n", promo[i].nom);
        printf("Prenom : %s\n", promo[i].prenom);
        printf("Adresse : %s\n", promo[i].adresse);
        printf("Note 1 : %.1f\n", promo[i].noteC);
        printf("Note 2 : %.1f\n\n", promo[i].noteOS);
    }

    return 0;
}
