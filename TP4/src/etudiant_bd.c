#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- STRUCTURE ETUDIANT ---
typedef struct {
    char nom[50];
    char prenom[50];
    char adresse[100]; // Peut contenir des espaces !
    float note1;
    float note2;
} Etudiant;

// --- FONCTION NETTOYAGE BUFFER ---
void vider_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// --- FONCTION SUPPRESSION RETOUR LIGNE ---
// fgets garde le "\n" à la fin, on doit l'enlever pour que ce soit propre
void nettoyer_str(char *str) {
    char *pos = strchr(str, '\n');
    if (pos != NULL) *pos = '\0';
}

// --- FONCTION ECRITURE FICHIER ---
void ajouter_au_fichier(Etudiant e) {
    FILE *fp = fopen("etudiant.txt", "a"); // "a" pour Ajouter (Append)
    if (fp == NULL) {
        printf("(!) Erreur d'ouverture du fichier.\n");
        return;
    }
    // Formatage propre dans le fichier
    fprintf(fp, "Nom: %s | Prenom: %s | Adr: %s | Notes: %.2f, %.2f\n", 
            e.nom, e.prenom, e.adresse, e.note1, e.note2);
    fclose(fp);
}

int main() {
    Etudiant classe[5];
    int nb_etudiants = 2; // On en met 2 pour tester rapidement (au lieu de 5)

    printf("\n==============================================\n");
    printf("      EXERCICE 4.3 : BASE DE DONNEES          \n");
    printf("==============================================\n");
    printf("Les données seront sauvegardées dans 'etudiant.txt'\n");

    // Optionnel : On vide le fichier au démarrage pour repartir à zéro
    FILE *reset = fopen("etudiant.txt", "w");
    if(reset) fclose(reset);

    for (int i = 0; i < nb_etudiants; i++) {
        printf("\n--- Saisie Étudiant %d/%d ---\n", i + 1, nb_etudiants);

        // 1. NOM
        printf("Nom : ");
        fflush(stdout);
        scanf("%s", classe[i].nom);
        vider_buffer(); // Toujours nettoyer après un scanf string

        // 2. PRENOM
        printf("Prénom : ");
        fflush(stdout);
        scanf("%s", classe[i].prenom);
        vider_buffer();

        // 3. ADRESSE (Attention aux espaces !)
        printf("Adresse (ex: 12 rue de la Paix) : ");
        fflush(stdout);
        // fgets permet de lire toute la ligne avec les espaces
        fgets(classe[i].adresse, 100, stdin);
        nettoyer_str(classe[i].adresse); // On enlève le "Entrée" à la fin

        // 4. NOTES
        printf("Note 1 : ");
        fflush(stdout);
        while (scanf("%f", &classe[i].note1) != 1) {
            printf("   (!) Note invalide. Réessayez : ");
            fflush(stdout);
            vider_buffer();
        }

        printf("Note 2 : ");
        fflush(stdout);
        while (scanf("%f", &classe[i].note2) != 1) {
            printf("   (!) Note invalide. Réessayez : ");
            fflush(stdout);
            vider_buffer();
        }
        vider_buffer(); // Nettoyage final pour le tour suivant

        // Écriture immédiate dans le fichier
        ajouter_au_fichier(classe[i]);
    }

    printf("\n==============================================\n");
    printf("   SUCCÈS : %d étudiants enregistrés !\n", nb_etudiants);
    printf("   Vérifiez le fichier avec : cat etudiant.txt\n");
    printf("==============================================\n");

    return 0;
}
