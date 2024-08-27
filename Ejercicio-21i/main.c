#include <stdio.h>

int main() {
    
    int numEntero = 5;
    float numFlotante;

    
    numFlotante = numEntero; 
    printf("Conversión implícita: numEntero = %d, numFlotante = %.2f\n", numEntero, numFlotante);

    
    float otroFlotante = 7.89;
    int nuevoEntero;

    
    nuevoEntero = (int) otroFlotante; 
    printf("Conversión explícita: otroFlotante = %.2f, nuevoEntero = %d\n", otroFlotante, nuevoEntero);

    return 0;
}