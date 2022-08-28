#include <iostream>
#include "Rational.h"
#include "Irrational.h"
#include "Complex.h"
using namespace std;

int main()
{
    Number* list[5];
    list[0] = new Complex(0.5,0.5);
    list[1] = new Complex(5,5);
    list[2] = new Complex(5,0);
    list[3] = new Rational(10,2);
    list[4] = new Irrational(3.14159);
    cout<<  list[0]->toString()  << endl;   //=> 0.5+0.5i
    cout<<  list[1]->toString()  << endl;   //=> 5+5i
    cout<<  list[2]->toString()  << endl;   //=> 5
    cout<<  list[3]->toString()  << endl;   //=> 5
    cout<<  list[4]->toString()  << endl;   //=> 3.14159
    cout<<  ( (*list[0]) == (*list[1])  ? "Y" : "N" ) << endl;  //=> N
    cout<<  ( (*list[1]) != (*list[4])  ? "Y" : "N" ) << endl;  //=> Y
    cout<<  ( (*list[2]) == (*list[3])  ? "Y" : "N" ) << endl;  //=> Y
    cout<<  ( (*list[3]) == (*list[4])  ? "Y" : "N" ) << endl;  //=> N
    cout<<  ( (*static_cast<Real*>(list[3])) <= (*static_cast<Real*>(list[4]))  ? "Y" : "N" ) << endl;  //=> N

    return 0;
}
