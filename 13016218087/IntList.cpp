//File Name: IntList.cpp
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
#include <iostream>
#include <stdio.h>
#include "IntList.h"

using namespace std;


//构造函数
IntList::IntList(int numVals  , int val)
{
    if (numVals > 0)
    {
        numberValues = numVals;
        values = new int [numVals];
        for (int i = 0 ; i < numVals ; ++i)
            values[i] = val;
    }
    else
    {
        numberValues = 0;
        values = NULL;
    }
}

//拷贝函数
IntList::IntList(const IntList &il)
{
    numberValues = il.size();
    if (numberValues > 0)
    {
        values = new int [numberValues];
        for (int i = 0 ; i < numberValues ; i++)
            values[i] = il.values[i];
    }
}

//析构函数
IntList::~IntList()
{
    delete [] values;
    numberValues = 0;
    values = NULL;
}

//运算符重载
IntList& IntList::operator=(const IntList &il)
{
    if (this != &il)
    {
        numberValues = il.size();
        delete [] values;
        values = NULL;
        if (numberValues > 0)
        {
            values = new int [numberValues];
            for (int i = 0 ; i < numberValues ; i++)
                values[i] = il.values[i];
        }
    }
}


//SIZE函数
int IntList::size() const
{
    return this -> numberValues;
}

//RESIZE函数
void IntList::resize (int n  , int val )
{
    if (n <= 0)
    {
        numberValues = 0;
        delete [] values;
        values = NULL;
    }
    else
    {
        if (n > numberValues)
        {
            int *dva;
            dva = new int [n];
            for (int i = 0 ; i < numberValues ; i++)
                dva[i] = values[i];
            for (int j = numberValues ; j < n  ; j++)
                dva[j] = val;
            numberValues = n;
            values = new int [n];
            for (int k = 0 ; k < n ; k++)
                values[k] = dva[k];
            delete [] dva;
        }
        else
        {
            int *dva;
            dva = new int [n];
            for (int i = 0 ; i < n ; i++)
                dva[i] = values[i];
            numberValues = n;
            values = new int [n];
            for (int i = 0 ; i < n ; i++)
                values[i] = dva[i];
            delete [] dva;
        }

    }
}

//PUSH-BACK操作函数
void IntList::push_back (int val)
{
    if(this != NULL)
    {
        int *dva;
        dva = new int [numberValues + 1];
        for (int i = 0 ; i < numberValues ; i++)
            dva[i] = values[i];
        dva[numberValues] = val;
        numberValues = numberValues + 1;
        values = new int [numberValues];
        for (int i = 0 ; i < numberValues ; i++)
            values[i] = dva[i];
        delete [] dva;
    }
    else
    {
        values = new int [1];
        values[0] = val;
        numberValues = 1;
    }
}

//PRINT结果
void IntList::print()
{
    std::cout<< this->numberValues << ":";
    for (int i = 0; i < this->size(); ++i)
    {
        std::cout<< this->values[i] << " ";
    }
    std::cout << std::endl;
}
