#include <iostream>

using namespace std;

int main() 
{
int numero;
cout << "Ingrese un número: ";
cin >> numero;

if (numero % 2 == 0) 
{
cout << "El número " << numero << " es par. " << endl;
} else 
{
cout << "El número " << numero << " es impar. " << endl;
}
return 0;
}