#ifndef INDEXEDLIST_HPP
#define INDEXEDLIST_HPP

#include <stdexcept>

template <class T>
class IndexedList {
private:
	class Node {
	public:
		T data;
		Node* next;

		Node(T data = nullptr) : data(data), next(nullptr) {}
	};
	Node* front;
	int num_elements;
public:
	IndexedList();
	~IndexedList();
	IndexedList(const IndexedList& other) = delete;
	IndexedList& operator=(const IndexedList& other) = delete;

	int size() const;
	bool is_empty() const;
	T getAt(int index) const;
	void addAt(int index, const T& element);
	T removeFirst();
	T removeAt(int index);
	T removeLast();
	T first() const;
	T last() const;
};

#endif

template<class T>
IndexedList<T>::IndexedList() :
	front(nullptr), num_elements(0) {

}

template <class T>
IndexedList<T>::~IndexedList() {
	while (this->front != nullptr) {
		Node* temp = this->front;
		this->front = this->front->next;
		delete temp;
	}
}

template <class T>
int IndexedList<T>::size() const {
	// Returns size of IndexedList
	return num_elements;
}

template <class T>
bool IndexedList<T>::is_empty() const {
	// Returns if empty or not

	return num_elements == 0;
}

template <class T>
T IndexedList<T>::getAt(int index) const {
	// Returns element at index
	if (index < 0 || index >= num_elements) {
		throw std::out_of_range("Exception: getAt index out of range.");
	}
	Node* walker = front;
	for (int i = 0; i < index; ++i) {
		walker = walker->next;
	}
	return walker->data;
}

template <class T>
void IndexedList<T>::addAt(int index, const T& element) {
	// Adds element at an index
	if (index < 0 || index > num_elements) {
		throw std::exception("Exception: addAt out of range.");
	}
	Node* temp = new Node(element);
	if (index == 0) {
		temp->next = front;
		front = temp;
	} else {
		Node* walker = front;
		for (int i = 0; i < index - 1; i++) {
			walker = walker->next;
		}
		temp->next = walker->next;
		walker->next = temp;

	}
	num_elements++;
}

template <class T>
T IndexedList<T>::removeFirst() {
	// Removes first element in the IndexedList
	if (is_empty()) {
		throw std::exception("Exception: removeFirst on empty indexed list.");
	}
	T data = front->data;
	Node* temp = front;
	front = front->next;

	delete temp;
	num_elements--;

	return data;

}

template <class T>
T IndexedList<T>::removeAt(int index) {
	// Removes element at specific index
	if (index < 0 || index >= num_elements) {
		throw std::out_of_range("Exception: removeAt index out of range.");
	}
	Node* walker = front;
	if (index == 0) {
		front = front->next;
		T data = walker->data;
		delete walker;
		--num_elements;
		return data;
	}
	for (int i = 0; i < index - 1; ++i) {
		walker = walker->next;
	}
	Node* temp = walker->next;
	walker->next = temp->next;
	T data = temp->data;
	delete temp;
	--num_elements;
	return data;
}

template <class T>
T IndexedList<T>::removeLast() {
	// Removes last element in the IndexedList
	if (is_empty()) {
		throw std::out_of_range("Exception: removeLast on empty indexed list.");
	}
	if (num_elements == 1) {
		return removeFirst();
	}
	Node* walker = front;
	for (int i = 0; i < num_elements - 2; ++i) {
		walker = walker->next;
	}
	Node* temp = walker->next;
	T data = temp->data;
	delete temp;
	walker->next = nullptr;
	--num_elements;
	return data;
}

template <class T>
T IndexedList<T>::first() const {
	// Returns the first element in the IndexedList
	if (is_empty()) {
		throw std::out_of_range("Exception: last on empty indexed list.");
	}
	return front->data;
}

template <class T>
T IndexedList<T>::last() const {
	// Returns the last element in the IndexedList
	if (is_empty()) {
		throw std::out_of_range("Exception: last on empty indexed list.");
	}
	Node* walker = front;
	while (walker->next != nullptr) {
		walker = walker->next;
	}
	return walker->data;
}