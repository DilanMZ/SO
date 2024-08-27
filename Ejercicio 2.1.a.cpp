#include "iostream"

using namespace std;

bool bisiesto (int año)
{
return ((año%4==0 && año%100!=0 )|| año%400==0); // Un año es bisiesto si cumple lo siguiente: es divisible por 4 y no lo es por 100 o sí es divisible por 400.
}

int main()
{
int año;
cout << "Ingrese el año: ";
cin >> año;
if (bisiesto(año))
cout << "El año " << año << " es bisiesto.\n\n";
else
cout << "El año " << año << " NO es bisiesto.\n\n";
return 0;
}