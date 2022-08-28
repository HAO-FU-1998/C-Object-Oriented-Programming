//File Name: IntList.cpp
//Author: 李晓鹏
//Student Number: 3016218087
//Email: 1940913015@qq.com
//Assignment:#4
//Version: 20170330
//Description: 该CPP程序用于IntList.h的实现，通过构造函数来产生新对象，通过一系列函数的调用来改变对象内容，输出用COUT到屏幕上
/*Future Improvements:
1.每个函数的注释要更加详细
2.要优化代码的总行数，减少冗余代码
3.变量命名要更有意义
4.指针的使用要正确得当*/
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <algorithm>
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
    if (il.numberValues > 0)
    {
        numberValues = il.size();
        values = new int [numberValues];
        for (int i = 0 ; i < numberValues ; i++)
            values[i] = il.values[i];
    }
    else
    {
        numberValues = 0;
        values = NULL;
    }
}

//析构函数
IntList::~IntList()
{
    if (numberValues > 0)
    {
        delete [] values;
        numberValues = 0;
        values = NULL;
    }
    else
    {
        values = NULL;
    }

}

//运算符重载
IntList& IntList::operator=(const IntList &il)
{
    if (this != &il)
    {
        if (il.numberValues > 0)
        {
            delete [] values;
            numberValues = il.size();
            values = new int [numberValues];
            for (int i = 0 ; i < numberValues ; i++)
                values[i] = il.values[i];
        }
        else
        {
            delete [] values;
            numberValues = il.size();
            values = NULL;
        }
    }
    return *this;
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
            int *dva = new int [n];
            for (int i = 0 ; i < numberValues ; i++)
                dva[i] = values[i];
            for (int j = numberValues ; j < n  ; j++)
                dva[j] = val;
            numberValues = n;
            delete [] values;
            values = dva;
            dva = NULL;
        }
        else
        {
            numberValues = n;
        }

    }
}

//PUSH-BACK操作函数
void IntList::push_back (int val)
{
        int *dva = new int [numberValues + 1];
        for (int i = 0 ; i < numberValues ; i++)
            dva[i] = values[i];
        dva[numberValues] = val;
        numberValues = numberValues + 1;
        delete [] values;
        values = dva;
        dva = NULL;
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
//重载【】
int& IntList::operator [] ( const int index)
{
        return values[index];
}
const int& IntList::operator [] ( const int index) const
{
        return values[index];
}
//重载其他运算符
 bool operator == (const IntList& il1, const IntList& il2)
{
    if (il1.size() == il2.size())
    {
        int i = 0;
        while (i < il1.size() && il1[i] == il2[i])
        {
            i++;
        }
        if (i == il1.size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
bool operator != (const IntList& il1, const IntList& il2)
{
    if (il1.size() == il2.size())
    {
        int i = 0;
        while (i < il1.size() && il1[i] == il2[i])
        {
            i++;
        }
        if (i == il1.size())
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        return true;
    }
}

IntList operator+(const IntList& il1, const IntList& il2)
{
    int large = max(il1.size(), il2.size());
    int small = min(il1.size(), il2.size());
    int i = 0;
    IntList mercy(large, 0);
    for(i = 0; i < small; i++)
    {
        mercy[i] = il1[i] + il2[i];
    }
    for( ; i < large; i++)
    {
        if(il1.size() < large)
        {
            mercy[i] = il2[i];
        }
        else
        {
            mercy[i] = il1[i];
        }
    }
    return mercy;
}
IntList operator-(const IntList& il1, const IntList& il2)
{
    int large = max(il1.size(), il2.size());
    int small = min(il1.size(), il2.size());
    int i = 0;
    IntList mercy(large,0);
    for(i = 0; i < small; i++)
    {
        mercy[i] = il1[i] - il2[i];
    }
    for( ; i < large; i++)
    {
        if(il1.size() < large)
        {
            mercy[i] = il2[i];
        }
        else
        {
            mercy[i] = il1[i];
        }
    }
    return mercy;
}
//重载输入输出运算符
std::ostream& operator<<(std::ostream& ost, const IntList& il)
{
    ost << il.size() << ":";
    for(int i = 0; i < il.size(); ++i)
    {
        ost << il[i] << " ";
    }
    return ost;
}
std::istream& operator>>(std::istream& ist, IntList& il)
{
    int i = 0;
    ist >> i;
    IntList newIntList(i,0);
    for(int j = 0; j < i; ++j)
    {
        ist >> newIntList[j];
    }
    il = newIntList;
    return ist;
}
