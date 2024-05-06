#ifndef HEAP_HPP
#define HEAP_HPP

#include <stdexcept>

template <class T>
class Heap {
private:
    int capacity;
    int nrOfElements;
    T* elements;
    void expand();
public:
    Heap(int initialCapacity = 10);
    ~Heap();
    Heap(const Heap& other) = delete;
    Heap& operator=(const Heap& other) = delete;

    int size() const;
    bool is_empty() const;
    void insert(const T& element);
    T extractMax();
    T getMax() const;
};

#endif


template <class T>
Heap<T>::Heap(int initialCapacity) {
    this->capacity = initialCapacity;
    this->nrOfElements = 0;
    this->elements = new T[this->capacity];
}

template <class T>
Heap<T>::~Heap() {
    delete[] this->elements;
}

template <class T>
void Heap<T>::expand() {
    int newsize = capacity * 2;
    T* temp = new T[newsize];
    for (int i = 0; i < nrOfElements; i++) {
        temp[i] = elements[i];
    }
    delete[] elements;
    elements = temp;
    capacity = newsize;
}

template <class T>
int Heap<T>::size() const {
    return nrOfElements;
}

template <class T>
bool Heap<T>::is_empty() const {
    return nrOfElements == 0;
}

template <class T>
void Heap<T>::insert(const T& element) {
    if (nrOfElements == capacity) {
        expand();
    }
    elements[nrOfElements++] = element;
    // Restore heap property
    int index = nrOfElements - 1;
    while (index > 0 && elements[index] > elements[(index - 1) / 2]) {
        std::swap(elements[index], elements[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

template <class T>
T Heap<T>::extractMax() {
    if (is_empty()) {
        throw std::logic_error("Heap is empty");
    }
    T maxElement = elements[0];

    elements[0] = elements[--nrOfElements];
    int index = 0;
    while (true) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;
        if (leftChild < nrOfElements && elements[leftChild] > elements[largest]) {
            largest = leftChild;
        }
        if (rightChild < nrOfElements && elements[rightChild] > elements[largest]) {
            largest = rightChild;
        }
        if (largest != index) {
            std::swap(elements[index], elements[largest]);
            index = largest;
        } else {
            break;
        }
    }
    return maxElement;
}

template <class T>
T Heap<T>::getMax() const {
    if (is_empty()) {
        throw std::logic_error("Heap is empty");
    } else {
        return elements[0];
    }
}