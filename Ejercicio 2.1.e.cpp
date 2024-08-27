#include <iostream>

using namespace std;

int main() 
{
int serie;
    
cout << "¿De cuántos dígitos quieres que sea la serie?: ";
cin >> serie; // NUMERO DE TERMINOS A CALCULAR
    
int a = 0, b= 1;
cout << "Los primeros " << serie << " números de Fibonacci son:" <<endl;
cout << a << " " << b << " "; // Imprimir los primeros dos terminos de fibonacci
   
for (int i = 2; i < serie; ++i)  // Calcular e imprimir los siguientes terminos de Fibonacci
{
int c = a + b;
cout << c << " ";
a = b;
b = c;
}

return 0;
}