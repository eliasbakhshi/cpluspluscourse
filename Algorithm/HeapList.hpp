//#ifndef HEAPLIST_HPP
//#define HEAPLIST_HPP
//
///*
//
//This is just for extra info
//
//*/
//
//#include "IndexedList.hpp"
//#include <stdexcept>
//
//template <class T>
//class HeapList {
//private:
//    IndexedList<T> elements;
//
//public:
//    HeapList() = default;
//    ~HeapList() = default;
//    HeapList(const HeapList& other) = delete;
//    HeapList& operator=(const HeapList& other) = delete;
//
//    int size() const;
//    bool is_empty() const;
//    void insert(const T& element);
//    T extractMax();
//    T getMax() const;
//};
//#endif
//
//template <class T>
//int HeapList<T>::size() const {
//    return elements.size();
//}
//
//template <class T>
//bool HeapList<T>::is_empty() const {
//    return elements.is_empty();
//}
//
//template <class T>
//void HeapList<T>::insert(const T& element) {
//    elements.addAt(0, element);
//}
//
//template <class T>
//T HeapList<T>::extractMax() {
//    if (is_empty()) {
//        throw std::runtime_error("Heap is empty");
//    }
//    T max = elements.last();
//    elements.removeLast();
//    return max;
//}
//
//template <class T>
//T HeapList<T>::getMax() const {
//    if (is_empty()) {
//        throw std::runtime_error("Heap is empty");
//    }
//    return elements.last();
//}
//
