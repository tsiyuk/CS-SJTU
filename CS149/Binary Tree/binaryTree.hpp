#pragma once
#include"bTree.hpp"

template <class T>
class binaryTree : public bTree<T>
{
	friend void printTree(const binaryTree &t, T flag);
	friend bool operator==(const binaryTree &t1, const binaryTree &t2);	   //6-5 overload == operator
	friend bool checkSymmetry(const binaryTree &t1, const binaryTree &t2); //6-6 check if two binary trees are symmetric to each other

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
	Node* find(T x, Node *t) const
	{
	Node *tmp;
	if (t == nullptr)
		return nullptr;
	if (t->data == x)
		return t;
	if (tmp = find(x->left))
		return tmp;
	else
		return find(x->right);
	}
	void clear(Node *&t);
	void preOrder(Node *t) const;
	void midOrder(Node *t) const;
	void postOrder(Node *t) const;
	void exchange(Node *t);															//6-1 exchange the left subtree and the right subtree of a binary tree
	int countDegreeTwo(Node *t);													//6-2 count the number of the vertice of degree 2 in a binary tree
	int size(binaryTree<T>::Node *t) const;										
	int height(binaryTree<T>::Node *t) const;										
	bool checkEqual(const binaryTree::Node *t1, const binaryTree::Node *t2);		//check whether two binary trees are equal
	bool checkSymmetryNode(const binaryTree::Node *t1, const binaryTree::Node *t2); //6-6 check if two binary trees are symmetric to each other

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
