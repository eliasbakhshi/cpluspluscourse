#ifndef STACK_H
#define STACK_H
#include <exception>

/*
throw exception if pop() or peek() is excuted when stack is empty

for example in pop():

throw std::exception("calling pop() on Empty stack")

if the stack is empty
*/

template <typename T>
class Stack {
private:
	T* elements;
	int currentCapacity;
	int top;
	void expand();
public:
	Stack(int initialCapacity = 10);
	virtual ~Stack();
	Stack(const Stack& other) = delete;
	Stack& operator=(const Stack& other) = delete;
	void push(const T& element);
	T pop();
	const T& peek() const;
	bool is_empty() const;
};

#endif

template<typename T>
inline void Stack<T>::expand() {
	int newCapacity = currentCapacity * 2;
	T* newElements = new T[newCapacity];
	for (int i = 0; i < currentCapacity; i++) {
		newElements[i] = elements[i];
	}
	delete[] elements;
	elements = newElements;
	currentCapacity = newCapacity;
}

// kopienring construckturn
template<typename T>
inline Stack<T>::Stack(int initialCapacity) :currentCapacity(initialCapacity), top(0), elements(new T[initialCapacity]) {}

// dekonstructorn
template<typename T>
inline Stack<T>::~Stack() {
	delete[] elements;
}

// för att pusha elements
template<typename T>
inline void Stack<T>::push(const T& element) {
	if (top == currentCapacity)
		expand();
	elements[top++] = element;
}

template<typename T>
inline T Stack<T>::pop() {
	if (is_empty()) {
		throw std::exception("Execption pop on empty statck");
	}
	return elements[--top];
}

template<typename T>
inline const T& Stack<T>::peek() const {
	if (is_empty()) {
		throw std::exception("Execption on pop empty stack");
	}
	return elements[top - 1];
	// TODO: insert return statement here
}

template<typename T>
inline bool Stack<T>::is_empty() const {
	return top == 0;
}
