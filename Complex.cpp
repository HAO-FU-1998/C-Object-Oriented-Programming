//  Complex.cpp
//  钟丽
//  3016218107
//  Leilani_zhong@163.com
//  3
//  20170331
//  能用简单的运算符号计算复数的加减乘除，并用<<,>> 进行简洁的输入输出
//  数据可从文件及控制台输入，以复数的格式输出
//  数据被输出到控制台或者文件中
/*  1.函数的使用及编写可以更简单
 2.考虑优化算法来提高效率
 */

#include"Complex.h"
#include<cmath>
#include <iomanip>
#include<sstream>
#include <iostream>
using namespace  std;

int Complex::numberOfObjects = 0;

Complex:: Complex(double Real, double Imag){
    RealPart = Real;
    ImagPart = Imag;
    numberOfObjects++;
}

Complex:: Complex(double Real){
    RealPart = Real;
    ImagPart = 0;
    numberOfObjects++;
}

Complex:: Complex(){
    RealPart = 0;
    ImagPart = 0;
    numberOfObjects++;
}

Complex:: ~Complex(){
    numberOfObjects--;
}

Complex Complex::add(const Complex temp) const{
    double real = RealPart + temp.RealPart;
    double imag = ImagPart + temp.ImagPart;
    return Complex(real, imag);
}

Complex Complex::subtract(const Complex temp) const{
    double real = RealPart - temp.RealPart;
    double imag = ImagPart - temp.ImagPart;
    return Complex(real, imag);
}

Complex Complex::multiply(const Complex temp) const{
    double real = RealPart * temp.RealPart - ImagPart * temp.ImagPart;
    double imag = ImagPart * temp.RealPart + RealPart * temp.ImagPart;
    return Complex(real, imag);
}

Complex Complex::divide(const Complex temp) const{
    double divisor = temp.RealPart * temp.RealPart + temp.ImagPart * temp.ImagPart;
    double real = (RealPart * temp.RealPart + ImagPart * temp.ImagPart)/divisor;
    double imag = (ImagPart * temp.RealPart - RealPart * temp.ImagPart)/divisor;
    return Complex(real, imag);
}

double Complex::abs() const{
    double rel = pow(RealPart,2.0);
    double img = pow(ImagPart,2.0);
    double res = pow((rel+img),1.0/2.0);
    return res;
}

string Complex::toString() const{
    stringstream s1,s2;
    double rel = RealPart;
    double ima = ImagPart;
    s1 << setprecision(6) << rel;
    s2 << setprecision(6) << ima;
    string res;
    if(ImagPart == 0)
        res = s1.str();
    else
        res = s1.str() + "+" + s2.str() + "i";
    return res;
}

const double Complex::getRealPart() const{
    return RealPart;
}

const double Complex::getImaginaryPart() const{
    return ImagPart;
}

double & Complex::operator[](int index){
    if(index == 0)
        return RealPart;
    else
        return ImagPart;
}

const double& Complex::operator[](const int index) const{
    if(index == 0)
        return RealPart;
    else
        return ImagPart;
}

Complex Complex::operator+() const{
    return *this;
}

Complex Complex::operator-() const{
    double rel = 0.0, Ima = 0.0;
    rel = -RealPart;
    Ima = -ImagPart;
    Complex temp(rel,Ima);
    return temp;
}

Complex& Complex::operator+=(const Complex& temp){
    *this = add(temp);
    return *this;
}

Complex& Complex::operator-=(const Complex& temp){
    *this = subtract(temp);
    return *this;
}

Complex& Complex::operator*=(const Complex& temp){
    *this = multiply(temp);
    return *this;
}

Complex& Complex::operator/=(const Complex& temp){
    *this = divide(temp);
    return *this;
}

Complex& Complex::operator++(){
    RealPart ++;
    return *this;
}

Complex& Complex::operator--(){
    RealPart --;
    return *this;
}

Complex Complex::operator++(int dummy){
    Complex temp(RealPart, ImagPart);
    this->RealPart++;
    return temp;
}

Complex Complex::operator--(int dummy){
    Complex temp(RealPart, ImagPart);
    this->RealPart--;
    return temp;
}

ostream& operator << (ostream& out, const Complex& temp){
    double rel = temp.getRealPart();
    double Ima = temp.getImaginaryPart();
    if(Ima == 0)
        out << setprecision(6) << rel;
    else
        out << setprecision(6) << rel << "+" << setprecision(6) << Ima << "i";
    return out;
}


istream& operator>>(istream& in,  Complex& temp){
    in >> temp[0];
    in >> temp[1];
    return in;
}

Complex operator+(const Complex& left, const Complex& right){
    return left.add(right);
};

Complex operator-(const Complex& left, const Complex& right){
    return left.subtract(right);
};

Complex operator*(const Complex& left, const Complex& right){
    return left.multiply(right);
};

Complex operator/(const Complex& left, const Complex& right){
    return left.divide(right);
}
