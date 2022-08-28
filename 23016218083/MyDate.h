// File Name: MyDate.cpp
// Author: 傅淏
// Student Number: 3016218083
// Email: 907571579@qq.com
// Assignment: 2
// Version: 1
// Description: （1）把整数转成日期。（2）接受三个整数分别代表年、月、日三个字段。（3）返回此对象增加相应天数的日期。（4）返回值为此对象与形参之间的距离，当此对象比形参晚时返回正整数。（5）输出符合ISO8601 标准。等等
// Future Improvements: 1、缩短编程时间，熟练编程。2、注意加强注释的使用及简洁。3、尽量使用最简便的算法。4、不耻下问。5、要有自己的创新。

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
