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
#include <cstdlib>
#include <algorithm>
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
int& IntList::operator[](const int index){
    return values[index];
}
const int& IntList::operator[](const int index) const{
    return values[index];
}
bool operator==(const IntList& il1, const IntList& il2){
    if(il1.size() != il2.size()){
        return false;
    }
    else{
        for(int i = 0; i < il1.size(); ++i){
            if(il1[i] != il2[i]){
                return false;
            }
        }
    }
    return true;
}
bool operator!=(const IntList& il1, const IntList& il2){
    if(il1.size() != il2.size()){
        return true;
    }
    else{
        for(int i = 0; i < il1.size(); ++i){
            if(il1[i] != il2[i]){
                return true;
            }
        }
    }
    return false;
}
IntList operator+(const IntList& il1, const IntList& il2){
    const int bigSize = max(il1.size(), il2.size());
    const int smallSize = min(il1.size(), il2.size());
    int i = 0;
    IntList result(bigSize, 0);
    for(i = 0; i < smallSize; ++i){
        result[i] = il1[i] + il2[i];
    }
    for( ; i < bigSize; ++i){
        if(il1.size() < bigSize){
            result[i] = il2[i];
        }
        else{
            result[i] = il1[i];
        }
    }
    return result;
}
IntList operator-(const IntList& il1, const IntList& il2){
    const int bigSize = max(il1.size(), il2.size());
    const int smallSize = min(il1.size(), il2.size());
    int i = 0;
    IntList result(bigSize,0);
    for(i = 0; i < smallSize; ++i){
        result[i] = il1[i] - il2[i];
    }
    for( ; i < bigSize; ++i){
        if(il1.size() < bigSize){
            result[i] = il2[i];
        }
        else{
            result[i] = il1[i];
        }
    }
    return result;
}
std::ostream& operator<<(std::ostream& ost, const IntList& il){
    ost << il.size() << ":";
    for(int i = 0; i < il.size(); ++i){
        ost << il[i] << " ";
    }
    return ost;
}
std::istream& operator>>(std::istream& ist, IntList& il){
    int i = 0;
    ist >> i;
    IntList newIntList(i,0);
    for(int j = 0; j < i; ++j){
        ist >> newIntList[j];
    }
    il = newIntList;
    return ist;
}








