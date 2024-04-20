#ifndef QUEUE_H
#define QUEUE_H
#include <exception>
#include <iostream>

using namespace std;

/*
throw exception if dequeue() or peek() is excuted when queue is empty

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
	bool is_empty();
};

#endif

template<typename T>
inline Queue<T>::Queue() : first(nullptr), last(nullptr) {}

template<typename T>
inline Queue<T>::~Queue() {}

template<typename T>
inline void Queue<T>::enqueue(const T& element) {
	// check if queue is empty
	if (is_empty()) {
		first = new Node(element);
		last = first;
	} else { // There is al least one element
		first->next = new Node(element);
		last = first->next;
	}
	cout << first->data << endl;
}
//
//template<typename T>
//inline T Queue<T>::dequeue() {
//	Node* temp = first;
//
//	if (first == NULL) {
//		cout << "Linked list is empty. Nothing to delete.";
//		return T();
//	}
//	first = first->next;
//	delete (temp);
//	return T();
//}
//
//template<typename T>
//inline const T& Queue<T>::peek() const {
//	if (is_empty()) {
//		throw exception("Exception: peak on empty queue");
//	}
//	return first->data;
//}
//
template<typename T>
inline bool Queue<T>::is_empty() {
	return first == nullptr;
}
