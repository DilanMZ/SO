#include <iostream>
#include <vector>

using namespace std;

// Función para verificar si un número es primo
bool prime(int number) {
    if (number <= 1){
      return false;
    }
        
    for (int i = 2; i <= number/2; i++) {
        if (number % i == 0)
            return false;
    }
    return true;
}

// Función para mostrar los números primos en un vector
void primesInList(const vector<int>& numbers) {
    cout << "Prime numbers in the list: ";
    for (int num : numbers) {
        if (prime(num)) {
            cout << num << " ";
        }
    }
    cout << endl;
}

int main() {
    int option;
    do {
        cout << "\nWelcome to Menu:\n1. Check if a number is prime\n2. Find prime numbers in a list\n3. Exit\nChoose an option: ";
        cin >> option;

        switch (option) {
            case 1: {
                int number;
                cout << "Enter a number: ";
                cin >> number;
                if (prime(number)) {
                    cout << number << " is a prime number.\n";
                } else {
                    cout << number << " is not a prime number.\n";
                }
                break;
            }
            case 2: {
                int n;
                cout << "Enter the number of elements in the list: ";
                cin >> n;
                vector<int> numbers(n);
                cout << "Enter the numbers:\n";
                for (int i = 0; i < n; i++) {
                    cin >> numbers[i];
                }
                  primesInList(numbers);
                break;
            }

            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid option, please try again.\n";
        }
    } while (option != 4);

    return 0;
}