//#include "IndexedList.hpp"
//#include <iostream>
//#include <string>
//
//bool TestsIndexedList() {
//    std::string ds_name = "IndexedList";
//    std::cout << ds_name << " TEST" << std::endl;
//    std::cout << "Testing " << ds_name << " with ints" << std::endl;
//    IndexedList<int> i_list;
//
//    std::cout << "New " << ds_name << " should be empty ....";
//    if (!i_list.is_empty()) {
//        std::cout << " but was not" << std::endl;
//        return false;
//    }
//    std::cout << " OK!" << std::endl;
//
//    std::cout << "Using addAt() with integers 10, 20, and 30....: ";
//    for (int i = 1; i < 4; ++i) {
//        i_list.addAt(0, i * 10);
//    }
//    std::cout << std::endl;
//
//    std::string result_string;
//    std::string control_string = "30,30 20,20 10,10 ";
//    std::cout << "Using first() and removeFirst() on " << ds_name << " until empty ..... ";
//    while (!i_list.is_empty()) {
//        result_string += std::to_string(i_list.first()) + ",";
//        result_string += std::to_string(i_list.removeFirst()) + " ";
//    }
//    if (result_string != control_string) {
//        std::cout << "expected " << control_string << " but got " << result_string << std::endl;
//        return false;
//    }
//    std::cout << "OK!" << std::endl;
//
//    std::cout << "Using add_to_back() with integers 10, 20, and 30....: ";
//    for (int i = 1; i < 4; ++i) {
//        i_list.addAt(i - 1, i * 10);
//    }
//    std::cout << std::endl;
//
//    result_string = "";
//    control_string = "30,30 20,20 10,10 ";
//    std::cout << "Using last and removeLast on " << ds_name << " until empty ..... ";
//    while (!i_list.is_empty()) {
//        result_string += std::to_string(i_list.last()) + ",";
//        result_string += std::to_string(i_list.removeLast()) + " ";
//    }
//    if (result_string != control_string) {
//        std::cout << "expected " << control_string << " but got " << result_string << std::endl;
//        return false;
//    }
//    std::cout << "OK!" << std::endl;
//
//    std::cout << "Mixing the aforementioned functions  ......  ";
//    for (int i = 1; i < 3; ++i) {
//        i_list.addAt(0, i * 11);
//    }
//    for (int i = 3; i < 5; ++i) {
//        i_list.addAt(i - 1, i * 11);
//    }
//    for (int i = 1; i < 3; ++i) {
//        i_list.removeLast();
//    }
//    for (int i = 9; i < 12; ++i) {
//        i_list.addAt(i - 7, i * 11);
//    }
//    for (int i = 5; i < 8; ++i) {
//        i_list.addAt(i, i * 11);
//    }
//
//    result_string = "";
//    while (!i_list.is_empty()) {
//        result_string += std::to_string(i_list.removeFirst()) + " ";
//        result_string += std::to_string(i_list.removeLast()) + " ";
//    }
//    control_string = "22 77 11 66 99 55 110 121 ";
//    if (result_string != control_string) {
//        std::cout << "expected " << control_string << " but got " << result_string << std::endl;
//        return false;
//    }
//    std::cout << "OK!" << std::endl;
//
//    std::cout << "Using addAt and removeAt on prepopulated " << ds_name << " .... " << std::endl;
//    std::cout << "  Adding 0,1,2,...,7,8,9 using add_to_back()" << std::endl;
//    for (int i = 0; i < 10; ++i) {
//        i_list.addAt(i, i);
//    }
//
//    std::cout << "  checking size() .. ";
//    if (i_list.size() != 10) {
//        std::cout << " expected size() == 10, but is " << i_list.size() << std::endl;
//        return false;
//    }
//    std::cout << "OK!" << std::endl;
//
//    std::cout << "  Calling removeAt() for index 9, 5, 2, 0" << std::endl;
//    i_list.removeAt(9);
//    i_list.removeAt(5);
//    i_list.removeAt(2);
//    i_list.removeAt(0);
//    std::cout << "  checking size() .. ";
//    if (i_list.size() != 6) {
//        std::cout << " expected size() == 6, but is " << i_list.size() << std::endl;
//        return false;
//    }
//    std::cout << "OK!" << std::endl;
//
//    std::cout << "  Calling addAt() with (index,value) for (0,0, (2,2), (5,5), (9,9)" << std::endl;
//    i_list.addAt(0, 0);
//    i_list.addAt(2, 2);
//    i_list.addAt(5, 5);
//    i_list.addAt(9, 9);
//    std::cout << "  checking size() .. ";
//    if (i_list.size() != 10) {
//        std::cout << " expected size() == 10, but is " << i_list.size() << std::endl;
//        return false;
//    }
//    std::cout << "OK!" << std::endl;
//
//    std::cout << "  Calling removeAt(0) until " << ds_name << " is empty using is_empty() .... " << std::endl;
//    result_string = "";
//    control_string = "0 1 2 3 4 5 6 7 8 9 ";
//    while (!i_list.is_empty()) {
//        result_string += std::to_string(i_list.removeAt(0)) + " ";
//    }
//
//    if (result_string != control_string) {
//        std::cout << "Expected " << control_string << " but got " << result_string << std::endl;
//        return false;
//    }
//    std::cout << "OK!" << std::endl;
//
//    std::cout << std::endl;
//    std::cout << "Testing " << ds_name << " with strings .... " << std::endl;
//    IndexedList<std::string> s_list;
//
//    std::cout << "Testing add_to_front() with A, B, C and D .... ";
//    s_list.addAt(0, "A");
//    s_list.addAt(0, "B");
//    s_list.addAt(0, "C");
//    s_list.addAt(0, "D");
//
//    result_string = "";
//    control_string = "DCBA";
//
//    while (!s_list.is_empty()) {
//        result_string += s_list.removeFirst();
//    }
//    if (result_string != control_string) {
//        std::cout << " expected " << control_string << " but got " << result_string << std::endl;
//        return false;
//    }
//
//    std::cout << " OK!" << std::endl << std::endl;;
//    return true;
//}
//
//bool ExceptionsIndexedList() {
//    std::string ds_name = "IndexedList";
//    std::cout << ds_name << " EXCEPTIONS" << std::endl;
//    std::cout << "Testing " << ds_name << " for exceptions" << std::endl;
//
//    IndexedList<int> i_list;
//
//    // Exceptions
//    // add at < 0 
//    std::cout << "addAt() with index < 0 ... ";
//    try {
//        i_list.addAt(-1, -1);
//        std::cout << " expected exception to be raised." << std::endl;
//        return false;
//    } catch (const std::exception& e) {
//        std::cout << "OK!" << std::endl;
//    }
//
//    // add at > size
//    std::cout << "addAt() with index > size of " << ds_name << " ... ";
//    try {
//        i_list.addAt(123123, 123123);
//        std::cout << " expected exception to be raised." << std::endl;
//        return false;
//    } catch (const std::exception& e) {
//        std::cout << "OK!" << std::endl;
//    }
//
//    // first on empty
//    std::cout << "using first() with empty " << ds_name << " ... ";
//    try {
//        i_list.first();
//        std::cout << " expected exception to be raised." << std::endl;
//        return false;
//    } catch (const std::exception& e) {
//        std::cout << "OK!" << std::endl;
//    }
//
//    // last on empty
//    std::cout << "using last() with empty " << ds_name << " ... ";
//    try {
//        i_list.last();
//        std::cout << " expected exception to be raised." << std::endl;
//        return false;
//    } catch (const std::exception& e) {
//        std::cout << "OK!" << std::endl;
//    }
//
//    // removeFirst on empty
//    std::cout << "using removeFirst() with empty " << ds_name << " ... ";
//    try {
//        i_list.removeFirst();
//        std::cout << " expected exception to be raised." << std::endl;
//        return false;
//    } catch (const std::exception& e) {
//        std::cout << "OK!" << std::endl;
//    }
//
//    // removeLast on empty
//    std::cout << "using removeLast() with empty " << ds_name << " ... ";
//    try {
//        i_list.removeLast();
//        std::cout << " expected exception to be raised." << std::endl;
//        return false;
//    } catch (const std::exception& e) {
//        std::cout << "OK!" << std::endl;
//    }
//
//    // removeAt on empty
//    std::cout << "using removeAt on empty " << ds_name << " ... ";
//    try {
//        i_list.removeAt(0);
//        std::cout << " expected exception to be raised." << std::endl;
//        return false;
//    } catch (const std::exception& e) {
//        std::cout << "OK!" << std::endl;
//    }
//
//    i_list.addAt(0, 1);
//    // removeAt < 0
//    std::cout << "using removeAt with index < 0 ... ";
//    try {
//        i_list.removeAt(-1);
//        std::cout << " expected exception to be raised." << std::endl;
//        return false;
//    } catch (const std::exception& e) {
//        std::cout << "OK!" << std::endl;
//    }
//
//    // removeAt > size
//    std::cout << "using removeAt with index > size of " << ds_name << " ... ";
//    try {
//        i_list.removeAt(123123);
//        std::cout << " expected exception to be raised." << std::endl;
//        return false;
//    } catch (const std::exception& e) {
//        std::cout << "OK!" << std::endl;
//    }
//
//    return true;
//}
//
//int main()
//{
//	if (TestsIndexedList())
//		if (ExceptionsIndexedList())
//			return 0;
//	return 1;
//}