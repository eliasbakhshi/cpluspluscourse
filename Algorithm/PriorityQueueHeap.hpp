#ifndef PRIORITYQUEUEHEAP_HPP
#define PRIORITYQUEUEHEAP_HPP

#include "Heap.hpp"
#include <stdexcept>

template <typename T>
class PriorityQueueHeap {
private:
    Heap<T> heap;

public:
    PriorityQueueHeap();
    ~PriorityQueueHeap() = default;
    PriorityQueueHeap(const PriorityQueueHeap& other) = delete;
    PriorityQueueHeap& operator =(const PriorityQueueHeap& other) = delete;

    int size() const;
    void enqueue(const T& element);
    T dequeue();
    T peek() const;
    bool is_empty() const;
};

#endif

template <class T>
PriorityQueueHeap<T>::PriorityQueueHeap() {

}

template <class T>
int PriorityQueueHeap<T>::size() const {
    return heap.size();
}

template <class T>
void PriorityQueueHeap<T>::enqueue(const T& element) {
    heap.insert(element);
}

template <class T>
T PriorityQueueHeap<T>::dequeue() {
    if (is_empty()) {
        throw std::logic_error("Priority queue is empty");
    }
    return heap.extractMax();
}

template <class T>
T PriorityQueueHeap<T>::peek() const {
    if (is_empty()) {
        throw std::logic_error("Priority queue is empty");
    }
    return heap.getMax();
}

template <class T>
bool PriorityQueueHeap<T>::is_empty() const {
    return heap.is_empty();
}
