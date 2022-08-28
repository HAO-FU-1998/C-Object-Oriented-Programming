//File Name: Complex.cpp
//Author: ������
//Student Number: 3016218087
//Email: 1940913015@qq.com
//Assignment:#3
//Version: 20170328
//Description: ��CPP��������Complex.h��ʵ�֣�ͨ�����캯���������¶���ͨ��һϵ�к����ĵ������ı�������ݣ������COUT����Ļ��
/*Future Improvements:
1.ÿ��������ע��Ҫ������ϸ
2.Ҫ�Ż�������������������������
3.��������Ҫ��������
4.ָ���ʹ��Ҫ��ȷ�õ�*/
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include "Complex.h"
using namespace std;


//���캯��
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
//��������
Complex::~Complex()
{
    a = b = 0;
}
//��ȡʵ�����鲿
const double Complex::getRealPart() const
{
    return this -> a;
}
const double Complex::getImaginaryPart() const
{
    return this -> b;
}
//������Ӽ��˳�����ֵ����
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
//תΪ�ַ���a��bi������鲿Ϊ0��ֻ��ʾa
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
//�����+=��-=��*=��/=����
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
//���ء���
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
//һԪ�Ӽ����������
Complex Complex:: operator+() const
{
    return *this;
}
Complex Complex:: operator-() const
{
    return Complex(-a , -b);
}
//ǰ��++��--����
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
//����++��--����
Complex Complex::operator++(int mercy)//��������
{
    Complex temp(a , b);
    a = a + 1;
    return temp;
}
Complex Complex::operator--(int mercy)//��������
{
    Complex temp(a , b);
    a = a - 1;
    return temp;
}


//��������ַ�������
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

//�ǳ�Ա�����Ӽ��˳�����
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
