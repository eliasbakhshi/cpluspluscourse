//#include "Testing_functions.h"
//#include <string>
//#include <iostream>
//#include <utility>
//
//using namespace std;
//
//class ComparableElem {
//private:
//	int value;
//	int control;
//public:
//	ComparableElem(int value = 0, int control = 0) : value(value), control(control) {}
//	int getControl() const {
//		return control;
//	}
//	bool operator<(const ComparableElem& other) const {
//		return value < other.value;
//	}
//	bool operator<=(const ComparableElem& other) const {
//		return value <= other.value;
//	}
//	bool operator>(const ComparableElem& other) const {
//		return value > other.value;
//	}
//	bool operator>=(const ComparableElem& other) const {
//		return value >= other.value;
//	}
//	bool operator==(const ComparableElem& other) const {
//		return value == other.value;
//	}
//};
//
//void setSeed(unsigned int seed) {
//	srand(seed);
//}
//
//void generateIntegers(int nrs[], int nrOf, int maxValue = 1000) {
//	for (int i = 0; i < nrOf; i++) {
//		nrs[i] = rand() % maxValue;
//	}
//}
//
//template<typename T>
//bool isSorted(T arr[], int nrOf) {
//	for (int i = 0; i < nrOf - 1; i++)
//		if (arr[i + 1] < arr[i])
//			return false;
//	return true;
//}
//
//template<typename T>
//bool hasSameElements(T arrOne[], T arrTwo[], int nrOf) {
//	int count = 0;
//	for (int i = 0; i < nrOf; i++) {
//		for (int k = 0; k < nrOf; k++) {
//			if (arrTwo[i] == arrOne[k])
//				count++;
//		}
//	}
//	return count == nrOf;
//}
//
//bool testSameElementsInArrayBeforeAndAfterSorting(void (*sortfunc)(int*, int), string nameOfSortAlgorithm) {
//	std::cout << "Test " << nameOfSortAlgorithm << " on same elements in array before and after sorting has 1 testcase " << std::endl;
//	const int CAP = 9;
//	int beforeArr[CAP]{ 55, 11, 33, 88, 99, 22, 44, 66, 77 };
//	int afterArr[CAP]{ 55, 11, 33, 88, 99, 22, 44, 66, 77 };
//	sortfunc(afterArr, CAP);
//	if (!hasSameElements(beforeArr, afterArr, CAP))
//		return false;
//	std::cout << "Test 1: OK " << std::endl;
//	std::cout << "################## OK ##################### " << std::endl;
//	return true;
//}
//
//bool testSortOnSmallIntegerArrays(void (*sortfunc)(int*, int), string nameOfSortAlgorithm) {
//	std::cout << "Test " << nameOfSortAlgorithm << " on small arrays has 4 testcases" << std::endl;
//	const int CAP = 10;
//	setSeed(200);
//	int arr1[CAP];
//	generateIntegers(arr1, CAP, 100);
//	sortfunc(arr1, CAP);
//	if (!isSorted(arr1, CAP)) {
//		std::cout << "NOT CORRECT 1: array containing " << CAP << " integers is not correctly sorted using " << nameOfSortAlgorithm << std::endl;
//		return false;
//	}
//	std::cout << "Test 1 : OK " << std::endl;
//	int arr2[CAP];
//	generateIntegers(arr2, CAP, 500);
//	sortfunc(arr2, CAP);
//	if (!isSorted(arr2, CAP)) {
//		std::cout << "NOT CORRECT 2: array containing " << CAP << " integers is not correctly sorted using " << nameOfSortAlgorithm << std::endl;
//		return false;
//	}
//	std::cout << "Test 2 : OK " << std::endl;
//	int arr3[4]{ 11,11,11,11 };
//	sortfunc(arr3, 4);
//	if (!isSorted(arr3, 4)) {
//		std::cout << "NOT CORRECT 3: array containing " << 4 << " equal integers is not correctly sorted using " << nameOfSortAlgorithm << std::endl;
//		return false;
//	}
//	std::cout << "Test 3 : OK " << std::endl;
//	int arr4[9]{ 99, 88, 77, 66, 55, 44, 33, 22, 11 };
//	sortfunc(arr4, 9);
//	if (!isSorted(arr4, 9)) {
//		std::cout << "NOT CORRECT 4: array containing " << 9 << " integers in reversed order is not correctly sorted using " << nameOfSortAlgorithm << std::endl;
//		return false;
//	}
//	std::cout << "Test 4 : OK " << std::endl;
//	std::cout << "################## OK ##################### " << std::endl;
//	return true;
//}
//
//bool testSortOnBiggerIntegerArrays(void (*sortfunc)(int*, int), string nameOfSortAlgorithm) {
//	std::cout << "Test " << nameOfSortAlgorithm << " on bigger arrays has 4 testcases" << std::endl;
//	int testCase = 1;
//	setSeed(33);
//	const int cap[3]{ 100, 1000, 10000 };
//	int* arr = nullptr;
//	for (int i = 0; i < 3; i++) {
//		arr = new int[cap[i]];
//		generateIntegers(arr, cap[i], 2 * cap[i]);
//		sortfunc(arr, cap[i]);
//		if (!isSorted(arr, cap[i])) {
//			std::cout << "NOT CORRECT " << i + 1 << " : array containing " << cap[i] << " integers is not correctly sorted using " << nameOfSortAlgorithm << std::endl;
//			return false;
//		}
//		std::cout << "Test " << testCase << " : OK " << std::endl;
//		testCase++;
//		delete[] arr;
//	}
//
//	arr = new int[cap[0]];
//	generateIntegers(arr, cap[0]);
//	sortfunc(arr, cap[0]);
//	int* reverseArr = new int[cap[0]];
//	for (int i = 0; i < cap[0]; i++) {
//		reverseArr[0] = arr[cap[0] - 1 - i];
//	}
//	sortfunc(reverseArr, cap[0]);
//	if (!isSorted(reverseArr, cap[0])) {
//		std::cout << "NOT CORRECT 4: array containing " << cap[0] << " integers in reverse order is not correctly sorted using " << nameOfSortAlgorithm << std::endl;
//		return false;
//	}
//	delete[] arr;
//	delete[] reverseArr;
//
//	std::cout << "Test " << testCase << " : OK " << std::endl;
//	std::cout << "################## OK ##################### " << std::endl;
//
//	return true;
//}
//
//bool testSortOnArraysWithObjects(void (*sortfunc)(ComparableElem*, int), string nameOfSortAlgorithm, bool checkIfStable = false) {
//	std::cout << "Test " << nameOfSortAlgorithm << " on arrays containing objects has ";
//	if (checkIfStable) {
//		cout << " 3 ";
//	} else {
//		cout << " 2 ";
//	}
//	cout << " testcases" << std::endl;
//	const int CAP = 5;
//	ComparableElem arr1[CAP] = { ComparableElem(55, 5), ComparableElem(11, 1), ComparableElem(22, 2), ComparableElem(77, 7), ComparableElem(33, 3) };
//	sortfunc(arr1, CAP);
//	if (!isSorted(arr1, CAP)) {
//		std::cout << "NOT CORRECT 1: array containing " << CAP << " objects is not correctly sorted using " << nameOfSortAlgorithm << std::endl;
//		return false;
//	}
//	std::cout << "Test 1 : OK " << std::endl;
//	const int CAP2 = 12;
//	ComparableElem arr2[CAP2];
//	for (int i = 0; i < CAP2; i++) {
//		arr2[i] = ComparableElem(55, i);
//	}
//	arr2[3] = ComparableElem(77, 0);
//	arr2[4] = ComparableElem(77, 1);
//
//	sortfunc(arr2, CAP2);
//	if (!isSorted(arr2, CAP2)) {
//		std::cout << "NOT CORRECT 2: array containing " << CAP2 << " elements with some equal values is not correctly sorted using " << nameOfSortAlgorithm << std::endl;
//		return false;
//	}
//	std::cout << "Test 2 : OK " << std::endl;
//	if (checkIfStable) {
//		for (int i = 0; i < CAP2 - 1; i++) {
//			if (arr2[i] > arr2[i + 1] || (arr2[i] == arr2[i + 1] && arr2[i].getControl() >= arr2[i + 1].getControl())) {
//				std::cout << "NOT CORRECT 3: array containing " << CAP2 << " elements with some equal values has been rearranges => not stable" << std::endl;
//				return false;
//			}
//
//		}
//
//		std::cout << "Test 3 : OK " << std::endl;
//	}
//	std::cout << "################## OK ##################### " << std::endl;
//	return true;
//}
//
//
//
//int main() {
//	if (!testSameElementsInArrayBeforeAndAfterSorting(quickSort<int>, "quicksort")) {
//		cout << "NOT OK" << endl;
//		return 1;
//	}
//	if (!testSortOnSmallIntegerArrays(quickSort<int>, "quicksort")) {
//		std::cout << "Test quicksort on small arrays : NOT OK" << std::endl;
//		return 1;
//	}
//	if (!testSortOnBiggerIntegerArrays(quickSort<int>, "quicksort")) {
//		std::cout << "Test quicksort on bigger arrays : NOT OK" << std::endl;
//		return 1;
//	}
//	if (!testSortOnArraysWithObjects(quickSort<ComparableElem>, "quicksort")) {
//		std::cout << "Test quicksort on arrays with objects: NOT OK" << std::endl;
//		return 1;
//	}
//
//	if (!testSameElementsInArrayBeforeAndAfterSorting(mergeSort<int>, "mergesort")) {
//		cout << "NOT OK" << endl;
//		return 2;
//	}
//	if (!testSortOnSmallIntegerArrays(mergeSort<int>, "mergesort")) {
//		std::cout << "Test mergesort on small arrays : NOT OK" << std::endl;
//		return 2;
//	}
//	if (!testSortOnBiggerIntegerArrays(mergeSort<int>, "mergesort")) {
//		std::cout << "Test mergesort on bigger arrays : NOT OK" << std::endl;
//		return 2;
//	}
//	if (!testSortOnArraysWithObjects(mergeSort<ComparableElem>, "mergesort", true)) {
//		std::cout << "Test mergesort on arrays with objects: NOT OK" << std::endl;
//		return 2;
//	}
//
//	if (!testSameElementsInArrayBeforeAndAfterSorting(heapSort<int>, "heapsort")) {
//		cout << "NOT OK" << endl;
//		return 3;
//	}
//	if (!testSortOnSmallIntegerArrays(heapSort<int>, "heapsort")) {
//		std::cout << "Test heapsort on small arrays : NOT OK" << std::endl;
//		return 3;
//	}
//	if (!testSortOnBiggerIntegerArrays(heapSort<int>, "heapsort")) {
//		std::cout << "Test heapsort on bigger arrays : NOT OK" << std::endl;
//		return 3;
//	}
//	if (!testSortOnArraysWithObjects(heapSort<ComparableElem>, "heapsort")) {
//		std::cout << "Test heapsort on arrays with objects: NOT OK" << std::endl;
//		return 3;
//	}
//
//	return 0;
//}
//
