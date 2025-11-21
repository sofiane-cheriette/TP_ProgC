#include <stdio.h>

int main() {
    int n = 10; // On veut les 10 premiers termes
    int u0 = 0;
    int u1 = 1;
    int un;
    int i;

    printf("Suite de Fibonacci pour n=%d :\n", n);

    // Affiche les deux premiers manuellement
    printf("%d, %d", u0, u1);

    // Boucle à partir de U2
    for (i = 2; i <= n; i++) {
        un = u0 + u1; // La somme des deux précédents
        printf(", %d", un);
        
        // On décale pour le tour suivant
        u0 = u1;
        u1 = un;
    }
    printf("\n");

    return 0;
}
