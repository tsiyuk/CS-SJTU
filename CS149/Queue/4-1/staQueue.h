#ifndef STAQUEUE_H
#define STAQUEUE_H
#include <iostream>
using namespace std;


template<class T>
class staQueue
{
    public:
        staQueue(int size=10);
        virtual ~staQueue();
        bool isEmpty()const;
        void enQueue(const T &x);
        T deQueue();
        T getHead()const;
    private:
        T *elem;
        int maxSize;
        int rear;
        void doubleSpace();
};

#endif // STAQUEUE_H
