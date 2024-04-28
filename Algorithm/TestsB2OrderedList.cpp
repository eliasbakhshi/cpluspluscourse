#include "OrderedList.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

bool TestsOrderedList() {

    std::string ds_name = "OrderedList";
    std::cout << ds_name << " TEST" << std::endl;
    std::cout << "Testing " << ds_name << " with ints" << std::endl;
    OrderedList<int> i_list;

    std::cout << "New " << ds_name << " should be empty ....";
    if (!i_list.is_empty()) {
        std::cout << " but was not" << std::endl;
        return false;
    }
    std::cout << " OK!" << std::endl;

    std::cout << "Using add() with integers 30, 20, and 10....: ";
    for (int i = 3; i > 0; --i) {
        i_list.add(i * 10);
    }
    std::cout << std::endl;

    std::string result_string = "";
    std::string control_string = "10,10 20,20 30,30 ";
    std::cout << "Using first() and removeFirst() on " << ds_name << " until empty .....";

    while (!i_list.is_empty()) {
        result_string += std::to_string(i_list.first());
        result_string += "," + std::to_string(i_list.removeFirst()) + " ";
    }

    if (result_string != control_string) {
        std::cout << "expected " << control_string << " but got " << result_string << std::endl;
        return false;
    }
    std::cout << " OK!" << std::endl;

    std::cout << "Using add() with integers 10, 20, and 30....: ";
    for (int i = 1; i < 4; ++i) {
        i_list.add(i * 10);
    }
    std::cout << std::endl;

    result_string = "";
    control_string = "30,30 20,20 10,10 ";
    std::cout << "Using last() and removeLast() on " << ds_name << " until empty .....";

    while (!i_list.is_empty()) {
        result_string += std::to_string(i_list.last());
        result_string += "," + std::to_string(i_list.removeLast()) + " ";
    }

    if (result_string != control_string) {
        std::cout << "expected " << control_string << " but got " << result_string << std::endl;
        return false;
    }
    std::cout << " OK!" << std::endl;

    std::cout << "Mixing the aforementioned functions ......  ";
    for (int i = 1; i < 3; ++i) {
        i_list.add(i * 11);
    }
    i_list.removeFirst();
    for (int i = 3; i < 5; ++i) {
        i_list.add(i * 11);
    }
    for (int i = 1; i < 3; ++i) {
        i_list.removeLast();
    }
    for (int i = 9; i < 12; ++i) {
        i_list.add(i * 11);
    }
    i_list.removeFirst();
    for (int i = 5; i < 8; ++i) {
        i_list.add(i * 11);
    }

    result_string = "";
    while (!i_list.is_empty()) {
        result_string += std::to_string(i_list.removeFirst()) + " ";
        result_string += std::to_string(i_list.removeLast()) + " ";
    }
    control_string = "55 121 66 110 77 99 ";
    if (result_string != control_string) {
        std::cout << " expected " << control_string << " but got " << result_string << std::endl;
        return false;
    }
    std::cout << " OK!" << std::endl;

    std::cout << "Using add and remove on prepopulated " << ds_name << " .... " << std::endl;

    std::cout << "  Adding 0, 1, 2, ..., 7, 8, 9 using add()" << std::endl;
    for (int i = 0; i < 10; ++i) {
        i_list.add(i);
    }

    std::cout << "  Checking size() .. ";
    if (i_list.size() != 10) {
        std::cout << " expected size() == 10, but is " << i_list.size() << std::endl;
        return false;
    }
    std::cout << "OK!" << std::endl;

    std::cout << "  Calling remove() for values 9, 5, 2, 0" << std::endl;
    i_list.remove(9);
    i_list.remove(5);
    i_list.remove(2);
    i_list.remove(0);

    std::cout << "  Checking size() .. ";
    if (i_list.size() != 6) {
        std::cout << " expected size() == 6, but is " << i_list.size() << std::endl;
        return false;
    }
    std::cout << "OK!" << std::endl;

    std::cout << "  Calling add() with 0, 2, 5, and 9" << std::endl;
    i_list.add(0);
    i_list.add(2);
    i_list.add(5);
    i_list.add(9);

    std::cout << "  Checking size() .. ";
    if (i_list.size() != 10) {
        std::cout << " expected size() == 10, but is " << i_list.size() << std::endl;
        return false;
    }
    std::cout << "OK!" << std::endl;

    std::cout << "  Calling removeLast() until " << ds_name << " is empty using is_empty() .... " << std::endl;
    result_string = "";
    control_string = "0 1 2 3 4 5 6 7 8 9 ";
    while (!i_list.is_empty()) {
        result_string += std::to_string(i_list.removeFirst()) + " ";
    }

    if (result_string != control_string) {
        std::cout << "Expected " << control_string << " but got " << result_string << std::endl;
        return false;
    }
    std::cout << "OK!" << std::endl;

    std::cout << std::endl;
    std::cout << "Testing " << ds_name << " with strings .... " << std::endl;
    OrderedList<std::string> s_list;

    std::cout << "Testing add() with A, B, C, and D .... ";
    s_list.add("B");
    s_list.add("D");
    s_list.add("A");
    s_list.add("C");

    result_string = "";
    control_string = "ABCD";

    while (!s_list.is_empty()) {
        result_string += s_list.removeFirst();
    }
    if (result_string != control_string) {
        std::cout << " expected " << control_string << " but got " << result_string << std::endl;
        return false;
    }

    std::cout << " OK!" << std::endl;
    return true;
}

bool ExceptionsOrderedList() {
    using namespace std;

    std::string ds_name = "OrderedList";
    std::cout << ds_name << " EXCEPTIONS" << std::endl;
    std::cout << "Testing " << ds_name << " for exceptions" << std::endl;

    OrderedList<int> i_list;

    // first on empty
    std::cout << "Using first() with empty " << ds_name << " ... ";
    try {
        i_list.first();
        std::cout << "expected exception to be raised." << std::endl;
        return false;
    } catch (const std::exception& e) {
        std::cout << "OK!" << std::endl;
    }

    // last on empty
    std::cout << "Using last() with empty " << ds_name << " ... ";
    try {
        i_list.last();
        std::cout << "expected exception to be raised." << std::endl;
        return false;
    } catch (const std::exception& e) {
        std::cout << "OK!" << std::endl;
    }

    // removeFirst on empty
    std::cout << "Using removeFirst() with empty " << ds_name << " ... ";
    try {
        i_list.removeFirst();
        std::cout << "expected exception to be raised." << std::endl;
        return false;
    } catch (const std::exception& e) {
        std::cout << "OK!" << std::endl;
    }

    // removeLast on empty
    std::cout << "Using removeLast() with empty " << ds_name << " ... ";
    try {
        i_list.removeLast();
        std::cout << "expected exception to be raised." << std::endl;
        return false;
    } catch (const std::exception& e) {
        std::cout << "OK!" << std::endl;
    }

    // remove on empty
    std::cout << "Using remove() on empty " << ds_name << " ... ";
    try {
        i_list.remove(1);
        std::cout << "expected exception to be raised." << std::endl;
        return false;
    } catch (const std::exception& e) {
        std::cout << "OK!" << std::endl;
    }

    // get on empty
    std::cout << "Using get() on empty " << ds_name << " ... ";
    try {
        i_list.get(0);
        std::cout << "expected exception to be raised." << std::endl;
        return false;
    } catch (const std::exception& e) {
        std::cout << "OK!" << std::endl;
    }

    i_list.add(1);

    // remove non-existing element
    std::cout << "Using remove() for non-existing element ... ";
    try {
        i_list.remove(0);
        std::cout << "expected exception to be raised." << std::endl;
        return false;
    } catch (const std::exception& e) {
        std::cout << "OK!" << std::endl;
    }

    return true;
}

int main()
{
    if (TestsOrderedList())
        if (ExceptionsOrderedList())
            return 0;
    return 1;
}