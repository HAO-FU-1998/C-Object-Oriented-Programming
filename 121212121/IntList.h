// File Name: IntList.cpp
// Author: 傅淏
// Student Number: 3016218083
// Email: 907571579@qq.com
// Assignment: 1
// Version: 1
// Description: 运用类的思想，通过函数的构造，拷贝，析构，size与resize，push back操作以及运算符重载来实现对一个数组的一些操作
// Future Improvements: 1、缩短编程时间，熟练编程。2、注意加强注释的使用及简洁。3、尽量使用最简便的算法。

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
    int *star; //用于变量的push back
};

#endif /* defined(__IntList__IntList__) */
