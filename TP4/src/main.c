#include <stdio.h>
#include <stdlib.h>
#include "operator.h"
#include "fichier.h"
#include "liste.h"

// --- Fonction pour nettoyer le buffer (le tuyau d'entrée) ---
// Elle "mange" tout ce qui traîne jusqu'au retour à la ligne
void vider_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// --- Fonctions d'enrobage pour chaque exercice ---

void run_ex41() {
    int n1, n2;
    char op;
    printf("\n--- Calcul avec operateurs ---\n");
    
    // 1. Demande num1
    printf("Entrez num1 : ");
    // Si l'utilisateur tape des bêtises, scanf renvoie 0. On gère ça.
    while (scanf("%d", &n1) != 1) { 
        printf("Erreur : Entrez un nombre entier valide : ");
        vider_buffer(); // On nettoie les erreurs
    }
    
    // 2. Demande num2
    printf("Entrez num2 : ");
    while (scanf("%d", &n2) != 1) {
        printf("Erreur : Entrez un nombre entier valide : ");
        vider_buffer();
    }
    
    // On vide le buffer avant de lire le caractère (pour enlever le "Entrée" précédent)
    vider_buffer(); 

    // 3. Demande l'opérateur
    printf("Entrez l'operateur (+, -, *, /, %%, &, |, ~) : ");
    scanf("%c", &op); 
    // Pas besoin de boucle ici, scanf("%c") prendra le premier caractère dispo

    int res = 0;
    switch(op) {
        case '+': res = somme(n1, n2); break;
        case '-': res = difference(n1, n2); break;
        case '*': res = produit(n1, n2); break;
        case '/': res = quotient(n1, n2); break;
        case '%': res = modulo(n1, n2); break;
        case '&': res = et_logique(n1, n2); break;
        case '|': res = ou_logique(n1, n2); break;
        case '~': res = negation(n1); break;
        default: printf("Operateur inconnu !\n"); return;
    }
    printf("Resultat : %d\n", res);
}

void run_ex42() {
    int choix;
    char nom_fic[100];
    char message[256];

    printf("\n--- Gestion de fichiers ---\n");
    printf("1. Lire un fichier\n2. Ecrire dans un fichier\nVotre choix : ");
    
    if (scanf("%d", &choix) != 1) {
        printf("Saisie invalide.\n");
        vider_buffer();
        return;
    }
    vider_buffer(); // Important pour nettoyer après le chiffre

    if (choix == 1) {
        printf("Nom du fichier a lire : ");
        scanf("%s", nom_fic);
        vider_buffer();
        lire_fichier(nom_fic);
    } else if (choix == 2) {
        printf("Nom du fichier ou ecrire : ");
        scanf("%s", nom_fic);
        vider_buffer(); // On nettoie après le nom du fichier
        
        printf("Message a ecrire : ");
        fgets(message, 256, stdin); // Lit la ligne entière
        ecrire_dans_fichier(nom_fic, message);
    }
}

void run_ex47() {
    struct liste_couleurs ma_liste;
    init_liste(&ma_liste);
    
    printf("\n--- Gestion Liste Couleurs ---\n");
    printf("Creation et insertion de 10 couleurs aleatoires...\n");

    for(int i=0; i<10; i++) {
        struct couleur c;
        c.r = rand() % 256;
        c.g = rand() % 256;
        c.b = rand() % 256;
        c.a = 255;
        insertion(&c, &ma_liste);
    }

    printf("Liste des couleurs :\n");
    parcours(&ma_liste);
}

// --- MAIN ---
int main() {
    int choix = 0;
    
    while (1) {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Exercice 4.1 (Calculatrice)\n");
        printf("2. Exercice 4.2 (Fichiers)\n");
        printf("3. Exercice 4.7 (Liste Couleurs)\n");
        printf("4. Quitter\n");
        printf("Choix : ");
        
        // Sécurisation de la saisie du menu
        if (scanf("%d", &choix) != 1) {
            // Si l'utilisateur tape une lettre au lieu d'un chiffre
            printf("--> Erreur : veuillez entrer un chiffre entre 1 et 4.\n");
            vider_buffer(); // On vide la saisie incorrecte
            continue; // On recommence la boucle
        }

        switch (choix) {
            case 1: run_ex41(); break;
            case 2: run_ex42(); break;
            case 3: run_ex47(); break;
            case 4: return 0;
            default: printf("Choix invalide.\n");
        }
    }
    return 0;
}
