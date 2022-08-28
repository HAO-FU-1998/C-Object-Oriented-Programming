#include <iostream>
#include "IntList.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    IntList a(10,3);
    IntList b;
    IntList c(b);

    a.print();
    b.print();
    c.print();

    b.push_back(2);
    b.push_back(3);
    b.print();

    c=a;
    c.print();

    a.resize(0,1);
    a.print();

    b.resize(8,4);
    a=b;
    a.print();
    b.print();

    b=a;
    IntList d(b);
    b.print();
    d.print();


//
    return 0;
}
