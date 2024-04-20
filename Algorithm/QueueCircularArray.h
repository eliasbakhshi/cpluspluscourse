#ifndef QUEUE_H
#define QUEUE_H
#include <exception>

/*
throw exception if dequeue() or peek() is excuted when queue is empty

for example in dequeue():

throw std::exception("calling dequeue() on Empty queue")

if the queue is empty
*/

template <typename T>
class Queue
{
private:
	T* elements;
	int currentCapacity;
	int first;
	int last;
public:
	Queue();
	virtual ~Queue();
	Queue(const Queue& other) = delete;
	Queue& operator=(const Queue& other) = delete;
	void enqueue(const T& element);
	T dequeue();
	const T& peek() const;
	bool is_empty();
};

#endif
