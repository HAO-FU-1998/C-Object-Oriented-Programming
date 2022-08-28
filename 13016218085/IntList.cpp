//Fail Name:IitList.cpp
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

#include <iostream>
#include "IntList.h"
using namespace std;

IntList::IntList(int numVals, int val){//constructor:默认长度为0,
    if(numVals > 0){
        numberValues = numVals;
        values = new int [numberValues];
        for(int i = 0; i < numberValues; i++){
            values[i] = val;
        }
    }
    else{//当长度为零时，不申请内存，values指向NULL
        numberValues = 0;
        values = NULL;
    }
}
IntList::IntList(const IntList & il){//拷贝构造函数：注意深拷贝和浅拷贝的问题，构造出来的新的IntList要申请一片新的内存
    if(il.numberValues > 0){
        numberValues = il.numberValues;
        values = new int[numberValues];
        for(int i = 0; i < numberValues; i++){
            values[i] = il.values[i];
        }
    }
    else{//同样要注意numberValues = 0 的情况
        numberValues = 0;
        values = NULL;
    }
}
IntList::~IntList(){//destructor要释放内存，
    if(numberValues > 0){
        delete [] values;
        numberValues = 0;
        values = NULL;
    }
    else
        values = NULL;
}
IntList& IntList::operator=(const IntList & il){//=运算符重载，仍然注意numberValues = 0 的情况
    if(this != &il && il.numberValues > 0){
        delete [] values;
        numberValues = il.numberValues;
        values = new int [numberValues];
        for(int i = 0; i < numberValues; i++){
            values[i] = il.values[i];
        }
    }
    else if(this != &il && il.numberValues == 0){
        delete [] values;
        numberValues = il.numberValues;
        values = NULL;
    }
    else
        return *this;
    return *this;
}
int IntList::size() const{//返回IntList的大小，即numberValues
    return numberValues;
}
void IntList::resize(int n, int val){//当n大于原来的size，使用val初始化多出的元素，当n小于原谅的size，直接截断原list
    if(n > numberValues){
        int* temp = new int [n];
        for(int i = 0; i < n; i++){
            temp[i] = val;
        }
        for(int i = 0; i < numberValues; i++){
            temp[i] = values[i];
        }
        numberValues = n;
        delete [] values;
        values = temp;
        temp = NULL;
    }
    else if(n <=numberValues && n !=0){
        numberValues = n;
    }
    else{
        numberValues = 0;
        delete [] values;
        values = NULL;
    }
}
void IntList::push_back(int val){
    numberValues++;
    int * temp = new int [numberValues];
    for(int i = 0; i < numberValues - 1; i++){
        temp[i] = values[i];
    }
    temp[numberValues - 1] = val;
    delete [] values;
    values = temp;
    temp = NULL;
}
void IntList::print()
{
    std::cout<< this->numberValues << ":";
    for (int i = 0; i < this->size(); ++i)
    {
        std::cout<< this->values[i] << " ";
    }
    std::cout << std::endl;
}
