#include <stdio.h>

int main() {
    // Tableaux parallèles pour 5 étudiants
    char noms[5][50] = {"Dupont", "Martin", "Durand", "Petit", "Leroy"};
    char prenoms[5][50] = {"Marie", "Pierre", "Paul", "Jacques", "Sophie"};
    char adresses[5][100] = {"Lyon", "Paris", "Marseille", "Lille", "Bordeaux"};
    
    float notesC[5] = {12.5, 14.0, 8.5, 16.0, 10.0};
    float notesOS[5] = {11.0, 14.5, 9.0, 15.5, 12.0};

    int i;
    
    printf("--- LISTE DES ETUDIANTS (Tableaux) ---\n");

    for (i = 0; i < 5; i++) {
        printf("Etudiant %d :\n", i + 1);
        printf("Nom : %s %s\n", noms[i], prenoms[i]);
        printf("Adresse : %s\n", adresses[i]);
        printf("Note C : %.1f | Note OS : %.1f\n\n", notesC[i], notesOS[i]);
    }

    return 0;
}
