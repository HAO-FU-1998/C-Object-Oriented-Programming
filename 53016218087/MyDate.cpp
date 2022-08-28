//File Name: MyDate.cpp
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
#include <iostream>
#include <ctime>
#include <cmath>
#include <string>
#include <stdexcept>
#include "MyDate.h"
using namespace std;

//北京时区
const static long TIMEZONE_OFFSET = 60 * 60 * 8;
//转换构造函数，秒数转换成天
MyDate::MyDate(long long elapseTime)
{
    int day;
    day = (elapseTime + TIMEZONE_OFFSET) / 86400;
    dayStorage = day;
}

//构造函数，构造一个日期并换成天存储
MyDate::MyDate(int year , int month , int newDay)
{
    int day;

    //异常处理部分
    if (month >= 13 || month <= 0)
    {
        throw invalid_argument("Invalid Date!");
    }
    if (year != 1752 && month != 9 && (newDay < 1 || newDay > getNumberOfDaysInMonth(year , month)))
    {
        throw invalid_argument("Invalid Date!");
    }
    if (year == 1752 && month == 9)
    {
        if (newDay < 1 || newDay > 30)
        {
            throw invalid_argument("Invalid Date!");
        }
        if (newDay > 2 && newDay < 14)
        {
            throw invalid_argument("Invalid Date!");
        }
    }

    //构造函数部分
    if(year >= 1970)
    {
        day = newDay - 1;
        while(month > 1)
        {
            day = day + getNumberOfDaysInMonth(year, month-1);
            month--;
        }
        while(year > 1970)
        {
            day = day + (isLeapYear(year) ? 366 : 365);
            year--;
        }
    }
    else if(year < 1970 && year >= 1752)
    {
        //考虑1752年9月2日到14日中间少11天
        if (year == 1752 && month == 9 && day > 2)
            day = newDay - 12;
        else
            day = newDay - 1;
        while(month > 1)
        {
            day = day + getNumberOfDaysInMonth(year, month-1);
            month--;
        }
        while(year < 1970)
        {
            if(year == 1752)
            {
                day = day - (isLeapYear(year) ? 366 : 365) + 11;
                year++;
            }
            else
            {
                day = day - (isLeapYear(year) ? 366 : 365);
                year++;
            }
        }
    }
    else
    {
        day = newDay - 1;
        while(month > 1)
        {
            day = day + getNumberOfDaysInMonth(year, month-1);
            month--;
        }
        while(year < 1752)
        {
            day = day - (isOldLeapYear(year) ? 366 : 365);
            year++;
        }
        while(year >= 1752 && year < 1970)
        {
            if(year == 1752)
            {
                day = day - (isLeapYear(year) ? 366 : 365) + 11;
                year++;
            }
            else
            {
                day = day - (isLeapYear(year) ? 366 : 365);
                year++;
            }
        }
    }
    dayStorage = day;
}

//增加天数
MyDate MyDate::add(int addDay) const
{
    int day;
    day = dayStorage + addDay;
    MyDate dva(1 , day);
    return dva;
}

//减少天数
MyDate MyDate::subtract(int subtractDay) const
{
    int day;
    day = dayStorage - subtractDay;
    MyDate dva(1 , day);
    return dva;
}

//日期减法得天数
int MyDate::subtract(const MyDate& dva) const
{
    int day;
    day = this -> dayStorage - dva.dayStorage;
    return day;
}

//判断日期是否相等
bool MyDate::equals(const MyDate& dva) const
{
    if(this -> dayStorage == dva.dayStorage)
        return true;
    else
        return false;
}

//判断日期是否小于
bool MyDate::lessThan(const MyDate& dva) const
{
    if(this -> dayStorage < dva.dayStorage)
        return true;
    else
        return false;
}
//判断日期是否小于等于
bool MyDate::lessThanOrEquals(const MyDate& dva) const
{
    if(this -> dayStorage <= dva.dayStorage)
        return true;
    else
        return false;
}

//判断日期是否大于
bool MyDate::greaterThan(const MyDate& dva) const
{
    if(this -> dayStorage > dva.dayStorage)
        return true;
    else
        return false;
}

//判断日期是否大于等于
bool MyDate::greaterThanOrEquals(const MyDate& dva) const
{
    if(this -> dayStorage >= dva.dayStorage)
        return true;
    else
        return false;
}

//toString函数，用于输出年月日
string MyDate::toString() const
{
    int month;
    int year;
    int day;
    string date1 = "";
    string date2 = "";
    string date3 = "";
    string result = "";
    string number = "";
    day = dayStorage;

    if(day >= 0)
    {
        year = 1970;
        while (day >= (isLeapYear(year) ? 366 : 365))
        {
            day = day - (isLeapYear(year) ? 366 : 365);
            year++;
        }
        month = 1;
        while (day >= getNumberOfDaysInMonth(year, month))
        {
            day = day - getNumberOfDaysInMonth(year, month);
            month++;
        }
        day = day + 1;

    }
    else
    {
        //将负数天数换成正数来减
        day = fabs(day) ;
        year = 1970;
        while (year >= 1753 && day >= (isLeapYear(year-1) ? 366 : 365))
        {
            if(year == 1753)
            {
                day = day - (isLeapYear(year-1) ? 366 : 365) + 11;
                year--;
            }
            else
            {
                day = day - (isLeapYear(year-1) ? 366 : 365);
                year--;
            }

        }
        if (year == 1753 && day >= 355 && day <366)
        {
            day = day - 355;
            year--;
        }
        while (year < 1753 && day >= (isOldLeapYear(year-1) ? 366 : 365))
        {
            day = day - (isOldLeapYear(year-1) ? 366 : 365);
            year--;
        }
        if (day > 0)
        {
            //当需要减去的天数不够一年时，先减去1天变成前一年最后一天的年月
            year--;
            month = 12;
            day = day - 1;
            while (day >= getNumberOfDaysInMonth(year, month))
            {
                day = day - getNumberOfDaysInMonth(year, month);
                month--;
            }
            if (year == 1752 && month == 9 && day <= 16)
                day = 30 - day ;
            else
                day = getNumberOfDaysInMonth(year, month) - day;
        }
        else
        {
            //需要减去的天数为零时，正好是这一年的一月一日
            month = 1;
            day = 1;
        }

    }

    //年月日按标准格式转换
    //年
    if (year >= 0)
    {
        number = year % 10 + '0';
        date1 = number + date1;
        while (year / 10 != 0)
        {
            year = year / 10;
            number = year % 10 + '0';
            date1 = number + date1;
        }
        while (date1.length() < 4)
            date1 = '0' + date1;
    }
    else
    {
        year = fabs(year);
        number = year % 10 + '0';
        date1 = number + date1;
        while (year / 10 != 0)
        {
            year = year / 10;
            number = year % 10 + '0';
            date1 = number + date1;
        }
        while (date1.length() < 4)
            date1 = '0' + date1;
        date1 = "-" + date1;
    }
    //月
    number = month % 10 + '0';
    date2 = number + date2;
    if (month / 10 != 0)
    {
        month = month / 10;
        number = month % 10 + '0';
        date2 = number + date2;
    }
    else
        date2 = '0' + date2;
    date2 = "-" + date2;
    //日
    number = day % 10 + '0';
    date3 = number + date3;
    if (day / 10 != 0)
    {
        day = day / 10;
        number = day % 10 + '0';
        date3 = number + date3;
    }
    else
        date3 = '0' + date3;
    date3 = "-" + date3;
    //总结果
    result = date1 + date2 + date3;
    return result;
}

//用于类内部更改私有的day
MyDate::MyDate (int mercy , int day)
{
    dayStorage = day;
}

int dayStorage;
//判断是否是闰年
bool MyDate::isLeapYear(int year) const
{
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}
bool MyDate::isOldLeapYear(int year) const
{
    return year % 4 == 0;
}

int MyDate::getNumberOfDaysInMonth(int year, int month) const
{
    if (month == 1 || month == 3 || month == 5 || month == 7 ||
        month == 8 || month == 10 || month == 12)
        return 31;

    if (month == 4 || month == 6 || month == 11)
        return 30;
    //考虑1752年9月的特殊19天，将9月单独讨论
    if (year == 1752 && month == 9)
        return 19;
    else if (year != 1752 && month == 9)
        return 30;
    else


    if (month == 2)
    {
        if(year >= 1752)
            return isLeapYear(year) ? 29 : 28;
        else
            return isOldLeapYear(year) ? 29 : 28;
    }


return 0;
}

//新增功能部分
bool MyDate::operator==(const MyDate& dt) const
{
    this -> equals(dt);
}
bool MyDate::operator<(const MyDate& dt) const
{
    this -> lessThan(dt);
}
bool MyDate::operator<=(const MyDate& dt) const
{
    this -> lessThanOrEquals(dt);
}
bool MyDate::operator>(const MyDate& dt) const
{
    this -> greaterThan(dt);
}
bool MyDate::operator>=(const MyDate& dt) const
{
    this -> greaterThanOrEquals(dt);
}

MyDate MyDate::operator+(int days) const
{
    this -> add(days);
}
MyDate MyDate::operator-(int days) const
{
    this -> subtract(days);
}

int MyDate::operator-(const MyDate& dt) const
{
    this -> subtract(dt);
}

ostream& operator<<(ostream& os,const MyDate& dt)
{
    cout << dt.toString();
    return os;
}
