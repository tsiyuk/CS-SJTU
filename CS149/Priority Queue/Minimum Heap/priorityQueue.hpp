#ifndef PRIORITYQUEUE_HPP_
#define PRIORITYQUEUE_HPP_
// minimum heap

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
	int findmin(const T &x, int index);

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
	int findMin(const T &x);				 // return the index of minimun element which is bigger than x
	void decreaseKey(int i, const T &value); // decrease the keyvalue of array[i] by the given value
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
	for (; hole > 1 && x < array[hole / 2]; hole /= 2)
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
		if (child != currentSize && array[child] > array[child + 1])
			child++;
		if (array[child] < tmp)
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
// return the index of minimun element which is bigger than x
template <class T>
int priorityQueue<T>::findMin(const T &x)
{
	return findmin(x, 1);
}
template <class T>
int priorityQueue<T>::findmin(const T &x, int index)
{
	if (index > currentSize)
	{
		return currentSize;
	}
	else
	{
		if (array[index] > x)
		{
			return index;
		}
		else
		{
			int left = findmin(x, index * 2);
			int right = findmin(x, index * 2 + 1);
			return array[left] <= array[right] ? left : right;
		}
	}
}
// decrease the keyvalue of array[i] by the given value
template <class T>
void priorityQueue<T>::decreaseKey(int i, const T &value)
{
	array[i] -= value;
	for (; i >= 1; i = i / 2)
	{
		if (array[i] < array[i / 2])
		{
			T tmp = array[i / 2];
			array[i / 2] = array[i];
			array[i] = tmp;
		}
		else
			break;
	}
}