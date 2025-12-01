#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vider_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Fonction pour enlever le retour à la ligne à la fin d'une saisie
void nettoyer_saisie(char *str) {
    str[strcspn(str, "\n")] = 0;
}

int main() {
    char nom_fichier[100];
    char phrase[100];
    char ligne[1024]; // Tampon pour lire une ligne du fichier
    FILE *fp;

    printf("\n==============================================\n");
    printf("      EXERCICE 4.6 : RECHERCHE FICHIER        \n");
    printf("==============================================\n");

    // 1. Demande du fichier
    printf("1. Nom du fichier où chercher (ex: etudiant.txt) : ");
    scanf("%s", nom_fichier);
    vider_buffer();

    // 2. Ouverture fichier
    fp = fopen(nom_fichier, "r");
    if (fp == NULL) {
        printf("(!) Erreur : Impossible d'ouvrir '%s'. Vérifiez le nom.\n", nom_fichier);
        return 1;
    }

    // 3. Demande de la phrase
    printf("2. Phrase ou mot à chercher : ");
    fgets(phrase, sizeof(phrase), stdin);
    nettoyer_saisie(phrase); // Enlève le "Entrée"

    printf("\n--- Recherche de \"%s\" en cours ---\n", phrase);

    int num_ligne = 1;
    int total_trouve = 0;

    // Lecture ligne par ligne
    while (fgets(ligne, sizeof(ligne), fp)) {
        int compte_ligne = 0;
        char *ptr = ligne;

        // Recherche toutes les occurrences dans la ligne actuelle
        while ((ptr = strstr(ptr, phrase)) != NULL) {
            compte_ligne++;
            ptr++; // On avance d'un caractère pour continuer à chercher
        }

        if (compte_ligne > 0) {
            printf(" -> Trouvé Ligne %d (%d fois)\n", num_ligne, compte_ligne);
            total_trouve += compte_ligne;
        }
        num_ligne++;
    }

    printf("----------------------------------------------\n");
    if (total_trouve == 0) {
        printf("   Résultat : Aucune occurrence trouvée.\n");
    } else {
        printf("   Résultat : Trouvé %d fois au total.\n", total_trouve);
    }
    printf("----------------------------------------------\n");

    fclose(fp);
    return 0;
}
