#ifndef SET
#define SET

#include <iostream>
using namespace std;

template<class T>
class set
{
	template<typename T> friend set<T> operator +(const set<T>& s1, const set<T>& s2);
	template<typename T> friend set<T> operator *(const set<T>& s1, const set<T>& s2);
	template<typename T> friend set<T> operator -(const set<T>& s1, const set<T>& s2);

private:
	T* data;
	int currentSize, maxSize;
	void doubleSpace();
	bool exist(T x)const;

public:
	set();
	set(const set<T>& s);
	~set() { delete[]data; }
	set& operator=(const set<T>& s);
	int getSize() { return currentSize; }
	bool insert(T x);
	bool erase(T x);
	void display();
};

#endif

template <class T>
set<T>::set()
{
	currentSize = 0;
	maxSize = 20;
	data = new T[maxSize];
}

template <class T>
set<T>::set(const set<T> &s)
{
	currentSize = s.currentSize;
	maxSize = s.maxSize;
	data = new T[maxSize];
	for (int i = 0; i <= currentSize; i++)
	{
		data[i] = s.data[i];
	}
}

template <class T>
void set<T>::doubleSpace()
{
	maxSize *= 2;
	T *tmp = data;
	data = new T[maxSize];
	for (int i = 0; i <= currentSize; i++)
		data[i] = tmp[i];
	delete[] tmp;
}

template <class T>
bool set<T>::exist(T x) const
{
	for (int i = 0; i <= currentSize; i++)
		if (data[i] == x)
			return true;
	return false;
}

template <class T>
bool set<T>::insert(T x)
{
	if (exist(x))
		return false;
	if (currentSize == maxSize - 1)
		doubleSpace();
	data[++currentSize] = x;
	return true;
}

template <class T>
bool set<T>::erase(T x)
{
	bool flag;
	int i;
	for (i = 0; i <= currentSize; i++)
	{
		if (data[i] == x)
		{
			flag = true;
			break;
		}
	}
	if (flag)
	{
		for (; i <= currentSize - 1; i++)
			data[i] = data[i + 1];
		--currentSize;
	}
	return flag;
}

template <class T>
void set<T>::display()
{
	for (int i = 1; i <= currentSize; i++)
		cout << data[i] << ' ';
	cout << endl;
}

template <class T>
set<T> &set<T>::operator=(const set<T> &s)
{
	currentSize = s.currentSize;
	maxSize = s.maxSize;
	delete[] data;
	data = new T[maxSize];
	for (int i = 0; i <= currentSize; i++)
	{
		data[i] = s.data[i];
	}
	return *this;
}

template <class T>
set<T> operator*(const set<T> &s1, const set<T> &s2)
{
	set<T> sum;
	for (int i = 0; i <= s1.currentSize; i++)
	{
		if (s2.exist(s1.data[i]))
			sum.insert(s1.data[i]);
	}
	return sum;
}

template <class T>
set<T> operator+(const set<T> &s1, const set<T> &s2)
{
	set<T> mul = s1;
	for (int i = 0; i <= s2.currentSize; i++)
	{
		mul.insert(s2.data[i]);
	}
	return mul;
}

template <class T>
set<T> operator-(const set<T> &s1, const set<T> &s2)
{
	set<T> dif = s1;
	for (int i = 1; i <= s1.currentSize; i++)
	{
		if (s2.exist(s1.data[i]))
			dif.erase(s1.data[i]);
	}
	return dif;
}