//
//  main.cpp
//  IntList
//
//  Created by Yevon Zhang on 17/2/14.
//  Copyright (c) 2017å¹?Yevon Zhang. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "IntList.h"

using namespace std;

void test_print(const IntList il){
    cout<< il.size() << ":";
    for (int i = 0; i < il.size(); ++i)
        cout<< il[i] << " ";
    cout<<endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    IntList a(10,3);
    IntList b;
    IntList c;
    const IntList ca(3,4);

    /*std::ifstream fs;
    fs.open("test.txt");
    fs >> b >> c;
    fs.close();
    */

    cin >> b >> c;

    cout << endl;

    a=c;

    cout<< "test--" << "ca=";
    test_print(ca);
    cout<< "test--" << "a=";
    test_print(a);
    cout<< "test--" << "b=";
    test_print(b);
    cout<< "test--" << "c=";
    test_print(c);

    if (a == c) {
        cout<< "test--" << "a+c=";
        test_print(a+c);
    }
    if (a != b) {
        cout<< "test--" << "a-b=";
        test_print(a-b);
    }

    c.push_back(-9);
    c[0] = c[2];
    cout<< "test--" << "c=";
    test_print(c);

    a.resize(5,8);
    a[4] = b[2];
    cout<< "test--" << "a=";
    test_print(a);

    IntList *pa = new IntList(6);
    delete pa;
    cout<< "test--" << "pa=";
    test_print(*pa);

    IntList *pb = new IntList[3];
    pb[2].resize(3,-99);
    pb[2].push_back(-100);
    cout<< "test--" << "pb[2]=";
    test_print(pb[2]);


    /*
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
        cout<<"a[15] is "<<a[15]<<endl;
        cout<<"b[1] is "<<b[1]<<endl;
        cout<<"c[0] is "<<c[0]<<endl;
    }
     */
    return 0;
}
