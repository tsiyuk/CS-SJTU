#include"binaryTree.hpp"
#include<iostream>

int main()
{
    binaryTree<char> tree;
    tree.createTree('@');
    tree.preOrder();
    tree.midOrder();
    tree.postOrder();
    tree.levelOrder();
    printTree(tree, '@');
    // std::cout<<tree.isFull()<<endl;
    // std::cout<<tree.isComplete()<<endl;
    // tree.delLeft('L');
    // tree.delRight('C');
    // tree.delLeft('C');
    // tree.levelOrder();
    // printTree(tree, '@');
    tree.exchange();
    printTree(tree, '@');
    std::cout<<"The number of degree 2 vertex is "<<tree.countDegreeTwo()<<endl;
    binaryTree<char> t2;
    t2.createTree('@');
    if(tree == t2)
        printf("Equal\n");
    if(checkSymmetry(tree, t2))
        printf("Symmetric\n");
    return 0;
}