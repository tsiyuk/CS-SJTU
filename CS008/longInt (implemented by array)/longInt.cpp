#include "longInt.h"

//构造函数
//将一个数倒序保存在longInt对象中
longInt::longInt(const char* num)
{
	int l = strlen(num);
	n = new char[l + 1];
	for (int i = 0;i < l;++i)
		n[i] = num[l-i-1];
	n[l] = '\0';
}

//复制构造函数
longInt::longInt(const longInt& num)
{
	int l = strlen(num.n);
	delete[]n;
	n = new char[l + 1];
	for (int i = 0;i < l;++i)
		n[i] = num.n[i];
	n[l] = '\0';
}

//函数：output
//用法：num.output()
//此函数将传入对象以倒序打印出来
void longInt::output()
{
	int l = strlen(n);
	for (int i = l - 1; i >= 0; --i)
		cout << n[i];
}

//函数：add
//用法：longInt n = add(longInt num1, longInt num2)
//此函数将num1与num2相加，将其结果保存在一个longInt类对象中
longInt add(const longInt& num1, const longInt& num2)
{
	int llength, slength;
	char* n3;
	if (strlen(num1.n) > strlen(num2.n)) {
		llength = strlen(num1.n);
		slength = strlen(num2.n);
		n3 = num1.n;
	}
	else {
		llength = strlen(num2.n);
		slength = strlen(num1.n);
		n3 = num2.n;
	}//找出长度较长的数组
	int s = 0;
	int carry = 0;//进位数
	char* sum = new char[llength + 2];
	for (int j = 0; j < slength; ++j) {
		s = (num1.n[j] - '0') + (num2.n[j] - '0') + carry;
		sum[j] = s % 10 + '0';
		carry = s / 10;
	}//对短数组部分进行处理
	for (int j = slength; j < llength; ++j) {
		s = carry + n3[j] - '0';
		sum[j] = s % 10 + '0';
		carry = s / 10;
	}//对长数组部分进行处理
	if (carry == 1) {
		sum[llength] = '1';
		sum[llength + 1] = '\0';
	}//多进一位
	else sum[llength] = '\0';
	longInt r;
	r.n = sum;

	return r;
}

//函数：greaterEqual
//用法：bool flag = greaterEqual(longInt num1, longInt num2)
//此函数判断num1是否大于等于num2，返回一个bool值
bool greaterEqual(const longInt& num1, const longInt& num2)
{
	int length1 = strlen(num1.n), length2 = strlen(num2.n);
	if (length1 == length2) {
		for (int i = length1 - 1; i >= 0; --i) {
			if (num1.n[i] < num2.n[i])
				return false;
			else if (num1.n[i] > num2.n[i]) return true;
		}
		return true;
	}
	else {
		if (length1 > length2) return true;
		else return false;
	}
}

//函数：sub
//用法：longInt n = sub(longInt num1, longInt num2)
//此函数将num1和num2中的正整数相减，结果作为返回值，存放于longInt型对象中。调用函数时，必须保证num1大于等于num2
longInt sub(const longInt& num1, const longInt& num2)
{
	if (!greaterEqual(num1, num2)) {
		cout << "num1 is smaller than num2" << endl;
		longInt n;
        return n;
	}
	//判断num1是否大于等于num2
	int llength = strlen(num1.n), slength = strlen(num2.n);
	char* dif = new char[llength + 1];
	int d = 0;
	bool flag = 0;//是否退位的标志
	for (int i = 0; i < slength; ++i) {
		d = (num1.n[i] - '0') - (num2.n[i] - '0');
		if (flag) --d;
		if (d >= 0) {
			dif[i] = d + '0';
			flag = 0;
		}
		else {
			dif[i] = 10 + d + '0';
			flag = 1;
		}
	}//对短数组部分进行处理
	for (int j = slength; j < llength; ++j) {
		d = num1.n[j] - '0' - flag;
		if (d >= 0) {
			dif[j] = d + '0';
			flag = 0;
		}
		else {
			dif[j] = d + 10 + '0';
			flag = 1;
		}
	}//对长数组部分进行处理
	int i = llength;
	while (i > 1) {
		if (dif[i - 1] != '0') break;
		else --i;
	}
	dif[i] = '\0';//处理多余的零并加上'\0'
	longInt s;
	s.n = dif;

	return s;
}

//函数：greater
//用法：bool flag = greater(longInt num1, longInt num2)
//此函数此函数判断num1是否大于num2，返回一个bool值
bool Greater(const longInt& num1, const longInt& num2)
{
	int length1 = strlen(num1.n), length2 = strlen(num2.n);
	if (length1 == length2) {
		for (int i = length1 - 1; i >= 0; --i) {
			if (num1.n[i] < num2.n[i])
				return false;
			else if (num1.n[i] > num2.n[i]) return true;
		}
		return false;
	}
	else {
		if (length1 > length2) return true;
		else return false;
	}
}

//函数：smaller
//用法：bool flag = smaller(longInt num1, longInt num2)
//此函数此函数判断num1是否小于num2，返回一个bool值
bool smaller(const longInt& num1, const longInt& num2)
{
	return !greaterEqual(num1, num2);
}

//函数：smallerEqual
//用法：bool flag = smallerEqual(longInt num1, longInt num2)
//此函数此函数判断num1是否小于等于num2，返回一个bool值
bool smallerEqual(const longInt& num1, const longInt& num2)
{
	return !Greater(num1, num2);
}

//函数：equal
//用法：bool flag = equal(longInt num1, longInt num2)
//此函数此函数判断num1是否等于num2，返回一个bool值
bool Equal(const longInt& num1, const longInt& num2)
{
	int length1 = strlen(num1.n), length2 = strlen(num2.n);
	if (length1 == length2) {
		for (int i = length1 - 1; i >= 0; --i) {
			if (num1.n[i] != num2.n[i])
				return false;
		}
		return true;
	}
	else return false;
}

//函数：notEqual
//用法：bool flag = notEqual(longInt num1, longInt num2)
//此函数此函数判断num1是否不等于num2，返回一个bool值
bool notEqual(const longInt& num1, const longInt& num2)
{
	return (!Equal(num1, num2));
}
