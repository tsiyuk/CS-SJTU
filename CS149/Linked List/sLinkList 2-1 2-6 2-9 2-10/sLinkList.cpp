#include "sLinkList.h"

template <class elemType>
sLinkList<elemType>::sLinkList()
{
    head = new node;
    currentLength = 0;
}
template <class elemType>
void sLinkList<elemType>::clear()
{
    node *p = head->next, *q;
    head->next = NULL;
    while (p != NULL)
    {
        q = p->next;
        delete p;
        p = q;
    }
    currentLength = 0;
}
template <class elemType>
void sLinkList<elemType>::insert(int i, elemType &x)
{
    node *pos;
    pos = move(i - 1);
    pos->next = new node(x, pos->next);
    currentLength++;
}
template <class elemType>
void sLinkList<elemType>::remove(int i)
{
    node *pos, *delp;
    pos = move(i - 1);
    delp = pos->next;
    pos->next = delp->next;
    delete delp;
    --currentLength;
}
template <class elemType>
int sLinkList<elemType>::search(const elemType &x) const
{
    node *p = head->next;
    int i = 0;
    while (p != NULL && p->data != x)
    {
        p = p->next;
        ++i;
    }
    if (p == NULL)
        return -1;
    else
        return i;
}
template <class elemType>
void sLinkList<elemType>::traverse() const
{
    node *p = head->next;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}
//erase(x, y)
//erase all nodes that its value is in the interval [x, y]
//2-1删除值在[x,y]之间的结点
template <class elemType>
void sLinkList<elemType>::erase(int x, int y)
{
    node *p = head;
    while (p->next != NULL)
    {
        if (p->next->data >= x && p->next->data <= y)
        {
            node *delp;
            delp = p->next;
            p->next = delp->next;
            delete delp;
            --currentLength; //删除一个结点
        }
        else
            p = p->next;
    }
}
//reverse()
//reverse a single link list, its tail become the head and so on
//2-6逆置一个单链表
template <class elemType>
void sLinkList<elemType>::reverse()
{
    if (head->next == NULL)
        return;
    node *now = head->next->next, *now_next;
    head->next->next = NULL; //将第一个结点变为最后一个结点
    while (now != NULL)
    {
        now_next = now->next;
        now->next = head->next;
        head->next = now;
        now = now_next;
    } //将后续的结点插入到head与最后一个结点之间
}
//invertsearch(x)
//when exactly having the head pointer, search for the node at the kth position from the tail of the linked list
//2-9链表中只给出头指针，在不改变链表的前提下，尽可能高效地查找链表倒数第k个位置上的节点
template <class elemType>
int sLinkList<elemType>::invertsearch(int k)
{
    int cur = 0;
    int i = 0;
    node *List = head;
    node *p = head->next;
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