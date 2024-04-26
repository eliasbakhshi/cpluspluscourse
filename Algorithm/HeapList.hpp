#ifndef HEAPLIST_HPP
#define HEAPLIST_HPP

#include "IndexedList.hpp"
#include <stdexcept>

template <class T>
class HeapList {
private:
    IndexedList<T> elements;

public:
    HeapList() = default;
    ~HeapList() = default;
    HeapList(const HeapList& other) = delete;
    HeapList& operator=(const HeapList& other) = delete;

    int size() const;
    bool is_empty() const;
    void insert(const T& element);
    T extractMax();
    T getMax() const;
};
#endif

template <class T>
int HeapList<T>::size() const{
    // Returns size of Heap
    return -1;
}

template <class T>
bool HeapList<T>::is_empty() const {
    // Returns if empty or now
    return false;
}
template <class T>
void HeapList<T>::insert(const T& element) {
    // Adds elements to Heap
}
template <class T>
T HeapList<T>::extractMax() {
    // Removes and returns max element
    return T();
}
template <class T>
T HeapList<T>::getMax() const {
    // Returns max element
    return T();
}