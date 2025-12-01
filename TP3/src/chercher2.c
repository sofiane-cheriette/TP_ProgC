#include <stdio.h>

// Fonction manuelle pour calculer la longueur d'une chaîne
int ma_strlen(char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Fonction manuelle pour comparer deux chaînes
int sont_identiques(char *s1, char *s2) {
    int i = 0;
    while (s1[i] != '\0' || s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return 0; // Différent
        }
        i++;
    }
    return 1; // Identique
}

int main() {
    // Tableau de pointeurs vers des chaînes littérales
    char *phrases[10] = {
        "Bonjour, comment ça va ?",
        "Le temps est magnifique aujourd'hui.",
        "C'est une belle journée.",
        "La programmation en C est amusante.",
        "Les tableaux en C sont puissants.",
        "Les pointeurs en C peuvent être déroutants.",
        "Il fait beau dehors.",
        "La recherche dans un tableau est intéressante.",
        "Les structures de données sont importantes.",
        "Programmer en C, c'est génial."
    };

    char *recherche = "La programmation en C est amusante.";
    char *autre_recherche = "Je préfère le Python.";
    
    int trouve = 0;

    printf("Recherche de : \"%s\"\n", recherche);
    
    // Logique de recherche
    for (int i = 0; i < 10; i++) {
        if (sont_identiques(phrases[i], recherche)) {
            trouve = 1;
            break;
        }
    }

    if (trouve) printf("-> Phrase trouvée\n\n");
    else printf("-> Phrase non trouvée\n\n");

    // Deuxième test
    trouve = 0;
    printf("Recherche de : \"%s\"\n", autre_recherche);
    for (int i = 0; i < 10; i++) {
        if (sont_identiques(phrases[i], autre_recherche)) {
            trouve = 1;
            break;
        }
    }

    if (trouve) printf("-> Phrase trouvée\n");
    else printf("-> Phrase non trouvée\n");

    return 0;
}
