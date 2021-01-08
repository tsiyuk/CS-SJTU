#include "BinarySearchTree.hpp"
#include <iostream>
using namespace std;
int main()
{
	SET<int, string> a[] = {{10, "aaa"}, {8, "bbb"}, {21, "ccc"}, {87, "ddd"}, {56, "eee"}, {4, "fff"}, {11, "ggg"}, {3, "hhh"}, {22, "iiiii"}, {7, "jjj"}};
	BinarySearchTree<int, string> tree;
	SET<int, string> x;
	SET<int, string> *p;
	for (int i = 0; i < 10; ++i)
		tree.insert(a[i]);
	p = tree.find(56);
	if (p)
		cout << "find 56 is " << p->key << " " << p->other << endl;
	else
		cout << "not found" << endl;
	tree.remove(56);
	p = tree.find(56);
	if (p)
		cout << "find 56 is " << p->key << " " << p->other << endl;
	else
		cout << "not found" << endl;
	int levelof8 = tree.getLevel(8);
	cout << "height of 8 is " << levelof8 << endl;
	SET<int, string> max, min;
	tree.getMax(max);
	tree.getMin(min);
	cout << "maxium of the tree is " << max.key << max.other << endl;
	cout << "minium of the tree is " << min.key << min.other << endl;
	SET<int, string> max3, min3;
	max3 = tree.getMaxith(3);
	min3 = tree.getMinith(3);
	cout << "the 3th maxium of the tree is " << max3.key << max3.other << endl;
	cout << "the 3th minium of the tree is " << min3.key << min3.other << endl;
	tree.deleteLess(4);
}