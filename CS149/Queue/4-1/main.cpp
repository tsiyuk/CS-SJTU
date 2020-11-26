#include <iostream>
#include "staQueue.h"

using namespace std;

int main()
{
    int size;
    cout << "please input the size of the queue" << endl;
    cin >> size;
    int *a = new int[size];
    staQueue<int> Q(size);
    cout << "please input the queue" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
        Q.enQueue(a[i]);
    }
    Q.enQueue(100);
    while (!Q.isEmpty())
    {
        cout << Q.deQueue() << ' ';
    }
    return 0;
}
