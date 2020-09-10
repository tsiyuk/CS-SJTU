#include <iostream>
#include "signedLongInt.h"
#include "longInt.h"
using namespace std;

int main()
{
	signedLongInt num1, num2;
	cout << "please input num1." << endl;
	cin >> num1;
	cout << "please input num2." << endl;
	cin >> num2;
	cout << num1 << " + " << num2 << " = ";
	signedLongInt num3 = num1 + num2;
	cout << num3 << endl;
	cout << num1 << " >= " << num2 << ' ';
	(num1 >= num2) ? (cout << "True\n") : (cout << "False\n");
	cout << num1 << " == " << num2 << ' ';
	(num1 == num2) ? (cout << "True\n") : (cout << "False\n");
	signedLongInt num4 = num1 - num2;
	cout << num1 << " - " << num2 << " = " << num4 << endl;
	cout << num1++ << ' ';
	cout << ++num1 << endl;
	cout << num2-- << ' ';
	cout << --num2 << endl;
	longInt n1, n2;
	cout << "please input num1." << endl;
	cin >> n1;
	cout << "please input num2." << endl;
	cin >> n2;
	longInt n5 = multi(n1,n2);
	cout << n5 << endl;

	return 0;
}
