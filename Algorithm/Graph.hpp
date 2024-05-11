#ifndef GRAPH_HPP
#define GRAPH_HPP
#include "DisjointSets.hpp"
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

	std::unordered_map<T, int> vertMap;
	std::vector<std::vector<Edge>>adjLists;
public:
	Graph();
	virtual ~Graph() = default;
	Graph(const Graph& other) = delete;
	Graph& operator=(const Graph& other) = delete;
	void addVertex(T theNode);
	void addEdge(T from, T to, int weight = 0);
	std::vector<T> getAllNeighboursTo(T vertex);
	int getNrOfVertices() const;
	int getNrOfEdges() const;
	void kruskals(std::vector<std::tuple<T, T, int>>& mst, int& totalCost);
	void prims(std::vector<std::tuple<T, T, int>>& mst, int& totalCost);
	//void readFromFile(std::string file);

	std::string depthFirstSearch(T from);
	std::string breadthFirstSearch(T from);
};


#endif

template<class T>
inline Graph<T>::Graph() {}

template<class T>
inline void Graph<T>::addVertex(T theNode) {
	// undantag ska kastas om noden redan finns
	if (vertMap.count(theNode) > 0) {
		throw std::exception("Error: call addVertexNot okay node already exisits");
	}
	/*vertMap[theNode] = (int)vertMap.size();
	adjLists.push_back(std::vector<Edge>());*/
	vertMap[theNode] = (int)vertMap.size();
	adjLists.push_back(std::vector<Edge>());
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
	adjLists[vertMap[from]].push_back(Edge(from, to, weight));
	adjLists[vertMap[to]].push_back(Edge(to, from, weight));
}

template<class T>
inline std::vector<T> Graph<T>::getAllNeighboursTo(T vertex) {
	// undantag om vertexen inte finns;
	if (vertMap.count(vertex) == 0) {
		throw std::exception("Error: No vertex of that kind inputted");
	}
	std::vector<T>neighbours;
	int place = vertMap[vertex];
	for (int i = 0; i < adjLists[place].size(); i++) {
		neighbours.push_back(adjLists[place][i].toVertex);
	}
	std::sort(neighbours.begin(), neighbours.end());
	return neighbours;

	/*std::vector<T>neighbours;
	int place = vertMap[vertex];
	for (int i = 0; i < adjLists[place].size(); i++)
	{
		neighbours.push_back(adjLists[place][i].toVertex);
	}
	std::sort(neighbours.begin(), neighbours.end());
	return neighbours;*/
}

template<class T>
inline void Graph<T>::kruskals(std::vector<std::tuple<T, T, int>>& mst, int& totalCost) {
	DisjointSets<T>disjointSet;
	// skapa ett set per båge
	for (const auto& vertexEntry : vertMap) {
		disjointSet.makeSet(vertexEntry.first);
	}

	//sortera
	std::vector<Edge> edges;
	for (const auto& adjList : adjLists) {
		for (const auto& edge : adjList) {
			edges.push_back(edge);
		}
	}
	std::sort(edges.begin(), edges.end());

	totalCost = 0;

	// lägg till
	for (const auto& edge : edges) {
		T from = edge.fromVertex;
		T to = edge.toVertex;
		int weight = edge.weight;

		//kolla om cykel
		if (disjointSet.findSet(from) != disjointSet.findSet(to)) {
			mst.push_back({ from, to, weight });
			totalCost += weight;
			disjointSet.unionSet(from, to);
		}
	}

	/*DisjointSets<T> disjSets;
	std::vector<Edge> allEdges;

	for (int i = 0; i < adjLists.size(); i++)
	{
		std::vector<Edge> currentVector = adjLists[i];
		disjSets.makeSet(currentVector[0].fromVertex);
		std::cout << currentVector[0].fromVertex << std::endl;
		for (int j = 0; j < currentVector.size(); j++)
		{
			allEdges.push_back(currentVector[j]);
		}
	}
	std::sort(allEdges.begin(), allEdges.end());

	int nrOfVertices = adjLists.size();
	int currentNrOfEdgesInMST = 0;
	int index = 0;
	while (currentNrOfEdgesInMST < nrOfVertices-1)
	{
		Edge currentEdge = allEdges[index++];
		if (disjSets.findSet(currentEdge.fromVertex) != disjSets.findSet(currentEdge.toVertex))
		{
			disjSets.unionSet(currentEdge.fromVertex, currentEdge.toVertex);
			mst.push_back(std::make_tuple(currentEdge.fromVertex, currentEdge.toVertex, currentEdge.weight));
			totalCost += currentEdge.weight;
			currentNrOfEdgesInMST++;
		}
	}*/
}

template<class T>
inline void Graph<T>::prims(std::vector<std::tuple<T, T, int>>& mst, int& totalCost) {
	std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> pq;
	std::unordered_set<T> visited;
	T startNode = vertMap.begin()->first;
	visited.insert(startNode);

	for (const auto& edge : adjLists[vertMap[startNode]]) {
		pq.push(edge);
	}
	totalCost = 0;

	while (!pq.empty()) {
		Edge currentEdge = pq.top();
		pq.pop();

		if (visited.find(currentEdge.toVertex) != visited.end()) {
			continue;
		}
		mst.push_back({ currentEdge.fromVertex, currentEdge.toVertex, currentEdge.weight });
		totalCost += currentEdge.weight;

		visited.insert(currentEdge.toVertex);

		for (const auto& edge : adjLists[vertMap[currentEdge.toVertex]]) {
			if (visited.find(edge.toVertex) == visited.end()) {
				pq.push(edge);
			}
		}
	}

}

template<class T>
inline int Graph<T>::getNrOfVertices() const {
	return (int)vertMap.size();
}

template<class T>
inline int Graph<T>::getNrOfEdges() const {
	int size = 0;
	for (int i = 0; i < adjLists.size(); i++) {
		size += (int)adjLists[i].size();
	}
	return size;
}



#include <sstream> // For string conversion


template <class T>
std::string Graph<T>::depthFirstSearch(T from) {
	std::unordered_set<T> visited;
	std::stringstream result; // Using stringstream for string conversion
	std::stack<T> stack;
	visited.insert(from);
	stack.push(from);

	while (!stack.empty()) {
		T vertex = stack.top();
		stack.pop();
		if (result.tellp() != 0) { // Checking if result is not empty
			result << ",";
		}
		result << vertex; // Appending vertex to stringstream
		for (const auto& edge : adjLists[vertMap[vertex]]) {
			if (visited.find(edge.toVertex) == visited.end()) {
				stack.push(edge.toVertex);
				visited.insert(edge.toVertex);
			}
		}
	}
	return result.str(); // Converting stringstream to string
}


//template <class T>
//std::string Graph<T>::depthFirstSearch(T from) {
//	//Funkar inte :(
//	std::unordered_set<T> visited;
//	std::string result;
//	std::stack<T> stack;
//	visited.insert(from);
//	stack.push(from);
//
//	while (!stack.empty()) {
//		T vertex = stack.top();
//		stack.pop();
//		if (!result.empty()) {
//			result += ",";
//		}
//		result += std::string(vertex);
//		for (const auto& edge : adjLists[vertMap[vertex]]) {
//			if (visited.find(edge.toVertex) == visited.end()) {
//				stack.push(edge.toVertex);
//				visited.insert(edge.toVertex);
//			}
//		}
//
//	}
//	return result;
//}



template <class T>
std::string Graph<T>::breadthFirstSearch(T from) {
	std::string result;
	std::unordered_set<T> visited;
	std::queue<T> q;
	q.push(from);
	visited.insert(from);

	while (!q.empty()) {
		T vertex = q.front();
		q.pop();
		if (!result.empty()) {
			result += ",";
		}
		result += std::string(vertex);

		std::vector<T> sortedNeighbors;
		for (const auto& edge : adjLists[vertMap[vertex]]) {
			if (visited.find(edge.toVertex) == visited.end()) {
				sortedNeighbors.push_back(edge.toVertex);
				visited.insert(edge.toVertex);
			}
		}
		std::sort(sortedNeighbors.begin(), sortedNeighbors.end());
		for (const auto& neighbor : sortedNeighbors) {
			q.push(neighbor);
		}
	}
	return result;
}







//#ifndef GRAPH_H
//#define GRAPH_H
//#include <utility>
//#include <vector>
//#include <climits>
//#include <tuple>
//#include <string>
//#include <unordered_map>
//#include <algorithm>
//
//const int INFINIT_COST = INT_MAX;
//
//template <class T>
//class Graph {
//private:
//	// for you decide
//	class Edge {
//	public:
//		int weight;
//		T fromVertex;
//		T toVertex;
//		Edge() {}
//		Edge(T fromVertex, T toVertex, int weight = 0) : fromVertex(fromVertex), toVertex(toVertex), weight(weight) {}
//		bool operator<(const Edge& other) { return weight < other.weight; }
//		bool operator>(const Edge& other) { return weight > other.weight; }
//		bool operator<=(const Edge& other) { return weight <= other.weight; }
//		bool operator>=(const Edge& other) { return weight >= other.weight; }
//		bool operator==(const Edge& other) { return fromVertex == other.fromVertex && toVertex == other.toVertex; /* ev även vikten*/ }
//		bool operator!=(const Edge& other) { return fromVertex != other.fromVertex || toVertex != other.toVertex; /* ev även vikten*/ }
//	};
//	std::unordered_map<T, int> vertMap;
//	std::vector<std::vector<Edge>> adjLists;
//
//public:
//	Graph();
//	virtual ~Graph() = default;
//	Graph(const Graph& other) = delete;
//	Graph& operator=(const Graph& other) = delete;
//	void addVertex(T theNode);
//	void addEdge(T from, T to, int weight = 0);
//	std::vector<T> getAllNeighboursTo(T vertex);
//	int getNrOfVertices() const;
//	int getNrOfEdges() const;
//	void kruskals(std::vector<std::tuple<T, T, int>>& mst, int& totalCost);
//	void prims(std::vector<std::tuple<T, T, int>>& mst, int& totalCost);
//	void readFromFile(std::string file);
//
//	std::string depthFirstSearch(T from);
//	std::string breadthFirstSearch(T from);
//};
//
//
//#endif
//
//template<class T>
//inline Graph<T>::Graph() {}
//
//template<class T>
//inline void Graph<T>::addVertex(T theNode) {
//	// Exception for existing node
//	if (vertMap.count(theNode) > 0) {
//		throw std::exception("Exception: call addVertex() on already existing key.");
//	}
//	vertMap[theNode] = (int)vertMap.size();
//	adjLists.push_back(std::vector<Edge>());
//
//}
//
//template<class T>
//inline void Graph<T>::addEdge(T from, T to, int weight) {
//	// addVertex() if node does not exists in the vertMap
//	if (vertMap.count(from) == 0) {
//		addVertex(from);
//	}
//	if (vertMap.count(to) == 0) {
//		addVertex(to);
//	}
//	adjLists[vertMap[from]].push_back(Edge(from, to, weight));
//	adjLists[vertMap[to]].push_back(Edge(to, from, weight));
//}
//
//template<class T>
//inline std::vector<T> Graph<T>::getAllNeighboursTo(T vertex) {
//	std::vector<T> neighbours;
//
//	// Check if the vertex exists in the vertex map
//	if (vertMap.count(vertex) == 0) {
//		// Vertex does not exist
//		return neighbours; // Return empty vector
//	}
//
//	// Get the index of the vertex in the adjacency list
//	int index = vertMap[vertex];
//
//	// Iterate over the adjacency list of the vertex
//	for (const Edge& edge : adjLists[index]) {
//		// Add the destination vertex of each edge to the neighbours vector
//		neighbours.push_back(edge.toVertex);
//	}
//
//	return neighbours;
//}
//
//
//
//template<class T>
//inline void Graph<T>::kruskals(std::vector<std::tuple<T, T, int>>& mst, int& totalCost) {
//	// Sort all the edges in non-decreasing order of their weight
//	std::vector<Edge> allEdges;
//	for (const auto& adjList : adjLists) {
//		for (const Edge& edge : adjList) {
//			allEdges.push_back(edge);
//		}
//	}
//	std::sort(allEdges.begin(), allEdges.end(), [](const Edge& a, const Edge& b) {
//		return a.weight < b.weight;
//		});
//
//	// Create a disjoint set to keep track of connected components
//	std::unordered_map<T, T> parent;
//	for (const auto& vertex : vertMap) {
//		parent[vertex.first] = vertex.first; // Each vertex is initially its own parent
//	}
//
//	totalCost = 0;
//	for (const Edge& edge : allEdges) {
//		T u = edge.fromVertex;
//		T v = edge.toVertex;
//
//		// Find the parents of u and v
//		while (parent[u] != u) {
//			u = parent[u];
//		}
//		while (parent[v] != v) {
//			v = parent[v];
//		}
//
//		// If adding this edge forms a cycle, skip it
//		if (u == v) {
//			continue;
//		}
//
//		// Add this edge to the MST
//		mst.push_back(std::make_tuple(edge.fromVertex, edge.toVertex, edge.weight));
//		totalCost += edge.weight;
//
//		// Union the two components by making one the parent of the other
//		parent[u] = v;
//	}
//}
//
//template<class T>
//inline void Graph<T>::prims(std::vector<std::tuple<T, T, int>>& mst, int& totalCost) {
//	std::unordered_set<T> visited;
//	std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> pq;
//
//	T startVertex = vertMap.begin()->first; // Start from any vertex
//	visited.insert(startVertex);
//
//	// Add all edges from the start vertex to the priority queue
//	for (const Edge& edge : adjLists[vertMap[startVertex]]) {
//		pq.push(edge);
//	}
//
//	totalCost = 0;
//	while (!pq.empty() && visited.size() < vertMap.size()) {
//		Edge minEdge = pq.top();
//		pq.pop();
//
//		if (visited.count(minEdge.toVertex)) {
//			continue; // Skip if the vertex is already visited
//		}
//
//		// Add this edge to the MST
//		mst.push_back(std::make_tuple(minEdge.fromVertex, minEdge.toVertex, minEdge.weight));
//		totalCost += minEdge.weight;
//
//		// Mark the 'to' vertex as visited
//		visited.insert(minEdge.toVertex);
//
//		// Add all edges from the 'to' vertex to the priority queue
//		for (const Edge& edge : adjLists[vertMap[minEdge.toVertex]]) {
//			pq.push(edge);
//		}
//	}
//}
//
//
////template<class T>
////inline void Graph<T>::kruskals(std::vector<std::tuple<T, T, int>>& mst, int& totalCost) {
////
////}
////
////template<class T>
////inline void Graph<T>::prims(std::vector<std::tuple<T, T, int>>& mst, int& totalCost) {
////
////}
//
//template<class T>
//inline int Graph<T>::getNrOfVertices() const {
//	return vertMap.size();
//}
//
//
//template<class T>
//inline int Graph<T>::getNrOfEdges() const {
//	int totalEdges = 0;
//	for (const auto& adjList : adjLists) {
//		totalEdges += adjList.size();
//	}
//	// Since each edge is counted twice (undirected graph), divide by 2
//	return totalEdges / 2;
//}
//
//
//template <class T>
//std::string Graph<T>::depthFirstSearch(T from) {
//	return "";
//}
//template <class T>
//std::string Graph<T>::breadthFirstSearch(T from) {
//	return "";
//}