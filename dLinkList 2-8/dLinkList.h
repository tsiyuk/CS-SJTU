#include <iostream>
using namespace std;

template<class elemType>
class dLinkList
{
    //overload the addition operator
    friend dLinkList<elemType> operator+(const dLinkList<elemType> &ls,const dLinkList<elemType> &rs);

    public:
        dLinkList();
        ~dLinkList(){clear();delete head;delete tail;}
        void clear();
        void insert(int i,const elemType &x);
        void remove(int i);
        dLinkList(const dLinkList<elemType> &obj);
        dLinkList<elemType> operator=(const dLinkList<elemType> &obj);
        void traverse() const;

    private:
        struct node{
            elemType data;
            node *prev,*next;

            node(const elemType &x,node *p=NULL,node *n=NULL)
                {data=x;prev=p;next=n;}
            node():next(NULL),prev(NULL){}
            ~node(){}
        };
        node *head,*tail;
        int currentLength;
        node *move(int i)const
        {
            node *p=head;
            while(i-->=0)p=p->next;
            return p;
        }
};
