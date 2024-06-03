//#include "Graph.hpp"
////#include "Testing_functions.h"
//#include <algorithm>
//#include <fstream>
//#include <string>
//#include <iostream>
//
//std::string getVector(std::vector<std::string> vec)
//{
//	std::string ret = "";
//	if(vec.size() > 0)
//	{
//		ret += vec[0];
//		for(int i = 1; i < vec.size(); ++i)
//			ret += "," + vec[i];
//	}
//
//	return ret;
//}
//
//void readFromFile(Graph<std::string> &g, std::string file)
//{
//	std::ifstream myfile(file);
//	while(true)
//	{
//		std::string from = "";
//		std::string to = "";
//		int weight = 0;
//
//		myfile >> from;
//		myfile >> to; 
//		myfile >> weight;
//		g.addEdge(from, to, weight);
//		if (myfile.eof())
//			break;
//	}
//	myfile.close();
//}
//
//bool BasicGraphTests()
//{
//	std::cout << "Starting basic Graph tests" << std::endl << std::endl;
//	std::cout << "Creating a graph and using readFromFile() ... " << std::flush;
//	Graph<std::string> g;
//	readFromFile(g, "graph_basic.txt");
//	std::cout << "OK!" << std::endl;
//
//	std::cout << "Checking number of vertices with getNrOfVertices() ... " << std::flush;
//	if (g.getNrOfVertices() != 6)
//	{
//		std::cout << "Incorrect." << std::endl;
//		std::cout << "Should be 6, but returns " << g.getNrOfVertices() << "." << std::endl;
//		return false;
//	}
//	std::cout << "OK!" << std::endl;
//
//	std::cout << "Checking number of edges with getNrOfEdges() ... " << std::flush;
//	if (g.getNrOfEdges() != 14)
//	{
//		std::cout << "Incorrect." << std::endl;
//		std::cout << "Should be 14, but returns " << g.getNrOfEdges() << "." << std::endl;
//		return false;
//	}
//	std::cout << "OK!" << std::endl;
//
//	std::vector<std::string> vertices = {"A","B","C","D","E","F"};
//	std::vector<std::vector<std::string>> edges;
//	edges.push_back({"B","D"});
//	edges.push_back({"A","C","F"});
//	edges.push_back({"B","D"});
//	edges.push_back({"A","C","E"});
//	edges.push_back({"D","F"});
//	edges.push_back({"B","E"});
//
//	std::cout << "Checking that all vertices and edges exist using getAllNeighboursTo() ... " << std::flush;
//	for(int i = 0; i < 6; ++i)
//	{
//		if (edges[i] != g.getAllNeighboursTo(vertices[i]))
//		{
//			std::cout << "Not all vertices and edges exist." << std::endl;
//			std::cout << "On vertex "<< vertices[i] << " there should be these edges: " << getVector(edges[i]) << std::endl;
//			std::cout << "But there are " << getVector(g.getAllNeighboursTo(vertices[i])) << std::endl;
//			return false;
//		}
//	}
//	std::cout << "OK!" << std::endl;
//	
//	std::cout << "Adding extra vertex Q using addVertex() and verifying its existence ... " << std::flush;
//	g.addVertex("Q");
//	std::vector<std::string> emptyVector;
//	if (g.getNrOfVertices() != 7 || g.getAllNeighboursTo("Q") != emptyVector || g.getNrOfEdges() != 14)
//	{
//		std::cout << "Graph should contain 7 vertices, 14 edges, and Q should contain no neighbor." << std::endl;
//		std::cout << "Your number of vertices are " << g.getNrOfVertices() << ", number of edges are " << g.getNrOfEdges() << " , and Qs neighbors are " << getVector(g.getAllNeighboursTo("Q"))<< std::endl;
//		return false;
//	}
//	std::cout << "OK!" << std::endl;
//
//	std::cout << "Adding edges between Q and A, and Q and C ... " << std::flush;
//	g.addEdge("Q","A", 0);
//	g.addEdge("Q","C", 0);
//	std::vector<std::string> result = {"A","C"};
//	if (g.getNrOfVertices() != 7 || g.getAllNeighboursTo("Q") != result || g.getNrOfEdges() != 18)
//	{
//		std::cout << "Graph should contain 7 vertices, 18 edges, and Q have A and C as neighbors." << std::endl;
//		std::cout << "Your number of vertices are " << g.getNrOfVertices() << ", number of edges are " << g.getNrOfEdges()<< ", and Qs neighbors are " << getVector(g.getAllNeighboursTo("Q")) << std::endl;
//		return false;
//	}
//	std::cout << "OK!" << std::endl;
//
//	std::cout << "All basic Graph tests OK!" << std::endl;
//	return true;
//}
//
//int main(int argc, char const *argv[])
//{
//	if(!BasicGraphTests())
//		return 1;	
//	return 0;
//}