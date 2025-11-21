#include <stdio.h>

struct Couleur {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
};

int main() {
    // Initialisation directe du tableau de structures
    struct Couleur palette[10] = {
        {0xEF, 0x78, 0x12, 0xFF}, // Couleur 1
        {0x2C, 0xC8, 0x64, 0xFF}, // Couleur 2
        {0x00, 0x00, 0x00, 0xFF}, // Couleur 3 (Noir)
        {0xFF, 0xFF, 0xFF, 0xFF}, // Couleur 4 (Blanc)
        // Les autres seront à 0 par défaut ou on peut les remplir...
    };

    int i;
    printf("--- COULEURS RGBA ---\n");
    
    // On affiche les 4 premières pour l'exemple
    for (i = 0; i < 4; i++) {
        printf("Couleur %d :\n", i + 1);
        // %d affiche la valeur décimale de l'octet
        printf("Rouge : %d\n", palette[i].r);
        printf("Vert  : %d\n", palette[i].g);
        printf("Bleu  : %d\n", palette[i].b);
        printf("Alpha : %d\n\n", palette[i].a);
    }

    return 0;
}
