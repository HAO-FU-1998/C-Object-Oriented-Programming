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

	bool operator==(const MyDate&) const;
	bool operator<(const MyDate&) const;
	bool operator<=(const MyDate&) const;
	bool operator>(const MyDate&) const;
	bool operator>=(const MyDate&) const;
	MyDate operator+(int days) const;
	MyDate operator-(int days) const;
	int operator-(const MyDate&) const;

    const static long TIMEZONE_OFFSET = 60*60*8; //Beijing TimeZone
    MyDate (int mercy , int day);//用于类内部更改天数
private:
    int dayStorage;
    bool isLeapYear(int year) const;
    bool isOldLeapYear(int year) const;
    int getNumberOfDaysInMonth(int year, int month) const;
};

ostream& operator<<(ostream& os,const MyDate& dt);
#endif // MYDATE_H
