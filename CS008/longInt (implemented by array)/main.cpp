#include <iostream>
#include "signedLongInt.h"
#include "conio.h"
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
	signedLongInt num5 = multiply(num1,num2);
	cout << num1 << " * " << num2 << " = " << num5 << endl;
	cout << "press any button to close" << endl;
	getch();

	return 0;
}
