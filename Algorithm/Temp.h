//#include <algorithm>
//#include <iostream>
//
//using namespace std;
//
//// print the list
//template <typename T>
//void printArray(T arr[], int length) {
//	for (int i = 0; i < length; i++) {
//		cout << arr[i] << " ";
//	}
//}
//
//
//template <typename T>
//void CountingSort(T elements[], int nrOfElements, int exp) {
//	// Find the maximum and minimum element in the array
//	T max_element = elements[0];
//	T min_element = elements[0];
//	for (int i = 1; i < nrOfElements; ++i) {
//		if (elements[i] > max_element)
//			max_element = elements[i];
//		if (elements[i] < min_element)
//			min_element = elements[i];
//	}
//
//	// Calculate the range of elements
//	int range = max_element - min_element + 1;
//
//	// Create and initialize the count array
//	int* count = new int[range] {0};
//
//	// Count the frequency of each element at the current position
//	for (int i = 0; i < nrOfElements; ++i)
//		++count[(elements[i] / exp) - (min_element / exp)];
//
//	// Perform prefix sum on count array
//	for (int i = 1; i < range; ++i)
//		count[i] += count[i - 1];
//
//	// Create a temporary array to store the sorted elements
//	T* tempArray = new T[nrOfElements];
//	printArray(elements, nrOfElements);
//	// Rearrange the elements based on the count array
//	for (int i = nrOfElements - 1; i >= 0; --i) {
//		tempArray[--count[(elements[i] / exp) - (min_element / exp)]] = elements[i];
//	}
//	printArray(elements, nrOfElements);
//
//	// Copy the sorted elements back to the original array
//	for (int i = 0; i < nrOfElements; ++i) {
//		elements[i] = tempArray[i];
//	}
//	printArray(elements, nrOfElements);
//
//	// Free dynamically allocated memory
//	delete[] count;
//	delete[] tempArray;
//}
//
//
//template <typename T>
//void RadixsortCounting(T elements[], int nrOfElements) {
//	// Find the maximum element to determine the number of digits
//	T max_element = *std::max_element(elements, elements + nrOfElements); // Use std::max_element
//
//	cout << "----------" << endl;
//	// Do counting sort for every digit (from least significant to most significant)
//	for (int exp = 1; max_element / exp > 0; exp = 10) {
//		CountingSort(elements, nrOfElements, exp);
//		// print the list
//		for (int i = 0; i < nrOfElements; i++) {
//			cout << elements[i] << " ";
//		}
//
//		cout << endl;
//	}
//}
//
//
//template <typename T>
//void heapify(T arr[], int nrOf, int i) {
//	int largest = i;
//	int l = 2 * i + 1;
//	int r = 2 * i + 2;
//
//	if (l< nrOf && arr[l] > arr[largest]) {
//		largest = l;
//	}
//	if (r< nrOf && arr[r] > arr[largest]) {
//		largest = r;
//	}
//	if (largest != i) {
//		T temp = arr[i];
//		arr[i] = arr[largest];
//		arr[largest] = temp;
//
//		heapify(arr, nrOf, largest);
//	}
//}
//
//template <typename T>
//void heapSort(T arr[], int nrOf) {
//	for (int i = nrOf / 2 - 1; i >= 0; i--) {
//		heapify(arr, nrOf, i);
//	}
//	for (int i = nrOf - 1; i >= 0; i--) {
//		T temp = arr[i];
//		arr[i] = arr[0];
//		arr[0] = temp;
//
//		heapify(arr, i, 0);
//	}
//}
//
//
//template <typename T>
//void merge(T arr[], int startIndex, int midIndex, int endIndex) {
//	T* tempArray = new T[endIndex - startIndex + 1];
//	int left = startIndex;
//	int right = midIndex + 1;
//	int index = 0;
//	while (left <= midIndex && right <= endIndex) {
//		if (arr[left] > arr[right]) {
//			tempArray[index++] = arr[right++];
//		} else {
//			tempArray[index++] = arr[left++];
//		}
//	}
//	while (left <= midIndex) {
//		tempArray[index++] = arr[left++];
//	}
//	while (right <= endIndex) {
//		tempArray[index++] = arr[right++];
//	}
//	for (int i = 0; i < endIndex - startIndex + 1; i++) {
//		arr[startIndex + i] = tempArray[i];
//	}
//	delete[] tempArray;
//}
//
//template <typename T>
//void mergeSort(T arr[], int startIndex, int endIndex) {
//	if (startIndex < endIndex) {
//		int midIndex = (startIndex + endIndex) / 2;
//		mergeSort(arr, startIndex, midIndex);
//		mergeSort(arr, midIndex + 1, endIndex);
//		merge(arr, startIndex, midIndex, endIndex);
//	}
//}
//
//template <typename T>
//void mergeSort(T arr[], int nrOf) {
//	mergeSort(arr, 0, nrOf - 1);
//}
//template <typename T>
//int partition(T arr[], int startIndex, int endIndex) {
//	T pivot = arr[endIndex];
//	int wall = startIndex - 1;
//	for (int i = startIndex; i < endIndex; i++) {
//		if (arr[i] < pivot) {
//			wall++;
//			T temp = arr[wall];
//			arr[wall] = arr[i];
//			arr[i] = temp;
//		}
//	}
//	arr[endIndex] = arr[wall + 1];
//	arr[wall + 1] = pivot;
//	return wall + 1;
//}
//
//
////template <typename T>
////void quickSort(T arr[], int startIndex, int endIndex) {
////    if (startIndex < endIndex) {
////        int pivot = partition(arr, startIndex, endIndex);
////        quickSort(arr, startIndex, pivot - 1);
////        quickSort(arr, pivot + 1, endIndex);
////    }
////}
//
//
////template <typename T>
////void quickSort(T arr[], int nrOf) {
////    quickSort(arr, 0, nrOf - 1);
////}
