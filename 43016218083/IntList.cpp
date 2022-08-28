// File Name: IntList.cpp
// Author: 傅淏
// Student Number: 3016218083
// Email: 907571579@qq.com
// Assignment: 4
// Version: 2
// Description: 运用类的思想，通过函数的构造，拷贝，析构，size与resize，push back操作以及运算符重载来实现对一个数组的一些操作
// Future Improvements: 1、缩短编程时间，熟练编程。2、注意加强注释的使用及简洁。3、尽量使用最简便的算法。
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <algorithm>
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
    if (il.numberValues > 0)
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
      int *star = new int [n];
      for (int i = 0; i < numberValues; i++)
      {
        star[i] = values[i];
      }
      for (int j = numberValues; j < n; j++)
      {
        star[j] = val;
      }
      numberValues = n;
      delete [] values;
      values = star;
      star = NULL;
    }
    else
    {
      numberValues = n;
    }
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

// Overload
int& IntList::operator [] (const int index)
{
  return values[index];
}

const int& IntList::operator [] (const int index) const
{
  return values[index];
}

// Overload equal operator
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

// Overload not equal operator
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

// Overload plus operator
IntList operator + (const IntList& il1, const IntList& il2)
{
  int largeSize = max(il1.size(), il2.size());
  int smallSize = min(il1.size(), il2.size());
  int j = 0;
  IntList star(largeSize, 0);

  for (j = 0; j < smallSize; j++)
  {
    star[j] = il1[j] + il2[j];
  }
  for ( ; j < largeSize; j++)
  {
    if (il1.size() < largeSize)
    {
      star[j] = il2[j];
    }
    else
    {
      star[j] = il1[j];
    }
  }
  return star;
}

// Overload subtract operator
IntList operator - (const IntList& il1, const IntList& il2)
{
  int largeSize = max(il1.size(), il2.size());
  int smallSize = min(il1.size(), il2.size());
  int j = 0;
  IntList star(largeSize, 0);

  for (j = 0; j < smallSize; j++)
  {
    star[j] = il1[j] - il2[j];
  }
  for ( ; j < largeSize; j++)
  {
    if (il1.size() < largeSize)
    {
      star[j] = il2[j];
    }
    else
    {
      star[j] = il1[j];
    }
  }
  return star;
}

// Overload input and output operators
std::ostream& operator << (std::ostream& ost, const IntList& il)
{
  ost << il.size() << ":";
  for (int i = 0; i < il.size(); ++i)
  {
    ost << il[i] << " ";
  }
  return ost;
}

std::istream& operator >> (std::istream& ist, IntList& il)
{
  int i = 0;
  ist >> i;
  IntList newIntList (i, 0);
  for (int j = 0; j < i; ++j)
  {
    ist >> newIntList[j];
  }
  il = newIntList;
  return ist;
}
