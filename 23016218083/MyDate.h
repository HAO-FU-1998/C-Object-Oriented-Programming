// File Name: MyDate.cpp
// Author: ���B
// Student Number: 3016218083
// Email: 907571579@qq.com
// Assignment: 2
// Version: 1
// Description: ��1��������ת�����ڡ���2���������������ֱ�����ꡢ�¡��������ֶΡ���3�����ش˶���������Ӧ���������ڡ���4������ֵΪ�˶������β�֮��ľ��룬���˶�����β���ʱ��������������5���������ISO8601 ��׼���ȵ�
// Future Improvements: 1�����̱��ʱ�䣬������̡�2��ע���ǿע�͵�ʹ�ü���ࡣ3������ʹ��������㷨��4���������ʡ�5��Ҫ���Լ��Ĵ��¡�

#ifndef MYDATE_H
#define MYDATE_H
#include <iostream>
using namespace std;

class MyDate
{
public:
	MyDate(long long); //seconds since UNIX epoch
	MyDate(int,int,int);  //year,month,day
	MyDate add(int) const;
	MyDate subtract(int) const;
	int subtract(const MyDate&) const;
	bool equals(const MyDate&) const;
	bool lessThan(const MyDate&) const;
	bool lessThanOrEquals(const MyDate&) const;
	bool greaterThan(const MyDate&) const;
	bool greaterThanOrEquals(const MyDate&) const;
	string toString() const;
	const static long TIMEZONE_OFFSET = 60*60*8; //Beijing TimeZone

	MyDate(int InputDay_1, int InputDay_2); // Change the days in class

private:
    int InputDay;
};

#endif // MYDATE_H
