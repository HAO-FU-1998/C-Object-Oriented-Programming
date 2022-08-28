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
  std::cout<< this->numberValues << ":";
  for (int i = 0; i < this->size(); ++i)
  {
    std::cout<< this->values[i] << " ";
  }
  std::cout << std::endl;
}

int main()
{
    std::cout << "Your Student No. and Name" << std::endl;
    IntList a(5 , 1);
    std::cout << "a(5,1)" << std::endl;
    a.print();
    a.resize(6,2);
    std::cout << "a.resize(6,2)" << std::endl;
    a.print();
    a.resize(4,2);
    std::cout << "a.resize(4,2)" << std::endl;
    a.print();
    IntList b;
    std::cout << "b" << std::endl;
    b.print();
    a=b;
    std::cout << "a=b" << std::endl;
    a.print();
    b.print();
    b.push_back(2);
    std::cout << "b.push_back(2)" << std::endl;
    a.print();
    b.print();
    b=b;
    std::cout << "b=b" << std::endl;
    a.print();
    b.print();
    b=a;
    std::cout << "b=a" << std::endl;
    a.print();
    b.print();
    b.push_back(2);
    std::cout << "b.push_back(2)" << std::endl;
    a.print();
    b.print();
    std::cout << "Program ended with exit code: 0" << std::endl;

    return 0;
}
