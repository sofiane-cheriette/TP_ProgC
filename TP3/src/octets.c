#include <stdio.h>

void afficher_octets(void *ptr, size_t taille, char *nom_type) {
    unsigned char *byte_ptr = (unsigned char *)ptr;
    
    printf("Octets de %s :\n ", nom_type);
    for (size_t i = 0; i < taille; i++) {
        printf("%02x ", byte_ptr[i]);
    }
    printf("\n\n");
}

int main() {
    short s = 258;          // 0x0102
    int i = 16909060;       // 0x01020304
    long int li = 16909060; 
    float f = 3.14f;
    double d = 3.14159;
    long double ld = 3.1415926535;

    afficher_octets(&s, sizeof(s), "short");
    afficher_octets(&i, sizeof(i), "int");
    afficher_octets(&li, sizeof(li), "long int");
    afficher_octets(&f, sizeof(f), "float");
    afficher_octets(&d, sizeof(d), "double");
    afficher_octets(&ld, sizeof(ld), "long double");

    return 0;
}
