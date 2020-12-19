#include <iostream>
#include "priorityQueue.hpp"

int main()
{
    int size;
    std::cout << "please input the initial size of the maximum heap\n";
    std::cin >> size;
    std::cout << "please input the elements of the maximum heap\n";
    int *arr = new int[size];
    for (int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }
    priorityQueue<int> minheap(arr, size);
    std::cout << std::endl;
    std::cout << minheap.findMin(9) << std::endl;
    minheap.decreaseKey(4, 7);
    while (!minheap.isEmpty())
    {
        std::cout << minheap.deQueue() << " ";
    }

    return 0;
}