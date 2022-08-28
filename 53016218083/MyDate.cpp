// File Name: MyDate.cpp
// Author: 傅淏
// Student Number: 3016218083
// Email: 907571579@qq.com
// Assignment: 5
// Version: 1
// Description: （1）把整数转成日期。（2）接受三个整数分别代表年、月、日三个字段。（3）返回此对象增加相应天数的日期。（4）返回值为此对象与形参之间的距离，当此对象比形参晚时返回正整数。（5）输出符合ISO8601 标准。等等
// Future Improvements: 1、缩短编程时间，熟练编程。2、注意加强注释的使用及简洁。3、尽量使用最简便的算法。4、不耻下问。5、要有自己的创新。


#include <iostream>
#include <ctime>
#include <string>
#include <cmath>
#include "MyDate.h"
#include <stdexcept>

using namespace std;

const static long TIMEZONE_OFFSET = 60 * 60 * 8; // Beijing TimeZone

MyDate::MyDate(long long InputSecond) // Turn seconds into days
{
  InputDay = (InputSecond + TIMEZONE_OFFSET) / (60 * 60 * 24);
}

MyDate MyDate::add(int AddDay) const
{
  int NewDay_1 = InputDay;
  MyDate NewDate(NewDay_1, AddDay);
  return NewDate;
}

MyDate MyDate::subtract(int SubtractDay) const
{
  int NewDay_2 = InputDay;
  SubtractDay *= -1;
  MyDate NewDate(NewDay_2,SubtractDay);
  return NewDate;
}

int MyDate::subtract(const MyDate& MyNewDate) const // Substract the days and get a number
{
  int NewDay_3;
  NewDay_3 = InputDay - MyNewDate.InputDay;
  return NewDay_3;
}

bool MyDate::equals(const MyDate& MyNewDate) const // Judge whether the dates are equals
{
  if (InputDay == MyNewDate.InputDay)
    return true;
  else
    return false;
}

bool MyDate::lessThan(const MyDate& MyNewDate) const // Judge whether the one date is less than the other
{
  if (InputDay < MyNewDate.InputDay)
    return true;
  else
    return false;
}

bool MyDate::greaterThan(const MyDate& MyNewDate) const // Judge whether the one date is greater than the other
{
  if (InputDay > MyNewDate.InputDay)
    return true;
  else
    return false;
}

bool MyDate::lessThanOrEquals(const MyDate& MyNewDate) const // Judge whether the one date is less than or equals the other
{
  if (InputDay <= MyNewDate.InputDay)
    return true;
  else
    return false;
}

bool MyDate::greaterThanOrEquals(const MyDate& MyNewDate) const // Judge whether the one date is greater than or equals the other
{
  if (InputDay >= MyNewDate.InputDay)
    return true;
  else
    return false;
}

MyDate::MyDate(int year, int month, int day)
{
  examine (year, month, day);
  InputDay = 0;
  int ZeroYear = 1970, ZeroMonth = 1;
  // Exception Handling

  if (year >= 1970)
    {
      while (year != ZeroYear)
      {
        if ((ZeroYear % 4 == 0 && ZeroYear % 100 != 0) || ZeroYear % 400 == 0) //Leap Year
          InputDay += 366;
        else
          InputDay += 365;
        ZeroYear ++;
      }
      while (month != ZeroMonth)
      {
        if (ZeroMonth == 1 || ZeroMonth == 3 || ZeroMonth == 5 || ZeroMonth == 7 || ZeroMonth ==8 || ZeroMonth == 10 || ZeroMonth == 12)
          InputDay += 31;
        else if (ZeroMonth == 2)
        {
          if ((ZeroYear % 4 == 0 && ZeroYear % 100 != 0) || ZeroYear % 400 == 0) //Leap Year
            InputDay += 29;
          else
            InputDay += 28;
        }
        else
          InputDay += 30;
        ZeroMonth ++;
      }
      InputDay += day - 1;
    }
    else
    {
      ZeroYear --;
      while (ZeroYear >= year)
      {
        if (ZeroYear > 1752)
        {
          if ((ZeroYear % 4 == 0 && ZeroYear % 100 != 0) || ZeroYear % 400 == 0)
            InputDay -= 366;
          else
            InputDay -= 365;
        }
        else if (ZeroYear == 1752)
          InputDay -= 355;
        else
        {
          if (ZeroYear % 4 == 0) //Leap Year Before 1752
            InputDay -= 366;
          else
            InputDay -= 365;
        }
        ZeroYear --;
      }
      while (month != ZeroMonth)
      {
        if (ZeroMonth == 1 || ZeroMonth == 3 || ZeroMonth == 5 || ZeroMonth == 7 || ZeroMonth ==8 || ZeroMonth == 10 || ZeroMonth == 12)
          InputDay += 31;
        else if (ZeroMonth == 2)
        {
          if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && year >= 1752) //Leap Year
            InputDay += 29;
          else if (year % 4 == 0 && year < 1752)
            InputDay += 29;
          else
            InputDay += 28;
        }
        else
        {
          if (year == 1752 && ZeroMonth == 9)
            InputDay += 19;
          else
            InputDay += 30;
        }
        ZeroMonth ++;
      }
      if (year == 1752 && month == 9 && day >= 14)
        InputDay += day - 1 - 11;
      else
        InputDay += day - 1;
    }
}

MyDate::MyDate(int InputDay_1, int InputDay_2)
{
  InputDay = InputDay_1 + InputDay_2;
}

string MyDate::toString() const
{
  int year = 1970, month = 1, day = 1;
  int InitialDay = InputDay;
  if (InitialDay >= 0)
  {
    while (InitialDay >= 365)
    {
      if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
      {
        if (InitialDay >= 366)
        {
          InitialDay -= 366;
          year ++;
        }
        else
          break;
      }
      else
      {
        InitialDay -= 365;
        year ++;
      }
    }
    while (InitialDay >= 28)
    {
      if (month == 1 || month == 3 || month == 5 || month == 7 || month ==8 || month == 10 || month == 12)
      {
        if (InitialDay >= 31)
        {
          InitialDay -= 31;
          month ++;
        }
        else
          break;
      }
      else if (month == 4 || month == 6 || month == 9 || month == 11)
      {
        if (InitialDay >= 30)
        {
          InitialDay -= 30;
          month ++;
        }
        else
          break;
      }
      else
      {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        {
          if (InitialDay >= 29)
          {
            InitialDay -= 29;
            month ++;
          }
          else
            break;
        }
        else
        {
          InitialDay -= 28;
          month ++;
        }
      }
    }
    day += InitialDay;
  }
  else
  {
    while (InitialDay <= -355)
    {
      if (((((year - 1) % 4 == 0 && (year - 1) % 100 != 0) || (year - 1) % 400 == 0)) && (year - 1) > 1752)
      {
        if (InitialDay <= -366)
        {
          InitialDay += 366;
          year --;
        }
        else
          break;
      }
      else if ((year - 1) % 4 == 0 && (year - 1) < 1752)
      {
        if (InitialDay <= -366)
        {
          InitialDay += 366;
          year --;
        }
        else
          break;
      }
      else if ((year - 1) == 1752)
      {
        InitialDay += 355;
        year --;
      }
      else
      {
        if (InitialDay <= -365)
        {
          InitialDay += 365;
          year--;
        }
        else
          break;
      }
    }
    month = 12;
    year --;
    while (InitialDay <= -19)
    {
      if (month == 1 || month == 3 || month == 5 || month == 7 || month ==8 || month == 10 || month == 12)
      {
        if (InitialDay <= -31)
        {
          InitialDay += 31;
          month --;
        }
        else
          break;
      }
      else if (month == 9 && year == 1752)
      {
        if (InitialDay <= -19)
        {
          InitialDay += 19;
          month --;
        }
        else
          break;
      }
      else if (month == 2)
      {
        if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && year >= 1752)
        {
          if (InitialDay <= -29)
          {
            InitialDay += 29;
            month --;
          }
          else
            break;
        }
        else if (year % 4 == 0 && year <= 1752)
        {
          if (InitialDay <= -29)
          {
            InitialDay += 29;
            month --;
          }
          else
            break;
        }
        else
        {
          if (InitialDay <= -28)
          {
            InitialDay += 28;
            month --;
          }
          else
            break;
        }
      }
      else
      {
        if (InitialDay <= -30)
        {
          InitialDay += 30;
          month --;
        }
        else
          break;
      }
    }
    if (InitialDay == 0)
    {
      month ++;
      if (month == 13)
      {
        month = 1;
        year ++;
      }
    }
    else
    {
      if (month == 1 || month == 3 || month == 5 || month == 7 || month ==8 || month == 10 || month == 12)
      {
        day = 31;
        day = day - (InitialDay * (-1) -1);
      }
      else if (month == 9 && year == 1752)
      {
        day = 30;
        if (InitialDay >= -17)
          day = day - (InitialDay * (-1) -1);
        else
          day = day - ((InitialDay - 11) * (-1) - 1);
      }
      else if (month == 2)
      {
        if ((((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && year >= 1752))
        {
          day = 29;
          day = day - (InitialDay * (-1) -1);
        }
        else if (year % 4 == 0 && year < 1752)
        {
          day = 29;
          day = day - (InitialDay * (-1) -1);
        }
        else
        {
          day = 28;
          day = day - (InitialDay * (-1) -1);
        }
      }
      else
      {
        day = 30;
        day = day - (InitialDay * (-1) -1);
      }
    }
  }
  string date1 = "";
  string date2 = "";
  string date3 = "";
  string result = "";
  string number = "";

  if (year >= 0)
  {
    number = year % 10 + '0';
    date1 = number + date1;
    while (year / 10 != 0)
    {
      year = year / 10;
      number = year % 10 + '0';
      date1 = number +date1;
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
      date1 = number +date1;
    }
    while (date1.length() < 4)
      date1 = '0' + date1;

    date1 = "-" + date1;
  }

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

  result = date1 + date2 + date3;
  return result;
}

// New Adding Functions
bool MyDate::operator == (const MyDate& dt) const
{
  this -> equals(dt);
}

bool MyDate::operator < (const MyDate& dt) const
{
  this -> lessThan(dt);
}

bool MyDate::operator <= (const MyDate& dt) const
{
  this -> lessThanOrEquals(dt);
}

bool MyDate::operator > (const MyDate& dt) const
{
  this -> greaterThan(dt);
}

bool MyDate::operator >= (const MyDate& dt) const
{
  this -> greaterThanOrEquals(dt);
}

MyDate MyDate::operator + (int days) const
{
  this -> add(days);
}

MyDate MyDate::operator - (int days) const
{
  this -> subtract(days);
}

int MyDate::operator - (const MyDate& dt) const
{
  this -> subtract(dt);
}

ostream& operator << (ostream& os, const MyDate& dt)
{
  cout << dt.toString();
  return os;
}

void MyDate::examine (int year, int month, int day)
{
  if (month < 1 || month > 12)
  {
    throw invalid_argument ("Invalid Date!");
  }
  if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
  {
    if (day < 1 || day > 31)
    {
      throw invalid_argument ("Invalid Date!");
    }
  }
  else if (month == 9)
  {
    if (year == 1752)
    {
      if (day < 1 || day > 30 || (day > 2 && day < 14))
      {
        throw invalid_argument ("Invalid Date!");
      }
    }
    else
    {
      if (day < 1 || day > 30)
      {
        throw invalid_argument ("Invalid Date!");
      }
    }
  }
  else if (month == 2)
  {
    if ((((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) && (year >= 1752)) || (year % 4 == 0 && year < 1752))
    {
      if (day < 1 || day > 29)
      {
        throw invalid_argument ("Invalid Date!");
      }
    }
    else
    {
      if (day < 1 || day > 28)
      {
        throw invalid_argument ("Invalid Date!");
      }
    }
  }
  else
  {
    if (day < 1 || day > 30)
    {
      throw invalid_argument ("Invalid Date!");
    }
  }
}




