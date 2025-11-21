#include <stdio.h>

int main() {
    // --- 1. CHAR (Caractères) ---
    char c = 'A';
    signed char sc = -12;
    unsigned char uc = 250; 

    printf("--- CARACTERES ---\n");
    printf("char : %c\n", c);
    printf("signed char (en nombre) : %d\n", sc);
    printf("unsigned char (en nombre) : %u\n", uc);

    // --- 2. SHORT (Entiers courts) ---
    short s = -32000;
    unsigned short us = 65000;

    printf("\n--- SHORT ---\n");
    printf("short : %d\n", s);
    printf("unsigned short : %u\n", us);

    // --- 3. INT (Entiers standards) ---
    int i = -123456;
    unsigned int ui = 123456789;

    printf("\n--- INT ---\n");
    printf("int : %d\n", i);
    printf("unsigned int : %u\n", ui);

    // --- 4. LONG INT ---
    long int li = -2000000000L;
    unsigned long int uli = 4000000000UL;

    printf("\n--- LONG INT ---\n");
    printf("long int : %ld\n", li);       // %ld pour Long Decimal
    printf("unsigned long int : %lu\n", uli); // %lu pour Long Unsigned

    // --- 5. LONG LONG INT ---
    long long int lli = -9000000000000000000LL;
    unsigned long long int ulli = 18000000000000000000ULL;

    printf("\n--- LONG LONG INT ---\n");
    printf("long long int : %lld\n", lli);       // %lld
    printf("unsigned long long int : %llu\n", ulli); // %llu

    // --- 6, 7, 8. FLOTTANTS (Nombres à virgule) ---
    float f = 3.14f;
    double d = 3.1415926535;
    long double ld = 3.14159265358979323846L;

    printf("\n--- FLOTTANTS ---\n");
    printf("float : %f\n", f);
    printf("double : %lf\n", d);        // %lf pour Long Float
    printf("long double : %Lf\n", ld);  // %Lf (L majuscule important)

    return 0;
}
