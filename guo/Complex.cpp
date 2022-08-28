#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include "Complex.h"
using namespace std;


Complex::Complex(const double a, const double b){
    this->a = a;
    this->b = b;
}
Complex::Complex(const double a){
    this->a = a;
    b = 0;
}
Complex::Complex(){
    a = 0;
    b = 0;
}
Complex::~Complex(){
    a = b = 0;
}
const double Complex::getRealPart() const{
    return a;
}
const double Complex::getImaginaryPart() const{
    return b;
}
Complex Complex::add(const Complex sc) const{
    double newRealPart = a + sc.a;
    double newImaginaryPart = b + sc.b;
    return Complex(newRealPart, newImaginaryPart);
}
Complex Complex::subtract(const Complex sc) const{
    double newRealPart = a - sc.a;
    double newImaginaryPart = b - sc.b;
    return Complex(newRealPart, newImaginaryPart);
}
Complex Complex::multiply(const Complex sc) const{
    double newRealPart = a * sc.a - b * sc.b;
    double newImaginaryPart = b * sc.a + a * sc.b;
    return Complex(newRealPart, newImaginaryPart);
}
Complex Complex::divide(const Complex sc) const{
    double newRealPart = (a * sc.a + b * sc.b) / (sc.a * sc.a + sc.b * sc.b);
    double newImaginaryPart = (b * sc.a - a * sc.b) / (sc.a * sc.a + sc.b * sc.b);
    return Complex(newRealPart, newImaginaryPart);
}
double Complex::abs() const{
    return sqrt(a * a + b * b);
}
string Complex::toString() const{
    stringstream temp;
    temp << a;
    string result = temp.str();
    if(b != 0){
        temp.str("");
        temp << b;
        result = result + " + " + temp.str() + 'i';
    }
    return result;
}
Complex& Complex::operator+=(const Complex& sc){
    *this = add(sc);
    return *this;
}
Complex& Complex::operator-=(const Complex& sc){
    *this = subtract(sc);
    return *this;
}
Complex& Complex::operator*=(const Complex& sc){
    *this = multiply(sc);
    return *this;
}
Complex& Complex::operator/=(const Complex& sc){
    *this = divide(sc);
    return *this;
}
double& Complex::operator[](const int& index){
    if(index == 0){
        return a;
    }
    else{
        return b;
    }
}
const double& Complex::operator[](const int index) const{
    if(index == 0){
        return a;
    }
    else{
        return b;
    }
}
Complex Complex::operator+() const{
    return *this;
}
Complex Complex::operator-() const{
    double newA = -a;
    double newB = -b;
    return Complex(newA, newB);
}
Complex& Complex::operator++(){
    a++;
    return *this;
}
Complex Complex::operator++(int i){
    double newA = a;
    double newB = b;
    a++;
    return Complex(newA, newB);
}
Complex& Complex::operator--(){
    a--;
    return *this;
}
Complex Complex::operator--(int i){
    double newA = a;
    double newB = b;
    a--;
    return Complex(newA, newB);
}
std::ostream& operator<<(std::ostream& ostr, const Complex& sc){
    ostr << sc.toString();
    return ostr;
}
std::istream& operator>>(std::istream& ostr, Complex& sc){
    ostr >> sc[0] >> sc[1];
    return ostr;
}
Complex operator+(const Complex& sc1, const Complex& sc2){
    return sc1.add(sc2);
}
Complex operator-(const Complex& sc1, const Complex& sc2){
    return sc1.subtract(sc2);
}
Complex operator*(const Complex& sc1, const Complex& sc2){
    return sc1.multiply(sc2);
}
Complex operator/(const Complex& sc1, const Complex& sc2){
    return sc1.divide(sc2);
}







