#include <stdio.h>

int Mayuscula(char letra) {
    // Si la letra está entre 'A' y 'Z', es una mayúscula
    if (letra >= 'A' && letra <= 'Z') {
        return 1;  // Devolver 1 si es mayúscula
    } else {
        return 0;  // Devolver 0 si no es mayúscula
    }
}

int main() {
    char letra;

    // Pedir al usuario que ingrese una letra
    printf("Introduce una letra: ");
    scanf("%c", &letra);

    // Verificar si la letra es mayúscula
    if (Mayuscula(letra)) {
        printf("La letra '%c' es mayúscula.\n", letra);
    } else {
        printf("La letra '%c' no es mayúscula.\n", letra);
    }

    return 0;
}