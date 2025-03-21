#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <iostream>
#include <exception>
#include "DisjointSetsTeacher.hpp"
#include <utility>
#include <vector>
#include <climits>
#include <tuple>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

template<typename T>
void swapIt(T& from, T& to) {
	T temp = to;
	to = from;
	from = temp;
}

template <typename T>
void insertionSort(T arr[], int nrOf) {
	for (int i = 0; i < nrOf; i++) {
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
			swapIt(arr[lowest], arr[i]);
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
	return -1;
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
void quickSortHelper(T arr[], int start, int end) {
	if (start < end) {
		T pivot = arr[end];
		int lower = start - 1;

		for (int i = start; i < end; i++) {
			if (arr[i] < pivot) {
				lower++;
				swapIt(arr[i], arr[lower]);
			}
		}
		swapIt(arr[lower + 1], pivot);
		int pivotIndex =  lower + 1;

		quickSortHelper(arr, start, pivotIndex - 1);
		quickSortHelper(arr, pivotIndex + 1, end);
	}
}


template <typename T>
void quickSortHelper(T arr[], int start, int end) {
	if (start < end) {
		T pivot = arr[end];
		int lower = start - 1;

		for (int i = start; i < end; i++) {
			if (arr[i] <= pivot) {
				lower++;
				swapIt(arr[i], arr[lower]);
			}
		}
		swapIt(arr[lower + 1], arr[end]);
		int pivotIndex = lower + 1;

		quickSortHelper(arr, start, pivotIndex - 1);
		quickSortHelper(arr, pivotIndex + 1, end);
	}
}

template <typename T>
void quickSort(T arr[], int nrOf) {
	quickSortHelper(arr, 0, nrOf - 1);
}

template <typename T>
void heapify(T arr[], int n, int i) {
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[largest]) {
		largest = l;
	}
	if (r < n && arr[r] > arr[largest]) {
		largest = r;
	}
	if (largest != i) {
		swapIt(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

template <typename T>
void heapSort(T arr[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(arr, n, i);
	}
	for (int i = n - 1; i > 0; i--) {
		swapIt(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
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
void Countingsort(T elements[], int nrOfElements) {
	T maxValue = elements[0];
	for (int i = 0; i < nrOfElements; i++) {
		if (maxValue < elements[i]) {
			maxValue = elements[i];
		}
	}

	int* count = new int[maxValue + 1] {0};

	for (int i = 0; i < nrOfElements; i++) {
		count[elements[i]]++;
	}

	int index = 0;
	for (int i = 0; i <= maxValue; i++) {
		while (count[i] > 0) {
			elements[index++] = i;
			count[i]--;
		}
	}

	delete[] count;
}




//
//const int INFINIT_COST = INT_MAX;
//
//template <class T>
//class Graph {
//	class Edge {
//	public:
//		T fromVertex;
//		T toVertex;
//		int weight;
//		Edge() {}
//		Edge(T fromVertex, T toVertex, int weight) : fromVertex(fromVertex), toVertex(toVertex), weight(weight) {}
//		bool operator<(const Edge& other) const { return weight < other.weight; }
//		bool operator>(const Edge& other) const { return weight > other.weight; }
//		bool operator<=(const Edge& other) const { return weight <= other.weight; }
//		bool operator>=(const Edge& other) const { return weight >= other.weight; }
//		bool operator==(const Edge& other) const { return fromVertex == other.fromVertex && toVertex != other.toVertex; }
//		bool operator!=(const Edge& other) const { return fromVertex != other.fromVertex || toVertex != other.toVertex; }
//	};
//
//	unordered_map<T, int> vertMap;
//	vector<vector<Edge>> edgeLists;
//
//public:
//	Graph();
//	virtual ~Graph() = default;
//	Graph(const Graph& other) = delete;
//	Graph& operator=(const Graph& other) = delete;
//	void addVertex(T theNode);
//	void addEdge(T from, T to, int weight = 0);
//	vector<T> getAllNeighboursTo(T vertex);
//	int getNrOfVertices() const;
//	int getNrOfEdges() const;
//	void kruskals(vector<tuple<T, T, int>>& mst, int& totalCost);
//	void prims(vector<tuple<T, T, int>>& mst, int& totalCost);
//	////void readFromFile(string file);
//	//string depthFirstSearchHelper(T vertex, unordered_set<T>& visited);
//	//string depthFirstSearch(T from);
//	//string breadthFirstSearch(T from);
//};
//
//
//template<class T>
//inline Graph<T>::Graph() {}
//
//template<class T>
//inline void Graph<T>::addVertex(T theNode) {
//	if (vertMap.count(theNode) > 0) {
//		throw exception("Exception: vertex already exists.");
//	}
//	vertMap[theNode] = (int)vertMap.size();
//	edgeLists.push_back(vector<Edge>());
//}
//
//template<class T>
//inline void Graph<T>::addEdge(T from, T to, int weight) {
//	if (vertMap.count(from) == 0) {
//		addVertex(from);
//	}
//	if (vertMap.count(to) == 0) {
//		addVertex(to);
//	}
//	edgeLists[vertMap[from]].push_back(Edge(from, to, weight));
//	edgeLists[vertMap[to]].push_back(Edge(to, from, weight));
//}
//
//template<class T>
//inline vector<T> Graph<T>::getAllNeighboursTo(T vertex) {
//	if (vertMap.count(vertex) == 0) {
//		throw exception("Error: No vertex of that kind inputted");
//	}
//	vector<T> neighbours;
//	for (int i = 0; i < edgeLists[vertMap[vertex]].size(); i++) {
//		neighbours.push_back(edgeLists[vertMap[vertex]][i].toVertex);
//	}
//	sort(neighbours.begin(), neighbours.end());
//	return neighbours;
//}
//
//
//
//template<class T>
//inline int Graph<T>::getNrOfVertices() const {
//	return (int)vertMap.size();
//}
//
//template<class T>
//inline int Graph<T>::getNrOfEdges() const {
//	int size = 0;
//	for (int i = 0; i < edgeLists.size(); i++) {
//		size += (int)edgeLists[i].size();
//	}
//	return size;
//}
//
//template<class T>
//inline void Graph<T>::prims(vector<tuple<T, T, int>>& mst, int& totalCost) {
//	priority_queue < Edge, vector<Edge>, greater<Edge>> pq;
//	unordered_set<T> visited;
//
//	T startPoint = vertMap.begin()->first;
//	visited.insert(startPoint);
//	totalCost = 0;
//
//	for (const auto& edge : edgeLists[vertMap[startPoint]]) {
//		pq.push(edge);
//	}
//
//	while (!pq.empty()) {
//		Edge currentEdge = pq.top();
//		pq.pop();
//		if (visited.count(currentEdge.toVertex) > 0) {
//			continue;
//		}
//
//		mst.push_back({ currentEdge.fromVertex, currentEdge.toVertex, currentEdge.weight });
//		totalCost += currentEdge.weight;
//		visited.insert(currentEdge.toVertex);
//
//		for (const auto & edge : edgeLists[vertMap[currentEdge.toVertex]]) {
//			if (visited.count(edge.toVertex) == 0) {
//				pq.push(edge);
//			}
//		}
//	}
//}
//
//template<class T>
//inline void Graph<T>::kruskals(vector<tuple<T, T, int>>& mst, int& totalCost) {
//	DisjointSets<T> disSet;
//	for (const auto & vert : vertMap) {
//		disSet.makeSet(vert.first);
//	}
//
//	vector<Edge> alla;
//	for (const auto& edges : edgeLists) {
//		for (const auto & edge : edges) {
//			alla.push_back(edge);
//		}
//	}
//	sort(alla.begin(), alla.end());
//	totalCost = 0;
//	
//	for (const auto & edge: alla) {
//		if (disSet.findSet(edge.fromVertex) != disSet.findSet(edge.toVertex)) {
//			mst.push_back({ edge.fromVertex, edge.toVertex, edge.weight });
//			totalCost += edge.weight;
//			disSet.unionSet(edge.fromVertex, edge.toVertex);
//		}
//	}
//}



#endif


//int main() {
//	BST<int> bst;
//
//	bst.insert(55);
//
//	cout << bst.toGraphviz() << endl;
//
//	return 0;
//}




//
//#ifndef HEAP_HPP
//#define HEAP_HPP
//
//#include <stdexcept>
//
//template <class T>
//class Heap {
//private:
//	int capacity;
//	int nrOfElements;
//	T* elements;
//	void expand();
//public:
//	Heap(int initialCapacity = 10);
//	~Heap();
//	Heap(const Heap& other) = delete;
//	Heap& operator=(const Heap& other) = delete;
//
//	int size() const;
//	bool is_empty() const;
//	void insert(const T& element);
//	T extractMax();
//	T getMax() const;
//};
//
//#endif
//
//
//template <class T>
//Heap<T>::Heap(int initialCapacity) : capacity(initialCapacity), nrOfElements(0), elements(new T[initialCapacity]) {}
//
//template <class T>
//Heap<T>::~Heap() {
//	delete[] elements;
//}
//
//template <class T>
//void Heap<T>::expand() {
//	int tempCapacity = capacity * 2;
//	T* tempElements = new T[tempCapacity];
//	for (int i = 0; i < capacity; i++) {
//		tempElements[i] = elements[i];
//	}
//	delete[] elements;
//	elements = tempElements;
//	capacity = tempCapacity;
//}
//
//template <class T>
//int Heap<T>::size() const {
//	return nrOfElements;
//}
//
//template <class T>
//bool Heap<T>::is_empty() const {
//	return nrOfElements == 0;
//}
//
//template <class T>
//void Heap<T>::insert(const T& element) {
//	if (nrOfElements == capacity) {
//		expand();
//	}
//	elements[nrOfElements++] = element;
//	int index = nrOfElements - 1;
//	while (index < 0 && elements[index] < elements[(index - 1) / 2]) {
//		std::swap(elements[index], elements[(index - 1) / 2]);
//		index = (index - 1) / 2;
//	}
//}
//
//template <class T>
//T Heap<T>::extractMax() {
//	if (is_empty()) {
//		throw std::exception("Exception: list is empty.");
//	}
//
//	T maxElement = elements[0];
//
//	elements[0] = elements[--nrOfElements];
//	int index = 0;
//	while (true) {
//		int leftchild = index * 2 + 1;
//		int rightchild = index * 2 + 2;
//		int largest = index;
//		if (leftchild < nrOfElements && elements[leftchild] > elements[largest]) {
//			largest = leftchild;
//		}
//		if (rightchild < nrOfElements && elements[rightchild] > elements[largest]) {
//			largest = rightchild;
//		}
//		if (index != largest) {
//			elements[index] = elements[largest];
//			index = largest;
//		} else {
//			break;
//		}
//	}
//	return maxElement;
//}
//
//template <class T>
//T Heap<T>::getMax() const {
//	if (is_empty()) {
//		throw std::exception("Exception: list is empty.");
//	}
//	return elements[0];
//}



//
//#ifndef ORDEREDLIST_HPP
//#define ORDEREDLIST_HPP
//
//#include <stdexcept>
//
//template <class T>
//class OrderedList {
//private:
//	struct Node {
//		T data;
//		Node* next;
//
//		Node(const T& value) : data(value), next(nullptr) {}
//	};
//
//	Node* front;
//	int num_elements;
//
//public:
//	OrderedList();
//	~OrderedList();
//	OrderedList(const OrderedList& other) = delete;
//	OrderedList& operator=(const OrderedList& other) = delete;
//
//	int size() const;
//	bool is_empty() const;
//	void add(const T& element);
//	T remove(const T& element);
//	T removeAt(int index);
//	T removeFirst();
//	T removeLast();
//	T get(const T& element) const;
//	T first() const;
//	T last() const;
//};
//
//#endif
//
//
//template <class T>
//OrderedList<T>::OrderedList() : front(nullptr), num_elements(0) {}
//
//template <class T>
//OrderedList<T>::~OrderedList() {
//	while (front != nullptr) {
//		Node* toDelete = front;
//		front = front->next;
//		delete toDelete;
//	}
//}
//
//template <class T>
//int OrderedList<T>::size() const {
//	return num_elements;
//}
//
//template <class T>
//bool OrderedList<T>::is_empty() const {
//	return num_elements == 0;
//}
//
//template <class T>
//void OrderedList<T>::add(const T& element) {
//	Node* temp = new Node(element);
//	if (is_empty() || front->data > element) {
//		temp->next = front;
//		front = temp;
//	} else {
//		Node* walker = front;
//		while (walker->next != nullptr && walker->next->data < element) {
//			walker = walker->next;
//		}
//		temp->next = walker->next;
//		walker->next = temp;
//	}
//	num_elements++;
//}
//
//template <class T>
//T OrderedList<T>::remove(const T& element) {
//	if (is_empty()) {
//		throw std::exception("Exception: remove() called on an empty list.");
//	}
//	if (element == front->data) {
//		return removeFirst();
//	}
//	Node* walker = front;
//	while (walker->next != nullptr && walker->next->data != element) {
//		walker = walker->next;
//	}
//	if (walker->next == nullptr) {
//		throw std::exception("Exception: element not found.");
//	}
//	Node* toDelete = walker->next;
//	T data = toDelete->data;
//	walker->next = toDelete->next;
//	delete toDelete;
//	num_elements--;
//	return data;
//}
//
//template <class T>
//T OrderedList<T>::removeAt(int index) {
//	if (index < 0 || index >= num_elements) {
//		throw std::exception("Exception: Called removeAt() and it is out of range");
//	}
//	if (index == 0) {
//		return removeFirst();
//	}
//	Node* walker = front;
//	for (int i = 0; i < index - 1; i++) {
//		walker = walker->next;
//	}
//	T data = walker->data;
//	Node* toDelete = walker->next;
//	walker->next = toDelete->next;
//	delete toDelete;
//	num_elements--;
//	return data;
//}
//
//template <class T>
//T OrderedList<T>::removeFirst() {
//	if (is_empty()) {
//		throw std::exception("Exception: removeFirst() called on an empty list.");
//	}
//	Node* toDelete = front;
//	front = front->next;
//	T data = toDelete->data;
//	delete toDelete;
//	num_elements--;
//	return data;
//}
//
//template <class T>
//T OrderedList<T>::removeLast() {
//	if (is_empty()) {
//		throw std::exception("Exception: removeFirst() called on an empty list.");
//	}
//	if (num_elements == 1) {
//		return removeFirst();
//	}
//	Node* walker = front;
//	while (walker->next->next != nullptr) {
//		walker = walker->next;
//	}
//
//	T data = walker->next->data;
//	delete walker->next;
//	walker->next = nullptr;
//	num_elements--;
//	return data;
//}
//
//template <class T>
//T OrderedList<T>::get(const T& element) const {
//	if (is_empty()) {
//		throw std::exception("Exception: get() called on an empty list.");
//	}
//	Node* walker = front;
//	while (walker != nullptr) {
//		if (walker->data == element) {
//			return walker->data;
//		}
//		walker = walker->next;
//	}
//	throw std::exception("Exception: element not found.");
//}
//
//template <class T>
//T OrderedList<T>::first() const {
//	if (is_empty()) {
//		throw std::exception("Exception: first() called on an empty list.");
//	}
//	return front->data;
//}
//
//template <class T>
//T OrderedList<T>::last() const {
//	if (is_empty()) {
//		throw std::exception("Exception: first() called on an empty list.");
//	}
//	Node* walker = front;
//	while (walker->next != nullptr) {
//		walker = walker->next;
//	}
//	return walker->data;
//}


//
//#ifndef INDEXEDLIST_HPP
//#define INDEXEDLIST_HPP
//
//#include <stdexcept>
//
//template <class T>
//class IndexedList {
//private:
//	class Node {
//	public:
//		T data;
//		Node* next;
//
//		Node(T data = nullptr) : data(data), next(nullptr) {}
//	};
//	Node* front;
//	int num_elements;
//public:
//	IndexedList();
//	~IndexedList();
//	IndexedList(const IndexedList& other) = delete;
//	IndexedList& operator=(const IndexedList& other) = delete;
//
//	int size() const;
//	bool is_empty() const;
//	T getAt(int index) const;
//	void addAt(int index, const T& element);
//	T removeFirst();
//	T removeAt(int index);
//	T removeLast();
//	T first() const;
//	T last() const;
//};
//
//#endif
//
//template<class T>
//IndexedList<T>::IndexedList() : first(nullptr), num_elements(0) {
//
//}
//
//template <class T>
//IndexedList<T>::~IndexedList() {
//	while (front != nullptr) {
//		Node* temp = front;
//		front = front->next;
//		delete temp;
//	}
//}
//
//template <class T>
//int IndexedList<T>::size() const {
//	return num_elements;
//}
//
//template <class T>
//bool IndexedList<T>::is_empty() const {
//	return num_elements == 0;
//}
//
//template <class T>
//T IndexedList<T>::getAt(int index) const {
//	if (index < 0 || index >= num_elements) {
//		throw std::exception("Exception: getAt() on an empty array.");
//	}
//	if (index == 0) {
//		return front->data;
//	} else {
//		Node* temp = front;
//		for (int i = 0; i < index - 1; i++) {
//			temp = temp->next;
//		}
//		return temp->data;
//	}
//}
//
//template <class T>
//void IndexedList<T>::addAt(int index, const T& element) {
//	if (index < 0 || index > num_elements) {
//		throw std::out_of_range("Exception: addAt() called out of range.");
//	}
//	Node* temp = front;
//	if (index == 0) {
//		temp->next = front;
//		front = temp;
//	} else {
//		Node* walker = front;
//		for (int i = 0; i < index -1; i++) {
//			walker = walker->next;
//		}
//		temp->next = walker->next;
//		walker->next = temp;
//	}
//	num_elements++:
//}
//
//template <class T>
//T IndexedList<T>::removeFirst() {
//	if (is_empty()) {
//		throw std::exception("Exception: getAt() on an empty array.");
//	}
//	Node* toDelete = front;
//	front = front->next;
//	T data = toDelete->data;
//	delete toDelete;
//	num_elements--;
//	return data;
//}
//
//template <class T>
//T IndexedList<T>::removeAt(int index) {
//	if (index < 0 || index >= num_elements) {
//		throw std::out_of_range("Exception: removeAt() called out of range.");
//	}
//	T data;
//	if (index == 0) {
//		Node* toDelete = front;
//		front = front->next;
//		data = toDelete->data;
//		delete toDelete;
//	} else {
//		Node* walker = front;
//		for (int i = 0; i < index - 1; i++) {
//			walker = walker->next;
//		}
//		Node* toDelete = walker->next;
//		walker->next = toDelete->next;
//		data = toDelete->data;
//		delete toDelete;
//	}
//	num_elements--;
//	return data;
//}
//
//template <class T>
//T IndexedList<T>::removeLast() {
//	if (is_empty()) {
//		throw std::exception("Exception: getAt() on an empty array.");
//	}
//	if (num_elements == 1) {
//		return removeFirst();
//	}
//	Node* walker = front;
//	while (walker->next->next != nullptr) {
//		walker = walker->next;
//	}
//	Node* toDelete = walker->next;
//	walker->next = toDelete->next;
//	T data = toDelete->data;
//	delete toDelete;
//	num_elements--;
//	return data;
//}
//
//template <class T>
//T IndexedList<T>::first() const {
//	if (is_empty()) {
//		throw std::exception("Exception: Called first() on an empty list.");
//	}
//	return front->data;
//}
//
//template <class T>
//T IndexedList<T>::last() const {
//	if (is_empty()) {
//		throw std::exception("Exception: last() called on an empty array.");
//	}
//	Node* walker = front;
//	while (walker->next != nullptr) {
//		walker = walker->next;
//	}
//	return walker->data;
//}


//
//template <typename T>
//class OrderedList {
//	class Node {
//	public:
//		T data;
//		Node* next;
//		Node(const T& data) : data(data), next(nullptr) {};
//	};
//	Node* front;
//	int num_elements;
//
//public:
//    OrderedList();
//    ~OrderedList();
//    OrderedList(const OrderedList& other) = delete;
//    OrderedList& operator=(const OrderedList& other) = delete;
//
//    int size() const;
//    bool is_empty() const;
//    void add(const T& element);
//    T remove(const T& element);
//    T removeAt(int index);
//    T removeFirst();
//    T removeLast();
//    T get(const T& element) const;
//    T first() const;
//    T last() const;
//};
//
//
//template <class T>
//OrderedList<T>::OrderedList(): front(nullptr), num_elements(0) {}
//
//template <class T>
//OrderedList<T>::~OrderedList() {
//    while (front != nullptr) {
//        Node* temp = front;
//        front = front->next;
//        delete temp;
//    }
//}
//
//template <class T>
//int OrderedList<T>::size() const {
//    return num_elements;
//}
//
//template <class T>
//bool OrderedList<T>::is_empty() const {
//    return num_elements == 0;
//}
//
//template <class T>
//void OrderedList<T>::add(const T& element) {
//    Node* temp = new Node(element);
//    if (is_empty() || element < front->data) {
//        temp->next = front;
//        front = temp;
//    } else {
//        Node* walker = front;
//        while (walker->next != nullptr && walker->next->data < element) {
//            walker = walker->next;
//        }
//        temp->next = walker->next;
//        walker->next = temp;
//    }
//    num_elements++;
//}
//
//template <class T>
//T OrderedList<T>::remove(const T& element) {
//    if (is_empty()) {
//        throw std::exception("Exception: Called remove() on an empty list.");
//    }
//    if (element == front->data) {
//        return removeFirst();
//    }
//    Node* temp = front;
//    while (temp->next != nullptr && temp->next->data != element) {
//        temp = temp->next;
//    }
//    if (temp->next == nullptr) {
//        throw std::out_of_range("Exception: Could not find the element.");
//    }
//    Node* toDelete = temp->next;
//    T data = temp->data;
//    temp->next = toDelete->next;
//    delete toDelete;
//    num_elements--;
//    return data;
//}
//
//template <class T>
//T OrderedList<T>::removeAt(int index) {
//    if (index < 0 || index >= num_elements) {
//        throw std::out_of_range("Exception: Out of range.");
//    }
//    if (index == 0) {
//        return removeFirst();
//    }
//
//    Node* temp = first;
//    for (int i = 0; i < index - 1; i++) {
//        temp = temp->next;
//    }
//    Node* toDelete = temp->next;
//    temp->next = toDelete->next;
//    T data = toDelete->data;
//    delete toDelete;
//    num_elements--;
//    return data;
//}
//
//template <class T>
//T OrderedList<T>::removeFirst() {
//    if (is_empty()) {
//        throw std::exception("Exception: removeFirst() called on an empty list.");
//    }
//    Node* temp = front;
//    front = front->next;
//    T data = temp->data;
//    delete temp;
//    num_elements--;
//    return data;
//}
//
//template <class T>
//T OrderedList<T>::removeLast() {
//    if (is_empty()) {
//        throw std::exception("Exception: removeLast() called on an empty list.");
//    }
//    if (num_elements == 1) {
//        return removeFirst();
//    }
//    Node* temp = front;
//    while (temp->next->next != nullptr) {
//        temp = temp->next;
//    }
//    Node* toDelete = temp->next;
//    temp->next = nullptr;
//    T data = toDelete->data;
//    delete toDelete;
//    num_elements--;
//    return data;
//}
//
//template <class T>
//T OrderedList<T>::get(const T& element) const {
//    Node* temp = front;
//    while (temp != nullptr) {
//        if (temp->data == element) {
//            return temp->data;
//        }
//        temp = temp->next;
//    }
//    throw std::exception("Exception: Element not found.");
//}
//
//template <class T>
//T OrderedList<T>::first() const {
//    if (is_empty()) {
//        throw std::exception("Exception: first() called on an empty list.");
//    }
//    return front->data;
//}
//
//template <class T>
//T OrderedList<T>::last() const {
//    if (is_empty()) {
//        throw std::exception("Exception: first() called on an empty list.");
//    }
//    Node* temp = front;
//    while (temp->next != nullptr) {
//        temp = temp->next;
//    }
//    return temp->data;    
//}


//
//template <typename T>
//class Queue {
//	T* elements;
//	int capacity, head, tail, nrOfElements;
//	void expand();
//public:
//	Queue(int initCapacity = 10);
//	virtual ~Queue();
//	Queue(Queue& other) = delete;
//	Queue operator=(Queue& other) = delete;
//	void enqueue(const T& element);
//	T dequeue();
//	const T& peek() const;
//	bool is_empty() const;
//};
//
//template<typename T>
//Queue<T>::Queue(int initCapacity): elements(new T[initCapacity]), capacity(initCapacity), head(0), tail(0), nrOfElements(0) {}
//
//template<typename T>
//Queue<T>::~Queue() {
//	delete[] elements;
//}
//
//template<typename T>
//void Queue<T>::enqueue(const T& element) {
//	if (nrOfElements == capacity) {
//		expand();
//	}
//	elements[tail] = element;
//	tail = (tail + 1) % capacity;
//	nrOfElements++;
//}
//
//template<typename T>
//T Queue<T>::dequeue() {
//	if (is_empty()) {
//		throw std::exception("Exception: dequeue() on an empty queue.");
//	}
//	T data = elements[head];
//	head = (head + 1) % capacity;
//	nrOfElements--;
//	return data;
//}
//
//template<typename T>
//const T& Queue<T>::peek() const {
//	if (is_empty()) {
//		throw std::exception("Exception: peek() on an empty queue.");
//	}
//	return elements[head];
//}
//
//template<typename T>
//bool Queue<T>::is_empty() const {
//	return nrOfElements == 0;
//}
//
//template<typename T>
//void Queue<T>::expand() {
//	int tempCapacity = capacity * 2;
//	T* tempElements = new T[tempCapacity];
//	for (int i = 0; i < capacity; i++) {
//		tempElements[i] = elements[(head + 1) % capacity];
//	}
//	delete[] elements;
//	elements = tempElements;
//	capacity = tempCapacity;
//	head = 0;
//	tail = nrOfElements;
//}
//


//
//
//template <typename T>
//class Stack {
//	T* elements;
//	int capacity;
//	int top;
//	void expand();
//public:
//	Stack(int initCapacity = 10);
//	virtual ~Stack();
//	Stack(Stack& other) = delete;
//	Stack operator=(Stack& other) = delete;
//	void push(const T& element);
//	const T& peek() const;
//	T pop();
//	bool is_empty() const;
//};
//
//template<typename T>
//inline void Stack<T>::expand() {
//	int newCapacity = capacity * 2;
//	T* tempElements = new T[newCapacity];
//	for (int i = 0; i < capacity; i++) {
//		tempElements[i] = elements[i];
//	}
//	delete[] elements;
//	elements = tempElements;
//	capacity = newCapacity;
//}
//
//template<typename T>
//inline Stack<T>::Stack(int initCapacity) : elements(new T[initCapacity]), capacity(initCapacity), top(0) {}
//
//template<typename T>
//inline Stack<T>::~Stack() {
//	delete []elements;
//}
//
//
//template<typename T>
//inline void Stack<T>::push(const T & element) {
//	if (top == capacity) {
//		expand();
//	}
//	elements[top++] = element;
//}
//template<typename T>
//inline const T& Stack<T>::peek() const{
//	if (is_empty()) {
//		throw std::exception("Exception: peek() called on an empty array.");
//	}
//	return elements[top - 1];
//}
//
//template<typename T>
//inline T Stack<T>::pop() {
//	if (is_empty()) {
//		throw std::exception("Exception: peek() called on an empty array.");
//	}
//	return elements[--top];
//}
//
//template<typename T>
//inline bool Stack<T>::is_empty() const {
//	return top == 0;
//}
//


//template<typename T>
//class Queue {
//	class Node {
//	public:
//		T data;
//		Node* next;
//		Node(T data, Node* next = nullptr) : data(data), next(next) {}
//	};
//	Node* first;
//	Node* last;
//public:
//	Queue();
//	virtual ~Queue();
//	Queue(const Queue& other) = delete;
//	Queue& operator=(const Queue& other) = delete;
//	void enqueue(const T& element);
//	T dequeue();
//	const T& peek();
//	bool is_empty();
//
//};
//
//template<typename T>
//inline Queue<T>::Queue() : first(nullptr), last(nullptr) {}
//
//template<typename T>
//inline Queue<T>::~Queue() {
//	while (first != nullptr) {
//		Node* temp = first;
//		first = first->next;
//		delete temp;
//	}
//}
//
//template<typename T>
//inline void Queue<T>::enqueue(const T& element) {
//	Node* temp = new Node(element);
//	if (is_empty()) {
//		first = last = temp;
//	} else {
//		last->next = temp;
//		last = temp;
//	}
//}
//
//template<typename T>
//inline T Queue<T>::dequeue() {
//	if (is_empty()) {
//		throw std::exception("Exception: dequeue on an empty queue.");
//	}
//	Node* temp = first;
//	T data = first->data;
//	first = first->next;
//
//	if (first == nullptr) {
//		last = nullptr;
//	}
//	delete temp;
//	return data;
//}
//template<typename T>
//inline const T& Queue<T>::peek() {
//	if (is_empty()) {
//		throw std::exception("Exception: peek on an empty array.");
//	}
//	return first->data;
//}
//
//template<typename T>
//inline bool Queue<T>::is_empty() {
//	return first == nullptr;
//}


//void printArray(int array[], int size) {
//	int i;
//	for (i = 0; i < size; i++)
//		cout << array[i] << " ";
//	cout << endl;
//}
//
//template<typename T>
//void swapIt(T& from, T& to) {
//	T temp = from;
//	from = to;
//	to = temp;
//}
//
//template <typename T>
//void insertionSort2(T arr[], int nOf) {
//	for (int i = 1; i < nOf; i++) {
//		T value = arr[i];
//		int j = i;
//
//		while (j > 0 && arr[j - 1] > value) {
//			arr[j] = arr[j - 1];
//			j--;
//		}
//		arr[j] = value;
//	}
//}
//
//template<typename T>
//void selectionSort2(T arr[], int length) {
//	int i, j, minIndex;
//	for (i = 0; i < length - 1; i++) {
//		minIndex = i;
//		for (j = i + 1; j < length; j++) {
//			if (arr[j] < arr[minIndex]) {
//				minIndex = j;
//			}
//		}
//		if (minIndex != i) {
//			swapIt(arr[minIndex], arr[i]);
//		}
//	}
//}
//
//template<typename T>
//int linearSearch2(T arr[], int length, T toFind) {
//	for (int i = 0; i < length - 1; i++) {
//		cout << i << endl;
//		if (arr[i] == toFind) return i;
//	}
//	return -1;
//}
//
//template<typename T>
//int binarySearch2(T arr[], int nOf, T toFind) {
//	int left = 0;
//	int right = nOf - 1;
//
//	while (left < right) {
//		int mid = (right - left) / 2;
//		if (arr[mid] == toFind) {
//			return mid;
//		} else if (toFind > arr[mid]) {
//			left = mid + 1;
//		} else {
//			right = mid - 1;
//		}
//	}
//	return -1;
//}
//
//template<typename T>
//int linearSearchRerc2(T arr[], int nOf, T toFind) {
//	cout << nOf << endl;
//	if (nOf < 0) {
//		return -1;
//	}
//	if (arr[nOf] == toFind) {
//		return nOf;
//	}
//	return linearSearchRerc2(arr, nOf - 1, toFind);
//}
//
//template<typename T>
//int binarySearchRec2(T arr[], int left, int right, T toFind) {
//	cout << left << endl;
//	if (left <= right) {
//		int mid = left + (right - left) / 2;
//		if (arr[mid] == toFind) {
//			return mid;
//		}
//		if (arr[mid] < toFind)
//			return binarySearchRec2(arr, mid + 1, right, toFind);
//		return binarySearchRec2(arr, left, mid - 1, toFind);
//	}
//	return -1;
//}
//
//template<typename T>
//void partition2(T arr[], int start, int end) {
//	T pivot = arr[end];
//	int i = start;
//	for (int j = start; j < end - 1; j++) {
//		if (arr[i] <= arr[j]) {
//			swapIt(arr[i], arr[j]);
//			i++;
//		}
//	}
//	swapIt(arr[i + 1], arr[end]);
//}
//
//
//
//
//// function to swap elements
//void swap(int* a, int* b) {
//	int t = *a;
//	*a = *b;
//	*b = t;
//}
//
//// function to rearrange array (find the partition point)
//template<typename T>
//
//int partition3(T arr[], int startIndex, int endIndex) {
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
