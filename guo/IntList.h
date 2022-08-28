#ifndef __IntList__IntList__
#define __IntList__IntList__

class IntList {

public:
    //function members
    IntList(int numVals = 0, int val = 0); // constructor
    IntList(const IntList &il); // copy constructor
    ~IntList(); // destructor
    IntList& operator=(const IntList &il); // = operator
    int size() const; // size of the list
    // resize list
    //当n大于原来的size，使用val初始化多出的元素
    //当n小于原来的size，直接截断原list
    void resize(int n = 0, int val = 0);// resize list
    void push_back(int val); // add new last element
    //print the list
    //输出格式  列表长度：元素1 元素2 元素3 ...
    void print();//print the list
    //取出index所在位置的整形数
    int& operator [] ( const int index);
    //取出index所在位置的整形数
    const int& operator [] ( const int index) const;

private:
    // data members
    int * values; //pointer to elements
    int numberValues; //size of list
    
};
//判断参数中的两个IntList是否相等，相等返回true，不等返回false
//相等定义为list长度和list中的每个数据都相等
bool operator == (const IntList& il1, const IntList& il2);
//判断参数中的两个IntList是否相等，相等返回false，不等返回true
//相等定义为list长度和list中的每个数据都相等
bool operator != (const IntList& il1, const IntList& il2);
//参数中的两个IntList相加
//两个list不等长的情况下，短list中差的元素视为0
IntList operator + (const IntList& il1, const IntList& il2);
//参数中的两个IntList相减，il1-il2
//两个list不等长的情况下，短list中差的元素视为0
IntList operator - (const IntList& il1, const IntList& il2);
//输出il，支持文件输出，格式等同print
std::ostream& operator << (std::ostream& ost, const IntList& il);
//由用户输入il的内容，支持文件输入
//输入格式：输入list长度，依次输入list的值，每个数字以空格或者回车间隔，输入完成以回车结束
std::istream& operator >> (std::istream& ist, IntList& il);

#endif /* defined(__IntList__IntList__) */
