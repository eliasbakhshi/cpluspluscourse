#ifndef SORTEDLIST_H
#define SORTEDLIST_H
#include <exception>

/*
* 
* It is exact the same as ordered list.
* 
The list is always kept sorted
The first element is at position 0
If an operation isn't possible to solve (for example getSmallestElement() from an empty list) throw exception 
*/

template <typename T>
class SortedList
{
private:
	class Node
	{
	public:
		T data;
		Node* next;
		Node(T data, Node* next = nullptr)
			: data(data), next(next) {}
	};
	// membervariables for you to add
public:
	SortedList();
	virtual ~SortedList();
	SortedList(const SortedList& other) = delete;
	SortedList& operator=(const SortedList& other) = delete;
	void addElement(const T& elem);
	T removeElementAt(int position);
	const T& getSmallestElement() const;
	int getPositionOfElement(const T& elem) const;
	int size() const;
};

#endif


template<typename T>
inline SortedList<T>::SortedList() : head(nullptr), listSize(0) {

}

template<typename T>
inline SortedList<T>::~SortedList() {
	while (head) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

template<typename T>
inline void SortedList<T>::addElement(const T& elem) {
	Node* newNode = new Node(elem);
	if (!head || elem < head->data) {
		newNode->next = head;
		head = newNode;
	} else {
		Node* current = head;
		while (current->next && elem > current->next->data) {
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}
	listSize++;
}

template<typename T>
inline T SortedList<T>::removeElementAt(int position) {
	if (position < 0 || position >= listSize) {
		throw std::exception("invaild position");
	}
	if (!head) {
		throw  std::exception("the list is empty");
	}
	Node* temp;
	if (position == 0) {
		temp = head;
		head = head->next;
	} else {
		Node* prev = head;
		for (int i = 0; i < position - 1; i++) {
			prev = prev->next;
		}
		temp = prev->next;
		prev->next = temp->next;
	}

	T data = temp->data;
	delete temp;
	listSize--;
	return data;

}

template<typename T>
inline const T& SortedList<T>::getSmallestElement() const {
	if (!head) {
		throw std::exception("List is empty");
	}
	return head->data;
	// TODO: insert return statement here
}

template<typename T>
inline int SortedList<T>::getPositionOfElement(const T& elem) const {
	int position = 0;
	Node* current = head;
	while (current && current->data != elem) {
		current = current->next;
		position++;


	}
	if (!current) {
		throw std::exception("Element not foundd");
	}
	return position;
}

template<typename T>
inline int SortedList<T>::size() const {
	return listSize;
}

