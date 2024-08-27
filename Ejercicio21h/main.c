#include <stdio.h>

int main() {
    int num1, num2, num3;
    
    
    printf("Introduce el primer número: ");
    scanf("%d", &num1);
    
    printf("Introduce el segundo número: ");
    scanf("%d", &num2);
    
    printf("Introduce el tercer número: ");
    scanf("%d", &num3);
    
    
    if (num1 >= num2 && num1 >= num3) {
        printf("El numero mayor es: %d\n", num1);
    } else if (num2 >= num1 && num2 >= num3) {
        printf("El numero mayor es: %d\n", num2);
    } else {
        printf("El numero mayor es: %d\n", num3);
    }

    return 0;
}