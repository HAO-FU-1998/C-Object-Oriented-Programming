//Fail Name:IitList.h
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

#ifndef INTLIST_H_INCLUDED
#define INTLIST_H_INCLUDED
using namespace std;

class IntList {

public:
    //function members
    IntList(int numVals = 0, int val = 0); // constructor
    IntList(const IntList &il); // copy constructor
    ~IntList(); // destructor
    IntList& operator=(const IntList &il); // = operator
    int size() const; // size of the list
    // resize list
    //��n����ԭ����size��ʹ��val��ʼ�������Ԫ��
    //��nС��ԭ�µ�size��ֱ�ӽض�ԭlist
    void resize(int n = 0, int val = 0);// resize list
    void push_back(int val); // add new last element
    //print the list
    //�����ʽ  �б��ȣ�Ԫ��1 Ԫ��2 Ԫ��3 ...
    void print();//print the list

private:
    // data members
    int * values; //pointer to elements
    int numberValues; //size of list
};


#endif // INTLIST_H_INCLUDED
