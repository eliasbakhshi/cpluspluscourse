#ifndef GRAPH_HPP
#define GRAPH_HPP
#include "DisjointSetsTeacher.hpp"
#include "MinPriorityQueueTeacher.hpp"
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

const int INFINIT_COST = INT_MAX;

template <class T>
class Graph {
private:
	class Edge {
	public:
		T fromVertex;
		T toVertex;
		int weight;
		Edge() {}
		Edge(T fromVertex, T toVertex, int weight = 0) :fromVertex(fromVertex), toVertex(toVertex), weight(weight) {}
		bool operator<(const Edge& other) const { return weight < other.weight; }
		bool operator>(const Edge& other) const { return weight > other.weight; }
		bool operator<=(const Edge& other) const { return weight <= other.weight; }
		bool operator>=(const Edge& other) const { return weight >= other.weight; }
		bool operator==(const Edge& other) const { return fromVertex == other.fromVertex && toVertex == other.toVertex; } // eventuelt även vikt
		bool operator!=(const Edge& other) const { return fromVertex != other.fromVertex && toVertex != other.toVertex; } //eventuelt äben vikt

	};

	unordered_map<T, int> vertMap;
	vector<vector<Edge>>edgeLists;
public:
	Graph();
	virtual ~Graph() = default;
	Graph(const Graph& other) = delete;
	Graph& operator=(const Graph& other) = delete;
	void addVertex(T theNode);
	void addEdge(T from, T to, int weight = 0);
	vector<T> getAllNeighboursTo(T vertex);
	int getNrOfVertices() const;
	int getNrOfEdges() const;
	void kruskals(vector<tuple<T, T, int>>& mst, int& totalCost);
	void prims(vector<tuple<T, T, int>>& mst, int& totalCost);
	//void readFromFile(string file);
	//string depthFirstSearchHelper(T vertex, unordered_set<T>& visited);
	string depthFirstSearch(T from);
	string breadthFirstSearch(T from);
};


#endif

template<class T>
inline Graph<T>::Graph() {}

template<class T>
inline void Graph<T>::addVertex(T theNode) {
	// undantag ska kastas om noden redan finns
	if (vertMap.count(theNode) > 0) {
		throw exception("Error: call addVertexNot okay node already exisits");
	}
	vertMap[theNode] = (int)vertMap.size();
	edgeLists.push_back(vector<Edge>());
}

template<class T>
inline void Graph<T>::addEdge(T from, T to, int weight) {
	// om någon av noderna inte finns i vertMap ska den/de läggas till
	if (vertMap.count(from) == 0) {
		addVertex(from);
	}
	if (vertMap.count(to) == 0) {
		addVertex(to);
	}
	edgeLists[vertMap[from]].push_back(Edge(from, to, weight));
	edgeLists[vertMap[to]].push_back(Edge(to, from, weight));
}

template<class T>
inline vector<T> Graph<T>::getAllNeighboursTo(T vertex) {
	// undantag om vertexen inte finns;
	if (vertMap.count(vertex) == 0) {
		throw exception("Error: No vertex of that kind inputted");
	}
	vector<T>neighbours;
	int place = vertMap[vertex];
	for (int i = 0; i < edgeLists[place].size(); i++) {
		neighbours.push_back(edgeLists[place][i].toVertex);
	}
	sort(neighbours.begin(), neighbours.end());
	return neighbours;
}

template<class T>
inline int Graph<T>::getNrOfVertices() const {
	return (int)vertMap.size();
}

template<class T>
inline int Graph<T>::getNrOfEdges() const {
	int size = 0;
	for (int i = 0; i < edgeLists.size(); i++) {
		size += (int)edgeLists[i].size();
	}
	return size;
}

template<class T>
inline void Graph<T>::kruskals(vector<tuple<T, T, int>>& mst, int& totalCost) {
	DisjointSets<T> disjointSets;
	for (const auto& vert : vertMap) {
		disjointSets.makeSet(vert.first);
	}

	vector<Edge> alla;
	for (const auto& edgeList : edgeLists) {
		for (const auto& edge : edgeList) {
			alla.push_back(edge);
		}
	}
	totalCost = 0;
	sort(alla.begin(), alla.end());

	for (const auto& edge : alla) {
		T from = edge.fromVertex;
		T to = edge.toVertex;
		int weight = edge.weight;
		if (disjointSets.findSet(from) != disjointSets.findSet(to)) {
			mst.push_back({ from, to, weight });
			totalCost += weight;
			disjointSets.unionSet(from, to);
		}
	}
	/*DisjointSets<T> disjSets;
	vector<Edge> allEdges;

	for (int i = 0; i < edgeLists.size(); i++)
	{
		vector<Edge> currentVector = edgeLists[i];
		disjSets.makeSet(currentVector[0].fromVertex);
		cout << currentVector[0].fromVertex << endl;
		for (int j = 0; j < currentVector.size(); j++)
		{
			allEdges.push_back(currentVector[j]);
		}
	}
	sort(allEdges.begin(), allEdges.end());

	int nrOfVertices = (int)edgeLists.size();
	int currentNrOfEdgesInMST = 0;
	int index = 0;
	while (currentNrOfEdgesInMST < nrOfVertices-1)
	{
		Edge currentEdge = allEdges[index++];
		if (disjSets.findSet(currentEdge.fromVertex) != disjSets.findSet(currentEdge.toVertex))
		{
			disjSets.unionSet(currentEdge.fromVertex, currentEdge.toVertex);
			mst.push_back(make_tuple(currentEdge.fromVertex, currentEdge.toVertex, currentEdge.weight));
			totalCost += currentEdge.weight;
			currentNrOfEdgesInMST++;
		}
	}*/
}

template<class T>
inline void Graph<T>::prims(vector<tuple<T, T, int>>& mst, int& totalCost) {
	//prio kö
	//priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
	MinPriorityQueue<Edge> pq;
	//visited set
	unordered_set<T> visited;
	T startNode = vertMap.begin()->first;
	visited.insert(startNode);

	////lägger till nodens grannar i vår prioQue
	for (const auto& edge : edgeLists[vertMap[startNode]]) {
		pq.enqueue(edge);
	}
	totalCost = 0;

	//håll på tills vår kö är tom
	while (!pq.is_empty()) {
		// ta första edgen i vår kö
		Edge currentEdge = pq.peek();
		// släng den
		pq.dequeue();
		// ger mig visited.end() om currentNode.toVertex inte finns i vår visited array
		// om vi inte har visitat noden som var på toppen, gå till den;

		//if (visited.find(currentEdge.toVertex) != visited.end()) {
		if (visited.count(currentEdge.toVertex) > 0) {
			continue;
		}
		//lägg till edgen i vår mst
		mst.push_back({ currentEdge.fromVertex, currentEdge.toVertex, currentEdge.weight });
		totalCost += currentEdge.weight;
		//släng in noden i visited
		visited.insert(currentEdge.toVertex);

		//lägga ner vår nya nods grannar om dom inte är redan visitade
		for (const auto& edge : edgeLists[vertMap[currentEdge.toVertex]]) {
			//if check om grannen är i visited
			//if (visited.find(edge.toVertex) == visited.end()) {
			if (visited.count(edge.toVertex) == 0) {
				pq.enqueue(edge);
			}
		}
	}
}




template <class T>
string Graph<T>::breadthFirstSearch(T from) {
	string result;
	unordered_set<T> visited;
	queue<T> q;
	q.push(from);
	visited.insert(from);

	while (!q.empty()) {
		T vertex = q.front();
		q.pop();
		if (!result.empty()) {
			result += ",";
		}
		result += string(vertex);

		vector<T> sortedNeighbors;
		for (const auto& edge : edgeLists[vertMap[vertex]]) {
			//if (visited.find(edge.toVertex) == visited.end()) {
			if (visited.count(edge.toVertex) == 0) {
				sortedNeighbors.push_back(edge.toVertex);
				visited.insert(edge.toVertex);
			}
		}
		sort(sortedNeighbors.begin(), sortedNeighbors.end());
		for (const auto& neighbor : sortedNeighbors) {
			q.push(neighbor);
		}
	}
	return result;
}


template <class T>
std::string Graph<T>::depthFirstSearch(T from) {
	string visited = "";
	stack<T> stack;
	vector<bool> visitedVector(edgeLists.size(), false);

	stack.push(from);

	while (!stack.empty()) {
		T current = stack.top();
		stack.pop();

		if (!visitedVector[vertMap[current]]) {
			visitedVector[vertMap[current]] = true;
			if (!visited.empty()) {
				visited += ",";
			}
			visited += current;

			vector<T> neighbors = getAllNeighboursTo(current);

			reverse(neighbors.begin(), neighbors.end());

			for (int i = 0; i < neighbors.size(); i++) {
				if (!visitedVector[vertMap[neighbors[i]]]) {
					stack.push(neighbors[i]);
				}
			}
		}
	}

	return visited;
}


//#include <sstream> // For string conversion
//template <class T>
//string Graph<T>::depthFirstSearch(T from) {
//	unordered_set<T> visited;
//	stringstream result; // Using stringstream for string conversion
//	stack<T> stack;
//	visited.insert(from);
//	stack.push(from);
//
//	while (!stack.empty()) {
//		T vertex = stack.top();
//		stack.pop();
//		if (result.tellp() != 0) { // Checking if result is not empty
//			result << ",";
//		}
//		result << vertex; // Appending vertex to stringstream
//		for (const auto& edge : edgeLists[vertMap[vertex]]) {
//			if (visited.find(edge.toVertex) == visited.end()) {
//				stack.push(edge.toVertex);
//				visited.insert(edge.toVertex);
//			}
//		}
//	}
//	return result.str(); // Converting stringstream to string
//}



// -------

//template <class T>
//string Graph<T>::depthFirstSearch(T from) {
//	//Funkar inte :(
//	unordered_set<T> visited;
//	string result;
//	stack<T> stack;
//	visited.insert(from);
//	stack.push(from);
//
//	while (!stack.empty()) {
//		T vertex = stack.top();
//		stack.pop();
//		if (!result.empty()) {
//			result += ",";
//		}
//		result += string(vertex);
//		for (const auto& edge : edgeLists[vertMap[vertex]]) {
//			if (visited.find(edge.toVertex) == visited.end()) {
//				stack.push(edge.toVertex);
//				visited.insert(edge.toVertex);
//			}
//		}
//	}
//	return result;
//}
//
//
//
//template <class T>
//string Graph<T>::breadthFirstSearch(T from) {
//	string result;
//	unordered_set<T> visited;
//	queue<T> q;
//	q.push(from);
//	visited.insert(from);
//
//	while (!q.empty()) {
//		T vertex = q.front();
//		q.pop();
//		if (!result.empty()) {
//			result += ",";
//		}
//		result += string(vertex);
//
//		vector<T> sortedNeighbors;
//		for (const auto& edge : edgeLists[vertMap[vertex]]) {
//			if (visited.find(edge.toVertex) == visited.end()) {
//				sortedNeighbors.push_back(edge.toVertex);
//				visited.insert(edge.toVertex);
//			}
//		}
//		sort(sortedNeighbors.begin(), sortedNeighbors.end());
//		for (const auto& neighbor : sortedNeighbors) {
//			q.push(neighbor);
//		}
//	}
//	return result;
//}






