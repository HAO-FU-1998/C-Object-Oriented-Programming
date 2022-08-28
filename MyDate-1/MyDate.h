//Fail Name:MyDate.h
//Author:郭培溟
//Student Number:3016218085
//Email:1072671422@qq.com
//Assignment:2
//Version:2.01
//Description:实现一个日期类，支持公元前9999到公元后9999，考虑闰年的问题，时间精确到天数
//输出对象的具体日期，输出格式符合ISO8601标准
//输出到屏幕
//Future Improvements:
//1.增加其他的运算符重载
//2.增加一些其他功能函数
//3.支持输出到文件
//4.优化算法，精简代码长度，尤其优化toString函数



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
