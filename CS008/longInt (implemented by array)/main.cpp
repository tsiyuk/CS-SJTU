#include <iostream>
#include <cstring>
#include"longInt.h"
using namespace std;

int main()
{
	char n1[129], n2[129];
	cout << "please input num1." << endl;
	cin.getline(n1, 128);
	cout << "please input num2." << endl;
	cin.getline(n2, 128);
	longInt num1(n1), num2(n2);
	num1.output();
	cout << " + ";
	num2.output();
	cout << " = ";
	longInt num3 = add(num1, num2);
	num3.output();
	cout<<endl;
    num1.output();
    cout<<" > ";
    num2.output();
	if(!Greater(num1,num2))
    {
        cout<<"False"<<endl;
        num2.output();
        cout<<" - ";
        num1.output();
        cout<<" = ";
        longInt num4 = sub(num2, num1);
        num4.output();
    }
	else cout<<"True";

	return 0;
}
