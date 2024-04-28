#ifndef QUEUE_H
#define QUEUE_H

#include <exception>

/*
throw exception if dequeue() or peek() is excuted when queue is empty

for example in dequeue():

throw std::exception("calling dequeue() on Empty queue")

if the queue is empty
*/

template <typename T>
class Queue {
private:
    T* elements;
    int currentCapacity;
    int head;
    int tail;
    int nrOfElements;
    void expand();
public:
    Queue();
    virtual ~Queue();
    Queue(const Queue& other) = delete;
    Queue& operator=(const Queue& other) = delete;
    void enqueue(const T& element);
    T dequeue();
    const T& peek() const;
    bool is_empty() const;
};

#endif


template<typename T>
Queue<T>::Queue() :currentCapacity(10), head(0), tail(0), nrOfElements(0), elements(new T[10]) {}

template<typename T>

Queue<T>::~Queue() {
    delete[] elements;
}
// Function declarations outside the class declaration
template<typename T>
void Queue<T>::enqueue(const T& element) {
    // Implementation here...
    if (nrOfElements == currentCapacity) {
        expand();
    }
    elements[tail] = element;
    tail = (tail + 1) % currentCapacity;
    nrOfElements++;
}

template<typename T>
T Queue<T>::dequeue() {
    if (is_empty()) {
        throw std::exception("Listan är fulll");
    }
    T element = elements[head];
    head = (head + 1) % currentCapacity;
    nrOfElements--;
    return element;
}

template<typename T>
const T& Queue<T>::peek() const {
    if (is_empty()) {
        throw std::exception("Listan är fulll");
    }
    return elements[head];
}

template<typename T>
bool Queue<T>::is_empty() const {
    return nrOfElements == 0;
}

template<typename T>
void Queue<T>::expand() {
    int NC = currentCapacity * 2;
    T* newElement = new T[NC];
    for (int i = 0; i < nrOfElements; i++) {
        newElement[i] = elements[(head + i) % currentCapacity];
    }
    delete[] elements;
    elements = newElement;
    head = 0;
    tail = nrOfElements;
    currentCapacity = NC;
}
