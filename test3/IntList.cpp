//File Name: IntList.cpp
//Author: ������
//Student Number: 3016218087
//Email: 1940913015@qq.com
//Assignment:#4
//Version: 20170330
//Description: ��CPP��������IntList.h��ʵ�֣�ͨ�����캯���������¶���ͨ��һϵ�к����ĵ������ı�������ݣ������COUT����Ļ��
/*Future Improvements:
1.ÿ��������ע��Ҫ������ϸ
2.Ҫ�Ż�������������������������
3.��������Ҫ��������
4.ָ���ʹ��Ҫ��ȷ�õ�*/
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <algorithm>
#include "IntList.h"

using namespace std;


//���캯��
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

//��������
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

//��������
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

//���������
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


//SIZE����
int IntList::size() const
{
    return this -> numberValues;
}

//RESIZE����
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

//PUSH-BACK��������
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

//PRINT���
void IntList::print()
{
    std::cout<< this->numberValues << ":";
    for (int i = 0; i < this->size(); ++i)
    {
        std::cout<< this->values[i] << " ";
    }
    std::cout << std::endl;
}
//���ء���
int& IntList::operator [] ( const int index)
{
        return values[index];
}
const int& IntList::operator [] ( const int index) const
{
        return values[index];
}
//�������������
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
//����������������
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
