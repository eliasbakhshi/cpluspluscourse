#ifndef ORDEREDLIST_HPP
#define ORDEREDLIST_HPP

#include <stdexcept>

template <class T>
class OrderedList {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* front;
    int num_elements;

public:
    OrderedList();
    ~OrderedList();
    OrderedList(const OrderedList& other) = delete;
    OrderedList& operator=(const OrderedList& other) = delete;
    
    int size() const;
    bool is_empty() const;
    void add(const T& element);
    T remove(const T& element);
    T removeAt(int index);
    T removeFirst();
    T removeLast();
    T get(const T& element) const;
    T first() const;
    T last() const;
};

#endif


template <class T>
OrderedList<T>::OrderedList() :
    front(nullptr), num_elements(0) {}

template <class T>
OrderedList<T>::~OrderedList() {
    while (front != nullptr) {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
}

template <class T>
int OrderedList<T>::size() const {
    return num_elements;
}

template <class T>
bool OrderedList<T>::is_empty() const {
    return front == nullptr;
}

template <class T>
void OrderedList<T>::add(const T& element) {
    Node* newelement = new Node(element);
    if (is_empty() || element < front->data) {
        newelement->next = front;
        front = newelement;
    } else {
        Node* temp = front;
        while (temp->next != nullptr && temp->next->data < element) {
            temp = temp->next;
        }
        newelement->next = temp->next;
        temp->next = newelement;
    }
    num_elements++;
}

template <class T>
T OrderedList<T>::remove(const T& element) {
    if (is_empty()) {
        throw std::logic_error("List is empty");
    }
    if (element == front->data) {
        return removeFirst();
    }
    Node* temp = front;
    while (temp->next != nullptr && temp->next->data != element) {
        temp = temp->next;
    }
    if (temp->next == nullptr) {
        throw std::logic_error("Element not found");
    }
    Node* todelete = temp->next;
    T data = todelete->data;
    temp->next = todelete->next;
    delete todelete;
    num_elements--;
    return data;
}

template <class T>
T OrderedList<T>::removeAt(int index) {
    if (index < 0 || index >= num_elements) {
        throw std::out_of_range("Index out of range");
    }
    if (index == 0) {
        return removeFirst();
    }
    Node* temp = front;
    for (int i = 0; i < index - 1; i++) {
        temp = temp->next;
    }
    Node* todelete = temp->next;
    T data = todelete->data;
    temp->next = todelete->next;
    delete todelete;
    num_elements--;
    return data;
}

template <class T>
T OrderedList<T>::removeFirst() {
    if (is_empty()) {
        throw std::logic_error("List is empty");
    }
    Node* temp = front;
    T data = temp->data;
    front = front->next;
    delete temp;
    num_elements--;
    return data;
}

template <class T>
T OrderedList<T>::removeLast() {
    if (is_empty()) {
        throw std::logic_error("List is empty");
    }
    if (num_elements == 1) {
        return removeFirst();
    }
    Node* temp = front;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    T data = temp->next->data;
    delete temp->next;
    temp->next = nullptr;
    num_elements--;
    return data;
}

template <class T>
T OrderedList<T>::get(const T& element) const {
    Node* temp = front;
    while (temp != nullptr) {
        if (temp->data == element) {
            return temp->data;
        }
        temp = temp->next;
    }
    throw std::logic_error("Element not found");
}

template <class T>
T OrderedList<T>::first() const {
    if (is_empty()) {
        throw std::logic_error("List is empty");
    }
    return front->data;
}

template <class T>
T OrderedList<T>::last() const {
    if (is_empty()) {
        throw std::logic_error("List is empty");
    }
    Node* temp = front;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    return temp->data;
}
