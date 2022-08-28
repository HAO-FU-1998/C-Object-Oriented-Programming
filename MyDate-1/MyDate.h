//Fail Name:MyDate.h
//Author:������
//Student Number:3016218085
//Email:1072671422@qq.com
//Assignment:2
//Version:2.01
//Description:ʵ��һ�������֧࣬�ֹ�Ԫǰ9999����Ԫ��9999��������������⣬ʱ�侫ȷ������
//�������ľ������ڣ������ʽ����ISO8601��׼
//�������Ļ
//Future Improvements:
//1.�������������������
//2.����һЩ�������ܺ���
//3.֧��������ļ�
//4.�Ż��㷨��������볤�ȣ������Ż�toString����



#ifndef MYDATE_H_INCLUDED
#define MYDATE_H_INCLUDED
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class MyDate
{
public:
    MyDate(long long);
    MyDate(int, int, int);
    MyDate add(int) const;
    MyDate subtract(int) const;
    int subtract(const MyDate&) const;
    bool equals(const MyDate&) const;
    bool lessThan(const MyDate&) const;
    bool greaterThan(const MyDate&) const;
    bool lessThanOrEquals(const MyDate&) const;
    bool greaterThanOrEquals(const MyDate&) const;
    string toString() const;
    const static long TIMEZONE_OFFSET = 60 * 60 * 8;
    bool operator==(const MyDate&) const;
    bool operator<(const MyDate&) const;
    bool operator>(const MyDate&) const;
    bool operator<=(const MyDate&) const;
    bool operator>=(const MyDate&) const;
    MyDate operator+(int days) const;
    MyDate operator-(int days) const;
    int operator-(const MyDate&) const;
private:
    int days;
    MyDate(int, int);
    void check(int, int, int);
};

ostream& operator<<(ostream& os, const MyDate& dt);
#endif // MYDATE_H_INCLUDED
