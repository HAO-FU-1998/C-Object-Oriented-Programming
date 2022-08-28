//File Name: IntList.h
//Author: 李晓鹏
//Student Number: 3016218087
//Email: 1940913015@qq.com
//Assignment:#1
//Version: 1.0
//Description: 该CPP程序用于IntList.h的实现，通过构造函数来产生新对象，通过一系列函数的调用来改变对象内容，输出用COUT到屏幕上
/*Future Improvements:
1.每个函数的注释要更加详细
2.要优化代码的总行数，减少冗余代码
3.变量命名要更有意义
4.指针的使用要正确得当*/
#ifndef __IntList__IntList__
#define __IntList__IntList__

#include <stdio.h>

class IntList {

public:
    //function members
    IntList(int numVals = 0, int val = 0); // constructor
    IntList(const IntList &il); // copy constructor
    ~IntList(); // destructor
    IntList& operator=(const IntList &il); // = operator
    int size() const; // size of the list
    // resize list
    //当n大于原来的size，使用val初始化多出的元素
    //当n小于原谅的size，直接截断原list
    void resize(int n = 0, int val = 0);// resize list
    void push_back(int val); // add new last element
    //print the list
    //输出格式  列表长度：元素1 元素2 元素3 ...
    void print();//print the list

private:
    // data members
    int * values; //pointer to elements
    int numberValues; //size of list
};

#endif /* defined(__IntList__IntList__) */
