//#include <iostream>
//#include <string>
//#include <stdexcept>
//#include "PriorityQueueHeap.hpp"
//
//bool TestsMaxPriorityQueue() {
//    std::string ds_name = "PriorityQueueHeap";
//
//    std::cout << ds_name << " TEST" << std::endl;
//    std::cout << "Testing " << ds_name << " with ints" << std::endl;
//    PriorityQueueHeap<int> i_pq;
//
//    std::cout << "New " << ds_name << " should be empty ....";
//    if (!i_pq.is_empty()) {
//        std::cout << " but was not" << std::endl;
//        return false;
//    }
//    std::cout << " OK!" << std::endl;
//
//    std::cout << "Using insert() with integers 30, 20, and 10....: ";
//    for (int i = 3; i > 0; --i) {
//        i_pq.enqueue(i * 10);
//    }
//    std::cout << std::endl;
//
//    std::string result_string;
//    std::string control_string = "30,30 20,20 10,10 ";
//    std::cout << "Using peek() and extract_min() on " << ds_name << " until empty .....";
//    while (!i_pq.is_empty()) {
//        result_string += std::to_string(i_pq.peek());
//        result_string += ',' + std::to_string(i_pq.dequeue()) + ' ';
//    }
//
//    if (result_string != control_string) {
//        std::cout << "expected " << control_string << " but got " << result_string << std::endl;
//        return false;
//    }
//    std::cout << " OK!" << std::endl;
//
//    std::cout << "Mixing the aforementioned functions ......  ";
//    for (int i = 1; i < 3; ++i) {
//        i_pq.enqueue(i * 11);
//    }
//    i_pq.dequeue();
//    for (int i = 3; i < 5; ++i) {
//        i_pq.enqueue(i * 11);
//    }
//    for (int i = 1; i < 3; ++i) {
//        i_pq.dequeue();
//    }
//    for (int i = 9; i < 12; ++i) {
//        i_pq.enqueue(i * 11);
//    }
//    i_pq.dequeue();
//    for (int i = 5; i < 8; ++i) {
//        i_pq.enqueue(i * 11);
//    }
//
//    result_string.clear();
//    while (!i_pq.is_empty()) {
//        result_string += std::to_string(i_pq.dequeue()) + ' ';
//    }
//    control_string = "110 99 77 66 55 11 ";
//    if (result_string != control_string) {
//        std::cout << " expected " << control_string << " but got " << result_string << std::endl;
//        return false;
//    }
//    std::cout << " OK!" << std::endl;
//
//    std::cout << "Testing " << ds_name << " with strings .... " << std::endl;
//    PriorityQueueHeap<std::string> s_list;
//
//    std::cout << "Testing add() with A, B, C and D .... ";
//    s_list.enqueue("B");
//    s_list.enqueue("D");
//    s_list.enqueue("A");
//    s_list.enqueue("C");
//
//    result_string.clear();
//    control_string = "DCBA";
//
//    while (!s_list.is_empty()) {
//        result_string += s_list.dequeue();
//    }
//    if (result_string != control_string) {
//        std::cout << " expected " << control_string << " but got " << result_string << std::endl;
//        return false;
//    }
//
//    std::cout << " OK!" << std::endl;
//    std::cout << "All tests for " << ds_name << " OK!" << std::endl << std::endl;
//    return true;
//}
//
//bool ExceptionsPriorityQueue() {
//    std::string ds_name = "PriorityQueueHeap";
//    std::cout << ds_name << " EXCEPTIONS" << std::endl;
//    PriorityQueueHeap<int> pq;
//
//    std::cout << "calling dequeue() on empty " << ds_name << " .. ";
//    try {
//        pq.dequeue();
//        std::cout << "expected exception to be raised." << std::endl;
//        return false;
//    } catch (const std::exception& e) {
//        std::cout << "OK!" << std::endl;
//    }
//
//    std::cout << "calling peek() on empty " << ds_name << " .. ";
//    try {
//        pq.peek();
//        std::cout << "expected exception to be raised." << std::endl;
//        return false;
//    } catch (const std::exception& e) {
//        std::cout << "OK!" << std::endl;
//    }
//
//    std::cout << "All exceptions for " << ds_name << " OK!" << std::endl;
//    return true;
//}
//
//int main()
//{
//    if(TestsMaxPriorityQueue())
//        if(ExceptionsPriorityQueue())
//            return 0;
//    return 1;
//}