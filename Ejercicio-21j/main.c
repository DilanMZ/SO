#include <stdio.h>

int main() {
    int numero;

    
    printf("Decimal\tOctal\tHexadecimal\n");

   
    for (numero = 1; numero <= 10; numero++) {
        printf("%d\t%o\t%x\n", numero, numero, numero);
    }

    return 0;
}