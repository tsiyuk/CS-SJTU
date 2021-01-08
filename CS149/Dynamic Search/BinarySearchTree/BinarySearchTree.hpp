//# -*- coding: utf-8 -*-
//9-1.2.3.5.6.7.8
#ifndef BINARYSEARCHTREE
#define BINARYSEARCHTREE

#include <iostream>
#include <stack>
using namespace std;

template <class KEY, class OTHER>
struct SET
{
	KEY key;
	OTHER other;
};

template <class KEY, class OTHER>
class BinarySearchTree
{
private:
	struct BinaryNode
	{
		SET<KEY, OTHER> data;
		BinaryNode *left;
		BinaryNode *right;
		BinaryNode(const SET<KEY, OTHER> &thedata, BinaryNode *lt = nullptr, BinaryNode *rt = nullptr)
			: data(thedata), left(lt), right(rt) {}
	};
	BinaryNode *root;

public:
	BinarySearchTree();
	~BinarySearchTree();
	SET<KEY, OTHER> *find(const KEY &x) const;		 //9-3 non-recursive find function
	void insert(const SET<KEY, OTHER> &x);			 //9-3 non-recursive insert function
	void remove(const KEY &x);						 //9-3 non-recursive remove function
	bool checkNode() const;							 //9-1 check if every node in the BST satisfies the discipline of the BST
	void deleteLess(const KEY x);					 //9-2 delete all the elements whose value is less than x
	void deleteMore(const KEY x);					 //9-2 delete all the elements whose value is more than x
	void deleteRange(const KEY low, const KEY high); //9-2 delete all the elements whose value is in the range [low, high]
	int getLevel(const KEY &x) const;				 //9-5 return the level of the specified element in the BST
	bool getMax(SET<KEY, OTHER> &max) const;		 //9-6 find the maximum element in the BST
	bool getMin(SET<KEY, OTHER> &min) const;		 //9-6 find the minimum element in the BST
	int size() const;								 //return the size of the BST
	SET<KEY, OTHER> *midOrder() const;				 //return an array contains all the elements of the BST in increasing order
	SET<KEY, OTHER> getMaxith(int i) const;			 //9-7 find the i-th largest element in the BST
	SET<KEY, OTHER> getMinith(int i) const;			 //9-8 find the i-th smallest element in the BST
private:
	void makeEmpty(BinaryNode *t);
	bool checkNode(BinaryNode *t, SET<KEY, OTHER> &min, SET<KEY, OTHER> &max) const; //9-1
	void deleteLess(BinaryNode *t, const KEY x);									 //9-2
	void deleteMore(BinaryNode *t, const KEY x);									 //9-2
	void deleteRange(BinaryNode *t, const KEY low, const KEY high);					 //9-2
	int getLevel(const KEY &x, BinaryNode *t) const;								 //9-5
	int size(BinaryNode *t) const;

private:
	struct StNode
	{
		BinaryNode *node;
		int TimesPops;
		StNode(BinaryNode *N = nullptr) : node(N), TimesPops(0) {}
	};
};

#endif


template <class KEY, class OTHER>
BinarySearchTree<KEY, OTHER>::BinarySearchTree()
{
	root = nullptr;
}

template <class KEY, class OTHER>
BinarySearchTree<KEY, OTHER>::~BinarySearchTree()
{
	makeEmpty(root);
}

template <class KEY, class OTHER>
inline void BinarySearchTree<KEY, OTHER>::makeEmpty(BinaryNode *t)
{
	if (t == nullptr)
		return;
	makeEmpty(t->left);
	makeEmpty(t->right);
	delete t;
}

template <class KEY, class OTHER>
SET<KEY, OTHER> *BinarySearchTree<KEY, OTHER>::find(const KEY &x) const //9-3 non-recursive find function
{
	BinaryNode *p = root;
	while (p != nullptr)
	{
		if (x > p->data.key)
			p = p->right;
		else
		{
			if (x < p->data.key)
				p = p->left;
			else
			{
				SET<KEY, OTHER> *a = &(p->data);
				return a;
			}
		}
	}
	return nullptr;
}

template <class KEY, class OTHER>
bool BinarySearchTree<KEY, OTHER>::checkNode() const //9-1 check if every node in the BST satisfies the discipline of the BST
{
	SET<KEY, OTHER> min, max;
	bool flag;
	if (root == nullptr)
		return true;
	if (root->left)
	{
		flag = checkNode(root->left, min, max);
		if (!flag || max.key > root->data.key)
			return false;
	}
	if (root->right)
	{
		flag = checkNode(root->right, min, max);
		if (!flag || min.key < root->data.key)
			return false;
	}
	return true;
}

template <class KEY, class OTHER>
bool BinarySearchTree<KEY, OTHER>::checkNode(BinaryNode *t, SET<KEY, OTHER> &min, SET<KEY, OTHER> &max) const
//9-1 private function to check if every node in the BST satisfies the discipline of the BST
{
	SET<KEY, OTHER> min2, max2;
	bool flag;
	if (t->left)
	{
		flag = checkNode(t->left, min, max2);
		if (!flag || t->data.key < max2.key)
			return false;
	}
	else
		min = t->data;
	if (t->right)
	{
		flag = checkNode(t->right, min2, max);
		if (!flag || t->data.key > min2.key)
			return false;
	}
	else
		max = t->data;
	return true;
}

template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::deleteLess(const KEY x) //9-2 delete all the elements whose value is less than x
{
	deleteLess(root, x);
}

template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::deleteLess(BinaryNode *t, const KEY x) //9-2 delete all the elements whose value is less than x
{
	if (t == nullptr)
		return;
	if (t->data.key < x) // delete the node and its left subtree
	{
		BinaryNode *tmp = t;
		t = t->right;
		makeEmpty(tmp->left);
		delete tmp;
		deleteLess(t, x); // recursive call on left subtree
	}
	else // recursive call on left subtree
		deleteLess(t->left, x);
}

template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::deleteMore(const KEY x) //9-2 delete all the elements whose value is more than x
{
	deleteMore(root, x);
}

template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::deleteMore(BinaryNode *t, const KEY x) //9-2 delete all the elements whose value is more than x
{
	if (t == nullptr)
		return;
	if (t->data.key > x)
	{
		BinaryNode *tmp = t;
		t = t->left;
		makeEmpty(tmp->right);
		delete tmp;
		deleteMore(t, x);
	}
	else
		deleteMore(t->right, x);
}

template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::deleteRange(const KEY low, const KEY high) 
//9-2 delete all the elements whose value is in the range [low, high]
{
	if (low < high)
		deleteRange(root, low, high);
}

template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::deleteRange(BinaryNode *t, const KEY low, const KEY high) 
//9-2 delete all the elements whose value is in the range [low, high]
{
	if (t == nullptr)
		return;
	if (t->data.key < low)
		deleteRange(t->right);
	if (t->data.key > high)
		deleteRange(t->left);
	else
	{
		remove(t->data.x, t);
		deleteRange(t, low, high);
	}
}

template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::remove(const KEY &x) //9-3 non-recursive remove function
{
	if (root == nullptr)
		return;
	BinaryNode *cur = root, *parent = root;
	int son; //0 stands for left,1 stands for right
	while (cur != nullptr)
	{
		if (x == cur->data.key)
			break;
		if (x < cur->data.key)
		{
			son = 0;
			parent = cur;
			cur = cur->left;
		}
		if (x > cur->data.key)
		{
			son = 1;
			parent = cur;
			cur = cur->right;
		}
	}
	if (cur == nullptr)
		return; // the node whose key value is x does not exist

	if ((cur->left != nullptr) && (cur->right != nullptr))
	{ //if cur has two sons
		BinaryNode *tmp = cur->right;
		if (tmp->left == nullptr)
		{ // tmp is the smallest node in the right subtree
			cur->data = tmp->data;
			cur->right = tmp->right;
			delete tmp;
			return;
		}
		while (tmp->left->left != nullptr) //find the smallest node in the right subtree
			tmp = tmp->left;
		BinaryNode *del = tmp->left; //record the smallest node in the right subtree
		cur->data = del->data;
		del->right = cur->right;
		delete del;
		return;
	}
	else
	{ //ֻif cur is the leaf node or only have one child
		if (son == 0)
			parent->left = (cur->left == nullptr ? cur->right : cur->left);
		else
			parent->right = (cur->left == nullptr ? cur->right : cur->left);
		delete cur;
		return;
	}
}

template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::insert(const SET<KEY, OTHER> &x) //9-3 non-recursive insert function
{
	BinaryNode *t = new BinaryNode(x, nullptr, nullptr);
	if (root == nullptr)
	{
		root = t;
		return;
	}
	BinaryNode *cur = root;
	while (cur != nullptr)
	{
		if (x.key < cur->data.key)
		{ //insert in the left subtree
			if (cur->left == nullptr)
			{
				cur->left = t;
				break;
			}
			else
				cur = cur->left;
		}
		else
		{
			if (x.key > cur->data.key)
			{ //insert in the right subtree
				if (cur->right == nullptr)
				{
					cur->right = t;
					break;
				}
				else
					cur = cur->right;
			}
			else
			{
				cout << "insert error" << endl;
				break;
			} //the node whose key value has already existed
		}
	}
}

template <class KEY, class OTHER>
int BinarySearchTree<KEY, OTHER>::getLevel(const KEY &x) const //9-5 return the level of the specified element in the BST
{
	return getLevel(x, root);
}

template <class KEY, class OTHER>
int BinarySearchTree<KEY, OTHER>::getLevel(const KEY &x, BinaryNode *t) const //9-5 return the level of the specified element in the BST
{
	int level;
	if (t == nullptr)
		return -1;
	if (t->data.key == x)
		return 1;
	if (t->data.key < x)
		level = getLevel(x, t->right);
	if (t->data.key > x)
		level = getLevel(x, t->left);
	return (level == -1 ? -1 : level + 1);
}

template <class KEY, class OTHER>
bool BinarySearchTree<KEY, OTHER>::getMax(SET<KEY, OTHER> &max) const //9-6 find the maximum element in the BST
{
	if (root == nullptr)
	{
		return 0;
		cout << "error" << endl;
	}
	BinaryNode *t = root;
	while (t->right != nullptr)
		t = t->right;
	max = t->data;
	return 1;
}

template <class KEY, class OTHER>
bool BinarySearchTree<KEY, OTHER>::getMin(SET<KEY, OTHER> &min) const //9-6 find the minimum element in the BST
{
	if (root == nullptr)
	{
		cout << "error" << endl;
		return 0;
	}
	BinaryNode *t = root;
	while (t->left != nullptr)
		t = t->left;
	min = t->data;
	return 1;
}

template <class KEY, class OTHER>
int BinarySearchTree<KEY, OTHER>::size() const //return the size of the BST
{
	return size(root);
}

template <class KEY, class OTHER>
int BinarySearchTree<KEY, OTHER>::size(BinaryNode *t) const
{
	if (t == nullptr)
		return 0;
	else
		return 1 + size(t->left) + size(t->right);
}

template <class KEY, class OTHER>
SET<KEY, OTHER> *BinarySearchTree<KEY, OTHER>::midOrder() const 
//return an array contains all the elements of the BST in increasing order
//implemented by midorder
{
	stack<StNode> s;
	StNode current(root);
	SET<KEY, OTHER> *array = new SET<KEY, OTHER>[1 + size()];
	int i = 1;

	s.push(current);
	while (!s.empty())
	{
		current = s.top();
		s.pop();
		if (++current.TimesPops == 2)
		{
			array[i++] = current.node->data;
			if (current.node->right != nullptr)
				s.push(StNode(current.node->right));
		}
		else
		{
			s.push(current);
			if (current.node->left != nullptr)
				s.push(StNode(current.node->left));
		}
	}
	return array;
}

template <class KEY, class OTHER>
SET<KEY, OTHER> BinarySearchTree<KEY, OTHER>::getMaxith(int i) const //9-7 find the i-th largest element in the BST
{
	SET<KEY, OTHER> *a;
	a = midOrder();
	return a[1 - i + size()];
}

template <class KEY, class OTHER>
SET<KEY, OTHER> BinarySearchTree<KEY, OTHER>::getMinith(int i) const //9-8 find the i-th smallest element in the BST
{
	SET<KEY, OTHER> *a;
	a = midOrder();
	return a[i];
}