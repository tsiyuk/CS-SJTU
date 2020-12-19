#ifndef PRIORITYQUEUE_HPP_
#define PRIORITYQUEUE_HPP_
// maximum heap

template <class T>
class priorityQueue
{
private:
	int currentSize;
	T *array;
	int maxSize;
	void doubleSpace();
	void buildHeap();
	void percolateDown(int hole);

public:
	priorityQueue(int capacity = 100)
	{
		array = new T[capacity];
		maxSize = capacity;
		currentSize = 0;
	}
	priorityQueue(T data[], int size)
	{
		maxSize = size + 10;
		currentSize = size;
		array = new T[maxSize];
		for (int i = 0; i < size; i++)
			array[i + 1] = data[i];
		buildHeap();
	}
	~priorityQueue() { delete[] array; }
	bool isEmpty() const { return currentSize == 0; }
	void enQueue(const T &x);
	T deQueue();
	T getHead() { return array[1]; }
};

#endif

template <class T>
void priorityQueue<T>::doubleSpace()
{
	T *tmp = array;
	array = new T[2 * maxSize];
	for (int i = 0; i <= currentSize; i++)
		array[i] = tmp[i];
	maxSize *= 2;
	delete[] tmp;
}
template <class T>
void priorityQueue<T>::enQueue(const T &x)
{
	if (currentSize == maxSize - 1)
		doubleSpace();
	int hole = ++currentSize;
	for (; hole > 1 && x > array[hole / 2]; hole /= 2)
		array[hole] = array[hole / 2];
	array[hole] = x;
}
template <class T>
T priorityQueue<T>::deQueue()
{
	T maxItem;
	maxItem = array[1];
	array[1] = array[currentSize--];
	percolateDown(1);
	return maxItem;
}
template <class T>
void priorityQueue<T>::percolateDown(int hole)
{
	int child;
	T tmp = array[hole];
	for (; hole * 2 <= currentSize; hole = child)
	{
		child = hole * 2;
		if (child != currentSize && array[child] < array[child + 1])
			child++;
		if (array[child] > tmp)
			array[hole] = array[child];
		else
			break;
	}
	array[hole] = tmp;
}
template <class T>
void priorityQueue<T>::buildHeap()
{
	for (int i = currentSize / 2; i > 0; --i)
		percolateDown(i);
}
