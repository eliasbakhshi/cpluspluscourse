#include "Lab.h"
#include "QueueLinkedList.h"
#include "Testing.h"
#include <string>
#include <iostream>
#include <utility>

using namespace std;
// lägg till test av att alla ursprungselement finns kvar efter sorteringen



class ComparableElem
{
public:
	int value;
	int control;
	ComparableElem(int value = 0, int control = 0) : value(value), control(control) {}
	bool operator<(const ComparableElem& other) const
	{
		return value < other.value;
	}
	bool operator<=(const ComparableElem& other) const
	{
		return value <= other.value;
	}
	bool operator>(const ComparableElem& other) const
	{
		return value > other.value;
	}
	bool operator>=(const ComparableElem& other) const
	{
		return value >= other.value;
	}
};

void setSeed(unsigned int seed)
{
	srand(seed);
}

void generateIntegers(int nrs[], int nrOf, int maxValue = 1000)
{
	for (int i = 0; i < nrOf; i++)
	{
		nrs[i] = rand() % maxValue;
	}
}

template<typename T>
bool isSorted(T arr[], int nrOf)
{
	for (int i = 0; i < nrOf - 1; i++)
		if (arr[i + 1] < arr[i])
			return false;
	return true;
}

template<typename T>
bool hasSameElement(T arrOne[], T arrTwo[], int nrOf)
{
	int count = 0;
	for (int i = 0; i < nrOf; i++)
	{
		for (int k = 0; k < nrOf; k++)
		{
			if (arrTwo[i] == arrOne[k])
				count++;
		}
	}
	return count == nrOf;
}

bool testSameElementsInArrayBeforeAndAfterSorting(void (*sortfunc)(int*, int), string nameOfSortAlgorithm)
{
	std::cout << "Test " << nameOfSortAlgorithm << " on same elements in array before and after sorting has 1 testcase " << std::endl;
	const int CAP = 9;
	int beforeArr[CAP]{ 55, 11, 33, 88, 99, 22, 44, 66, 77 };
	int afterArr[CAP]{ 55, 11, 33, 88, 99, 22, 44, 66, 77 };
	sortfunc(afterArr, CAP);
	if (!hasSameElement(beforeArr, afterArr, CAP))
		return false;
	std::cout << "Test 1: OK " << std::endl;
	std::cout << "################## OK ##################### " << std::endl;
	return true;
}

bool testSortOnSmallIntegerArrays(void (*sortfunc)(int*, int), string nameOfSortAlgorithm)
{
	std::cout << "Test " << nameOfSortAlgorithm << " on small arrays has 4 testcases" << std::endl;
	const int CAP = 10;
	setSeed(200);
	int arr1[CAP];
	generateIntegers(arr1, CAP, 100);
	sortfunc(arr1, CAP);
	if (!isSorted(arr1, CAP))
	{
		std::cout << "NOT CORRECT 1: array containing " << CAP << " integers is not correctly sorted using " << nameOfSortAlgorithm << std::endl;
		return false;
	}
	std::cout << "Test 1 : OK " << std::endl;
	int arr2[CAP];
	generateIntegers(arr2, CAP, 500);
	sortfunc(arr2, CAP);
	if (!isSorted(arr2, CAP))
	{
		std::cout << "NOT CORRECT 2: array containing " << CAP << " integers is not correctly sorted using " << nameOfSortAlgorithm << std::endl;
		return false;
	}
	std::cout << "Test 2 : OK " << std::endl;
	int arr3[4]{ 11,11,11,11 };
	sortfunc(arr3, 4);
	if (!isSorted(arr3, 4))
	{
		std::cout << "NOT CORRECT 3: array containing " << 4 << " equal integers is not correctly sorted using " << nameOfSortAlgorithm << std::endl;
		return false;
	}
	std::cout << "Test 3 : OK " << std::endl;
	int arr4[9]{ 99, 88, 77, 66, 55, 44, 33, 22, 11 };
	sortfunc(arr4, 9);
	if (!isSorted(arr4, 9))
	{
		std::cout << "NOT CORRECT 4: array containing " << 9 << " integers in reversed order is not correctly sorted using " << nameOfSortAlgorithm << std::endl;
		return false;
	}
	std::cout << "Test 4 : OK " << std::endl;
	std::cout << "################## OK ##################### " << std::endl;
	return true;
}

bool testSortOnBiggerIntegerArrays(void (*sortfunc)(int*, int), string nameOfSortAlgorithm)
{
	std::cout << "Test " << nameOfSortAlgorithm << " on bigger arrays has 4 testcases" << std::endl;
	int testCase = 1;
	setSeed(33);
	const int cap[3]{ 100, 1000, 10000 };
	int* arr = nullptr;
	for (int i = 0; i < 3; i++)
	{
		arr = new int[cap[i]];
		generateIntegers(arr, cap[i], 2 * cap[i]);
		sortfunc(arr, cap[i]);
		if (!isSorted(arr, cap[i]))
		{
			std::cout << "NOT CORRECT " << i + 1 << " : array containing " << cap[i] << " integers is not correctly sorted using " << nameOfSortAlgorithm << std::endl;
			return false;
		}
		std::cout << "Test " << testCase << " : OK " << std::endl;
		testCase++;
		delete[] arr;
	}

	arr = new int[cap[0]];
	generateIntegers(arr, cap[0]);
	sortfunc(arr, cap[0]);
	int* reverseArr = new int[cap[0]];
	for (int i = 0; i < cap[0]; i++)
	{
		reverseArr[0] = arr[cap[0] - 1 - i];
	}
	sortfunc(reverseArr, cap[0]);
	if (!isSorted(reverseArr, cap[0]))
	{
		std::cout << "NOT CORRECT 4: array containing " << cap[0] << " integers in reverse order is not correctly sorted using " << nameOfSortAlgorithm << std::endl;
		return false;
	}

	std::cout << "Test " << testCase << " : OK " << std::endl;
	std::cout << "################## OK ##################### " << std::endl;

	return true;
}

bool testSortOnArraysWithObjects(void (*sortfunc)(ComparableElem*, int), string nameOfSortAlgorithm, bool checkIfStable = false)
{
	std::cout << "Test " << nameOfSortAlgorithm << " on arrays containing objects has ";
	if (checkIfStable)
	{
		cout << " 3 ";
	}
	else
	{
		cout << " 2 ";
	}
	cout << " testcases" << std::endl;
	const int CAP = 5;
	ComparableElem arr1[CAP] = { ComparableElem(55, 5), ComparableElem(11, 1), ComparableElem(22, 2), ComparableElem(77, 7), ComparableElem(33, 3) };
	sortfunc(arr1, CAP);
	if (!isSorted(arr1, CAP))
	{
		std::cout << "NOT CORRECT 1: array containing " << CAP << " objects is not correctly sorted using " << nameOfSortAlgorithm << std::endl;
		return false;
	}
	std::cout << "Test 1 : OK " << std::endl;

	ComparableElem arr2[3] = { ComparableElem(55, 33), ComparableElem(55, 22), ComparableElem(55, 11) };
	sortfunc(arr2, 3);
	if (!isSorted(arr2, 3))
	{
		std::cout << "NOT CORRECT 2: array containing " << 3 << " equal values is not correctly sorted using " << nameOfSortAlgorithm << std::endl;
		return false;
	}
	std::cout << "Test 2 : OK " << std::endl;
	if (checkIfStable)
	{
		if (arr2[0].control != 33 || arr2[1].control != 22 || arr2[2].control != 11)
		{
			std::cout << "NOT CORRECT 3: array containing " << 3 << " equal values has been rearranges => not stable" << std::endl;
			return false;
		}
		std::cout << "Test 3 : OK " << std::endl;
	}
	std::cout << "################## OK ##################### " << std::endl;
	return true;
}

bool testLinearSearch()
{
	std::cout << "Test linear search has 5 testcases" << std::endl;
	int testCase = 1;
	const int CAP = 10;
	std::string animals[CAP] = { "cat", "ball", "dog", "snake", "frog", "snail", "fly", "seal", "mouse", "rat" };
	std::string toFind = "cat";
	int index = linearSearch(animals, CAP, toFind);
	if (index != 0)
	{
		std::cout << "NOT CORRECT 1: expected 0 but got " << index << " using linear search " << std::endl;
		return false;
	}
	std::cout << "Test " << testCase << " : OK " << std::endl;
	testCase++;
	toFind = "frog";
	index = linearSearch(animals, CAP, toFind);
	if (index != 4)
	{
		std::cout << "NOT CORRECT 2: expected 4 but got " << index << " using linear search " << std::endl;
		return false;
	}
	std::cout << "Test " << testCase << " : OK " << std::endl;
	testCase++;
	toFind = "rat";
	index = linearSearch(animals, CAP, toFind);
	if (index != 9)
	{
		std::cout << "NOT CORRECT 3: expected 9 but got " << index << " using linear search " << std::endl;
		return false;
	}
	std::cout << "Test " << testCase << " : OK " << std::endl;
	testCase++;
	toFind = "cake";
	index = linearSearch(animals, CAP, toFind);
	if (index != -1)
	{
		std::cout << "NOT CORRECT 4: expected -1 but got " << index << " using linear search " << std::endl;
		return false;
	}
	std::cout << "Test " << testCase << " : OK " << std::endl;
	testCase++;
	int numbers[4]{ 11, 22, 33, 44 };
	index = linearSearch(numbers, 4, 22);
	if (index != 1)
	{
		std::cout << "NOT CORRECT 5: expected 1 but got " << index << " using linear search " << std::endl;
		return false;
	}
	std::cout << "Test " << testCase << " : OK " << std::endl;
	std::cout << "################## OK ##################### " << std::endl;
	return true;

}

bool testbinarysearch()
{
	std::cout << "test binary search has 5 testcases" << std::endl;
	int testcase = 1;
	const int cap = 10;
	std::string animals[cap] = { "cat", "ball", "dog", "snake", "frog", "snail", "fly", "seal", "mouse", "rat" };
	insertionSort(animals, cap);
	std::string tofind = "ball";
	int index = binarySearch(animals, cap, tofind);
	if (index != 0)
	{
		std::cout << "not correct 1: expected 0 but got " << index << " using linear search " << std::endl;
		return false;
	}
	std::cout << "test " << testcase << " : ok " << std::endl;
	testcase++;
	tofind = "frog";
	index = binarySearch(animals, cap, tofind);
	if (index != 4)
	{
		std::cout << "not correct 2: expected 4 but got " << index << " using binary search " << std::endl;
		return false;
	}
	std::cout << "test " << testcase << " : ok " << std::endl;
	testcase++;
	tofind = "snake";
	index = binarySearch(animals, cap, tofind);
	if (index != 9)
	{
		std::cout << "not correct 3: expected 9 but got " << index << " using binary search " << std::endl;
		return false;
	}
	std::cout << "test " << testcase << " : ok " << std::endl;
	testcase++;
	tofind = "cake";
	index = binarySearch(animals, cap, tofind);
	if (index != -1)
	{
		std::cout << "not correct 4: expected -1 but got " << index << " using binary search " << std::endl;
		return false;
	}
	std::cout << "test " << testcase << " : ok " << std::endl;
	testcase++;
	int numbers[4]{ 11, 22, 33, 44 };
	index = binarySearch(numbers, 4, 22);
	if (index != 1)
	{
		std::cout << "not correct 5: expected 1 but got " << index << " using binary search " << std::endl;
		return false;
	}
	std::cout << "test " << testcase << " : ok " << std::endl;
	std::cout << "################## ok ##################### " << std::endl;
	return true;

}

int main()
{
	/*const int CAP = 9;
	int aa[CAP]{ 77, 11, 33, 88, 99, 22, 44, 66, 55 };
	cout << partition3(aa, 0, CAP);
	printArray(aa, CAP);

	selectionSort2(aa, CAP);

	cout << linearSearch2(aa, CAP, 55) << endl;
	cout << binarySearch2(aa, CAP, 55) << endl;
	cout << "binarySearchRec2 " << endl;
	cout << binarySearchRec2(aa, 0, CAP - 1, 22) << endl;


	cout << "Start 2" << endl;
	for (auto a : aa ) {
		cout << a << " ";
	}
	cout << endl << "End 2" << endl;*/


	/* QueueLinkedList */

	cout << "QueueLinkedList";

	Queue<int> iQueue;
	try {
		iQueue.enqueue(22);
	} catch (exception e) {
		cout << e.what() << endl;
	}


	//
	//if (!testSameElementsInArrayBeforeAndAfterSorting(insertionSort<int>, "insertionsort"))
	//{
	//	cout << "NOT OK" << endl;
	//	return -1;
	//}
	//if (!testSameElementsInArrayBeforeAndAfterSorting(selectionSort<int>, "selectionsort"))
	//{
	//	cout << "NOT OK" << endl;
	//	return -1;
	//}
	//if (!testSortOnSmallIntegerArrays(insertionSort<int>, "insertionsort"))
	//{
	//	std::cout << "Test insertionsort on small arrays : NOT OK" << std::endl;
	//	return 1;
	//}
	//
	//if (!testSortOnSmallIntegerArrays(selectionSort<int>, "selectionsort"))
	//{
	//	std::cout << "Test selectionsort on small arrays : NOT OK" << std::endl;
	//	return 2;
	//}
	//if (!testSortOnBiggerIntegerArrays(insertionSort<int>, "insertionsort"))
	//{
	//	std::cout << "Test insertionsort on bigger arrays : NOT OK" << std::endl;
	//	return 3;
	//}
	//if (!testSortOnBiggerIntegerArrays(selectionSort<int>, "selectionsort"))
	//{
	//	std::cout << "Test selectionsort on bigger arrays : NOT OK" << std::endl;
	//	return 4;
	//}
	//if (!testSortOnArraysWithObjects(insertionSort<ComparableElem>, "insertionsort", true))
	//{
	//	std::cout << "Test insertionsort on arrays with objects: NOT OK" << std::endl;
	//	return 5;
	//}
	//if (!testSortOnArraysWithObjects(selectionSort<ComparableElem>, "selectionsort"))
	//{
	//	std::cout << "Test selectionsort on arrays with objects: NOT OK" << std::endl;
	//	return 6;
	//}
	//if (!testLinearSearch())
	//{
	//	std::cout << "Test linear search : NOT OK" << std::endl;
	//	return 7;
	//}
	//if (!testbinarysearch())
	//{
	//	std::cout << "Test binary search : NOT OK" << std::endl;
	//	return 8;
	//}
	//här kan du lägga till tester för ex-vis rekursiva versioner av 
	// sorteringsfunktioner

	return 0;
}

