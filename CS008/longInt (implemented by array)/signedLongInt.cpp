#include "signedLongInt.h"

//复制构造函数
signedLongInt::signedLongInt(const signedLongInt &other)
{
    sign = other.sign;
    N = other.N;
}

//>>运算符重载函数
istream &operator>>(istream &is, signedLongInt &num)
{
    char *a = new char[256];
    char *tmp;
    is >> a;
    switch (a[0])
    {
    case '+':
        num.sign = '+';
        tmp = a + 1;
        break;
    case '-':
        num.sign = '-';
        tmp = a + 1;
        break;
    default:
        num.sign = '+';
        tmp = a;
        break;
    }
    longInt t(tmp);
    num.N = t;
    delete[] a;

    return is;
}

//<<运算符重载函数
ostream &operator<<(ostream &os, const signedLongInt &num)
{
    if (num.sign == '+')
    {
        os << num.N;
    }
    else
    {
        os << '-' << num.N;
    }
    return os;
}

//+运算符重载函数
signedLongInt operator+(const signedLongInt &num1, const signedLongInt &num2)
{
    signedLongInt result;
    if (num1.sign == num2.sign)
    {
        result.N = num1.N + num2.N;
        result.sign = num1.sign;
    }
    else
    {
        if (num1.N > num2.N)
        {
            result.sign = num1.sign;
            result.N = num1.N - num2.N;
        }
        else
        {
            if (num1.N == num2.N)
            {
                result.sign = '+';
                result.N = num1.N - num2.N;
            }
            else
            {
                result.sign = num2.sign;
                result.N = num2.N - num1.N;
            }
        }
    }
    return result;
}

//-运算符重载函数
signedLongInt operator-(const signedLongInt &num1, const signedLongInt &num2)
{
    signedLongInt result;
    if (num1.sign == num2.sign)
    {
        if (num1.N > num2.N)
        {
            result.N = num1.N - num2.N;
            result.sign = num1.sign;
        }
        else
        {
            if (num1.N == num2.N)
            {
                result.sign = '+';
                result.N = num1.N - num2.N;
            }
            else
            {
                result.N = num2.N - num1.N;
                result.sign = (num2.sign == '+') ? '-' : '+';
            }
        }
    }
    else
    {
        result.N = num1.N + num2.N;
        result.sign = num1.sign;
    }
    return result;
}

//赋值运算符重载函数
signedLongInt signedLongInt::operator=(const signedLongInt &other)
{
    if (this == &other)
        return *this;

    this->sign = other.sign;
    this->N = other.N;
    return *this;
}

//>运算符重载函数
bool operator>(const signedLongInt &num1, const signedLongInt &num2)
{
    if (num1.sign == num2.sign)
    {
        if (num1.sign == '+')
            return (num1.N > num2.N);
        else
            return (num1.N < num2.N);
    }
    else
    {
        if (num1.sign == '+')
            return true;
        else
            return false;
    }
}

//>=运算符重载函数
bool operator>=(const signedLongInt &num1, const signedLongInt &num2)
{
    if (num1.sign == num2.sign)
    {
        if (num1.sign == '+')
            return (num1.N >= num2.N);
        else
            return (num1.N <= num2.N);
    }
    else
    {
        if (num1.sign == '+')
            return true;
        else
            return false;
    }
}

//<运算符重载函数
bool operator<(const signedLongInt &num1, const signedLongInt &num2)
{
    return !(num1 >= num2);
}

//<=运算符重载函数
bool operator<=(const signedLongInt &num1, const signedLongInt &num2)
{
    return !(num1 > num2);
}

//==运算符重载函数
bool operator==(const signedLongInt &num1, const signedLongInt &num2)
{
    if (num1.sign != num2.sign)
        return false;
    else
        return (num1.N == num2.N);
}

//!=运算符重载函数
bool operator!=(const signedLongInt &num1, const signedLongInt &num2)
{
    return !(num1 == num2);
}

//++运算符（前缀）重载函数
signedLongInt signedLongInt::operator++()
{
    signedLongInt t("1");
    *this = *this + t;
    return *this;
}

//++运算符（后缀）重载函数
signedLongInt signedLongInt::operator++(int x)
{
    signedLongInt tmp = *this;
    ++(*this);
    return tmp;
}

//--运算符（前缀）重载函数
signedLongInt signedLongInt::operator--()
{
    signedLongInt t("1");
    *this = *this - t;
    return *this;
}

//--运算符（后缀）重载函数
signedLongInt signedLongInt::operator--(int x)
{
    signedLongInt tmp = *this;
    --(*this);
    return tmp;
}

//乘法运算
signedLongInt multiply(const signedLongInt &num1, const signedLongInt &num2)
{
    signedLongInt result;
    (num1.sign == num2.sign)? (result.sign = '+'):(result.sign = '-');
    result.N = multi(num1.N, num2.N);
    return result;
}