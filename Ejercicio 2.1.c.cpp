#include <iostream>

using namespace std;

double potencia(int, int);

int main()
{
int base, exponente;
cout << "Introduzca base: ";
cin >> base;
do
{
cout << "Introduzca exponente: ";
cin >> exponente;
} while(exponente<0);
cout << base << " elevado a " << exponente << " = " << potencia(base,exponente) << endl;
return 0;
}

double potencia(int base, int exponente)
{
if (exponente==0)
return 1;
else
return base*(potencia(base,exponente-1)); // La potencia es el ejercicio de multiplicar la base por sí misma tantas veces como el exponente lo indique.
}