#include <stdio.h>
#include <stdlib.h>
#include "operator.h"
#include "fichier.h"
#include "liste.h"

// --- Fonction outil pour nettoyer les erreurs de saisie ---
void vider_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// --- EXERCICE 4.1 : LA CALCULATRICE ---
void run_ex41() {
    int n1, n2;
    char op;

    printf("\n==============================================\n");
    printf("      EXERCICE 4.1 : CALCULATRICE             \n");
    printf("==============================================\n");
    printf("INSTRUCTION : Tapez les nombres un par un.\n\n");
    
    // --- ETAPE 1 : PREMIER NOMBRE ---
    printf("1. Entrez le premier nombre entier (ex: 10)\n");
    printf("   Votre nombre : "); 
    fflush(stdout); // Force l'affichage du texte AVANT la saisie
    
    while (scanf("%d", &n1) != 1) { 
        printf("   (!) Invalide. Réesseyez : ");
        fflush(stdout);
        vider_buffer(); 
    }

    // --- ETAPE 2 : DEUXIEME NOMBRE ---
    printf("\n2. Entrez le deuxieme nombre entier (ex: 5)\n");
    printf("   Votre nombre : ");
    fflush(stdout);

    while (scanf("%d", &n2) != 1) {
        printf("   (!) Invalide. Réesseyez : ");
        fflush(stdout);
        vider_buffer();
    }
    
    vider_buffer(); // Nettoyage de sécurité

    // --- ETAPE 3 : OPERATEUR ---
    printf("\n3. Choisissez l'opération (+ - * / %% & | ~)\n");
    printf("   Votre opérateur : ");
    fflush(stdout);
    
    scanf("%c", &op); 

    int res = 0;
    // Vérification division par zéro
    if ((op == '/' || op == '%') && n2 == 0) {
        printf("\n(!) Erreur : Division par zéro impossible !\n");
        return;
    }

    switch(op) {
        case '+': res = somme(n1, n2); break;
        case '-': res = difference(n1, n2); break;
        case '*': res = produit(n1, n2); break;
        case '/': res = quotient(n1, n2); break;
        case '%': res = modulo(n1, n2); break;
        case '&': res = et_logique(n1, n2); break;
        case '|': res = ou_logique(n1, n2); break;
        case '~': res = negation(n1); break;
        default: printf("\n(!) Operateur non reconnu.\n"); return;
    }

    printf("\n----------------------------------------------\n");
    printf("   RÉSULTAT : %d\n", res);
    printf("----------------------------------------------\n");
}

// --- EXERCICE 4.2 : GESTION FICHIERS ---
void run_ex42() {
    int choix;
    char nom_fic[100];
    char message[256];

    printf("\n==============================================\n");
    printf("      EXERCICE 4.2 : GESTION DE FICHIERS      \n");
    printf("==============================================\n");
    printf("Que voulez-vous faire ?\n");
    printf("   [1] LIRE un fichier\n");
    printf("   [2] ECRIRE dans un fichier\n");
    printf("   Votre choix : ");
    fflush(stdout);
    
    if (scanf("%d", &choix) != 1) {
        printf("(!) Choix invalide.\n");
        vider_buffer();
        return;
    }
    vider_buffer(); 

    if (choix == 1) {
        printf("\n--- MODE LECTURE ---\n");
        printf("Nom du fichier à lire : ");
        fflush(stdout);
        scanf("%s", nom_fic);
        
        printf("\n--- Contenu du fichier ---\n");
        lire_fichier(nom_fic); 
        printf("\n--------------------------\n");

    } else if (choix == 2) {
        printf("\n--- MODE ECRITURE ---\n");
        printf("Nom du fichier : ");
        fflush(stdout);
        scanf("%s", nom_fic);
        vider_buffer(); 
        
        printf("Message à écrire : ");
        fflush(stdout);
        fgets(message, 256, stdin); 
        
        ecrire_dans_fichier(nom_fic, message);
        printf("--> Succès.\n");
    } else {
        printf("(!) Option inconnue.\n");
    }
}

// --- EXERCICE 4.7 : LISTE COULEURS ---
void run_ex47() {
    struct liste_couleurs ma_liste;
    init_liste(&ma_liste);
    
    printf("\n==============================================\n");
    printf("      EXERCICE 4.7 : LISTE CHAINEE            \n");
    printf("==============================================\n");
    printf("Génération de 10 couleurs aléatoires...\n");
    
    for(int i=0; i<10; i++) {
        struct couleur c;
        c.r = rand() % 256;
        c.g = rand() % 256;
        c.b = rand() % 256;
        c.a = 255; 
        insertion(&c, &ma_liste);
    }

    printf("Voici la liste générée :\n");
    printf("----------------------------------------------\n");
    parcours(&ma_liste);
    printf("----------------------------------------------\n");
}

// --- MAIN (MENU PRINCIPAL) ---
int main() {
    int choix = 0;
    
    while (1) {
        printf("\n\n");
        printf("##############################################\n");
        printf("#               MENU PRINCIPAL               #\n");
        printf("##############################################\n");
        printf("   [1] Calculatrice\n");
        printf("   [2] Fichiers\n");
        printf("   [3] Liste Couleurs\n");
        printf("   [4] Quitter\n");
        printf("\nVotre choix : ");
        fflush(stdout); // Important pour que le curseur reste sur la ligne
        
        if (scanf("%d", &choix) != 1) {
            printf("\n(!) Tapez un chiffre entre 1 et 4.\n");
            vider_buffer(); 
            continue; 
        }

        switch (choix) {
            case 1: run_ex41(); break;
            case 2: run_ex42(); break;
            case 3: run_ex47(); break;
            case 4: 
                printf("Au revoir !\n");
                return 0;
            default: 
                printf("\n(!) Choix invalide.\n");
        }
    }
    return 0;
}
