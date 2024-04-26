//#include <stdexcept>
//
//template <class T>
//class OrderedList {
//private:
//    class Node {
//    public:
//        T data;
//        Node* next;
//        Node(const T& data, Node* next = nullptr)
//            : data(data), next(next) {}
//    };
//    Node* front;
//
//public:
//    OrderedList() : front(nullptr) {}
//    ~OrderedList();
//
//    // Förbjud kopiering och tilldelning
//    OrderedList(const OrderedList& other) = delete;
//    OrderedList& operator=(const OrderedList& other) = delete;
//
//    int size() const;
//    bool is_empty() const;
//    void add(const T& element);
//    T removeAt(int index);
//    T removeFirst();
//    T removeLast();
//    T getAt(int index) const;
//    T first() const;
//    T last() const;
//};
//
//template<class T>
//OrderedList<T>::~OrderedList() {
//    while (front) {
//        Node* temp = front;
//        front = front->next;
//        delete temp;
//    }
//}
//
//template<class T>
//int OrderedList<T>::size() const {
//    int count = 0;
//    Node* current = front;
//    while (current) {
//        ++count;
//        current = current->next;
//    }
//    return count;
//}
//
//template<class T>
//bool OrderedList<T>::is_empty() const {
//    return front == nullptr;
//}
//
//template<class T>
//void OrderedList<T>::add(const T& element) {
//    Node* newNode = new Node(element);
//    if (!front || element < front->data) {
//        newNode->next = front;
//        front = newNode;
//    } else {
//        Node* current = front;
//        while (current->next && current->next->data < element) {
//            current = current->next;
//        }
//        newNode->next = current->next;
//        current->next = newNode;
//    }
//}
//
//template<class T>
//T OrderedList<T>::removeAt(int index) {
//    if (index < 0 || index >= size()) {
//        throw std::out_of_range("Index out of range");
//    }
//    if (index == 0) {
//        return removeFirst();
//    }
//    Node* current = front;
//    for (int i = 0; i < index - 1; ++i) {
//        current = current->next;
//    }
//    Node* temp = current->next;
//    T data = temp->data;
//    current->next = temp->next;
//    delete temp;
//    return data;
//}
//
//template<class T>
//T OrderedList<T>::removeFirst() {
//    if (is_empty()) {
//        throw std::runtime_error("List is empty");
//    }
//    Node* temp = front;
//    T data = temp->data;
//    front = front->next;
//    delete temp;
//    return data;
//}
//
//template<class T>
//T OrderedList<T>::removeLast() {
//    if (is_empty()) {
//        throw std::runtime_error("List is empty");
//    }
//    if (!front->next) {
//        return removeFirst();
//    }
//    Node* current = front;
//    while (current->next->next) {
//        current = current->next;
//    }
//    Node* temp = current->next;
//    T data = temp->data;
//    current->next = nullptr;
//    delete temp;
//    return data;
//}
//
//template<class T>
//T OrderedList<T>::getAt(int index) const {
//    if (index < 0 || index >= size()) {
//        throw std::out_of_range("Index out of range");
//    }
//    Node* current = front;
//    for (int i = 0; i < index; ++i) {
//        current = current->next;
//    }
//    return current->data;
//}
//
//template<class T>
//T OrderedList<T>::first() const {
//    if (is_empty()) {
//        throw std::runtime_error("List is empty");
//    }
//    return front->data;
//}
//
//template<class T>
//T OrderedList<T>::last() const {
//    if (is_empty()) {
//        throw std::runtime_error("List is empty");
//    }
//    Node* current = front;
//    while (current->next) {
//        current = current->next;
//    }
//    return current->data;
//}
//
//
//
//template <class T>
//class PriorityQueue {
//private:
//    OrderedList<T> list;
//
//public:
//    PriorityQueue() = default;
//    ~PriorityQueue() = default;
//
//    // Förbjud kopiering och tilldelning
//    PriorityQueue(const PriorityQueue& other) = delete;
//    PriorityQueue& operator=(const PriorityQueue& other) = delete;
//
//    void enqueue(const T& element) {
//        list.add(element);
//    }
//
//    T dequeue() {
//        if (is_empty()) {
//            throw std::runtime_error("Queue is empty");
//        }
//        T front = list.removeFirst();
//        return front;
//    }
//
//    T peek() const {
//        if (is_empty()) {
//            throw std::runtime_error("Queue is empty");
//        }
//        return list.first();
//    }
//
//    bool is_empty() const {
//        return list.is_empty();
//    }
//
//    int size() const {
//        return list.size();
//    }
//};
