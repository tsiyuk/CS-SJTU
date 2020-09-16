#ifndef SLINKLIST_H
#define SLINKLIST_H
#include <cstddef>
#include <iostream>
using namespace std;

template <class elemType>
class sLinkList
{
    public:
        sLinkList();
        virtual ~sLinkList() {clear();delete head;};
        void clear();
        int lenght() const {return currentLength;}
        void insert(int i,elemType &x);
        void remove(int i);
        int search(const elemType &x) const;
        void erase(int x,int y);
        void reverse();
        void traverse() const;
        int invertsearch(int k);

    private:
        struct node{
            elemType data;
            node *next;

            node(const elemType &x,node *n=NULL)
                {data=x;next=n;}
            node():next(NULL){}
            ~node(){}
        };
        node *head;
        int currentLength;
        node *move(int i)const
        {
            node *p=head;
            while (i-->=0) p=p->next;
            return p;
        }
};

#endif // SLINKLIST_H


