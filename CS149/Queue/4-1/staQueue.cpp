#include "staQueue.h"

template <class T>
staQueue<T>::staQueue(int size)
{
    elem = new T[size];
    maxSize = size;
    rear = -1;
}
template <class T>
staQueue<T>::~staQueue()
{
    delete[] elem;
}
template <class T>
bool staQueue<T>::isEmpty() const
{
    return rear == -1;
}
template <class T>
void staQueue<T>::enQueue(const T &x)
{
    if ((rear + 1) == maxSize)
        doubleSpace(); // if the queue is full, call apply doubleSpace()
    rear += 1;
    elem[rear] = x;
}
template <class T>
T staQueue<T>::getHead() const
{
    return elem[0];
}
template <class T>
void staQueue<T>::doubleSpace()
{
    T *tmp = elem;
    elem = new T[2 * maxSize];
    for (int i = 0; i < maxSize; i++)
        elem[i] = tmp[i];
    rear = maxSize - 1;
    maxSize *= 2;
    delete tmp;
}
template <class T>
T staQueue<T>::deQueue()
{
    T *tmp = elem;
    T out = tmp[0];
    elem = new T[maxSize - 1];
    for (int i = 1; i < maxSize; i++)
        elem[i - 1] = tmp[i];
    maxSize -= 1;
    rear = rear - 1;
    delete tmp;
    return out;
}