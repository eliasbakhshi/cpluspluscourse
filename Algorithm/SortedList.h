#ifndef SORTEDLIST_H
#define SORTEDLIST_H
#include <exception>

/*
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

