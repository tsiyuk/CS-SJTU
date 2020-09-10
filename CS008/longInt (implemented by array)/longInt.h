#include <iostream>
#include <cstring>
using namespace std;

class longInt
{
	//函数：+
	//用法：longInt n = num1 + num2
	//此函数将num1与num2相加，将其结果保存在一个longInt类对象中
	friend longInt operator+(const longInt &num1, const longInt &num2);

	//函数：>=
	//此函数判断num1是否大于等于num2，返回一个bool值
	friend bool operator>=(const longInt &num1, const longInt &num2);

	//函数：-
	//用法：longInt n = num1 - num2
	//此函数将num1和num2中的正整数相减，结果作为返回值，存放于longInt型对象中。调用函数时，必须保证num1大于num2ng
	friend longInt operator-(const longInt &num1, const longInt &num2);

	//函数：>
	//此函数此函数判断num1是否大于num2，返回一个bool值
	friend bool operator>(const longInt &num1, const longInt &num2);

	//函数：<
	//此函数此函数判断num1是否小于num2，返回一个bool值
	friend bool operator<(const longInt &num1, const longInt &num2);

	//函数：<=
	//此函数此函数判断num1是否小于等于num2，返回一个bool值
	friend bool operator<=(const longInt &num1, const longInt &num2);

	//函数：==
	//此函数此函数判断num1是否等于num2，返回一个bool值
	friend bool operator==(const longInt &num1, const longInt &num2);

	//函数：!=
	//此函数此函数判断num1是否不等于num2，返回一个bool值
	friend bool operator!=(const longInt &num1, const longInt &num2);

	//函数：<<
	//输出运算符重载
	friend ostream &operator<<(ostream &os, const longInt &num);

	//函数：>>
	//输入运算符重载
	friend istream &operator>>(istream &is, longInt &num);

	//函数：*
	//乘法运算符重载
	friend longInt multi(const longInt &num1, const longInt &num2);

private:
	//倒序储存数的指针
	char *n;

public:
	//构造函数
	//将一个数倒序保存在longInt对象中
	longInt(const char *num = "");

	//复制构造函数
	longInt(const longInt &num);

	//析构函数
	~longInt()
	{
		delete[] n;
		n = NULL;
	}

	//函数：=
	//此函数为赋值运算符的重载
	longInt operator=(const longInt &other);

	//函数：++
	//自增（前缀）运算符重载
	longInt &operator++();

	//函数：++
	//自增（后缀）运算符重载
	longInt operator++(int x);

	//函数：--
	//自减（前缀）运算符重载
	longInt &operator--();

	//函数：--
	//自减（后缀）运算符重载
	longInt operator--(int x);
};