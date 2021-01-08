#include <iostream>
#include "set.hpp"
using namespace std;

int main()
{
	int n1, n2;
	set<char> s1, s2, s3, s4, s5;
	cin >> n1 >> n2;
	for (int i = 0;i < n1;i++) {
		char x;
		cin >> x;
		s1.insert(x);
	}
	for (int i = 0;i < n2;i++) {
		char x;
		cin >> x;
		s2.insert(x);
	}
	s3 = s1 + s2;
	s4 = s1 * s2;
	s5 = s1 - s2;
	s1.display();
	s2.display();
	s3.display();
	s4.display();
	s5.display();
}