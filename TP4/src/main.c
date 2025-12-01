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
    printf("INSTRUCTION : Tapez les nombres un par un.\n");
    printf("Ne tapez PAS '5*5' d'un coup.\n\n");
    
    // --- ETAPE 1 : PREMIER NOMBRE ---
    printf("1. Entrez le premier nombre entier (ex: 10) puis appuyez sur ENTREE :\n");
    printf("   Votre nombre : ");
    while (scanf("%d", &n1) != 1) { 
        printf("   (!) Ce n'est pas un nombre valide. Réesseyez : ");
        vider_buffer(); 
    }

    // --- ETAPE 2 : DEUXIEME NOMBRE ---
    printf("\n2. Entrez le deuxieme nombre entier (ex: 5) puis appuyez sur ENTREE :\n");
    printf("   Votre nombre : ");
    while (scanf("%d", &n2) != 1) {
        printf("   (!) Ce n'est pas un nombre valide. Réesseyez : ");
        vider_buffer();
    }
    
    // Nettoyage de sécurité avant de demander le caractère
    vider_buffer(); 

    // --- ETAPE 3 : OPERATEUR ---
    printf("\n3. Choisissez l'opération à effectuer.\n");
    printf("   Symboles disponibles : +  -  * /  %%  &  |  ~\n");
    printf("   Votre opérateur : ");
    scanf("%c", &op); 

    int res = 0;
    // Vérification pour éviter la division par zéro avant le calcul
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
        case '~': res = negation(n1); printf("(Note : le 2ème nombre a été ignoré pour le ~)\n"); break;
        default: printf("\n(!) Operateur '%c' non reconnu.\n", op); return;
    }

    printf("\n----------------------------------------------\n");
    printf("   RÉSULTAT DU CALCUL : %d\n", res);
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
    printf("   [1] -> LIRE le contenu d'un fichier existant\n");
    printf("   [2] -> ECRIRE un message dans un fichier\n");
    printf("   Votre choix (1 ou 2) : ");
    
    if (scanf("%d", &choix) != 1) {
        printf("(!) Choix invalide.\n");
        vider_buffer();
        return;
    }
    vider_buffer(); 

    if (choix == 1) {
        printf("\n--- MODE LECTURE ---\n");
        printf("Entrez le nom du fichier (ex: fichier.txt) : ");
        scanf("%s", nom_fic);
        printf("\n--- Début du contenu ---\n");
        lire_fichier(nom_fic); // Fonction définie dans fichier.c
        printf("\n--- Fin du contenu ---\n");

    } else if (choix == 2) {
        printf("\n--- MODE ECRITURE ---\n");
        printf("1. Nom du fichier à créer/écraser (ex: test.txt) : ");
        scanf("%s", nom_fic);
        vider_buffer(); // Important
        
        printf("2. Tapez le message à écrire (puis Entrée) : ");
        fgets(message, 256, stdin); 
        
        ecrire_dans_fichier(nom_fic, message); // Fonction définie dans fichier.c
        printf("--> Succès : Message enregistré dans '%s'.\n", nom_fic);
    } else {
        printf("(!) Option inconnue.\n");
    }
}

// --- EXERCICE 4.7 : LISTE COULEURS ---
void run_ex47() {
    struct liste_couleurs ma_liste;
    init_liste(&ma_liste);
    
    printf("\n==============================================\n");
    printf("      EXERCICE 4.7 : LISTE CHAINEE (COULEURS) \n");
    printf("==============================================\n");
    printf("Le programme va générer 10 couleurs aléatoires\n");
    printf("et les ajouter automatiquement dans une liste...\n");
    
    // Petite pause simulée ou message d'attente (optionnel)
    printf("Génération en cours...\n");

    for(int i=0; i<10; i++) {
        struct couleur c;
        c.r = rand() % 256;
        c.g = rand() % 256;
        c.b = rand() % 256;
        c.a = 255; // Alpha opaque
        insertion(&c, &ma_liste);
    }

    printf("Terminé. Voici le contenu de la liste :\n");
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
        printf("Choisissez un exercice à tester :\n\n");
        printf("   [1] Calculatrice (Opérations +, -, *, etc.)\n");
        printf("   [2] Fichiers (Lecture / Écriture)\n");
        printf("   [3] Liste Chaînée (Couleurs RGB)\n");
        printf("   [4] Quitter le programme\n");
        printf("\nVotre choix (tapez le numéro puis Entrée) : ");
        
        if (scanf("%d", &choix) != 1) {
            printf("\n(!) Erreur : Vous devez taper un chiffre (1, 2, 3 ou 4).\n");
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
                printf("\n(!) Ce numéro n'est pas dans le menu.\n");
        }
    }
    return 0;
}
