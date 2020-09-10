#ifndef LONGINT_H
#define LONGINT_H


#include<iostream>
#include<cstring>
using namespace std;

class longInt
{
	//函数：add
	//用法：longInt n = add(longInt num1, longInt num2)
	//此函数将num1与num2相加，将其结果保存在一个longInt类对象中
	friend longInt add(const longInt& num1, const longInt& num2);

	//函数：greaterEqual
	//用法：bool flag = greaterEqual(longInt num1, longInt num2)
	//此函数判断num1是否大于等于num2，返回一个bool值
	friend bool greaterEqual(const longInt& num1, const longInt& num2);

	//函数：sub
	//用法：longInt n = sub(longInt num1, longInt num2)
	//此函数将num1和num2中的正整数相减，结果作为返回值，存放于longInt型对象中。调用函数时，必须保证num1大于num2ng
	friend longInt sub(const longInt& num1, const longInt& num2);

	//函数：greater
	//用法：bool flag = greater(longInt num1, longInt num2)
	//此函数此函数判断num1是否大于num2，返回一个bool值
	friend bool Greater(const longInt& num1, const longInt& num2);

	//函数：smaller
	//用法：bool flag = smaller(longInt num1, longInt num2)
	//此函数此函数判断num1是否小于num2，返回一个bool值
	friend bool smaller(const longInt& num1, const longInt& num2);

	//函数：smallerEqual
	//用法：bool flag = smallerEqual(longInt num1, longInt num2)
	//此函数此函数判断num1是否小于等于num2，返回一个bool值
	friend bool smallerEqual(const longInt& num1, const longInt& num2);

	//函数：equal
	//用法：bool flag = equal(longInt num1, longInt num2)
	//此函数此函数判断num1是否等于num2，返回一个bool值
	friend bool Equal(const longInt& num1, const longInt& num2);

	//函数：notEqual
	//用法：bool flag = notEqual(longInt num1, longInt num2)
	//此函数此函数判断num1是否不等于num2，返回一个bool值
	friend bool notEqual(const longInt& num1, const longInt& num2);

private:
	char* n;

public:
	//构造函数
	//将一个数倒序保存在longInt对象中
	longInt(const char* num = "");
	//复制构造函数
	longInt(const longInt& num);
	//析构函数
	~longInt(){ delete[] n;}

	//函数：output
	//用法：output(longInt num)
	//此函数将传入对象打印出来
	void output();

};


#endif // LONGINT_H
