#include <iostream>
#include  "MyDate.h"
using namespace std;

// => 代表本行的输出

int main()
{
    const MyDate d0(0);
    //测试用例0，测试1970-01-01附近的日期
    cout << d0.add(-1).toString()  << endl;  // => 1969-12-31
    cout << (d0.subtract(1).lessThan(d0) ? "Y":"N" ) << endl; // => Y
    cout << (d0.greaterThanOrEquals(d0.add(1)) ? "Y":"N" ) << endl; // => N
    //测试用例1，2017-03-18
    MyDate d1(17243LL*60*60*24);
    cout << d1.toString()  << endl;  // => 2017-03-18
    cout << (d0.lessThanOrEquals(d1.subtract(17243)) ? "Y":"N" ) << endl; // => Y
    //测试用例2，2050-01-01，测试是否支持2038年之后
    MyDate d2(2100,1,1);
    cout << d2.subtract(d0) << endl;  // => 47482
    cout << d2.add(365).toString() <<endl; //=>2101-01-01
    //测试用例3，1752-09-14，测试历法切换
    MyDate d3(1752,9,2);
    cout << (d3.add(1).equals(MyDate(1752,9,14)) ? "Y":"N" ) << endl; // => Y
    //测试用例6，-0000-12-31，公元前1年12月31日，测试公元前日期
    MyDate d4(0,12,31);
    cout << d4.subtract(MyDate(1,1,1)) << endl; // => -1
    cout << d4.subtract(366).toString() << endl; // => -0001-12-31

    return 0;
}
