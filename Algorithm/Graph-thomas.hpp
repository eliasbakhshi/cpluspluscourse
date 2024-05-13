#ifndef GRAPH_H
#define GRAPH_H
#include <utility>
#include <vector>
#include <map>
#include <climits>
#include <tuple>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "DisjointSetsTeacher.hpp"
#include "MinPriorityQueueTeacher.hpp"
#include "unordered_set"
const int INFINIT_COST = INT_MAX;

template <typename T>
class Graph
{
private:
	
	class Edge
	{
	public:
		T fromVertex;
		T toVertex;
		int weight;
		Edge() {};
		Edge(T fromVertex, T toVertex, int weight) : fromVertex(fromVertex), toVertex(toVertex), weight(weight) {};
		bool operator<(const Edge& other) { return weight < other.weight; };
		bool operator<=(const Edge& other) { return weight <= other.weight; };
		bool operator>(const Edge& other) { return weight > other.weight; };
		bool operator>=(const Edge& other) { return weight >= other.weight; };
		bool operator==(const Edge& other) { return weight == other.weight; };
		bool operator!=(const Edge& other) { return weight != other.weight; };
	};
	

	std::unordered_map<T, int> vertMap;
	std::vector < std::vector<Edge>> adjLists;
	
public:
	Graph();
	virtual ~Graph();
	Graph(const Graph& other) = delete;
	Graph& operator=(const Graph& other) = delete;
	void addVertex(T theNode);
	void addEdge(T from, T to, int weight = 0);
	std::vector<T> getAllNeighboursTo(T vertex);
	int getNrOfVerticies() const;
	int getNrOfEdges() const;
	void prims(std::vector<std::tuple<T, T, int>>& mst, int &totalCost);
	void kruskals(std::vector<std::tuple<T, T, int>>& mst, int& totalCost);
};


#endif

template<typename T>
inline Graph<T>::Graph()
{
}

/*
	vad ska stå i destruktorn?
*/

template<typename T>
inline Graph<T>::~Graph()
{
}

template<typename T>
inline void Graph<T>::addVertex(T theNode)
{
	if (vertMap.count(theNode) > 0)
	{
		throw std::exception("Exception: vertix already exist");
	}

	vertMap[theNode] = (int)vertMap.size();
	adjLists.push_back(std::vector<Edge>());
}

template<typename T>
inline void Graph<T>::addEdge(T from, T to, int weight)
{
	if (vertMap.count(from) == 0)
	{
		addVertex(from);
	}
	if (vertMap.count(to) == 0)
	{
		addVertex(to);
	}

	adjLists[vertMap[from]].push_back(Edge(from, to, weight));
	//adjLists[vertMap[to]].push_back(Edge(to, from, weight));

}

template<typename T>
inline std::vector<T> Graph<T>::getAllNeighboursTo(T vertex)
{

	std::vector<T> neighbours;

	auto it = vertMap.find(vertex);
	if (it != vertMap.end())
	{

		int index = it->second;
		std::vector<Edge>& edges = adjLists[index];

		for (const Edge& edge : edges)
		{
			neighbours.push_back(edge.toVertex);
		}
		std::sort(neighbours.begin(), neighbours.end());
	}
	else
	{
		throw std::exception("Exception: vertex is not found");
	}


	return neighbours;
}

template<typename T>
inline int Graph<T>::getNrOfVerticies() const
{
	return (int)vertMap.size();
}

template<typename T>
inline int Graph<T>::getNrOfEdges() const
{
	int numEdges = 0;
	for (const auto& list : adjLists)
	{
		numEdges += (int)list.size();

	}
	return numEdges;
}


template<typename T>
inline void Graph<T>::prims(std::vector<std::tuple<T, T, int>>& mst, int& totalCost)
{
	mst.clear();

	MinPriorityQueue <Edge> pq;
	std::unordered_set<T> visited;
	std::string result;

	T startNode = vertMap.begin()->first;
	visited.insert(startNode);

	for (int i = 0; i < adjLists[vertMap[startNode]].size(); i++)
	{
		pq.enqueue(adjLists[vertMap[startNode]][i]);
	}
	
	totalCost = 0;

	while (!pq.is_empty())
	{
		Edge currentNode = pq.peek();
		pq.dequeue();

		if (visited.find(currentNode.toVertex) != visited.end())
		{
			continue;
		}


		mst.push_back({ currentNode.fromVertex, currentNode.toVertex, currentNode.weight });
		totalCost += currentNode.weight;
		visited.insert(currentNode.toVertex);

		for (const auto& edge : adjLists[vertMap[currentNode.toVertex]])
		{
			if (visited.find(edge.toVertex) == visited.end())
			{
				pq.enqueue(edge);
			}
		}

	}


}

template<typename T>
inline void Graph<T>::kruskals(std::vector<std::tuple<T, T, int>>& mst, int& totalCost)
{
	//DisjointSets<T> disjointSets;

	////skapa en vector/array med alla bågar	
	//std::vector<Edge> edges;
	//for (int i = 0; i < adjLists.size(); i++)
	//{
	//	std::vector<Edge> currentVect = adjLists[i];
	//	disjointSets.makeSet(currentVect[0].fromVertex);
	//	std::cout << currentVect[0].fromVertex << std::endl;
	//	for (int k = 0; k < currentVect.size(); k++)
	//	{
	//		edges.push_back(currentVect[k]);// kopierar bågen
	//	}
	//}
	////sortera denna vector/array
	//// sorteringen kostat n log n
	//std::sort(edges.begin(), edges.end());


	////skapa disjunkta mände för varje nod, fixat
	//int nrOfVertices = (int)adjLists.size();
	//int currentNrOfEdgesInMst = 0;
	//int index = 0;
	//while (currentNrOfEdgesInMst < nrOfVertices - 1)
	//{
	//	Edge currentEdge = edges[index++];
	//	if (disjointSets.findSet(currentEdge.fromVertex) != disjointSets.findSet(currentEdge.toVertex))
	//	{
	//		disjointSets.unionSet(currentEdge.fromVertex, currentEdge.toVertex);
	//		mst.push_back(std::make_tuple(currentEdge.fromVertex, currentEdge.toVertex, currentEdge.weight));
	//		totalCost += currentEdge.weight;
	//		currentNrOfEdgesInMst++;
	//	}
	//}


	/*DisjointSets<T> disjointSets;

	std::vector<Edge> edges;
	for (int i = 0; i < adjLists.size(); i++)
	{
		std::vector<Edge> currentVect = adjLists[i];
		disjointSets.makeSet(currentVect[0].fromVertex);

		for (int k = 0; k < currentVect.size(); k++)
		{
			edges.push_back(currentVect[k]);
		}
	}

	std::sort(edges.begin(), edges.end());

	int nrOfVerticies = (int)adjLists.size();
	int currentNrOfEdgesInMst = 0;
	int index = 0;
	while (currentNrOfEdgesInMst < nrOfVerticies - 1)
	{
		Edge currentEdge = edges[index++];
		if (disjointSets.findSet(currentEdge.fromVertex) != disjointSets.findSet(currentEdge.toVertex))
		{
			disjointSets.unionSet(currentEdge.fromVertex, currentEdge.toVertex);
			mst.push_back(std::make_tuple(currentEdge.fromVertex, currentEdge.toVertex, currentEdge.weight));
			totalCost += currentEdge.weight;
			currentNrOfEdgesInMst++;
		}
	
	}*/



	DisjointSets<T> disjointSets;

	std::vector<Edge> edges;
	for (int i = 0; i < adjLists.size(); i++)
	{
		std::vector<Edge> currentVertex = adjLists[i];
		disjointSets.makeSet(currentVertex[0].fromVertex);
		for (int k = 0; k < currentVertex.size(); k++)
		{
			edges.push_back(currentVertex[k]);
		}
	}
	std::sort(edges.begin(), edges.end());

	int nrOfVertices = (int)vertMap.size();
	int currentNrOfEdgesInMst = 0;
	int index = 0;
	while (currentNrOfEdgesInMst < nrOfVertices - 1)
	{

		Edge currentEdge = edges[index++];

		if (disjointSets.findSet(currentEdge.fromVertex) != disjointSets.findSet(currentEdge.toVertex))
		{

			disjointSets.unionSet(currentEdge.fromVertex, currentEdge.toVertex);
			mst.push_back(std::make_tuple(currentEdge.fromVertex, currentEdge.toVertex, currentEdge.weight));
			totalCost += currentEdge.weight;
			currentNrOfEdgesInMst++;
		}

	}

}



