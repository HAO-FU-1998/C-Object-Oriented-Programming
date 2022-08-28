//Fail Name:MyDate.cpp
//Author:郭培溟
//Student Number:3016218085
//Email:1072671422@qq.com
//Assignment:2
//Version:2.01
//Description:实现一个日期类，支持公元前9999到公元后9999，考虑闰年的问题，时间精确到天数
//输出对象的具体日期，输出格式符合ISO8601标准
//输出到屏幕
//Future Improvements:
//1.增加其他的运算符重载
//2.增加一些其他功能函数
//3.支持输出到文件
//4.优化算法，精简代码长度，尤其优化toString函数

#include "MyDate.h"
#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
using namespace std;

MyDate::MyDate(long long seconds){
    days = (seconds + TIMEZONE_OFFSET) / 60 / 60 / 24;//构造函数：利用距离1970年的秒数来构造对象
}
MyDate::MyDate(int year, int month, int day){
    check(year, month, day);
    days = 0;//首先将对象的数据域初始化为0，很重要，不然结果不正确
    int tempOfYear = 1970, tempOfMonth = 1;/*利用逼近的方法，先声明一个tempOfYear，并且初始化为1970，tempOfYear每向year逼近一年
    则days增加相应一年的天数，如此逼近到目标年份year停止*/
    if(year >= 1970){
        while(year != tempOfYear){
            if((tempOfYear % 4 == 0 && tempOfYear % 100 != 0) || tempOfYear % 400 == 0) //闰年
                days += 366;
            else
                days += 365;
            tempOfYear++;
        }
        while(month != tempOfMonth){/*类比于年份的逼近，月份的逼近原理相同*/
            if(tempOfMonth == 1 || tempOfMonth == 3 || tempOfMonth == 5 || tempOfMonth == 7 || tempOfMonth ==8 || tempOfMonth == 10 || tempOfMonth == 12)
                days += 31;
            else if(tempOfMonth == 2){
                if((tempOfYear % 4 == 0 && tempOfYear % 100 != 0) || tempOfYear % 400 == 0)//闰年
                    days += 29;
                else
                    days += 28;
            }
            else
                days += 30;
            tempOfMonth++;
        }
        days += day - 1;
    }
    else{
        tempOfYear--;/*1970年之后，则要求days为负数*/
        while(tempOfYear >= year){/*原理同样相同于上面的年份逼近，但是days要为减法，并且一旦逼近到目标年份之后，实际上已经到了
                目标日期的时间点之前，所以要求之后的月份逼近转变为加法*/
            if(tempOfYear > 1752){
                if((tempOfYear % 4 == 0 && tempOfYear % 100 != 0) || tempOfYear % 400 == 0)
                    days -= 366;
                else
                    days -= 365;
            }
            else if(tempOfYear == 1752)
                days -= 355;
            else{
                if(tempOfYear % 4 == 0)//1752年之前的闰年
                    days -= 366;
                else
                    days -= 365;
            }
            tempOfYear--;
        }
        while(month != tempOfMonth){/*次数注意月份的逼近一定采用加法*/
            if(tempOfMonth == 1 || tempOfMonth == 3 || tempOfMonth == 5 || tempOfMonth == 7 || tempOfMonth ==8 || tempOfMonth == 10 || tempOfMonth == 12)
                days += 31;
            else if(tempOfMonth == 2){
                if(((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && year >= 1752)//闰年
                    days += 29;
                else if(year % 4 == 0 && year < 1752)
                    days += 29;
                else
                    days += 28;
            }
            else{
                if(year == 1752 && tempOfMonth == 9)/*月份的逼近要注意1752年的九月份其实只有19天*/
                    days += 19;
                else
                    days += 30;
            }
            tempOfMonth++;
        }
        if(year == 1752 && month == 9 && day >= 14){
            days += day - 1 - 11;
        }
        else
            days += day - 1;
    }
}
MyDate::MyDate(int days1, int days2){/*新增加的构造函数，可以方便的用days来直接构造新的对象*/
    days = days1 + days2;
}
MyDate MyDate::add(int daysOfAdd) const{/*加法运算*/
    int daysOfOld = days;
    MyDate newDate(daysOfOld, daysOfAdd);
    return newDate;
}
MyDate MyDate::subtract(int daysOfSubtract) const{/*减法运算*/
    int daysOfOld = days;
    daysOfSubtract *= -1;
    MyDate newDate(daysOfOld,daysOfSubtract);
    return newDate;
}
int MyDate::subtract(const MyDate& myDate0) const{
    int result = days - myDate0.days;
    return result;
}
bool MyDate::equals(const MyDate& myDate0) const{/*对于对象的相等测试*/
    if(days == myDate0.days)
        return true;
    else
        return false;
}
bool MyDate::lessThan(const MyDate& myDate0) const{/*小于测试*/
    if(days < myDate0.days)
        return true;
    else
        return false;
}
bool MyDate::greaterThan(const MyDate& myDate0) const{/*大于测试*/
    if(days > myDate0.days)
        return true;
    else
        return false;
}
bool MyDate::lessThanOrEquals(const MyDate& myDate0) const{/*小于等于测试*/
    if(days <= myDate0.days)
        return true;
    else
        return false;
}
bool MyDate::greaterThanOrEquals(const MyDate& myDate0) const{/*大于等于测试*/
    if(days >= myDate0.days)
        return true;
    else
        return false;
}
bool MyDate::operator==(const MyDate& myDate0) const{
    return equals(myDate0);
}
bool MyDate::operator<(const MyDate& myDate0) const{
    return lessThan(myDate0);
}
bool MyDate::operator>(const MyDate& myDate0) const{
    return greaterThan(myDate0);
}
bool MyDate::operator<=(const MyDate& myDate0) const{
    return lessThanOrEquals(myDate0);
}
bool MyDate::operator>=(const MyDate& myDate0) const{
    return greaterThanOrEquals(myDate0);
}
MyDate MyDate::operator+(int days) const{
    return add(days);
}
MyDate MyDate::operator-(int days) const{
    return subtract(days);
}
int MyDate::operator-(const MyDate& myDate0) const{
    return subtract(myDate0);
}
string MyDate::toString() const{/*toString函数实现对象的输出，但关键点在于将days转化为年月日的形式，类似于第二个构造函数的逆运算*/
    int year = 1970, month = 1, day = 1, days0 = days;/*首先虚拟一个将要输出的日期为1970-01-01，为目标日期，然后由于为只读函数，days不可改变
    所以声明新的days变量*/
    if(days0 >= 0){/*若在1970-01-01之后的话要实行减法制，虚拟的目标日期每增加一年，则days0减少，直到最终的年份*/
        while(days0 >= 365){
            if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
                if(days0 >= 366){
                    days0 -= 366;
                    year++;
                }
                else
                    break;
            }
            else{
                days0 -= 365;
                year++;
            }
        }
        while(days0 >= 28){/*月份的逼近*/
            if(month == 1 || month == 3 || month == 5 || month == 7 || month ==8 || month == 10 || month == 12){
                if(days0 >= 31){
                    days0 -= 31;
                    month++;
                }
                else
                    break;
            }
            else if(month == 4 || month == 6 || month == 9 || month == 11){
                if(days0 >= 30){
                    days0 -= 30;
                    month++;
                }
                else
                    break;
            }
            else{
                if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
                    if(days0 >= 29){
                        days0 -= 29;
                        month++;
                    }
                    else
                        break;
                }
                else{
                    days0 -= 28;
                    month++;
                }
            }
        }
        day += days0;
    }
    else{/*1970年之前的转化情况*/
        while(days0 <= -355){/*年份的转换情况，要注意闰年的问题，1752年前后的闰年方式并不相同，并且在1752年时候进行了儒瑞历和格里历
                的变换，导致减少了11天*/
            if(((((year - 1)% 4 == 0 && (year - 1) % 100 != 0) || (year - 1) % 400 == 0)) && (year - 1) > 1752){
                if(days0 <= -366){
                    days0+= 366;
                    year--;
                }
                else
                    break;
            }
            else if((year - 1) % 4 == 0 && (year - 1) < 1752){
                if(days0 <= -366){
                    days0 += 366;
                    year--;
                }
                else
                    break;
            }
            else if((year - 1) == 1752){
                days0 += 355;
                year--;
            }
            else{
                if(days0 <= -365){
                    days0 += 365;
                    year--;
                }
                else
                    break;
            }
        }
        month = 12;/*月份的逼近要从12月份倒着进行，所以先把虚拟出来的month = 12，且年份-1*/
        year--;
        while(days0 <= -19){
            if(month == 1 || month == 3 || month == 5 || month == 7 || month ==8 || month == 10 || month == 12){
                if(days0 <= -31){
                    days0 += 31;
                    month--;
                }
                else
                    break;
            }
            else if(month == 9 && year == 1752){
                if(days0 <= -19){
                    days0 += 19;
                    month--;
                }
                else
                    break;
            }
            else if(month == 2){
                if(((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && year >= 1752){
                    if(days0 <= -29){
                        days0 += 29;
                        month--;
                    }
                    else
                        break;
                }
                else if(year % 4 == 0 && year <= 1752){
                    if(days0 <= -29){
                        days0 += 29;
                        month--;
                    }
                    else
                        break;
                }
                else{
                    if(days0 <= -28){
                        days0 += 28;
                        month--;
                    }
                    else
                        break;
                }
            }
            else{
                if(days0 <= -30){
                    days0 += 30;
                    month--;
                }
                else
                    break;
            }
        }
        if(days0 == 0){/*如若days0 = 0，则一定把开始就减少的月份加上去，并且年份如果到了13，则把月份调回1，且年分数加上一*/
            month++;
            if(month == 13){
                month = 1;
                year++;
            }
        }
        else{
            if(month == 1 || month == 3 || month == 5 || month == 7 || month ==8 || month == 10 || month == 12){
                day = 31;
                day = day - (days0 * (-1) -1);
            }
            else if(month == 9 && year == 1752){/*日期转换时一定注意，9月份2号过了之后改成14号而不是3号*/
                day = 30;
                if(days0>= -17)
                    day = day - (days0 * (-1) -1);
                else
                    day = day - ((days0 - 11) * (-1) - 1);
            }
            else if(month == 2){
                if((((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && year >= 1752)){
                    day = 29;
                    day = day - (days0 * (-1) -1);
                }
                else if((year % 4 == 0 && year < 1752)){
                    day = 29;
                    day = day - (days0 * (-1) -1);
                }
                else{
                    day = 28;
                    day = day - (days0 * (-1) -1);
                }
            }
            else{
                day = 30;
                day = day - (days0 * (-1) -1);
            }
        }
    }
    string stringOfYear, stringOfMonth, stringOfDay;/*将日期一字符串的形式输出出去。所以将其转换*/
    int year0 = static_cast<int>(fabs(year));
    while(year0 != 0){
        stringOfYear = static_cast<char>((year0 % 10) + '0') + stringOfYear;/*先转换成字符，然后与字符串拼接*/
        year0 = year0 / 10;
    }
    while(stringOfYear.length() < 4)
        stringOfYear = '0' + stringOfYear;
    if(year < 0)
        stringOfYear = '-' + stringOfYear;
    while(month != 0){
        stringOfMonth = static_cast<char>((month % 10) + '0') + stringOfMonth;
        month = month / 10;
    }
    while(stringOfMonth.length() < 2)
        stringOfMonth = '0' + stringOfMonth;
    while(day != 0){
        stringOfDay = static_cast<char>((day % 10) + '0') + stringOfDay;
        day = day / 10;
    }
    while(stringOfDay.length() < 2)
        stringOfDay = '0' + stringOfDay;
    stringOfYear = stringOfYear + '-' + stringOfMonth + '-' + stringOfDay;
    return stringOfYear;
}
ostream& operator<<(ostream& os, const MyDate& dt){
    os << dt.toString();
    return os;
}
void MyDate::check(int year, int month, int day){
    if(month < 1 || month > 12){
        throw invalid_argument("Invalid Date!");
    }
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
        if(day < 1 || day > 31){
            throw invalid_argument("Invalid Date!");
        }
    }
    else if(month == 9){
        if(year == 1752){
            if(day < 1 || day > 30 || (day > 2 && day < 14)){
                throw invalid_argument("Invalid Date!");
            }
        }
        else{
            if(day < 1 || day > 30){
                throw invalid_argument("Invalid Date!");
            }
        }
    }
    else if(month == 2){
        if((((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) && (year >= 1752)) || (year % 4 == 0 && year < 1752)){
            if(day < 1 || day > 29){
                throw invalid_argument("Invalid Date!");
            }
        }
        else{
            if(day < 1 || day > 28){
                throw invalid_argument("Invalid Date!");
            }
        }
    }
    else{
        if(day < 1 || day > 30){
            throw invalid_argument("Invalid Date!");
        }
    }
}






