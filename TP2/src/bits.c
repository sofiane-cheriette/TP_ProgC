#include <stdio.h>

int main() {
    // On choisit un nombre qui a le 4ème bit (bit 28) et le 20ème bit (bit 12) à 1
    // 4ème bit depuis la gauche (sur 32 bits) = index 28 (car 31, 30, 29, 28)
    // 20ème bit depuis la gauche = index 12
    unsigned int d = 268439552; // Valeur binaire avec ces bits activés

    printf("Valeur testee : %u\n", d);

    // Extraction (Décalage vers la droite puis masque & 1)
    int bit4 = (d >> 28) & 1;
    int bit20 = (d >> 12) & 1;

    // Vérification
    if (bit4 == 1 && bit20 == 1) {
        printf("1\n");
    } else {
        printf("0\n");
    }

    return 0;
}
