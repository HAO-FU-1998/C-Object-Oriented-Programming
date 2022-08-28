// File Name: IntList.cpp
// Author: ���B
// Student Number: 3016218083
// Email: 907571579@qq.com
// Assignment: 1
// Version: 1
// Description: �������˼�룬ͨ�������Ĺ��죬������������size��resize��push back�����Լ������������ʵ�ֶ�һ�������һЩ����
// Future Improvements: 1�����̱��ʱ�䣬������̡�2��ע���ǿע�͵�ʹ�ü���ࡣ3������ʹ��������㷨��
#include <iostream>
#include <stdio.h>
#include "IntList.h"

using namespace std;

// Constructor
IntList::IntList(int numVals, int val)
{
  if (numVals > 0)
  {
    values = new int [numVals];
    numberValues = numVals;

    for (int i = 0; i < numVals; i ++)
    {
      values[i] = val;
    }
  }
  else
  {
    values = NULL;
    numberValues = 0;
  }
}

// Copy Constructor
IntList::IntList(const IntList &il)
{
  if (il.numberValues > 0)
  {
    numberValues = il.size();
    values = new int [numberValues];

    for (int j = 0; j < numberValues; j ++)
    {
      values[j] = il.values[j];
    }
  }
  else
  {
    numberValues = 0;
    values = NULL;
  }
}

// Destructor
IntList::~IntList()
{
  if (numberValues > 0)
  {
    delete [] values;
    values = NULL;
    numberValues = 0;
  }
  else
  {
    values = NULL;
  }
}

// = Operator
IntList& IntList::operator = (const IntList &il)
{
  if (this != &il)
  {
    if (numberValues > 0)
    {
      numberValues = il.size();
      delete [] values;
      values = new int [numberValues];

      for (int k = 0; k < numberValues; k ++)
        values[k] = il.values[k];
    }
    else
    {
      numberValues = il.size();
      delete [] values;
      values = NULL;
    }
  }
  return *this;
}

// Size of the list
int IntList::size() const
{
  return this -> numberValues;
}

// Resize list
void IntList::resize(int n, int val)
{
  if (n > numberValues)
  {
    int* temp = new int [n];

    for (int i = 0; i < n; i++)
    {
      temp[i] = val;
    }
    for (int i = 0; i < numberValues; i++)
    {
      temp[i] = values[i];
    }

    numberValues = n;
    delete [] values;
    values = temp;
    temp = NULL;
  }
  else if (n <= numberValues && n != 0)
  {
    numberValues = n;
  }
  else
  {
    numberValues = 0;
    delete [] values;
    values = NULL;
  }
}

// Add new last element
void IntList::push_back(int val)
{
  int *star = new int [numberValues + 1];

  for (int i = 0; i < numberValues; i ++)
  {
    star[i] = values[i];
  }
  star[numberValues] = val;
  numberValues += 1;
  delete [] values;
  values = star;
  star = NULL;
}

// Print
void IntList::print()
{
  std::cout << this -> numberValues << ":";
  for (int i = 0; i < this -> size(); ++i)
  {
    std::cout << this -> values[i] << " ";
  }
  std::cout << std::endl;
}









//
//  main.cpp
//  IntList
//
//  Created by Yevon Zhang on 17/2/14.
//  Copyright (c) 2017�� Yevon Zhang. All rights reserved.
//

#include <iostream>
#include "IntList.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    IntList a(10,3);
    IntList b;
    IntList c(b);

    a.print();
    b.print();
    c.print();

    b.push_back(2);
    b.push_back(3);
    b.print();

    c=a;
    c.print();

    a.resize(0,1);
    a.print();

    b.resize(8,4);
    a=b;
    a.print();
    b.print();

    b=a;
    IntList d(b);
    b.print();
    d.print();

std::cout << "Your Student No. and Name\n";
IntList a(5,1);
std::cout << "a(5,1)\n";
a.print();
//
a.resize(6,2);
std::cout << "a.resize(6,2)\n";
a.print();
//
a.resize(4,2);
std::cout << "a.resize(4,2)\n";
a.print();
//
//
IntList b;
std::cout << "b\n";
b.print();
//
a=b;
std::cout << "a=b\n";
a.print();
b.print();
//
b.push_back(2);
std::cout << "b.push_back(2)\n";
a.print();
b.print();
//
b=b;
std::cout << "b=b\n";
a.print();
b.print();
//
b=a;
std::cout << "b=a\n";
a.print();
b.print();
//
b.push_back(2);
std::cout << "b.push_back(2)\n";
a.print();
b.print();
//
    return 0;
}


