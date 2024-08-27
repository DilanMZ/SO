#include <stdio.h>

int Minuscula(char letra) {
    // Si la letra está entre 'A' y 'Z', es una mayúscula
    if (letra >= 'a' && letra <= 'z') {
        return 1;  
    } else {
        return 0;  
    }
}

int main() {
    char letra;

    
    printf("Introduce una letra: ");
    scanf("%c", &letra);

    // Verificar si la letra es mayúscula
    if (Minuscula(letra)) {
        printf("La letra '%c' es minuscula.\n", letra);
    } else {
        printf("La letra '%c' no es minuscula.\n", letra);
    }

    return 0;
}