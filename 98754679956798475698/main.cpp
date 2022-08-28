//
//  main.cpp
//  IntList
//
//  Created by Yevon Zhang on 17/2/14.
//  Copyright (c) 2017Äê Yevon Zhang. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "IntList.h"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    IntList a(10,3);
    IntList b;
    IntList c(b);
    const IntList ca;

    std::ifstream fs;
    fs.open("test.txt");
    fs >> b;
    fs.close();
    c = b;

    cout<<"After file input b and c=b"<<endl;
    cout<<"a is "<<a<<endl;
    cout<<"b is "<<b<<endl;
    cout<<"c is "<<c<<endl;

    if(b == c){
        cout<<"if b==c"<<endl;
        cin>>b;
    }

    a.push_back(7);

    cout<<"After cout input b and a push_back"<<endl;
    cout<<"a is "<<a<<endl;
    cout<<"b is "<<b<<endl;
    cout<<"c is "<<c<<endl;

    cout<<"a+b is "<<(a+b)<<endl;
    cout<<"a-b is "<<(a-b)<<endl;

    c.resize(0,1);
    if(b != c){
        cout<<"if b!=c"<<endl;
        cout<<"b[1] is "<<b[1]<<endl;
    }
    return 0;
}

