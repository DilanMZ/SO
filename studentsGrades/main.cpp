#include <iomanip>
#include <iostream>
#include <list>
#include <string>
using namespace std;

void grades();

int main() { grades(); }

void grades() {
  bool validation = false;
  int option = 0;
  double grade = 0;
  list<double> gradesList;

  cout << "Welcome to the OS students grades" << endl;

  do {

    cout << "\nPlease choose an option\n1. Join grades\n2. list all grades\n3. "
            "exit\n"
         << endl;
    cin >> option;

    switch (option) {
    case 1:
      cout << "Join the grade of the student: ";
      cin >> grade;
      gradesList.push_back(grade);
      validation = true;
      break;
      

    case 2:
      if (validation) {
        int counter = 0;
        for (double i : gradesList) {
          counter++;
          cout << fixed << setprecision(2);
          cout << to_string(counter) + ". Grade: " + to_string(i) << endl;
        }
      } else {
        cout << "Haven't inserted grades yet" << endl << endl;
      }
      break;

    case 3:
      cout << "\nCome back" << endl;

      break;

    default:
      cout << "Please retry" << endl;
      break;
    }
  } while (option != 3);
}
