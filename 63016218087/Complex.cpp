//File Name: Complex.cpp
//Author: 李晓鹏
//Student Number: 3016218087
//Email: 1940913015@qq.com
//Assignment:#3
//Version: 20170328
//Description: 该CPP程序用于Complex.h的实现，通过构造函数来产生新对象，通过一系列函数的调用来改变对象内容，输出用COUT到屏幕上
/*Future Improvements:
1.每个函数的注释要更加详细
2.要优化代码的总行数，减少冗余代码
3.变量命名要更有意义
4.指针的使用要正确得当*/
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include "Complex.h"
using namespace std;


//构造函数
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
    this -> b = 0;
}
//析构函数
Complex::~Complex()
{
    a = b = 0;
}
//获取实部和虚部
const double Complex::getRealPart() const
{
    return this -> a;
}
const double Complex::getImaginaryPart() const
{
    return this -> b;
}
//运算符加减乘除绝对值函数
Complex Complex:: add(const Complex sc) const
{
    double r = a + sc.a;
    double i = b + sc.b;
    return Complex(r , i);
}
Complex Complex:: subtract(const Complex sc) const
{
    double r = a - sc.a;
    double i = b - sc.b;
    return Complex(r , i);
}
Complex Complex:: multiply(const Complex sc) const
{
    double r = a * sc.a - b * sc.b;
    double i = b * sc.a + a * sc.b;
    return Complex(r , i);
}
Complex Complex:: divide(const Complex sc) const
{
    double r = (a * sc.a + b * sc.b) / (sc.a * sc.a + sc.b * sc.b);
    double i = (b * sc.a - a * sc.b) / (sc.a * sc.a + sc.b * sc.b);
    return Complex(r , i);
}
double Complex::abs() const
{
    double length = sqrt(a * a + b * b);
    return length;
}
//转为字符串a＋bi，如果虚部为0，只显示a
std::string Complex::toString() const
{
    stringstream ss;
    if (b != 0)
    {
        if(b > 0)
        {
            ss << a << "+" << b << "i";
        }
        else
        {
            ss << a << b << "i";
        }

    }
    else
    {
        ss << a ;
    }
    return ss.str();
}
//运算符+=，-=，*=，/=重载
Complex& Complex::operator+=(const Complex& sc)
{
    *this = add(sc);
    return *this;
}
Complex& Complex::operator-=(const Complex& sc)
{
    *this = subtract(sc);
    return *this;
}
Complex& Complex::operator*=(const Complex& sc)
{
    *this = multiply(sc);
    return *this;
}
Complex& Complex::operator/=(const Complex& sc)
{
    *this = divide(sc);
    return *this;
}
//重载【】
double& Complex::operator[](const int index)
{
    if (index == 0)
        return a;
    else
        return b;
}
const double& Complex::operator[](const int index) const
{
    if (index == 0)
        return a;
    else
        return b;
}
//一元加减运算符重载
Complex Complex:: operator+() const
{
    return *this;
}
Complex Complex:: operator-() const
{
    return Complex(-a , -b);
}
//前置++与--重载
Complex& Complex:: operator++()
{
    a = a + 1;
    return *this;
}
Complex& Complex:: operator--()
{
    a = a - 1;
    return *this;
}
//后置++与--重载
Complex Complex::operator++(int mercy)//函数重载
{
    Complex temp(a , b);
    a = a + 1;
    return temp;
}
Complex Complex::operator--(int mercy)//函数重载
{
    Complex temp(a , b);
    a = a - 1;
    return temp;
}


//输入输出字符串重载
std::ostream& operator<<(std::ostream& ostr , const Complex& sc)
{
    cout << sc.toString();
    return ostr;
}
std::istream& operator>>(std::istream& ostr , Complex& sc)
{
    ostr >> sc[0] >> sc[1];
    return ostr;
}

//非成员函数加减乘除重载
Complex operator+(const Complex& sc1 , const Complex& sc2)
{
    return sc1.add(sc2);
}
Complex operator-(const Complex& sc1 , const Complex& sc2)
{
    return sc1.subtract(sc2);
}
Complex operator*(const Complex& sc1 , const Complex& sc2)
{
    return sc1.multiply(sc2);
}
Complex operator/(const Complex& sc1 , const Complex& sc2)
{
    return sc1.divide(sc2);
}
