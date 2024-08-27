#include <iostream>
using namespace std;

int main()
{
int numero, i;
long double factorial = 1;

cout<< "Ingresa un número: "; 
cin >> numero;

for (i=1; i <= numero; i++) // El factorial de un número es la multiplicación de los números que están comprendidos entre 1 hasta dicho número.
factorial = factorial * i;
cout << "Factorial de " << numero << " es: " << factorial << endl;
return 0;
}