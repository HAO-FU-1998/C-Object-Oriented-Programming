//Fail Name:IitList.h
//Author:郭培溟
//Student Number:3016218085
//Email:1072671422@qq.com
//Assignment:1
//Version:1.01
//Description:实现一个数组的类，要求使用动态内存，实现resize功能，可以变换数组长度，实现push_back功能，要求增加增加一个整数
//输出数组的长度以及数组中的所有数据
//输出到屏幕
//Future Improvements:
//1.增加其他的运算符重载
//2.增加一些其他功能函数
//3.支持输出到文件

#ifndef INTLIST_H_INCLUDED
#define INTLIST_H_INCLUDED
using namespace std;

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


#endif // INTLIST_H_INCLUDED
