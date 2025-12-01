#include <stdio.h>
#include <stdlib.h>
#include "fichier.h"

void lire_fichier(char *nom_de_fichier) {
    FILE *fp = fopen(nom_de_fichier, "r");
    char ch;
    
    if (fp == NULL) {
        printf("Erreur: Impossible d'ouvrir le fichier %s.\n", nom_de_fichier);
        return;
    }

    printf("Contenu du fichier %s :\n", nom_de_fichier);
    while ((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }
    printf("\n");
    fclose(fp);
}

void ecrire_dans_fichier(char *nom_de_fichier, char *message) {
    // "w" écrase le fichier, "a" ajoute à la fin. Le sujet implique une écriture simple.
    FILE *fp = fopen(nom_de_fichier, "w");
    
    if (fp == NULL) {
        printf("Erreur: Impossible d'ouvrir le fichier pour écriture.\n");
        return;
    }

    fprintf(fp, "%s", message);
    printf("Le message a été écrit dans le fichier %s.\n", nom_de_fichier);
    fclose(fp);
}
