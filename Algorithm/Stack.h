//#ifndef STACK_H
//#define STACK_H
//#include <exception>
//
///*
//throw exception if pop() or peek() is excuted when stack is empty
//
//for example in pop():
//
//throw std::exception("calling pop() on Empty stack")
//
//if the stack is empty
//*/
//
//template <typename T>
//class Stack
//{
//private:
//	T* elements;
//	int currentCapacity;
//	int top;
//	void expand();
//public:
//	Stack(int initialCapacity = 10);
//	virtual ~Stack();
//	Stack(const Stack& other) = delete;
//	Stack& operator=(const Stack& other) = delete;
//	void push(const T& element);
//	T pop();
//	const T& peek() const;
//	bool is_empty();
//};
//
//#endif
//
//template<typename T>
//inline void Stack<T>::expand() {}
//
//template<typename T>
//inline Stack<T>::Stack(int initialCapacity) : currentCapacity(initialCapacity), top(0), elements[new T(initialCapacity){0}
//	{}
//
//
//template<typename T>
//inline Stack<T>::~Stack() {}
//
//template<typename T>
//inline void Stack<T>::push(const T& element) {}
//
//template<typename T>
//inline T Stack<T>::pop() {
//	return T();
//}
//
//template<typename T>
//inline const T& Stack<T>::peek() const {
//	// TODO: insert return statement here
//}
//
//template<typename T>
//inline bool Stack<T>::is_empty() {
//	return false;
//}
