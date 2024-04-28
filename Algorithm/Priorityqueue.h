#pragma once
#include <stdexcept>


template <class T>
class PriorityQueue {
private:
    OrderedList<T> list;

public:
    PriorityQueue() = default;
    ~PriorityQueue() = default;

    // Förbjud kopiering och tilldelning
    PriorityQueue(const PriorityQueue& other) = delete;
    PriorityQueue& operator=(const PriorityQueue& other) = delete;

    void enqueue(const T& element) {
        list.add(element);
    }

    T dequeue() {
        if (is_empty()) {
            throw std::runtime_error("Queue is empty");
        }
        T front = list.removeFirst();
        return front;
    }

    T peek() const {
        if (is_empty()) {
            throw std::runtime_error("Queue is empty");
        }
        return list.first();
    }

    bool is_empty() const {
        return list.is_empty();
    }

    int size() const {
        return list.size();
    }
};
