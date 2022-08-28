//Fail Name:MyDate.cpp
//Author:������
//Student Number:3016218085
//Email:1072671422@qq.com
//Assignment:2
//Version:2.01
//Description:ʵ��һ�������֧࣬�ֹ�Ԫǰ9999����Ԫ��9999��������������⣬ʱ�侫ȷ������
//�������ľ������ڣ������ʽ����ISO8601��׼
//�������Ļ
//Future Improvements:
//1.�������������������
//2.����һЩ�������ܺ���
//3.֧��������ļ�
//4.�Ż��㷨��������볤�ȣ������Ż�toString����

#include "MyDate.h"
#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
using namespace std;

MyDate::MyDate(long long seconds){
    days = (seconds + TIMEZONE_OFFSET) / 60 / 60 / 24;//���캯�������þ���1970����������������
}
MyDate::MyDate(int year, int month, int day){
    check(year, month, day);
    days = 0;//���Ƚ�������������ʼ��Ϊ0������Ҫ����Ȼ�������ȷ
    int tempOfYear = 1970, tempOfMonth = 1;/*���ñƽ��ķ�����������һ��tempOfYear�����ҳ�ʼ��Ϊ1970��tempOfYearÿ��year�ƽ�һ��
    ��days������Ӧһ�����������˱ƽ���Ŀ�����yearֹͣ*/
    if(year >= 1970){
        while(year != tempOfYear){
            if((tempOfYear % 4 == 0 && tempOfYear % 100 != 0) || tempOfYear % 400 == 0) //����
                days += 366;
            else
                days += 365;
            tempOfYear++;
        }
        while(month != tempOfMonth){/*�������ݵıƽ����·ݵıƽ�ԭ����ͬ*/
            if(tempOfMonth == 1 || tempOfMonth == 3 || tempOfMonth == 5 || tempOfMonth == 7 || tempOfMonth ==8 || tempOfMonth == 10 || tempOfMonth == 12)
                days += 31;
            else if(tempOfMonth == 2){
                if((tempOfYear % 4 == 0 && tempOfYear % 100 != 0) || tempOfYear % 400 == 0)//����
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
        tempOfYear--;/*1970��֮����Ҫ��daysΪ����*/
        while(tempOfYear >= year){/*ԭ��ͬ����ͬ���������ݱƽ�������daysҪΪ����������һ���ƽ���Ŀ�����֮��ʵ�����Ѿ�����
                Ŀ�����ڵ�ʱ���֮ǰ������Ҫ��֮����·ݱƽ�ת��Ϊ�ӷ�*/
            if(tempOfYear > 1752){
                if((tempOfYear % 4 == 0 && tempOfYear % 100 != 0) || tempOfYear % 400 == 0)
                    days -= 366;
                else
                    days -= 365;
            }
            else if(tempOfYear == 1752)
                days -= 355;
            else{
                if(tempOfYear % 4 == 0)//1752��֮ǰ������
                    days -= 366;
                else
                    days -= 365;
            }
            tempOfYear--;
        }
        while(month != tempOfMonth){/*����ע���·ݵıƽ�һ�����üӷ�*/
            if(tempOfMonth == 1 || tempOfMonth == 3 || tempOfMonth == 5 || tempOfMonth == 7 || tempOfMonth ==8 || tempOfMonth == 10 || tempOfMonth == 12)
                days += 31;
            else if(tempOfMonth == 2){
                if(((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && year >= 1752)//����
                    days += 29;
                else if(year % 4 == 0 && year < 1752)
                    days += 29;
                else
                    days += 28;
            }
            else{
                if(year == 1752 && tempOfMonth == 9)/*�·ݵıƽ�Ҫע��1752��ľ��·���ʵֻ��19��*/
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
MyDate::MyDate(int days1, int days2){/*�����ӵĹ��캯�������Է������days��ֱ�ӹ����µĶ���*/
    days = days1 + days2;
}
MyDate MyDate::add(int daysOfAdd) const{/*�ӷ�����*/
    int daysOfOld = days;
    MyDate newDate(daysOfOld, daysOfAdd);
    return newDate;
}
MyDate MyDate::subtract(int daysOfSubtract) const{/*��������*/
    int daysOfOld = days;
    daysOfSubtract *= -1;
    MyDate newDate(daysOfOld,daysOfSubtract);
    return newDate;
}
int MyDate::subtract(const MyDate& myDate0) const{
    int result = days - myDate0.days;
    return result;
}
bool MyDate::equals(const MyDate& myDate0) const{/*���ڶ������Ȳ���*/
    if(days == myDate0.days)
        return true;
    else
        return false;
}
bool MyDate::lessThan(const MyDate& myDate0) const{/*С�ڲ���*/
    if(days < myDate0.days)
        return true;
    else
        return false;
}
bool MyDate::greaterThan(const MyDate& myDate0) const{/*���ڲ���*/
    if(days > myDate0.days)
        return true;
    else
        return false;
}
bool MyDate::lessThanOrEquals(const MyDate& myDate0) const{/*С�ڵ��ڲ���*/
    if(days <= myDate0.days)
        return true;
    else
        return false;
}
bool MyDate::greaterThanOrEquals(const MyDate& myDate0) const{/*���ڵ��ڲ���*/
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
string MyDate::toString() const{/*toString����ʵ�ֶ������������ؼ������ڽ�daysת��Ϊ�����յ���ʽ�������ڵڶ������캯����������*/
    int year = 1970, month = 1, day = 1, days0 = days;/*��������һ����Ҫ���������Ϊ1970-01-01��ΪĿ�����ڣ�Ȼ������Ϊֻ��������days���ɸı�
    ���������µ�days����*/
    if(days0 >= 0){/*����1970-01-01֮��Ļ�Ҫʵ�м����ƣ������Ŀ������ÿ����һ�꣬��days0���٣�ֱ�����յ����*/
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
        while(days0 >= 28){/*�·ݵıƽ�*/
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
    else{/*1970��֮ǰ��ת�����*/
        while(days0 <= -355){/*��ݵ�ת�������Ҫע����������⣬1752��ǰ������귽ʽ������ͬ��������1752��ʱ��������������͸�����
                �ı任�����¼�����11��*/
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
        month = 12;/*�·ݵıƽ�Ҫ��12�·ݵ��Ž��У������Ȱ����������month = 12�������-1*/
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
        if(days0 == 0){/*����days0 = 0����һ���ѿ�ʼ�ͼ��ٵ��·ݼ���ȥ����������������13������·ݵ���1�������������һ*/
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
            else if(month == 9 && year == 1752){/*����ת��ʱһ��ע�⣬9�·�2�Ź���֮��ĳ�14�Ŷ�����3��*/
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
    string stringOfYear, stringOfMonth, stringOfDay;/*������һ�ַ�������ʽ�����ȥ�����Խ���ת��*/
    int year0 = static_cast<int>(fabs(year));
    while(year0 != 0){
        stringOfYear = static_cast<char>((year0 % 10) + '0') + stringOfYear;/*��ת�����ַ���Ȼ�����ַ���ƴ��*/
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






