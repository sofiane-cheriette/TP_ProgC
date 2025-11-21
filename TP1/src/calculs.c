#include <stdio.h>

int main() {
    // Variables à modifier pour tester
    int num1 = 12;
    int num2 = 5;
    char op = '*'; // Change ce symbole pour tester (+, -, *, /, %, &, |, ~)

    printf("Operation demandee : %d %c %d\n", num1, op, num2);

    switch(op) {
        case '+':
            printf("Addition : %d\n", num1 + num2);
            break;

        case '-':
            printf("Soustraction : %d\n", num1 - num2);
            break;

        case '*':
            printf("Multiplication : %d\n", num1 * num2);
            break;

        case '/':
            if(num2 != 0)
                printf("Division : %d\n", num1 / num2);
            else
                printf("Erreur : Division par zero impossible !\n");
            break;

        case '%':
            if(num2 != 0)
                printf("Modulo (Reste) : %d\n", num1 % num2);
            else
                printf("Erreur : Modulo par zero impossible !\n");
            break;

        case '&':
            printf("ET Binaire (Bitwise AND) : %d\n", num1 & num2);
            break;

        case '|':
            printf("OU Binaire (Bitwise OR) : %d\n", num1 | num2);
            break;

        case '~':
            // L'opérateur ~ s'applique à un seul nombre (num1 ici)
            printf("NON Binaire (Bitwise NOT sur num1) : %d\n", ~num1);
            break;

        default:
            printf("Operateur inconnu !\n");
            break;
    }

    return 0;
}

