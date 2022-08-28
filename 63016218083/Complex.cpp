// File Name: Complex.cpp
// Author: 傅淏
// Student Number: 3016218083
// Email: 907571579@qq.com
// Assignment: 6
// Version: 1
// Description: 运用类的思想，通过运算符重载来实现对复数的一些操作
// Future Improvements: 1、缩短编程时间，熟练编程。2、注意加强注释的使用及简洁。3、尽量使用最简便的算法。
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include "Complex.h"

using namespace std;

// Constructor
Complex::Complex ()
{
  a = 0;
  b = 0;
}

Complex::Complex (const double a , const double b)
{
  this -> a = a;
  this -> b = b;
}

Complex::Complex (const double a)
{
  this -> a = a;
  b = 0;
}

// Destructor
Complex::~Complex()
{
  a = b = 0;
}

// Get the real part and the imaginary part
const double Complex::getRealPart() const
{
  return this -> a;
}

const double Complex::getImaginaryPart() const
{
  return this -> b;
}

// Four fundamental rules and absolute value of the operator
Complex Complex::add (const Complex sc) const
{
  double newRealPart = a + sc.a;
  double newImaginaryPart = b + sc.b;
  return Complex(newRealPart, newImaginaryPart);
}

Complex Complex::subtract (const Complex sc) const
{
  double newRealPart = a - sc.a;
  double newImaginaryPart = b - sc.b;
  return Complex(newRealPart, newImaginaryPart);
}

Complex Complex::multiply (const Complex sc) const
{
  double newRealPart = a * sc.a - b * sc.b;
  double newImaginaryPart = b * sc.a + a * sc.b;
  return Complex(newRealPart, newImaginaryPart);
}

Complex Complex::divide (const Complex sc) const
{
  double newRealPart = (a * sc.a + b * sc.b) / (sc.a * sc.a + sc.b * sc.b);
  double newImaginaryPart = (b * sc.a - a * sc.b) / (sc.a * sc.a + sc.b * sc.b);
  return Complex(newRealPart, newImaginaryPart);
}

double Complex::abs() const
{
  double length = sqrt(a * a + b * b);
  return length;
}

// Switch to the string
string Complex::toString() const
{
  stringstream temp;
  temp << a;
  string result = temp.str();
  if (b != 0)
  {
    temp.str("");
    temp << b;
    if (b > 0)
    {
      result = result + "+" + temp.str() + 'i';
    }
    else
    {
      result = result + temp.str() + 'i';
    }
  }
  return result;
}

// Overload logogram operator
Complex& Complex::operator += (const Complex& sc)
{
  *this = add(sc);
  return *this;
}

Complex& Complex::operator -= (const Complex& sc)
{
  *this = subtract(sc);
  return *this;
}

Complex& Complex::operator *= (const Complex& sc)
{
  *this = multiply(sc);
  return *this;
}

Complex& Complex::operator /= (const Complex& sc)
{
  *this = divide(sc);
  return *this;
}

// Overload [] operator
double& Complex::operator [] (const int index)
{
  if (index == 0)
  {
    return a;
  }
  else
  {
    return b;
  }
}

const double& Complex::operator [] (const int index) const
{
  if (index == 0)
  {
    return a;
  }
  else
  {
    return b;
  }
}

// Overload unary operator
Complex Complex::operator + () const
{
  return *this;
}

Complex Complex::operator - () const
{
  return Complex(-a , -b);
}

// Overload prepose and postpose operator
Complex& Complex::operator ++ ()
{
  a++;
  return *this;
}

Complex Complex::operator ++ (int star)
{
  Complex temp (a , b);
  a ++;
  return temp;
}

Complex& Complex::operator -- ()
{
  a--;
  return *this;
}

Complex Complex::operator -- (int star)
{
  Complex temp (a , b);
  a --;
  return temp;
}

// Overload input and output operators
std::ostream& operator << (std::ostream& ostr, const Complex& sc)
{
  ostr << sc.toString();
  return ostr;
}

std::istream& operator >> (std::istream& ostr, Complex& sc)
{
  ostr >> sc[0] >> sc[1];
  return ostr;
}

// Overload non-member unary operator
Complex operator + (const Complex& sc1 , const Complex& sc2)
{
  return sc1.add(sc2);
}

Complex operator - (const Complex& sc1 , const Complex& sc2)
{
  return sc1.subtract(sc2);
}

Complex operator * (const Complex& sc1 , const Complex& sc2)
{
  return sc1.multiply(sc2);
}

Complex operator / (const Complex& sc1 , const Complex& sc2)
{
  return sc1.divide(sc2);
}
