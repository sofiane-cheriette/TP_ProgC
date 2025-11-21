#include <stdio.h>

int main() {
    // 1. Déclaration des variables
    char c = 'A';
    int i = 100;
    float f = 3.14;
    double d = 123.456;

    // 2. Déclaration des pointeurs (qui stockent les adresses)
    char *p_c = &c;
    int *p_i = &i;
    float *p_f = &f;
    double *p_d = &d;

    // 3. Avant manipulation (Affichage adresses %p et valeurs %x pour hex)
    printf("--- AVANT MANIPULATION ---\n");
    printf("Adresse de c: %p, Valeur: %x (char)\n", p_c, c);
    printf("Adresse de i: %p, Valeur: %x (int)\n", p_i, i);
    
    // Pour les float/double, l'affichage hexa direct (%x) avec printf est complexe en C strict
    // On affiche en %f pour simplifier ou on caste, mais suivons l'exemple simple :
    printf("Adresse de f: %p, Valeur (float): %f\n", p_f, f); 
    printf("Adresse de d: %p, Valeur (double): %lf\n\n", p_d, d);

    // 4. Manipulation VIA les pointeurs
    *p_c = 'Z';   // Change c
    *p_i = 999;   // Change i
    *p_f = 0.00;  // Change f

    // 5. Après manipulation
    printf("--- APRES MANIPULATION ---\n");
    printf("Adresse de c: %p, Valeur: %x (char)\n", p_c, c);
    printf("Adresse de i: %p, Valeur: %x (int)\n", p_i, i);
    printf("Adresse de f: %p, Valeur: %f\n", p_f, f);

    return 0;
}
