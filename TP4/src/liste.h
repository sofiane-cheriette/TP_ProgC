#ifndef LISTE_H
#define LISTE_H

struct couleur {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
};

// Élément de la liste
struct element {
    struct couleur val;
    struct element *next;
};

// Structure de contrôle de la liste
struct liste_couleurs {
    struct element *head;
};

void init_liste(struct liste_couleurs *liste);
void insertion(struct couleur *c, struct liste_couleurs *liste);
void parcours(struct liste_couleurs *liste);

#endif
