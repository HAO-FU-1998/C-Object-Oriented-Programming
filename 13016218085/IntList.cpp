//Fail Name:IitList.cpp
//Author:������
//Student Number:3016218085
//Email:1072671422@qq.com
//Assignment:1
//Version:1.01
//Description:ʵ��һ��������࣬Ҫ��ʹ�ö�̬�ڴ棬ʵ��resize���ܣ����Ա任���鳤�ȣ�ʵ��push_back���ܣ�Ҫ����������һ������
//�������ĳ����Լ������е���������
//�������Ļ
//Future Improvements:
//1.�������������������
//2.����һЩ�������ܺ���
//3.֧��������ļ�

#include <iostream>
#include "IntList.h"
using namespace std;

IntList::IntList(int numVals, int val){//constructor:Ĭ�ϳ���Ϊ0,
    if(numVals > 0){
        numberValues = numVals;
        values = new int [numberValues];
        for(int i = 0; i < numberValues; i++){
            values[i] = val;
        }
    }
    else{//������Ϊ��ʱ���������ڴ棬valuesָ��NULL
        numberValues = 0;
        values = NULL;
    }
}
IntList::IntList(const IntList & il){//�������캯����ע�������ǳ���������⣬����������µ�IntListҪ����һƬ�µ��ڴ�
    if(il.numberValues > 0){
        numberValues = il.numberValues;
        values = new int[numberValues];
        for(int i = 0; i < numberValues; i++){
            values[i] = il.values[i];
        }
    }
    else{//ͬ��Ҫע��numberValues = 0 �����
        numberValues = 0;
        values = NULL;
    }
}
IntList::~IntList(){//destructorҪ�ͷ��ڴ棬
    if(numberValues > 0){
        delete [] values;
        numberValues = 0;
        values = NULL;
    }
    else
        values = NULL;
}
IntList& IntList::operator=(const IntList & il){//=��������أ���Ȼע��numberValues = 0 �����
    if(this != &il && il.numberValues > 0){
        delete [] values;
        numberValues = il.numberValues;
        values = new int [numberValues];
        for(int i = 0; i < numberValues; i++){
            values[i] = il.values[i];
        }
    }
    else if(this != &il && il.numberValues == 0){
        delete [] values;
        numberValues = il.numberValues;
        values = NULL;
    }
    else
        return *this;
    return *this;
}
int IntList::size() const{//����IntList�Ĵ�С����numberValues
    return numberValues;
}
void IntList::resize(int n, int val){//��n����ԭ����size��ʹ��val��ʼ�������Ԫ�أ���nС��ԭ�µ�size��ֱ�ӽض�ԭlist
    if(n > numberValues){
        int* temp = new int [n];
        for(int i = 0; i < n; i++){
            temp[i] = val;
        }
        for(int i = 0; i < numberValues; i++){
            temp[i] = values[i];
        }
        numberValues = n;
        delete [] values;
        values = temp;
        temp = NULL;
    }
    else if(n <=numberValues && n !=0){
        numberValues = n;
    }
    else{
        numberValues = 0;
        delete [] values;
        values = NULL;
    }
}
void IntList::push_back(int val){
    numberValues++;
    int * temp = new int [numberValues];
    for(int i = 0; i < numberValues - 1; i++){
        temp[i] = values[i];
    }
    temp[numberValues - 1] = val;
    delete [] values;
    values = temp;
    temp = NULL;
}
void IntList::print()
{
    std::cout<< this->numberValues << ":";
    for (int i = 0; i < this->size(); ++i)
    {
        std::cout<< this->values[i] << " ";
    }
    std::cout << std::endl;
}
