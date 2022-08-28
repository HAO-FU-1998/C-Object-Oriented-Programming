//File Name: MyDate.h
//Author: ������
//Student Number: 3016218087
//Email: 1940913015@qq.com
//Assignment:#2
//Version: 1.2
//Description: ��CPP��������MyDate.h��ʵ�֣�ͨ�����캯���������¶��󣬿�����-9999��9999�귶Χ�Լ����ꡢ�����л������Ҫ��MAIN��������COUT << toString()
/*Future Improvements:
1.ÿ��������ע��Ҫ������ϸ
2.Ҫ�Ż�������������������������
3.��������Ҫ��������
4.1752���������������һЩ���⣬��һ�����Ż�*/
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
	bool lessThanOrEquals(const MyDate&) const;
	bool greaterThan(const MyDate&) const;
	bool greaterThanOrEquals(const MyDate&) const;
	string toString() const;
	const static long TIMEZONE_OFFSET = 60*60*8; //Beijing TimeZone

	MyDate (int mercy , int day);//�������ڲ���������
private:
    int dayStorage;
    bool isLeapYear(int year) const;
    int getNumberOfDaysInMonth(int year, int month) const;
};

#endif // MYDATE_H
