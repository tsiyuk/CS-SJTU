#ifndef BINARYTREE_HPP_
#define BINARYTREE_HPP_

#include "bTree.hpp"
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

// declartion
template <class T>
class binaryTree;
template <class T>
bool operator==(const binaryTree<T> &t1, const binaryTree<T> &t2);
template <class T>
void printTree(const binaryTree<T> &t, T flag);
template <class T>
bool checkSymmetry(const binaryTree<T> &t1, const binaryTree<T> &t2);

template <class T>
class binaryTree : public bTree<T>
{
	friend void printTree<T>(const binaryTree<T> &t, T flag);
	friend bool operator==<T>(const binaryTree<T> &t1, const binaryTree<T> &t2);	//6-5 overload == operator
	friend bool checkSymmetry<T>(const binaryTree<T> &t1, const binaryTree<T> &t2); //6-6 check if two binary trees are symmetric to each other

private:
	struct Node
	{
		Node *left, *right;
		T data;

		Node() : left(nullptr), right(nullptr){};
		Node(T item, Node *L = nullptr, Node *R = nullptr) : data(item), left(L), right(R) {}
		~Node() {}
	};
	Node *root;

private:
	Node *find(T x, Node *t) const
	{
		Node *tmp;
		if (t == nullptr)
			return nullptr;
		if (t->data == x)
			return t;
		tmp = find(x, t->left);
		if (tmp)
			return tmp;
		else
			return find(x, t->right);
	}
	void clear(Node *&t);
	void preOrder(Node *t) const;
	void midOrder(Node *t) const;
	void postOrder(Node *t) const;
	void exchange(Node *t);		 //6-1 exchange the left subtree and the right subtree of a binary tree
	int countDegreeTwo(Node *t); //6-2 count the number of the vertice of degree 2 in a binary tree
	int size(binaryTree<T>::Node *t) const;
	int height(binaryTree<T>::Node *t) const;
	bool checkEqual(binaryTree<T>::Node *t1, binaryTree<T>::Node *t2); //check whether two binary trees are equal
	bool checkSymmetryNode(binaryTree<T>::Node *t1, binaryTree<T>::Node *t2); //6-6 check if two binary trees are symmetric to each other

public:
	binaryTree() : root(nullptr) {}
	binaryTree(T x) { root = new Node(x); }
	~binaryTree() { clear(root); }
	void clear();
	bool isEmpty() const;
	T Root(T flag) const;		 //return the root
	T lchild(T x, T flag) const; //return left child
	T rchild(T x, T flag) const; //return right child
	void delLeft(T x);			 //delete the left child vertex
	void delRight(T x);			 //delete the right child vertex
	void preOrder() const;		 //pre-order
	void midOrder() const;		 //in-order
	void postOrder() const;		 //post-order
	void levelOrder() const;	 //level-order
	void createTree(T flag);	 //create a new binary tree, parameter flag represents the empty node
	void exchange();			 //6-1 exchange the left subtree and the right subtree of a binary tree
	int countDegreeTwo();		 //6-2 count the number of the vertice of degree 2 in a binary tree
	int size() const;			 //return the size of the binary tree
	bool isFull() const;		 //6-3 check whether the binary tree is a full binary tree
	bool isComplete() const;	 //6-4 check whether the binary tree is a complete binary tree
	int height() const;			 //return the height of the binary tree
	T parent(T x, T flag) const { return flag; }
};

#endif

template <class T>
bool binaryTree<T>::isEmpty() const
{
	return root == nullptr;
}
template <class T>
T binaryTree<T>::Root(T flag) const
{
	if (root == nullptr)
		return flag;
	else
		return root->data;
}
template <class T>
void binaryTree<T>::clear(binaryTree<T>::Node *&t)
{
	if (t == nullptr)
		return;
	clear(t->left);
	clear(t->right);
	delete t;
	t = nullptr;
}
template <class T>
void binaryTree<T>::clear()
{
	clear(root);
}
template <class T>
void binaryTree<T>::preOrder(binaryTree<T>::Node *t) const
{
	if (t == nullptr)
		return;
	cout << t->data << ' ';
	preOrder(t->left);
	preOrder(t->right);
}
template <class T>
void binaryTree<T>::preOrder() const
{
	cout << "\nPre-order:";
	preOrder(root);
}
template <class T>
void binaryTree<T>::midOrder(binaryTree<T>::Node *t) const
{
	if (t == nullptr)
		return;
	midOrder(t->left);
	cout << t->data << ' ';
	midOrder(t->right);
}
template <class T>
void binaryTree<T>::midOrder() const
{
	cout << "\nIn-order:";
	midOrder(root);
}
template <class T>
void binaryTree<T>::postOrder(binaryTree<T>::Node *t) const
{
	if (t == nullptr)
		return;
	postOrder(t->left);
	postOrder(t->right);
	cout << t->data << ' ';
}
template <class T>
void binaryTree<T>::postOrder() const
{
	cout << "\nPost-order:";
	postOrder(root);
}
template <class T>
void binaryTree<T>::levelOrder() const
{
	queue<Node *> que;
	Node *tmp;

	cout << "\nLevel-order:";
	que.push(root);

	while (!que.empty())
	{
		tmp = que.front();
		que.pop();
		cout << tmp->data << ' ';
		if (tmp->left)
			que.push(tmp->left);
		if (tmp->right)
			que.push(tmp->right);
	}
}

template <class T>
void binaryTree<T>::delLeft(T x)
{
	Node *tmp = find(x, root);
	if (tmp == nullptr)
		return;
	clear(tmp->left);
}
template <class T>
void binaryTree<T>::delRight(T x)
{
	Node *tmp = find(x, root);
	if (tmp == nullptr)
		return;
	clear(tmp->right);
}
template <class T>
T binaryTree<T>::lchild(T x, T flag) const
{
	Node *tmp = find(x, root);
	if (tmp == nullptr || tmp->left == nullptr)
		return flag;
	return tmp->left->data;
}
template <class T>
T binaryTree<T>::rchild(T x, T flag) const
{
	Node *tmp = find(x, root);
	if (tmp == nullptr || tmp->right == nullptr)
		return flag;
	return tmp->right->data;
}

template <class T>
void binaryTree<T>::createTree(T flag)
{
	queue<Node *> que;
	Node *tmp;
	T x, ldata, rdata;
	cout << "\nplease input the root";
	cin >> x;
	root = new Node(x);
	que.push(root);

	while (!que.empty())
	{
		tmp = que.front();
		que.pop();
		cout << "\ninput " << tmp->data << "'s two child " << flag << " represents the empty node\n";
		cin >> ldata >> rdata;
		if (ldata != flag)
			que.push(tmp->left = new Node(ldata));
		if (rdata != flag)
			que.push(tmp->right = new Node(rdata));
	}
	cout << "create completed!\n";
}

// public exchange function
// exchange the left subtree and the right subtree of a binary tree
template <class T>
void binaryTree<T>::exchange() // 6-1
{
	exchange(root);
}
// private exchange function
template <class T>
void binaryTree<T>::exchange(Node *t) // 6-1
{
	Node *tmp;
	if (t->left)
		exchange(t->left);
	if (t->right)
		exchange(t->right);
	tmp = t->left;
	t->left = t->right;
	t->right = tmp;
}
// public countDegreeTwo function
// count the number of the vertice of degree 2 in a binary tree
template <class T>
int binaryTree<T>::countDegreeTwo() // 6-2
{
	return countDegreeTwo(root);
}
// private countDegreeTwo function
template <class T>
int binaryTree<T>::countDegreeTwo(Node *t) //6-2
{
	if (t == nullptr)
		return 0; // meet the leaf of the tree
	if (t->left && t->right)
		return 1 + countDegreeTwo(t->left) + countDegreeTwo(t->right); // a degree 2 vertex
	else
		return countDegreeTwo(t->left) + countDegreeTwo(t->right); //a degree 1 vertex
}

// public size function
// return the number of vertice in the binary tree
template <class T>
int binaryTree<T>::size() const
{
	return size(root);
}
// private size function
template <class T>
int binaryTree<T>::size(binaryTree<T>::Node *t) const
{
	if (t == NULL)
		return 0;
	return 1 + size(t->left) + size(t->right);
}

// public height function
// return the height of the binary tree
template <class T>
int binaryTree<T>::height() const
{
	return height(root);
}

// private height function
template <class T>
int binaryTree<T>::height(binaryTree<T>::Node *t) const
{
	if (t == NULL)
		return 0;
	int lt = height(t->left), rt = height(t->right);
	return 1 + ((lt > rt) ? lt : rt);
}

// check whether the binary tree is a full binary tree
template <class T>
bool binaryTree<T>::isFull() const //6-3
{
	if (size() == (pow(2, height()) - 1))
		return 1;
	else
		return 0;
}

// check whether the binary tree is a complete binary tree
template <class T>
bool binaryTree<T>::isComplete() const //6-4
{
	struct elem
	{
		binaryTree<T>::Node *p;
		int num; // numbering every vertex of the binary tree
	};
	queue<elem> que;
	elem cur, child;
	int last = 1; // the number the last visited vertex
	int sum = 1;  // total number of the vertex
	if (root == nullptr)
		return 1;
	cur.p = root;
	cur.num = 1;
	que.push(cur);
	while (!que.empty())
	{
		cur = que.front();
		que.pop();
		if (cur.p->left)
		{
			++sum;
			child.p = cur.p->left;
			last = child.num = 2 * cur.num; // numbering the left child
			que.push(child);
		}
		if (cur.p->right)
		{
			++sum;
			child.p = cur.p->right;
			last = child.num = 2 * cur.num + 1; // numbering the right child
			que.push(child);
		}
	}
	return sum == last; // return if the total number of the vertice equals to the number of the last vertex
}

// overload == operator to check whether two binary trees are equal
template <class T>
bool operator==(const binaryTree<T> &t1, const binaryTree<T> &t2) //6-5
{
	return checkEqual(t1.root, t2.root);
}

// check if two binary trees are equal
template <class T>
bool binaryTree<T>::checkEqual(binaryTree<T>::Node *t1, binaryTree<T>::Node *t2)
{
	if (t1 == nullptr && t2 == nullptr)
		return 1;
	if (t1 == nullptr || t2 == nullptr)
		return 0;
	if (t1->data != t2.data)
		return 0;
	return checkEqual(t1->left, t2->left) && checkEqual(t1->right, t2->right);
}
// public checkSymmetry function
// check if two binary trees are symmetric to each other
template <class T>
bool checkSymmetry(const binaryTree<T> &t1, const binaryTree<T> &t2) //6-6
{
	return checkSymmetryNode(t1.root, t2.root);
}
// private checkSymmetry function
template <class T>
bool binaryTree<T>::checkSymmetryNode(binaryTree<T>::Node *t1, binaryTree<T>::Node *t2) //6-6
{
	if (t1 == nullptr && t2 == nullptr)
		return 1;
	if (t1 == nullptr || t2 == nullptr)
		return 0;
	if (t1->data != t2.data)
		return 0;
	return checkSymmetryNode(t1->left, t2->right) && checkSymmetryNode(t2->left, t1->right);
}

template <class T>
void printTree(const binaryTree<T> &t, T flag)
{
	queue<T> que;
	if (!t.root)
		return;
	que.push(t.root->data);
	cout << endl;
	while (!que.empty())
	{
		T p, l, r;
		p = que.front();
		que.pop();
		l = t.lchild(p, flag);
		r = t.rchild(p, flag);
		cout << p << " " << l << " " << r << endl;
		if (l != flag)
			que.push(l);
		if (r != flag)
			que.push(r);
	}
}