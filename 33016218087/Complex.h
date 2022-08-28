//
//  Complex.h
//
//  Created by Yevon Zhang on 17/3/18.
//  Copyright (c) 2017�� Yevon Zhang. All rights reserved.
//

#ifndef __Complex__
#define __Complex__

#include <iostream>

class Complex{
public://public����Ϊ����ӿڣ��������ӡ��޸Ļ�ɾ��
    Complex();//a��0��b��0
    Complex(const double a, const double b);
    Complex(const double a);//b��0
    ~Complex();
    const double getRealPart() const;//����ʵ��
    const double getImaginaryPart() const;//�����鲿
    Complex add(const Complex sc) const;//�ӷ���sc��Ϊ�ڶ�������
    Complex subtract(const Complex sc) const;//������sc��Ϊ�ڶ�������
    Complex multiply(const Complex sc) const;//�˷���sc��Ϊ�ڶ�������
    Complex divide(const Complex sc) const;//������sc��Ϊ����
    double abs() const;//���ؾ���ֵ
    std::string toString() const;//תΪ�ַ���a��bi������鲿Ϊ0��ֻ��ʾa

    Complex& operator+=(const Complex& sc);
    Complex& operator-=(const Complex& sc);
    Complex& operator*=(const Complex& sc);
    Complex& operator/=(const Complex& sc);
    double& operator[](const int index);
    const double& operator[](const int index) const;

    Complex operator+() const;//��������ʵ�ʸı�
    Complex operator-() const;//ʵ���鲿ͬʱȡ��
    Complex& operator++();//��ʵ��ǰ�ã���
    Complex operator++(int);//��ʵ�����ã���
    Complex& operator--();//��ʵ��ǰ�ã���
    Complex operator--(int);//��ʵ�����ã���

private://private����Ϊ�ڲ�ʵ�֣����������ӡ��޸Ļ�ɾ��
    double a;//ʵ��
    double b;//�鲿

};

//ȫ�ֱ����ͺ������֣��������ӡ��޸Ļ�ɾ��
std::ostream& operator<<(std::ostream& ostr, const Complex& sc);//���a+bi��֧���ļ����
std::istream& operator>>(std::istream& ostr, Complex& sc);//����ʵ���鲿��sc��֧���ļ�����
Complex operator+(const Complex& sc1, const Complex& sc2);//�ӷ�
Complex operator-(const Complex& sc1, const Complex& sc2);//����
Complex operator*(const Complex& sc1, const Complex& sc2);//�˷�
Complex operator/(const Complex& sc1, const Complex& sc2);//����

#endif /* defined(__Complex__) */
