#pragma once
#include <iostream>
#include <exception>

using namespace std;





//
//template <typename T>
//class Queue {
//	T* elements;
//	int capacity, head, tail, nrOfElements;
//	void expand();
//public:
//	Queue(int initCapacity = 10);
//	virtual ~Queue();
//	Queue(Queue& other) = delete;
//	Queue operator=(Queue& other) = delete;
//	void enqueue(const T& element);
//	T dequeue();
//	const T& peek() const;
//	bool is_empty() const;
//};
//
//template<typename T>
//Queue<T>::Queue(int initCapacity): elements(new T[initCapacity]), capacity(initCapacity), head(0), tail(0), nrOfElements(0) {}
//
//template<typename T>
//Queue<T>::~Queue() {
//	delete[] elements;
//}
//
//template<typename T>
//void Queue<T>::enqueue(const T& element) {
//	if (nrOfElements == capacity) {
//		expand();
//	}
//	elements[tail] = element;
//	tail = (tail + 1) % capacity;
//	nrOfElements++;
//}
//
//template<typename T>
//T Queue<T>::dequeue() {
//	if (is_empty()) {
//		throw std::exception("Exception: dequeue() on an empty queue.");
//	}
//	T data = elements[head];
//	head = (head + 1) % capacity;
//	nrOfElements--;
//	return data;
//}
//
//template<typename T>
//const T& Queue<T>::peek() const {
//	if (is_empty()) {
//		throw std::exception("Exception: peek() on an empty queue.");
//	}
//	return elements[head];
//}
//
//template<typename T>
//bool Queue<T>::is_empty() const {
//	return nrOfElements == 0;
//}
//
//template<typename T>
//void Queue<T>::expand() {
//	int tempCapacity = capacity * 2;
//	T* tempElements = new T[tempCapacity];
//	for (int i = 0; i < capacity; i++) {
//		tempElements[i] = elements[(head + 1) % capacity];
//	}
//	delete[] elements;
//	elements = tempElements;
//	capacity = tempCapacity;
//	head = 0;
//	tail = nrOfElements;
//}
//


//
//
//template <typename T>
//class Stack {
//	T* elements;
//	int capacity;
//	int top;
//	void expand();
//public:
//	Stack(int initCapacity = 10);
//	virtual ~Stack();
//	Stack(Stack& other) = delete;
//	Stack operator=(Stack& other) = delete;
//	void push(const T& element);
//	const T& peek() const;
//	T pop();
//	bool is_empty() const;
//};
//
//template<typename T>
//inline void Stack<T>::expand() {
//	int newCapacity = capacity * 2;
//	T* tempElements = new T[newCapacity];
//	for (int i = 0; i < capacity; i++) {
//		tempElements[i] = elements[i];
//	}
//	delete[] elements;
//	elements = tempElements;
//	capacity = newCapacity;
//}
//
//template<typename T>
//inline Stack<T>::Stack(int initCapacity) : elements(new T[initCapacity]), capacity(initCapacity), top(0) {}
//
//template<typename T>
//inline Stack<T>::~Stack() {
//	delete []elements;
//}
//
//
//template<typename T>
//inline void Stack<T>::push(const T & element) {
//	if (top == capacity) {
//		expand();
//	}
//	elements[top++] = element;
//}
//template<typename T>
//inline const T& Stack<T>::peek() const{
//	if (is_empty()) {
//		throw std::exception("Exception: peek() called on an empty array.");
//	}
//	return elements[top - 1];
//}
//
//template<typename T>
//inline T Stack<T>::pop() {
//	if (is_empty()) {
//		throw std::exception("Exception: peek() called on an empty array.");
//	}
//	return elements[--top];
//}
//
//template<typename T>
//inline bool Stack<T>::is_empty() const {
//	return top == 0;
//}
//


//template<typename T>
//class Queue {
//	class Node {
//	public:
//		T data;
//		Node* next;
//		Node(T data, Node* next = nullptr) : data(data), next(next) {}
//	};
//	Node* first;
//	Node* last;
//public:
//	Queue();
//	virtual ~Queue();
//	Queue(const Queue& other) = delete;
//	Queue& operator=(const Queue& other) = delete;
//	void enqueue(const T& element);
//	T dequeue();
//	const T& peek();
//	bool is_empty();
//
//};
//
//template<typename T>
//inline Queue<T>::Queue() : first(nullptr), last(nullptr) {}
//
//template<typename T>
//inline Queue<T>::~Queue() {
//	while (first != nullptr) {
//		Node* temp = first;
//		first = first->next;
//		delete temp;
//	}
//}
//
//template<typename T>
//inline void Queue<T>::enqueue(const T& element) {
//	Node* temp = new Node(element);
//	if (is_empty()) {
//		first = last = temp;
//	} else {
//		last->next = temp;
//		last = temp;
//	}
//}
//
//template<typename T>
//inline T Queue<T>::dequeue() {
//	if (is_empty()) {
//		throw std::exception("Exception: dequeue on an empty queue.");
//	}
//	Node* temp = first;
//	T data = first->data;
//	first = first->next;
//
//	if (first == nullptr) {
//		last = nullptr;
//	}
//	delete temp;
//	return data;
//}
//template<typename T>
//inline const T& Queue<T>::peek() {
//	if (is_empty()) {
//		throw std::exception("Exception: peek on an empty array.");
//	}
//	return first->data;
//}
//
//template<typename T>
//inline bool Queue<T>::is_empty() {
//	return first == nullptr;
//}


//void printArray(int array[], int size) {
//	int i;
//	for (i = 0; i < size; i++)
//		cout << array[i] << " ";
//	cout << endl;
//}
//
//template<typename T>
//void swapIt(T& from, T& to) {
//	T temp = from;
//	from = to;
//	to = temp;
//}
//
//template <typename T>
//void insertionSort2(T arr[], int nOf) {
//	for (int i = 1; i < nOf; i++) {
//		T value = arr[i];
//		int j = i;
//
//		while (j > 0 && arr[j - 1] > value) {
//			arr[j] = arr[j - 1];
//			j--;
//		}
//		arr[j] = value;
//	}
//}
//
//template<typename T>
//void selectionSort2(T arr[], int length) {
//	int i, j, minIndex;
//	for (i = 0; i < length - 1; i++) {
//		minIndex = i;
//		for (j = i + 1; j < length; j++) {
//			if (arr[j] < arr[minIndex]) {
//				minIndex = j;
//			}
//		}
//		if (minIndex != i) {
//			swapIt(arr[minIndex], arr[i]);
//		}
//	}
//}
//
//template<typename T>
//int linearSearch2(T arr[], int length, T toFind) {
//	for (int i = 0; i < length - 1; i++) {
//		cout << i << endl;
//		if (arr[i] == toFind) return i;
//	}
//	return -1;
//}
//
//template<typename T>
//int binarySearch2(T arr[], int nOf, T toFind) {
//	int left = 0;
//	int right = nOf - 1;
//
//	while (left < right) {
//		int mid = (right - left) / 2;
//		if (arr[mid] == toFind) {
//			return mid;
//		} else if (toFind > arr[mid]) {
//			left = mid + 1;
//		} else {
//			right = mid - 1;
//		}
//	}
//	return -1;
//}
//
//template<typename T>
//int linearSearchRerc2(T arr[], int nOf, T toFind) {
//	cout << nOf << endl;
//	if (nOf < 0) {
//		return -1;
//	}
//	if (arr[nOf] == toFind) {
//		return nOf;
//	}
//	return linearSearchRerc2(arr, nOf - 1, toFind);
//}
//
//template<typename T>
//int binarySearchRec2(T arr[], int left, int right, T toFind) {
//	cout << left << endl;
//	if (left <= right) {
//		int mid = left + (right - left) / 2;
//		if (arr[mid] == toFind) {
//			return mid;
//		}
//		if (arr[mid] < toFind)
//			return binarySearchRec2(arr, mid + 1, right, toFind);
//		return binarySearchRec2(arr, left, mid - 1, toFind);
//	}
//	return -1;
//}
//
//template<typename T>
//void partition2(T arr[], int start, int end) {
//	T pivot = arr[end];
//	int i = start;
//	for (int j = start; j < end - 1; j++) {
//		if (arr[i] <= arr[j]) {
//			swapIt(arr[i], arr[j]);
//			i++;
//		}
//	}
//	swapIt(arr[i + 1], arr[end]);
//}
//
//
//
//
//// function to swap elements
//void swap(int* a, int* b) {
//	int t = *a;
//	*a = *b;
//	*b = t;
//}
//
//// function to rearrange array (find the partition point)
//template<typename T>
//
//int partition3(T arr[], int startIndex, int endIndex) {
//	T pivot = arr[endIndex];
//	int wall = startIndex - 1;
//	for (int i = startIndex; i < endIndex; i++) {
//		if (arr[i] < pivot) {
//			wall++;
//			T temp = arr[wall];
//			arr[wall] = arr[i];
//			arr[i] = temp;
//		}
//	}
//	arr[endIndex] = arr[wall + 1];
//	arr[wall + 1] = pivot;
//	return wall + 1;
//}
