#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

void init_liste(struct liste_couleurs *liste) {
    liste->head = NULL;
}

void insertion(struct couleur *c, struct liste_couleurs *liste) {
    struct element *nouveau = malloc(sizeof(struct element));
    if (nouveau == NULL) return;

    nouveau->val = *c;     // Copie de la valeur
    nouveau->next = liste->head; // Insertion en tête
    liste->head = nouveau;
}

void parcours(struct liste_couleurs *liste) {
    struct element *actuel = liste->head;
    int i = 1;
    while (actuel != NULL) {
        printf("Couleur %d: R=%02X G=%02X B=%02X A=%02X\n", 
               i++, actuel->val.r, actuel->val.g, actuel->val.b, actuel->val.a);
        actuel = actuel->next;
    }
}
