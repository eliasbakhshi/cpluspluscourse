#ifndef LAB_A_H
#define LAB_A_H

#include <iostream>

using namespace std;

template<typename T>
void swapIt(T& from, T& to) {
	T temp = from;
	from = to;
	to = temp;
}

template <typename T>
void insertionSort(T arr[], int nrOf) {
	for (int i = 1; i < nrOf; i++) {
		int index = i;
		T value = arr[i];
		while (index > 0 && arr[index - 1] > value) {
			arr[index] = arr[index - 1];
			index--;
		}
		arr[index] = value;
	}
}

template <typename T>
void selectionSort(T arr[], int nrOf) {
	for (int i = 0; i < nrOf - 1; i++) {
		int lowest = i;
		for (int j = i + 1; j < nrOf; j++) {
			if (arr[lowest] > arr[j]) {
				lowest = j;
			}
		}
		if (lowest != i) {
			swapIt(arr[i], arr[lowest]);
		}
	}
}

template <typename T>
int linearSearch(T arr[], int nrOf, T toFind) {
	for (int i = 0; i < nrOf; i++) {
		if (arr[i] == toFind) {
			return i;
		}
	}
	return -1; // Element not found
}

template <typename T>
int binarySearch(T arr[], int nrOf, T toFind) {
	int left = 0;
	int right = nrOf - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] == toFind) {
			return mid;
		}
		if (arr[mid] < toFind) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	return -1;
}



template <typename T>
int linearSearchRecursive(T arr[], int endIndex, T toFind) {
	if (endIndex < 0) {
		return -1;
	}
	if (arr[endIndex] == toFind) {
		return endIndex;
	}
	return linearSearchRecursive(arr, endIndex - 1, toFind);
}

template <typename T>
int binarySearchRec(T arr[], int startIndex, int endIndex, T toFind) {
	if (startIndex >= endIndex) {
		return -1; // Element not found
	}
	int mid = (endIndex + startIndex) / 2;
	if (arr[mid] == toFind) {
		return mid;
	}
	if (arr[mid] < toFind) {
		return binarySearchRec(arr, mid + 1, endIndex, toFind);
	} else {
		return binarySearchRec(arr, startIndex, mid - 1, toFind);
	}
}

template <typename T>
void insertionSortWithBinarySearch(T arr[], int nrOf) {
	for (int i = 1; i < nrOf; i++) {
		T key = arr[i];
		int j = i - 1;

		int pos = binarySearch(arr, i, key);
		if (pos < 0) {
			pos = -(pos + 1);
		}
		while (j >= pos) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

// quicksort implementerad 
template <typename T>
void quickSort(T arr[], int start, int end) {
	if (start < end) {
		int pivotIndex = partition(arr, start, end);
		Quicksort(arr, start, pivotIndex - 1);
		Quicksort(arr, pivotIndex + 1, end);
	}
}

template <typename T>
int partition(T arr[], int start, int end) {
	T pivot = arr[end];
	int temp = start - 1;
	for (int i = start; i < end - 1; i++) {
		if (arr[i] <= pivot) {
			temp++;
			std::swap(arr[i], arr[temp]);
		}
	}
	std::swap(arr[temp + 1], arr[end]);
	return temp + 1;
}

template <typename T>
void merge(T arr[], int start, int mid, int end) {
	T* tempArray = new T[end - start + 1];
	int leftIndex = start;
	int rightIndex = mid + 1;
	int index = 0;

	while (leftIndex <= mid && rightIndex <= end) {
		if (arr[leftIndex] < arr[rightIndex]) {
			tempArray[index++] = arr[leftIndex++];
		} else {
			tempArray[index++] = arr[rightIndex++];
		}
	}

	while (leftIndex <= mid) {
		tempArray[index++] = arr[leftIndex++];
	}
	while (rightIndex <= end) {
		tempArray[index++] = arr[rightIndex++];
	}

	for (int i = 0; i < end - start + 1; i++) {
		arr[start + i] = tempArray[i];
	}
	delete[] tempArray;
}

template <typename T>
void mergesort(T arr[], int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		mergesort(arr, start, mid);
		mergesort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
}

template <typename T>
void heapify(T arr[], int n, int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest])
		largest = left;

	if (right < n && arr[right] > arr[largest])
		largest = right;

	if (largest != i) {
		std::swap(arr[i], arr[largest]);
		heapify(arr, n, largest);  // Call heapify recursively
	}
}

template <typename T>
void heapSort(T arr[], int nr) {
	// Build heap (rearrange array)
	for (int i = nr / 2 - 1; i >= 0; i--)
		heapify(arr, nr, i);

	// One by one extract an element from heap
	for (int i = nr - 1; i > 0; i--) {
		std::swap(arr[0], arr[i]);  // Move current root to end
		heapify(arr, i, 0);  // Call max heapify on the reduced heap
	}
}
#endif
