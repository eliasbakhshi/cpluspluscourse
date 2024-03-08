#include "Headers.h"
#include "Register.h"

#include <iostream>

int main() {

	int* ptr = nullptr; // ptr is stored at the address 300
	int** ptr2 = nullptr; // ptr is stored at the address 300
	ptr = new int(6); // returns the address 700
	ptr2 = &ptr;
	std::cout << "ptr: " << ptr << std::endl;
	std::cout << "*ptr: " << *ptr << std::endl;
	std::cout << "&ptr: " << &ptr << std::endl;
	std::cout << "&ptr2: " << &ptr2 << std::endl;
	int** pptr = new int* [2]; // returns the address 800
	pptr[0] = ptr;
	std::cout << "*pptr[0]" << *pptr[0] << std::endl;
	return 0;
	/*Register reg;
	reg.addExerciser("Elias", "Male", 22);
	reg.addElit("Bakhshi", "Male", "club 1", 5);

	int tt[10] = { 0 };

	Register reg2(reg);
	Register reg3 = reg2;
	reg2 = reg;

	reg.searchByName("Elias222");
	reg.showParticipants();
	
	cout << "22" << endl;
	reg2.showParticipants();
	cout << "33123" << endl;
	reg3.showParticipants();*/



	return 0;
}