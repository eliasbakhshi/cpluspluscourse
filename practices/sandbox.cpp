#include "functions.hpp"


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

void setNewPrice(car &theCar, float newPrice) {
	theCar.price = newPrice;
}

class Animal {
protected:
	string name;


public:
	Animal(string newName) {
		name = newName;
	}
	void setName(string newName) {
		name = newName;
	}

	string getName() {
		return name;
	}

};

class Cat : public Animal {
	float weight;

public:
	Cat(string n) : Animal(n) {
		name = n;
	}
	void setWeight(float newWeight) {
		weight = newWeight;
	}
	
	void showInfo() {
		cout << name << " is " << weight << "kg" << endl;
	}
};

void addValue(int &a, int b) {
	a += b;
}
void sandbox(string name) {
	int a = 10;
	int b = 20;
	addValue(a, b);

	cout << a << endl;
	/*string name = "cat";
	Animal test(name);
	Cat cat("Tiger");
	
	cat.setWeight(25.3);
	cat.showInfo();
	string animalName = test.getName();
	cout << "The name is " << animalName << endl;*/





	//car bmw = { "X200", 33.33 };
	//cout << bmw.model << " cost you " << bmw.price << " to buy it." << endl;

	//bmw.price = 45.33;
	//cout << "The new cost for the " << bmw.model << " is " << bmw.price << endl;

	//setNewPrice(bmw, 56.44);
	//cout << "The new cost for the " << bmw.model << " is " << bmw.price << endl;

	//enum class Person {name, age};
	//enum class User {name, age};

	//Person age = Person::age;

	//cout << "The test value is " << static_cast<int>(age) << endl;


	//int num = 20;
	//withReference(num);
	//cout << num << endl;
	//withPtr(&num);
	//cout << num << endl;


	//string file_content;
	//string the_line;

	////Read from the file.
	//ifstream test_file("text.txt");
	//if (test_file.is_open()) {
	//	cout << test_file.tellg() << endl;
	//	while (getline(test_file, the_line)) {
	//		cout << "Current position: " << test_file.tellg() << endl;
	//		cout << the_line << endl;
	//	}

	//	test_file.close();
	//} else cout << "Could not open the file";

	////Write in the file. 
	//cout << endl << endl;
	//cout << "test2" << endl;
	//fstream test_file2("text.txt", ios::app);
	//if (test_file2.is_open()) {
	//	test_file2.seekp(0, std::ios_base::beg);
	//	while (getline(test_file, the_line)) {
	//		cout << "ttt   " << test_file2.tellp();
	//		//test_file2.seekp(0, std::ios_base::beg);
	//		cout << the_line << endl;
	//	}
	//	//test_file2 << "This is a line.\n";
	//	//test_file2 << "This is another line.\n";
	//	test_file2.close();
	//} else cout << "Could not open the file";
	//cout << endl << endl;


	//cout << "End of the file. " << endl;
	//int test[3] = { 1,2,3 };


	/*int* valueZero = &test[1];
	cout << "Second element: " << *(valueZero) << endl;
	int test2 = 10;
	int* pTest = &test2;
	cout << "test    " << *pTest << endl << endl;
	cout << &pTest << endl << endl;
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