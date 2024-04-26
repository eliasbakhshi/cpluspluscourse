#ifndef QUEUE_H
#define QUEUE_H

#include <exception>
#include <iostream>


using namespace std;

/*
throw exception if dequeue() or peek() is executed when the queue is empty

for example in dequeue():

throw std::exception("calling dequeue() on Empty queue")

if the queue is empty
*/

template <typename T>
class Queue {
private:
	// inner class only accessible within Queue
	class Node {
	public:
		T data;
		Node* next;
		Node(T data, Node* next = nullptr)
			: data(data), next(next) {}
	};
	Node* first;
	Node* last;
public:
	Queue();
	virtual ~Queue();
	Queue(const Queue& other) = delete;
	Queue& operator=(const Queue& other) = delete;
	void enqueue(const T& element);
	T dequeue();
	const T& peek() const;
	bool is_empty() const;
};

template<typename T>
inline Queue<T>::Queue() : first(nullptr), last(nullptr) {}

template<typename T>
inline Queue<T>::~Queue() {
	// Deallocate all nodes in the queue
	while (first != nullptr) {
		Node* temp = first;
		first = first->next;
		delete temp;
	}
}

template<typename T>
inline void Queue<T>::enqueue(const T& element) {
	// Create a new node with the given element
	Node* newNode = new Node(element);

	// If the queue is empty, set both first and last pointers to the new node
	if (is_empty()) {
		first = last = newNode;
	} else { // If there is at least one element
		last->next = newNode; // Link the current last node to the new node
		last = newNode; // Update the last pointer to the new node
	}
}

template<typename T>
inline T Queue<T>::dequeue() {
	// Check if the queue is empty
	if (is_empty()) {
		throw std::exception("calling dequeue() on empty queue");
	}

	// Store the data of the first node
	T data = first->data;

	// Store the address of the first node
	Node* temp = first;

	// Move the first pointer to the next node
	first = first->next;

	// If the queue becomes empty after dequeue, update the last pointer as well
	if (first == nullptr) {
		last = nullptr;
	}

	// Delete the first node
	delete temp;

	// Return the dequeued data
	return data;
}

template<typename T>
inline const T& Queue<T>::peek() const {
	if (is_empty()) {
		throw std::exception("peek() called on empty queue");
	}
	return first->data;
}

template<typename T>
inline bool Queue<T>::is_empty() const {
	return first == nullptr;
}

#endif
