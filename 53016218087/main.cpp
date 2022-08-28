#include <iostream>
#include <stdexcept>
#include  "MyDate.h"
using namespace std;

// => �����е����

int main()
{
    try {
        MyDate d(2000,15,12);
    } catch (exception& ex){
        cout << "Exception!"<<endl;
    }
    MyDate d0(0);
    //��������0������1970-01-01����������
    cout << d0 << endl;  // => 1970-01-01
    cout << d0+1 << endl;  // => 1970-01-02
    cout << d0+364 << endl;  // => 1970-12-31
    cout << d0+365  << endl;  // => 1971-01-01
    cout << d0-1 << endl;  // => 1969-12-31
    cout << d0-365 << endl;  // => 1969-01-01
    cout << d0-366 << endl;  // => 1968-12-31
    cout << ((d0-1==d0+(-1)) ? "equal":"not equal" ) << endl; // => equal
    cout << ((d0-(-1)==d0+1) ? "equal":"not equal" ) << endl; // => equal
    //��������1��2017-03-01
    MyDate d1(17226LL*60*60*24);
    cout << d1<< endl;  // => 2017-03-01
    cout << d1+7 << endl; // => 2017-03-08
     //��������2��2050-01-01�������Ƿ�֧��2038��֮��
    MyDate d2(2100,1,1);
    cout << d2-d0 << endl;  // => 47482
    cout << d2+365 <<endl; //=>2101-01-01
     //��������3��1752-09-14�����������л�
    MyDate d3(1752,9,14);
    cout << d3-1 << endl;  // => 1752-09-02
    //��������4��0001-01-01����Ԫ1��1��1�գ����Թ�Ԫǰ����
    MyDate d4(1,1,1);
    cout << d4-1 << endl;  // => 0000-12-31
    //��������5��0000-12-31����Ԫǰ1��12��31�գ����Թ�Ԫǰ����
    MyDate d5(0,12,31);
    cout << d5 << endl;  // => 0000-12-31
    cout << (d4-1==d5 ? "equal":"not equal" ) << endl; // => equal
    //��������6��-0001-12-31����Ԫǰ2��12��31�գ����Թ�Ԫǰ����
    MyDate d6(-1,12,31);
    cout << d6<< endl;  // => -0001-12-31
    cout << d6-d5 << endl; // => -366

/*
    MyDate d0(0);
    //��������0������1970-01-01����������
    cout << d0.toString()  << endl;  // => 1970-01-01
    cout << d0.add(1).toString()  << endl;  // => 1970-01-02
    cout << d0.add(364).toString()  << endl;  // => 1970-12-31
    cout << d0.add(365).toString()  << endl;  // => 1971-01-01
    cout << d0.subtract(1).toString()  << endl;  // => 1969-12-31
    cout << d0.subtract(365).toString()  << endl;  // => 1969-01-01
    cout << d0.subtract(366).toString()  << endl;  // => 1968-12-31
    cout << (d0.subtract(1).equals(d0.add(-1)) ? "equal":"not equal" ) << endl; // => equal
    cout << (d0.subtract(-1).equals(d0.add(1)) ? "equal":"not equal" ) << endl; // => equal
    //��������1��2017-03-01
    MyDate d1(17226*60*60*24LL);
    cout << d1.toString()  << endl;  // => 2017-03-01
    cout << d1.add(7).toString() << endl; // => 2017-03-08
     //��������2��2050-01-01�������Ƿ�֧��2038��֮��
    MyDate d2(2100,1,1);
    cout << d2.subtract(d0) << endl;  // => 47482
    cout << d2.add(365).toString() <<endl; //=>2101-01-01
     //��������3��1752-09-14�����������л�
    MyDate d3(1752,9,14);
    cout << d3.subtract(1).toString()  << endl;  // => 1752-09-02
    //��������4��0001-01-01����Ԫ1��1��1�գ����Թ�Ԫǰ����
    MyDate d4(1,1,1);
    cout << d4.subtract(1).toString()  << endl;  // => 0000-12-31
    //��������5��0000-12-31����Ԫǰ1��12��31�գ����Թ�Ԫǰ����
    MyDate d5(0,12,31);
    cout << d5.toString()  << endl;  // => 0000-12-31
    cout << (d4.subtract(1).equals(d5) ? "equal":"not equal" ) << endl; // => equal
    //��������6��-0001-12-31����Ԫǰ2��12��31�գ����Թ�Ԫǰ����
    MyDate d6(-1,12,31);
    cout << d6.toString()  << endl;  // => -0001-12-31
    cout << d6.subtract(d5) << endl; // => -366
*/
    return 0;
}
