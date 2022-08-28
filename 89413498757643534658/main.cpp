//
//  main.cpp
//  Complex
//
//  Created by Yevon Zhang on 17/3/26.
//  Copyright (c) 2017Äê Yevon Zhang. All rights reserved.
//

#include <iostream>
#include "Complex.h"
#include <iomanip>
#include "stdlib.h"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Complex!\n";
    Complex a(0.009499,0.06);
    Complex b(7.888888,-9.987);
    Complex c;

    cout<<"------------"<<endl;
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
    cout<<"------------"<<endl;
    cout<<a+b<<endl;
    cout<<a-b<<endl;
    cout<<a*b<<endl;
    cout<<a/b<<endl;
    cout<<"------------"<<endl;
    cout<<a.abs()<<endl;
    cout<<b.toString()<<endl;
    cout<<"------------"<<endl;
    cout<<a<<endl;
    cout<<(a+=b)<<endl;
    cout<<(a-=b)<<endl;
    cout<<(a*=b)<<endl;
    cout<<(a/=b)<<endl;
    cout<<a<<endl;
    cout<<"------------"<<endl;
    cout<<++a<<endl;
    cout<<a++<<endl;
    cout<<--a<<endl;
    cout<<a--<<endl;
    cout<<"------------"<<endl;
    cout<<a/c<<endl;

    return 0;
}

