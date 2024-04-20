#pragma once
#include <iostream>

using namespace std;

void printArray(int array[], int size) {
	int i;
	for (i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << endl;
}

template<typename T>
void swapIt(T& from, T& to) {
	T temp = from;
	from = to;
	to = temp;
}

template <typename T>
void insertionSort2(T arr[], int nOf) {
	for (int i = 1; i < nOf; i++) {
		T value = arr[i];
		int j = i;

		while (j > 0 && arr[j - 1] > value) {
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = value;
	}
}

template<typename T>
void selectionSort2(T arr[], int length) {
	int i, j, minIndex;
	for (i = 0; i < length - 1; i++) {
		minIndex = i;
		for (j = i + 1; j < length; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		if (minIndex != i) {
			swapIt(arr[minIndex], arr[i]);
		}
	}
}

template<typename T>
int linearSearch2(T arr[], int length, T toFind) {
	for (int i = 0; i < length - 1; i++) {
		cout << i << endl;
		if (arr[i] == toFind) return i;
	}
	return -1;
}

template<typename T>
int binarySearch2(T arr[], int nOf, T toFind) {
	int left = 0;
	int right = nOf - 1;

	while (left < right) {
		int mid = (right - left) / 2;
		if (arr[mid] == toFind) {
			return mid;
		} else if (toFind > arr[mid]) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	return -1;
}

template<typename T>
int linearSearchRerc2(T arr[], int nOf, T toFind) {
	cout << nOf << endl;
	if (nOf < 0) {
		return -1;
	}
	if (arr[nOf] == toFind) {
		return nOf;
	}
	return linearSearchRerc2(arr, nOf - 1, toFind);
}

template<typename T>
int binarySearchRec2(T arr[], int left, int right, T toFind) {
	cout << left << endl;
	if (left <= right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] == toFind) {
			return mid;
		}
		if (arr[mid] < toFind)
			return binarySearchRec2(arr, mid + 1, right, toFind);
		return binarySearchRec2(arr, left, mid - 1, toFind);
	}
	return -1;
}

template<typename T>
void partition2(T arr[], int start, int end) {
	T pivot = arr[end];
	int i = start;
	for (int j = start; j < end - 1; j++) {
		if (arr[i] <= arr[j]) {
			swapIt(arr[i], arr[j]);
			i++;
		}
	}
	swapIt(arr[i + 1], arr[end]);
}




// function to swap elements
void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

// function to rearrange array (find the partition point)
template<typename T>

int partition3(T arr[], int startIndex, int endIndex) {
	T pivot = arr[endIndex];
	int wall = startIndex - 1;
	for (int i = startIndex; i < endIndex; i++) {
		if (arr[i] < pivot) {
			wall++;
			T temp = arr[wall];
			arr[wall] = arr[i];
			arr[i] = temp;
		}
	}
	arr[endIndex] = arr[wall + 1];
	arr[wall + 1] = pivot;
	return wall + 1;
}
