#include <iostream>

using namespace std;
class Base{ public:    void foo(){cout << "Base foo" << endl;}    void bar(){cout << "Base bar" << endl;} }; class Derived : public Base { public:    void foo(int x) {cout << "Derived foo" << endl;}    void bar() {cout << "Derived bar" << endl;} };

int main()
{
Base& rBase1 = *(new Derived);
rBase1.bar();
    return 0;
}
