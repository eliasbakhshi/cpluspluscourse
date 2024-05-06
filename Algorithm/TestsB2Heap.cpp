////#include "Heap.hpp"
//#include "Testing_functions.h"
//
//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//
//bool TestsHeap() {
//	std::string ds_name = "Heap";
//    std::cout << ds_name << " TEST" << std::endl;
//    std::cout << "Testing " << ds_name << " with ints" << std::endl;
//
//    Heap<int> i_heap;
//    std::cout << "New " << ds_name << " should be empty ....";
//    if (!i_heap.is_empty()) {
//        std::cout << " but was not" << std::endl;
//        return false;
//    }
//    std::cout << " OK!" << std::endl;
//
//    std::cout << "Using insert() with integers 10, 20, and 30....: ";
//    for (int i = 1; i < 4; i++) {
//        i_heap.insert(i * 10);
//    }
//    std::cout << std::endl;
//
//    std::string result_string = "";
//    std::string control_string = "30,30 20,20 10,10 ";
//    std::cout << "Using peek() and extractMax() on " << ds_name << " until empty .....";
//    while (!i_heap.is_empty()) {
//        result_string += std::to_string(i_heap.getMax()) + ",";
//        result_string += std::to_string(i_heap.extractMax()) + " ";
//    }
//
//    if (result_string != control_string) {
//        std::cout << "\n  expected " << control_string << " but got " << result_string << std::endl;
//        return false;
//    }
//    std::cout << " OK!" << std::endl;
//
//
//    std::cout << "Mixing the aforementioned functions  ......  ";
//    for (int i = 1; i < 3; i++) {
//        i_heap.insert(i * 11);
//    }
//    i_heap.extractMax();
//    for (int i = 3; i < 5; i++) {
//        i_heap.insert(i * 11);
//    }
//    for (int i = 1; i < 3; i++) {
//        i_heap.extractMax();
//    }
//    for (int i = 9; i < 12; i++) {
//        i_heap.insert(i * 11);
//    }
//    i_heap.extractMax();
//    for (int i = 5; i < 8; i++) {
//        i_heap.insert(i * 11);
//    }
//
//    result_string = "";
//    while (!i_heap.is_empty()) {
//        result_string += std::to_string(i_heap.extractMax()) + " ";
//    }
//    std::string control_string2 = "110 99 77 66 55 11 ";
//    if (result_string != control_string2) {
//        std::cout << " expected " << control_string2 << " but got " << result_string << std::endl;
//        return false;
//    }
//    std::cout << " OK!" << std::endl;
//
//
//    std::cout << "Testing " << ds_name << " with strings .... " << std::endl;
//    Heap<std::string> s_list;
//
//    std::cout << "Testing add() with A, B, C and D .... ";
//    s_list.insert("B");
//    s_list.insert("D");
//    s_list.insert("A");
//    s_list.insert("C");
//
//    result_string = "";
//    std::string control_string3 = "DCBA";
//
//    while (!s_list.is_empty()) {
//        result_string += s_list.extractMax();
//    }
//    if (result_string != control_string3) {
//        std::cout << " expected " << control_string3 << " but got " << result_string << std::endl;
//        return false;
//    }
//
//    std::cout << " OK!" << std::endl;
//    std::cout << "All functionality tests OK for " << ds_name << std::endl << std::endl;
//    return true;
//}
//
//bool ExceptionsHeap() {
//
//    std::string ds_name = "Heap";
//    std::cout << ds_name << " EXCEPTIONS " << std::endl;
//    Heap<int> heap;
//    std::cout << "calling extractMax() on empty " << ds_name << " .. ";
//    try {
//        heap.extractMax();
//        std::cout << "expected exception to be raised." << std::endl;
//        return false;
//    } catch (const std::exception& e) {
//        std::cout << "OK!" << std::endl;
//    }
//
//    std::cout << "calling getMax() on empty " << ds_name << " .. ";
//    try {
//        heap.getMax();
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
//
//
//int main()
//{
//	if(TestsHeap())
//		if(ExceptionsHeap())
//			return 0;
//	return 1;
//}