#include "functions.hpp"



using namespace std;

struct car {
	string model;
	double price;
};

void plus2(int& num) {
	num += num;
}

void withReference(int& num) {
	num += 10;
	cout << num << endl;
}

void withPtr(int* num) {
	*num += *num;
}


void sandbox() {

	int num = 20;
	withReference(num);
	cout << num << endl;
	withPtr(&num);
	cout << num << endl;


	string file_content;
	string the_line;

	// Read from the file.
	//fstream test_file("text.txt", ios::in);
	//if (test_file.is_open()) {
	//	while (getline(test_file, the_line)) {
	//		cout << the_line << endl;
	//	}
	//	test_file.close();
	//} else cout << "Could not open the file";

	// Write in the file. 
	/*fstream test_file2("text.txt", ios::app);
	if (test_file2.is_open()) {
		test_file2.seekp(0, std::ios_base::beg);
		while (getline(test_file, the_line)) {
			cout << the_line << endl;
		}
		test_file2 << "This is a line.\n";
		test_file2 << "This is another line.\n";
		test_file2.close();
	} else cout << "Could not open the file";
	cout << endl << endl;

	int test[3] = { 1,2,3 };


	int* valueZero = &test[1];
	cout << "Second element: " << *(valueZero) << endl;
	int test2 = 10;
	int* pTest = &test2;
	cout << "test    " << *pTest << endl << endl;
	cout << &pTest << endl<< endl;
	cout << pTest << endl;


	int theNum = 10;
	plus2(theNum);
	cout << theNum;*/



	//car ford = { "x200", 123.232 };

	//int refer1 = 2;
	//int& refer2 = refer1;
	//cout << refer2;
	//cout << "555";

}