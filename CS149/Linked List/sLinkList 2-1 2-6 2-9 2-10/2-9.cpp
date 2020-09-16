//single link list
#include "sLinkList.h"
#include <iostream>
using namespace std;

template <class elemType>
int invertsearch(const sLinkList<elemType> &x, int k) //2-9链表中只给出头指针，查找链表倒数第k个位置上的节点
{
    int cur = 0;
    int i = 0;
    sLinkList<elemType>::node *List = x.head;
    sLinkList<elemType>::node *p = x.head->next;
    while (List->next != NULL)
    {
        ++cur;
        List = List->next;
    }            //获得链表的长度
    if (cur < k) //链表长度小于k，则查找失败
        return 0;
    else
    {
        while (i < cur - k)
        {
            p = p->next;
            ++i;
        }
        cout << p->data << endl;
        return 1;
    }
}
