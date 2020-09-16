#include "dLinkList.h"

template <class elemType>
dLinkList<elemType>::dLinkList()
{
    head = new node;
    head->next = tail = new node;
    tail->prev = head;
    currentLength = 0;
}
template <class elemType>
void dLinkList<elemType>::insert(int i, const elemType &x)
{
    node *pos, *tmp;
    pos = move(i);
    tmp = new node(x, pos->prev, pos);
    pos->prev->next = tmp;
    pos->prev = tmp;
    ++currentLength;
}
template <class elemType>
void dLinkList<elemType>::remove(int i)
{
    node *pos;
    pos = move(i);
    pos->prev->next = pos->next;
    pos->next->prev = pos->prev;
    delete pos;
    --currentLength;
}
template <class elemType>
void dLinkList<elemType>::clear()
{
    node *p = head->next, *q;
    head->next = tail;
    tail->prev = head;
    while (p != tail)
    {
        q = p->next;
        delete p;
        p = q;
    }
    currentLength = 0;
}
template <class elemType>
void dLinkList<elemType>::traverse() const
{
    node *p = head->next;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}
template <class elemType>
dLinkList<elemType> operator+(const dLinkList<elemType> &ls, const dLinkList<elemType> &rs) //加法运算符重载
{
    dLinkList<elemType> l = ls, r = rs;
    dLinkList<elemType>::node *p = r.head->next;
    l.tail->prev->next = r.head->next;
    p = l.tail->prev;
    delete l.tail;
    delete r.head;
    l.currentLength = ls.currentLength + rs.currentLength;
    return l;
}
template <class elemType>
dLinkList<elemType>::dLinkList(const dLinkList<elemType> &obj) //拷贝构造函数
{
    node *p = obj.head->next;
    head = new node;
    head->next = tail = new node;
    tail->prev = head;
    currentLength = 0;
    for (int i = 0; p != tail; ++i, p = p->next)
    {
        insert(i, p->data);
    }
}
template <class elemType>
dLinkList<elemType> dLinkList<elemType>::operator=(const dLinkList<elemType> &obj) //赋值运算符重载
{
    if (this == &obj)
        return *this; //若相同则直接返回this
    node *p = obj.head->next;
    clear();
    for (int i = 0; p != tail; ++i, p = p->next)
    {
        insert(i, p->data);
    }
    return *this;
}
