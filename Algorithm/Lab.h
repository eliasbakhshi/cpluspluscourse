#ifndef LAB_H
#define LAB_H

template <typename T>
void insertionSort(T arr[], int nrOf) {
    for (int i = 1; i < nrOf; i++) {
        T key = arr[i];
        int j = i;

        while (j > 0 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key;
    }
}

template <typename T>
void selectionSort(T arr[], int nrOf) {
    for (int i = 0; i < nrOf - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < nrOf; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            T temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
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
    while (left < right) {
        int mid = (right + left) / 2;
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

#endif