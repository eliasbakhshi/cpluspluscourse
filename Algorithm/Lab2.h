#include <iostream>
#include <utility>

#ifndef LAB_A2_H
#define LAB_A2_H

template <typename T>
void quickSortHelper(T arr[], int low, int high) {
    if (low < high) {
        T pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        int pi = i + 1;

        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}

template <typename T>
void quickSort(T arr[], int nrOf) {
    quickSortHelper(arr, 0, nrOf - 1);
}

template<typename T>
void merge(T arr[], int startIndex, int midIndex, int endIndex) {
    int leftNrOf = midIndex - startIndex + 1;
    int rightNrOf = endIndex - midIndex;
    T* left = new T[leftNrOf];
    T* right = new T[rightNrOf];

    for (int i = 0; i < leftNrOf; ++i)
        left[i] = arr[startIndex + i];
    for (int i = 0; i < rightNrOf; ++i)
        right[i] = arr[midIndex + 1 + i];

    int i = startIndex, j = 0, k = 0;
    while (j < leftNrOf && k < rightNrOf) {
        if (left[j] <= right[k]) {
            arr[i] = left[j];
            ++j;
        } else {
            arr[i] = right[k];
            ++k;
        }
        ++i;
    }
    while (j < leftNrOf) {
        arr[i] = left[j];
        ++j;
        ++i;
    }
    while (k < rightNrOf) {
        arr[i] = right[k];
        ++k;
        ++i;
    }
}

template <typename T>
void mergeSortHelper(T arr[], int l, int r) {
    if (l < r) {
        int m = (r + l) / 2;
        mergeSortHelper(arr, l, m);
        mergeSortHelper(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

template <typename T>
void mergeSort(T arr[], int nrOf) {
    mergeSortHelper(arr, 0, nrOf - 1);
}

template <typename T>
void heapify(T arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

template <typename T>
void heapSort(T arr[], int nrOf) {
    for (int i = nrOf / 2 - 1; i >= 0; i--)
        heapify(arr, nrOf, i);

    for (int i = nrOf - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

#endif
