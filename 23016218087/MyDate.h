//File Name: MyDate.h
//Author: 李晓鹏
//Student Number: 3016218087
//Email: 1940913015@qq.com
//Assignment:#2
//Version: 1.2
//Description: 该CPP程序用于MyDate.h的实现，通过构造函数来产生新对象，考虑了-9999到9999年范围以及闰年、历法切换，输出要在MAIN函数里用COUT << toString()
/*Future Improvements:
1.每个函数的注释要更加详细
2.要优化代码的总行数，减少冗余代码
3.变量命名要更有意义
4.1752年更换历法还存在一些问题，下一步将优化*/
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

	MyDate (int mercy , int day);//用于类内部更改天数
private:
    int dayStorage;
    bool isLeapYear(int year) const;
    int getNumberOfDaysInMonth(int year, int month) const;
};

#endif // MYDATE_H
