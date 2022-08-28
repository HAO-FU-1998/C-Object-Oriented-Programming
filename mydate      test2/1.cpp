#include <iostream>
#include <ctime>
#include <string>
#include <cmath>
#include "MyDate.h"

using namespace std;

const static long TIMEZONE_OFFSET = 60 * 60 * 8; // Beijing TimeZone

MyDate::MyDate(long long InputSecond) // Turn seconds into days
{
  Inputday = (InputSecond + TIMEZONE_OFFSET) / (60 * 60 * 24);
}

MyDate MyDate::add(int AddDay) const{
    int NewDay_1 = Inputday;
    MyDate NewDate(NewDay_1, AddDay);
    return NewDate;
}

MyDate MyDate::subtract(int SubtractDay) const{
    int NewDay_2 = Inputday;
    SubtractDay *= -1;
    MyDate NewDate(NewDay_2,SubtractDay);
    return NewDate;
}

int MyDate::subtract(const MyDate& MyNewDate) const // Substract the days and get a number
{
  int NewDay_3;
  NewDay_3 = Inputday - MyNewDate.Inputday;
  return NewDay_3;
}

bool MyDate::equals(const MyDate& MyNewDate) const // Judge whether the dates are equals
{
  if (Inputday == MyNewDate.Inputday)
    return true;
  else
    return false;
}

bool MyDate::lessThan(const MyDate& MyNewDate) const // Judge whether the one date is less than the other
{
  if (Inputday < MyNewDate.Inputday)
    return true;
  else
    return false;
}

bool MyDate::greaterThan(const MyDate& MyNewDate) const // Judge whether the one date is greater than the other
{
  if (Inputday > MyNewDate.Inputday)
    return true;
  else
    return false;
}

bool MyDate::lessThanOrEquals(const MyDate& MyNewDate) const // Judge whether the one date is less than or equals the other
{
  if (Inputday <= MyNewDate.Inputday)
    return true;
  else
    return false;
}

bool MyDate::greaterThanOrEquals(const MyDate& MyNewDate) const // Judge whether the one date is greater than or equals the other
{
  if (Inputday >= MyNewDate.Inputday)
    return true;
  else
    return false;
}
MyDate::MyDate(int InputDay_1, int InputDay_2)
{
  Inputday = InputDay_1 + InputDay_2;
}

int main()
{
    MyDate d0(0);
    //测试用例0，测试1970-01-01附近的日期
    cout << d0.toString()  << endl;  // => 1970-01-01
    cout << d0.add(1).toString()  << endl;  // => 1970-01-02
    cout << d0.add(364).toString()  << endl;  // => 1970-12-31
    cout << d0.add(365).toString()  << endl;  // => 1971-01-01
    cout << d0.subtract(1).toString()  << endl;  // => 1969-12-31
    cout << d0.subtract(365).toString()  << endl;  // => 1969-01-01
    cout << d0.subtract(366).toString()  << endl;  // => 1968-12-31
    cout << (d0.subtract(1).equals(d0.add(-1)) ? "equal":"not equal" ) << endl; // => equal
    cout << (d0.subtract(-1).equals(d0.add(1)) ? "equal":"not equal" ) << endl; // => equal
    //测试用例1，2017-03-01
    MyDate d1(17226*60*60*24LL);
    cout << d1.toString()  << endl;  // => 2017-03-01
    cout << d1.add(7).toString() << endl; // => 2017-03-08
     //测试用例2，2050-01-01，测试是否支持2038年之后
    MyDate d2(2100,1,1);
    cout << d2.subtract(d0) << endl;  // => 47482
    cout << d2.add(365).toString() <<endl; //=>2101-01-01
     //测试用例3，1752-09-14，测试历法切换
    MyDate d3(1752,9,14);
    cout << d3.subtract(1).toString()  << endl;  // => 1752-09-02
    //测试用例4，0001-01-01，公元1年1月1日，测试公元前日期
    MyDate d4(1,1,1);
    cout << d4.subtract(1).toString()  << endl;  // => 0000-12-31
    //测试用例5，0000-12-31，公元前1年12月31日，测试公元前日期
    MyDate d5(0,12,31);
    cout << d5.toString()  << endl;  // => 0000-12-31
    cout << (d4.subtract(1).equals(d5) ? "equal":"not equal" ) << endl; // => equal
    //测试用例6，-0001-12-31，公元前2年12月31日，测试公元前日期
    MyDate d6(-1,12,31);
    cout << d6.toString()  << endl;  // => -0001-12-31
    cout << d6.subtract(d5) << endl; // => -366

    return 0;
}



MyDate::MyDate(int year, int month, int day){
    Inputday = 0;
    int tempOfYear = 1970, tempOfMonth = 1;
    if(year >= 1970){
        while(year != tempOfYear){
            if((tempOfYear % 4 == 0 && tempOfYear % 100 != 0) || tempOfYear % 400 == 0) //闰年
                Inputday += 366;
            else
                Inputday += 365;
            tempOfYear++;
        }
        while(month != tempOfMonth){
            if(tempOfMonth == 1 || tempOfMonth == 3 || tempOfMonth == 5 || tempOfMonth == 7 || tempOfMonth ==8 || tempOfMonth == 10 || tempOfMonth == 12)
                Inputday += 31;
            else if(tempOfMonth == 2){
                if((tempOfYear % 4 == 0 && tempOfYear % 100 != 0) || tempOfYear % 400 == 0)//闰年
                    Inputday += 29;
                else
                    Inputday += 28;
            }
            else
                Inputday += 30;
            tempOfMonth++;
        }
        Inputday += day - 1;
    }
    else{
        tempOfYear--;
        while(tempOfYear >= year){
            if(tempOfYear > 1752){
                if((tempOfYear % 4 == 0 && tempOfYear % 100 != 0) || tempOfYear % 400 == 0)
                    Inputday -= 366;
                else
                    Inputday -= 365;
            }
            else if(tempOfYear == 1752)
                Inputday -= 355;
            else{
                if(tempOfYear % 4 == 0)//1752年之前的闰年
                    Inputday -= 366;
                else
                    Inputday -= 365;
            }
            tempOfYear--;
        }
        while(month != tempOfMonth){
            if(tempOfMonth == 1 || tempOfMonth == 3 || tempOfMonth == 5 || tempOfMonth == 7 || tempOfMonth ==8 || tempOfMonth == 10 || tempOfMonth == 12)
                Inputday += 31;
            else if(tempOfMonth == 2){
                if(((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && year >= 1752)//闰年
                    Inputday += 29;
                else if(year % 4 == 0 && year < 1752)
                    Inputday += 29;
                else
                    Inputday += 28;
            }
            else{
                if(year == 1752 && tempOfMonth == 9)
                    Inputday += 19;
                else
                    Inputday += 30;
            }
            tempOfMonth++;
        }
        if(year == 1752 && month == 9 && day >= 14){
            Inputday += day - 1 - 11;
        }
        else
            Inputday += day - 1;
    }
}

string MyDate::toString() const
{
  int year = 1970, month = 1, day = 1;
  int InitialDay = Inputday;
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



MyDate::MyDate(int day, int month, int year) // Construct a date, switch it into days and store it
{
  InputDay = 0;
  int ZeroYear = 1970, ZeroMonth = 1;
  if (year >= 1970)
  {
    while (year != ZeroYear)
    {
      if ((ZeroYear % 4 == 0 && ZeroYear % 100 != 0) || ZeroYear % 400 == 0)
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
        if ((ZeroYear % 4 == 0 && ZeroYear % 100 != 0) || ZeroYear % 400 == 0)//闰年
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
        if (ZeroYear % 4 == 0)
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
        if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && year >= 1752)
          InputDay += 29;
        else if(year % 4 == 0 && year < 1752)
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
    {
      InputDay += day - 1 - 11;
    }
    else
      InputDay += day - 1;
  }
}
