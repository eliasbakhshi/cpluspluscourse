#ifndef PRIORITYQUEUEORDEREDLIST_HPP
#define PRIORITYQUEUEORDEREDLIST_HPP

#include "OrderedList.hpp"
#include <stdexcept>

template<typename T>
class PriorityQueueOrderedList {
private:
    OrderedList<T> list;

public:
	PriorityQueueOrderedList();
    ~PriorityQueueOrderedList() = default;
    PriorityQueueOrderedList(const PriorityQueueOrderedList& other) = delete;
    PriorityQueueOrderedList& operator =(const PriorityQueueOrderedList& other) = delete;
    
    int size() const;
    void enqueue(const T& element);
    T dequeue();
    T peek() const;
    bool is_empty() const;
};

#endif

template <class T>
PriorityQueueOrderedList<T>::PriorityQueueOrderedList() {

}
template <class T>
int PriorityQueueOrderedList<T>::size() const {
    // Returns size of PQ
    return list.size();
}
template <class T>
void PriorityQueueOrderedList<T>::enqueue(const T& element) {
    // Adds element to PQ
    list.add(element);
}
template <class T>
T PriorityQueueOrderedList<T>::dequeue() {
    // Removes and returns next element from PQ
    if (is_empty()) {
        throw std::exception("the list is empty");
    }
    return list.removeFirst();
}
template <class T>
T PriorityQueueOrderedList<T>::peek() const {
    // Returns next element from PQ
    if (is_empty()) {
        throw std::exception("the list is empty");
    }
    return list.first();
}
template <class T>
bool PriorityQueueOrderedList<T>::is_empty() const {
    // Returns if PQ is empty or not
    return list.is_empty();
}