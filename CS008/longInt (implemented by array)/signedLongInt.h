#include <iostream>
#include <cstring>
#include "longInt.h"
using namespace std;

class signedLongInt
{
    //+运算符重载函数
    friend signedLongInt operator+(const signedLongInt &num1, const signedLongInt &num2);
    //-运算符重载函数
    friend signedLongInt operator-(const signedLongInt &num1, const signedLongInt &num2);
    //<<运算符重载函数
    friend ostream &operator<<(ostream &os, const signedLongInt &num);
    //>>运算符重载函数
    friend istream &operator>>(istream &is, signedLongInt &num);
    //>运算符重载函数
    friend bool operator>(const signedLongInt &num1, const signedLongInt &num2);
    //>=运算符重载函数
    friend bool operator>=(const signedLongInt &num1, const signedLongInt &num2);
    //<运算符重载函数
    friend bool operator<(const signedLongInt &num1, const signedLongInt &num2);
    //<=运算符重载函数
    friend bool operator<=(const signedLongInt &num1, const signedLongInt &num2);
    //==运算符重载函数
    friend bool operator==(const signedLongInt &num1, const signedLongInt &num2);
    //!=运算符重载函数
    friend bool operator!=(const signedLongInt &num1, const signedLongInt &num2);
    //乘法运算
    friend signedLongInt multiply(const signedLongInt &num1, const signedLongInt &num2);

private:
    char sign;
    longInt N;

public:
    //构造函数
    signedLongInt(const char *num = "", char s = '+') : N(num), sign(s) {}
    //复制构造函数
    signedLongInt(const signedLongInt &other);
    //析构函数
    ~signedLongInt() {}
    //赋值运算符重载函数
    signedLongInt operator=(const signedLongInt &other);
    //++运算符（前缀）重载函数
    signedLongInt operator++();
    //++运算符（后缀）重载函数
    signedLongInt operator++(int x);
    //--运算符（前缀）重载函数
    signedLongInt operator--();
    //--运算符（后缀）重载函数
    signedLongInt operator--(int x);
};