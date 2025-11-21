#include <stdio.h>

int main() {
    // Chaînes de base
    char str1[100] = "Hello"; // Grand tableau pour pouvoir concaténer après
    char str2[] = " World!";
    
    int longueur = 0;
    int i, j;

    // 1. Calculer la longueur de str1
    // On avance tant qu'on ne tombe pas sur le caractère de fin '\0'
    while (str1[longueur] != '\0') {
        longueur++;
    }
    printf("Longueur de '%s' : %d\n", str1, longueur);

    // 2. Copier str1 dans une autre chaine (copie)
    char copie[100];
    for (i = 0; i <= longueur; i++) { // <= pour copier aussi le '\0'
        copie[i] = str1[i];
    }
    printf("Chaine copiee : %s\n", copie);

    // 3. Concaténer (Ajouter str2 à la fin de str1)
    // On repart de la fin de str1 (variable 'longueur')
    j = 0;
    while (str2[j] != '\0') {
        str1[longueur + j] = str2[j];
        j++;
    }
    str1[longueur + j] = '\0'; // Ne pas oublier de fermer la chaîne !

    printf("Resultat concatenation : %s\n", str1);

    return 0;
}
