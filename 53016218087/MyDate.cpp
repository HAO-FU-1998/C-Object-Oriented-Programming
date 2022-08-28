//File Name: MyDate.cpp
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
#include <iostream>
#include <ctime>
#include <cmath>
#include <string>
#include <stdexcept>
#include "MyDate.h"
using namespace std;

//����ʱ��
const static long TIMEZONE_OFFSET = 60 * 60 * 8;
//ת�����캯��������ת������
MyDate::MyDate(long long elapseTime)
{
    int day;
    day = (elapseTime + TIMEZONE_OFFSET) / 86400;
    dayStorage = day;
}

//���캯��������һ�����ڲ�������洢
MyDate::MyDate(int year , int month , int newDay)
{
    int day;

    //�쳣������
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

    //���캯������
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
        //����1752��9��2�յ�14���м���11��
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

//��������
MyDate MyDate::add(int addDay) const
{
    int day;
    day = dayStorage + addDay;
    MyDate dva(1 , day);
    return dva;
}

//��������
MyDate MyDate::subtract(int subtractDay) const
{
    int day;
    day = dayStorage - subtractDay;
    MyDate dva(1 , day);
    return dva;
}

//���ڼ���������
int MyDate::subtract(const MyDate& dva) const
{
    int day;
    day = this -> dayStorage - dva.dayStorage;
    return day;
}

//�ж������Ƿ����
bool MyDate::equals(const MyDate& dva) const
{
    if(this -> dayStorage == dva.dayStorage)
        return true;
    else
        return false;
}

//�ж������Ƿ�С��
bool MyDate::lessThan(const MyDate& dva) const
{
    if(this -> dayStorage < dva.dayStorage)
        return true;
    else
        return false;
}
//�ж������Ƿ�С�ڵ���
bool MyDate::lessThanOrEquals(const MyDate& dva) const
{
    if(this -> dayStorage <= dva.dayStorage)
        return true;
    else
        return false;
}

//�ж������Ƿ����
bool MyDate::greaterThan(const MyDate& dva) const
{
    if(this -> dayStorage > dva.dayStorage)
        return true;
    else
        return false;
}

//�ж������Ƿ���ڵ���
bool MyDate::greaterThanOrEquals(const MyDate& dva) const
{
    if(this -> dayStorage >= dva.dayStorage)
        return true;
    else
        return false;
}

//toString�������������������
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
        //����������������������
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
            //����Ҫ��ȥ����������һ��ʱ���ȼ�ȥ1����ǰһ�����һ�������
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
            //��Ҫ��ȥ������Ϊ��ʱ����������һ���һ��һ��
            month = 1;
            day = 1;
        }

    }

    //�����հ���׼��ʽת��
    //��
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
    //��
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
    //��
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
    //�ܽ��
    result = date1 + date2 + date3;
    return result;
}

//�������ڲ�����˽�е�day
MyDate::MyDate (int mercy , int day)
{
    dayStorage = day;
}

int dayStorage;
//�ж��Ƿ�������
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
    //����1752��9�µ�����19�죬��9�µ�������
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

//�������ܲ���
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
