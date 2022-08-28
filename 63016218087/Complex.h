#ifndef COMPLEX_H
#define COMPLEX_H

#include "Number.h"
#include <iostream>

class Complex : public Number
{
public://public部分为对外接口，不可增加、修改或删除
    Complex();//a＝0，b＝0
    Complex(const double a, const double b);
    Complex(const double a);//b＝0
    ~Complex();
    const double getRealPart() const;//返回实部
    const double getImaginaryPart() const;//返回虚部
    Complex add(const Complex sc) const;//加法，sc作为第二操作数
    Complex subtract(const Complex sc) const;//减法，sc作为第二操作数
    Complex multiply(const Complex sc) const;//乘法，sc作为第二操作数
    Complex divide(const Complex sc) const;//除法，sc作为除数
    double abs() const;//返回绝对值
    std::string toString()  const ;//转为字符串a＋bi，如果虚部为0，只显示a

    Complex& operator+=(const Complex& sc);
    Complex& operator-=(const Complex& sc);
    Complex& operator*=(const Complex& sc);
    Complex& operator/=(const Complex& sc);
    double& operator[](const int index);
    const double& operator[](const int index) const;

    Complex operator+() const;//对数据无实质改变
    Complex operator-() const;//实部虚部取反
    Complex& operator++();//对实部前置＋＋
    Complex operator++(int);//对实部后置＋＋
    Complex& operator--();//对实部前置－－
    Complex operator--(int);//对实部后置－－

private://private部分为内部实现，可任意增加、修改或删除
    double a;//实部
    double b;//虚部

};

//全局变量和函数部分，不可增加、修改或删除
std::ostream& operator<<(std::ostream& ostr, const Complex& sc);//输出a+bi，支持文件输出
std::istream& operator>>(std::istream& istr, Complex& sc);//输入实部虚部到sc，支持文件输入
Complex operator+(const Complex& sc1, const Complex& sc2);//加法
Complex operator-(const Complex& sc1, const Complex& sc2);//减法
Complex operator*(const Complex& sc1, const Complex& sc2);//乘法
Complex operator/(const Complex& sc1, const Complex& sc2);//除法

#endif // COMPLEX_H
