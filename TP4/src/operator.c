#include "operator.h"

int somme(int num1, int num2) { return num1 + num2; }
int difference(int num1, int num2) { return num1 - num2; }
int produit(int num1, int num2) { return num1 * num2; }
int quotient(int num1, int num2) { return (num2 != 0) ? num1 / num2 : 0; }
int modulo(int num1, int num2) { return (num2 != 0) ? num1 % num2 : 0; }
int et_logique(int num1, int num2) { return num1 & num2; }
int ou_logique(int num1, int num2) { return num1 | num2; }
int negation(int num1) { return ~num1; }
