//File Name: IntList.cpp
//Author: ������
//Student Number: 3016218087
//Email: 1940913015@qq.com
//Assignment:#1
//Version: 1.0
//Description: ��CPP��������IntList.h��ʵ�֣�ͨ�����캯���������¶���ͨ��һϵ�к����ĵ������ı�������ݣ������COUT����Ļ��
/*Future Improvements:
1.ÿ��������ע��Ҫ������ϸ
2.Ҫ�Ż�������������������������
3.��������Ҫ��������
4.ָ���ʹ��Ҫ��ȷ�õ�*/
#include <iostream>
#include <stdio.h>
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
    numberValues = il.size();
    if (numberValues > 0)
    {
        values = new int [numberValues];
        for (int i = 0 ; i < numberValues ; i++)
            values[i] = il.values[i];
    }
}

//��������
IntList::~IntList()
{
    delete [] values;
    numberValues = 0;
    values = NULL;
}

//���������
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

//PUSH-BACK��������
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
