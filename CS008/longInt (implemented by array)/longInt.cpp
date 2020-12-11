#include "longInt.h"

//构造函数
//将一个数倒序保存在longInt对象中
longInt::longInt(const char *num)
{
	int l = strlen(num);
	n = new char[l + 1];
	for (int i = 0; i < l; ++i)
		n[i] = num[l - i - 1];
	n[l] = '\0';
}

//复制构造函数
longInt::longInt(const longInt &num)
{
	int l = strlen(num.n);
	n = new char[l + 1];
	for (int i = 0; i < l; ++i)
		n[i] = num.n[i];
	n[l] = '\0';
}

//函数：+
//用法：longInt n = num1 + num2
//此函数将num1与num2相加，将其结果保存在一个longInt类对象中
longInt operator+(const longInt &num1, const longInt &num2)
{
	int llength, slength;
	char *n3;
	if (strlen(num1.n) > strlen(num2.n))
	{
		llength = strlen(num1.n);
		slength = strlen(num2.n);
		n3 = num1.n;
	}
	else
	{
		llength = strlen(num2.n);
		slength = strlen(num1.n);
		n3 = num2.n;
	} //找出长度较长的数组
	int s = 0;
	int carry = 0; //进位数
	char *sum = new char[llength + 2];
	for (int j = 0; j < slength; ++j)
	{
		s = (num1.n[j] - '0') + (num2.n[j] - '0') + carry;
		sum[j] = s % 10 + '0';
		carry = s / 10;
	} //对短数组部分进行处理
	for (int j = slength; j < llength; ++j)
	{
		s = carry + n3[j] - '0';
		sum[j] = s % 10 + '0';
		carry = s / 10;
	} //对长数组部分进行处理
	if (carry == 1)
	{
		sum[llength] = '1';
		sum[llength + 1] = '\0';
	} //多进一位
	else
		sum[llength] = '\0';
	longInt r;
	r.n = sum;

	return r;
}

//函数：>=
//此函数判断num1是否大于等于num2，返回一个bool值
bool operator>=(const longInt &num1, const longInt &num2)
{
	int length1 = strlen(num1.n), length2 = strlen(num2.n);
	if (length1 == length2)
	{
		for (int i = length1 - 1; i >= 0; --i)
		{
			if (num1.n[i] < num2.n[i])
				return false;
			else if (num1.n[i] > num2.n[i])
				return true;
		}
		return true;
	}
	else
	{
		if (length1 > length2)
			return true;
		else
			return false;
	}
}

//函数：-
//用法：longInt n = num1 - num2
//此函数将num1和num2中的正整数相减，结果作为返回值，存放于longInt型对象中。调用函数时，必须保证num1大于等于num2
longInt operator-(const longInt &num1, const longInt &num2)
{
	if (!(num1 >= num2))
	{
		cout << "num1 is smaller than num2" << endl;
		longInt n;
		return n;
	}
	//判断num1是否大于等于num2
	int llength = strlen(num1.n), slength = strlen(num2.n);
	char *dif = new char[llength + 1];
	int d = 0;
	bool flag = 0; //是否退位的标志
	for (int i = 0; i < slength; ++i)
	{
		d = (num1.n[i] - '0') - (num2.n[i] - '0');
		if (flag)
			--d;
		if (d >= 0)
		{
			dif[i] = d + '0';
			flag = 0;
		}
		else
		{
			dif[i] = 10 + d + '0';
			flag = 1;
		}
	} //对短数组部分进行处理
	for (int j = slength; j < llength; ++j)
	{
		d = num1.n[j] - '0' - flag;
		if (d >= 0)
		{
			dif[j] = d + '0';
			flag = 0;
		}
		else
		{
			dif[j] = d + 10 + '0';
			flag = 1;
		}
	} //对长数组部分进行处理
	int i = llength;
	while (i > 1)
	{
		if (dif[i - 1] != '0')
			break;
		else
			--i;
	}
	dif[i] = '\0'; //处理多余的零并加上'\0'
	longInt s;
	s.n = dif;

	return s;
}

//函数：>
//此函数此函数判断num1是否大于num2，返回一个bool值
bool operator>(const longInt &num1, const longInt &num2)
{
	int length1 = strlen(num1.n), length2 = strlen(num2.n);
	if (length1 == length2)
	{
		for (int i = length1 - 1; i >= 0; --i)
		{
			if (num1.n[i] < num2.n[i])
				return false;
			else if (num1.n[i] > num2.n[i])
				return true;
		}
		return false;
	}
	else
	{
		if (length1 > length2)
			return true;
		else
			return false;
	}
}

//函数：<
//此函数此函数判断num1是否小于num2，返回一个bool值
bool operator<(const longInt &num1, const longInt &num2)
{
	return (!(num1 >= num2));
}

//函数：<=
//此函数此函数判断num1是否小于等于num2，返回一个bool值
bool operator<=(const longInt &num1, const longInt &num2)
{
	return (!(num1 > num2));
}

//函数：==
//此函数此函数判断num1是否等于num2，返回一个bool值
bool operator==(const longInt &num1, const longInt &num2)
{
	int length1 = strlen(num1.n), length2 = strlen(num2.n);
	if (length1 == length2)
	{
		for (int i = length1 - 1; i >= 0; --i)
		{
			if (num1.n[i] != num2.n[i])
				return false;
		}
		return true;
	}
	else
		return false;
}

//函数：!=
//此函数此函数判断num1是否不等于num2，返回一个bool值
bool operator!=(const longInt &num1, const longInt &num2)
{
	return (!(num1 == num2));
}

//函数：=
//此函数为赋值运算符的重载
longInt longInt::operator=(const longInt &other)
{
	if (this == &other)
		return *this;
	delete[] n;
	int l = strlen(other.n);
	n = new char[l + 1];
	for (int i = 0; i < l; ++i)
		n[i] = other.n[i];
	n[l] = '\0';
	return *this;
}

//函数：<<
//输出运算符重载
ostream &operator<<(ostream &os, const longInt &num)
{
	int l = strlen(num.n);
	for (int i = l - 1; i >= 0; --i)
		os << num.n[i];
	return os;
}

//函数：>>
//输入运算符重载
istream &operator>>(istream &is, longInt &num)
{
	char *s = new char[256];
	is >> s;
	int l = strlen(s);
	num.n = new char[l + 1];
	for (int i = 0; i < l; ++i)
		num.n[i] = s[l - i - 1];
	num.n[l] = '\0';

	return is;
}

//函数：++
//自增（前缀）运算符重载
longInt &longInt::operator++()
{
	int l = strlen(n);
	int s = 0, carry = 1;
	char *sum = new char[l + 2];
	int i = 0;
	for (; i < l; ++i)
	{
		if (carry == 0)
			break;
		else
		{
			s = n[i] - '0' + carry;
			carry = s / 10;
			sum[i] = s % 10 + '0';
		}
	}
	for (; i < l; ++i)
		sum[i] = n[i];
	if (carry == 1)
	{
		sum[l] = '1';
		sum[l + 1] = '\0';
	} //多进一位
	else
		sum[l] = '\0';
	delete[] n;
	n = sum;
	return *this;
}

//函数：++
//自增（后缀）运算符重载
longInt longInt::operator++(int x)
{
	longInt tmp = *this;
	++(*this);
	return tmp;
}

//函数：--
//自减（前缀）运算符重载
longInt &longInt::operator--()
{
	longInt num("0");
	if (*this <= num)
	{
		cout << "The number is smaller than 0";
		return *this;
	}
	int l = strlen(n);
	char *dif = new char[l + 1];
	bool flag = 1;
	int d = 0;
	int i = 0;
	for (; i < l; ++i)
	{
		if (!flag)
			break;
		d = n[i] - '0' - flag;
		if (d >= 0)
		{
			dif[i] = d + '0';
			flag = 0;
		}
		else
		{
			dif[i] = d + 10 + '0';
			flag = 1;
		}
	}
	for (; i < l; ++i)
		dif[i] = n[i];
	int j = l;
	while (j > 1)
	{
		if (dif[j - 1] != '0')
			break;
		else
			--j;
	}
	dif[j] = '\0'; //处理多余的零并加上'\0'
	delete[] n;
	n = dif;
	return *this;
}

//函数：--
//自减（后缀）运算符重载
longInt longInt::operator--(int x)
{
	longInt tmp = *this;
	--(*this);
	return tmp;
}

//函数：*
//乘法运算符重载
longInt multi(const longInt &num1, const longInt &num2)
{
	int l1 = strlen(num1.n), l2 = strlen(num2.n);
	int l = l1 + l2;
	char *result = new char[l + 1];
	int **number = new int *[l2];
	for (int i = 0; i < l2; ++i)
		number[i] = new int[l];
	for (int j = 0; j < l2; j++)
	{
		for (int i = 0; i < l; i++)
			number[j][i] = 0;
	}
	
	for (int j = 0; j < l2; j++)
	{
		int m = 0, carry = 0;
		int i = 0;
		for (; i < l1; ++i)
		{
			m = (num1.n[i] - '0') * (num2.n[j] - '0') + carry;
			number[j][i + j] += m % 10;
			carry = m / 10;
		}
		if(carry!=0) number[j][j+i] += carry;
	}//乘法部分
	// for (int i=0;i<l2;++i)
	// {
	// 	for(int j=0;j<l;++j)
	// 		cout<<number[i][j]<<' ';
	// 	cout<<endl;
	// }
	int carry2 = 0;
	for (int i = 0; i < l; ++i)
	{
		int tem = 0;
		for (int j = 0; j < l2; ++j)
		{
			tem += number[j][i];
		}
		tem += carry2;
		carry2 = tem / 10;
		result[i] = '0' + tem % 10;
	}//加法部分
	
	int i = l;
	while (i > 1)
	{
		if (result[i - 1] != '0')
			break;
		else
			--i;
	}
	result[i] = '\0';
	longInt r;
	r.n = result;

	for (int i = 0; i < l2; ++i)
		delete[] number[i];
	delete[] number;

	return r;
}