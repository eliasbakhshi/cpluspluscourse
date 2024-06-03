#ifndef LAB_A3_HHP
#define LAB_A3_HHP

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;


/*
You are allowed to add more function templates to handle
separate sub-tasks

Tip1: the function std::max_element(...) in standard library algorithm could be usefull in countingsort

Example:
int a[5]{4, -3, 5, 7, 1}

st::cout << *std::max_element(a, a+5);

will result in the output 7

Tip2: It is ok to use the template vector for the buckets (lists)

*/

template <typename T>
void Countingsort(T elements[], int nrOfElements) {
	// Find the maximum value in the array
	//T maxvalue = *max_element(elements, elements + nrOfElements);

    T maxvalue = 0;
    for (int i = 0; i < nrOfElements; i++) {
        if (maxvalue < elements[i]) {
            maxvalue = elements[i];
        }
    }

	// Allocate count (temprary) array dynamically
	int* count = new int[maxvalue + 1] {0};

	// Count the occurrences of each element in the array
	for (int i = 0; i < nrOfElements; i++) {
		count[elements[i]]++;
	}

	// Reconstruct the sorted array using the count array
	int index = 0;
	for (int i = 0; i <= maxvalue; i++) {
		while (count[i] > 0) {
			elements[index++] = i;
			count[i]--;
		}
	}

	// Deallocate dynamically allocated memory
	delete[] count;
}


template<typename T>
void CountingSortForRadix(T elements[], int nrOfElements, int exp) {
    const int maxvalue = 10; // for digits 0 to 9
    int count[maxvalue] = { 0 };

    // Count the occurrences of each digit
    for (int i = 0; i < nrOfElements; i++) {
        count[(elements[i] / exp) % 10]++;
    }

    // Modify count[i] so that count[i] now contains actual
    // position of this digit in output[]
    for (int i = 1; i < maxvalue; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    T* output = new T[nrOfElements];
    for (int i = nrOfElements - 1; i >= 0; i--) {
        output[count[(elements[i] / exp) % 10] - 1] = elements[i];
        count[(elements[i] / exp) % 10]--;
    }

    // Copy the output array to elements[]
    for (int i = 0; i < nrOfElements; i++) {
        elements[i] = output[i];
    }

    // Free dynamically allocated memory
    delete[] output;
}

template<typename T>
void RadixsortCounting(T elements[], int nrOfElements) {
    // Find the maximum element to know the number of digits
    T maxElement = *max_element(elements, elements + nrOfElements);

    // Perform counting sort for every digit, starting from the least significant digit
    for (int exp = 1; maxElement / exp > 0; exp *= 10) {
        CountingSortForRadix(elements, nrOfElements, exp);
    }
}


template<typename T>
void RadixsortBuckets(T elements[], int nrOfElements) {
    // Find the maximum element to know the number of digits
    T maxElement = *max_element(elements, elements + nrOfElements);
    int exp = 1;

    // Initialize array of vectors (buckets)
    vector<T> buckets[10]; // 10 buckets for digits 0 to 9

    // Perform bucket sort for every digit, starting from the least significant digit
    while (maxElement / exp > 0) {
        // Distribute elements into buckets
        for (int i = 0; i < nrOfElements; i++) {
            int bucketIndex = (elements[i] / exp) % 10;
            buckets[bucketIndex].push_back(elements[i]);
        }

        // Concatenate elements from buckets back into the original array
        int index = 0;
        for (int i = 0; i < 10; i++) { // Iterate over all buckets
            for (T element : buckets[i]) {
                elements[index++] = element;
            }
            buckets[i].clear(); // Clear the bucket for the next iteration
        }

        exp *= 10; // Move to the next digit position
    }
}

#endif