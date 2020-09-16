#include <iostream>
#include "sLinkList.h"

using namespace std;

int main()
{
	sLinkList <int> p1;
	int num = 0;
	int x = 0;
	cout << "please input the length of the linked list";
    cin >> num;

    for(int i = 0; i < num; i++)
	{
		cout << "please input the value of the " << i + 1 << "th element of linked list";
		cin >> x;
		p1.insert(i, x);
		cout << endl;
	}
    p1.erase(2,3);//2-1 erase all nodes that its value is in the interval [x, y]
    cout << "erase all nodes that its value is in the interval [2, 3]" << endl;
    p1.traverse();
    cout << endl;

    p1.reverse();//2-6 reverse a single link list, its tail become the head and so on
    cout << "the reversed linked list: " << endl;
    p1.traverse();
	cout << endl;

    cout<<"search for the node at the second position from the tail of the linked list"<<endl;
    p1.invertsearch(2);//2-9
	cout << endl;

	return 0;
}

