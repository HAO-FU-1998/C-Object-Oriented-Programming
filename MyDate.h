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
