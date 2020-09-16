#include "sLinkList.h"
#include <iostream>
using namespace std;

template <class elemType>
int wordsearch(const sLinkList<elemType> &str1, const sLinkList<elemType> &str2) //2-10找出由str1,str2所指向的两个链表的共同后缀的起始位置
{
    sLinkList<elemType>::node *p1 = str1.head;
    sLinkList<elemType>::node *p2 = str2.head; //定义两个指针分别指向两个链表的头节点
    p1 = str1.move(str1.currentLength);
    p2 = str2.move(str2.currentLength); //指向两个链表的最后一个节点
    int i;
    if (p1->data != p2->data)
    {
        cout << "不存在相同后缀" << endl;
        return 0;
    } //不存在相同后缀
    else
    {
        for (i = 0; i < min(str1.currentLength, str2.currentLength); ++i)
        {
            if (p1->data == p2->data)
            {
                p1 = str1.move(str1.currentLength - 1);
                p2 = str2.move(str2.currentLength - 1);
            } //若data相同，则向前移一位
            else
            {
                cout << "相同的后缀开始于倒数第" << i << "位";
                break;
            } //若data值不同，则说明相同后缀结束
        }
        return i;
    }
}
int min(const int &x, const int &y) //比较两个链表的长度大小
{
    if (x >= y)
        return y;
    else
        return x;
}
