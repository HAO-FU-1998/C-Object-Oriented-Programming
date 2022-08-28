#include <iostream>
#include "Complex.h"
using namespace std;

int main()
{
    Complex c1;
    Complex c2;
    cout << "Enter the first complex number: ";
    cin >> c1;
    cout << "Enter the second complex number: ";
    cin >> c2;
    cout << c1 << " + " << c2 << " = " << c1 + c2 << endl;
    cout << c1 << " - " << c2 << " = " << c1 - c2 << endl;
    cout << c1 << " * " << c2 << " = " << c1 * c2 << endl;
    cout << c1 << " / " << c2 << " = " << c1 / c2 << endl;
    cout << "|" << c1 << "|" << " = " << c1.abs() << endl;
    return 0;
}
