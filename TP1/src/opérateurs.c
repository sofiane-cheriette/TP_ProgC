#include <stdio.h>

int main() {
    // Déclaration des variables comme demandé
    int a = 16;
    int b = 3;

    printf("Valeurs initiales : a = %d, b = %d\n\n", a, b);

    printf("--- CALCULS ARITHMETIQUES ---\n");
    // Addition
    printf("Addition (a + b)       : %d\n", a + b);

    // Soustraction
    printf("Soustraction (a - b)   : %d\n", a - b);

    // Multiplication
    printf("Multiplication (a * b) : %d\n", a * b);

    // Division (Division entière car a et b sont des entiers)
    printf("Division (a / b)       : %d\n", a / b);

    // Modulo (Le reste de la division)
    // Note : Pour afficher le signe '%' avec printf, il faut écrire '%%'
    printf("Modulo (a %% b)         : %d\n", a % b);

    printf("\n--- COMPARAISONS LOGIQUES ---\n");
    printf("(Rappel : 0 = Faux, 1 = Vrai)\n");

    // Est-ce que a est égal à b ?
    printf("Est-ce que a == b ?    : %d\n", a == b);

    // Est-ce que a est supérieur à b ?
    printf("Est-ce que a > b ?     : %d\n", a > b);

    return 0;
}
