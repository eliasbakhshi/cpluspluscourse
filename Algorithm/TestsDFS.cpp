#include "Graph.hpp"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void readFromFile(Graph<std::string> &g, std::string file)
{
	std::ifstream myfile(file);
	while(true)
	{
		std::string from = "";
		std::string to = "";
		int weight = 0;

		myfile >> from;
		myfile >> to; 
		myfile >> weight;
		g.addEdge(from, to, weight);
		if (myfile.eof())
			break;
	}
	myfile.close();
}

bool DFSTests()
{
	std::cout << "Starting tests of DFS" << std::endl;
	std::cout << std::endl;

	std::cout << "Using graph_easy.txt" << std::endl;
	Graph<std::string> g;
	readFromFile(g, "graph_easy.txt");
	std::vector<std::string> data = {"A","B","C","D"};
	std::vector<std::string> correct = {"A,B,C,D", "B,A,D,C","C,B,A,D", "D,A,B,C"};
	for(int i = 0; i < data.size(); ++i)
	{
		std::cout << "  Running depthFirstSearch(" << data[i] << "), ..." << std::flush;
		std::string testt = g.depthFirstSearch(data[i]);
		if (correct[i] != g.depthFirstSearch(data[i]))
		{
			std::cout << "Your depthFirstSearch(" << data[i] << ") returns the incorrect traversing." << std::endl;
			std::cout << "Should be: " << correct[i] << std::endl;
			std::cout << "But is: " << g.depthFirstSearch(data[i]) << std::endl;
			return false;
		}
		std::cout << " OK!" << std::endl;
	}

	std::cout << "Using graph_medium.txt" << std::endl;
	Graph<std::string> g2;
	readFromFile(g2, "graph_medium.txt");
	data = {"A","B","I","F","G"};
	correct = {"A,B,C,D,E,F,G,H,I","B,A,H,G,F,D,C,I,E","I,C,B,A,H,G,F,D,E","F,D,C,B,A,H,G,I,E","G,F,D,C,B,A,H,I,E"};
	for(int i = 0; i < data.size(); ++i)
	{
		std::cout << "  Running depthFirstSearch((" << data[i] << "), ..." << std::flush;
		if (correct[i] != g2.depthFirstSearch(data[i]))
		{
			std::cout << "Your depthFirstSearch(" << data[i] << ") returns the incorrect traversing." << std::endl;
			std::cout << "Should be: " << correct[i] << std::endl;
			std::cout << "But is: " << g2.depthFirstSearch(data[i]) << std::endl;
			return false;
		}
		std::cout << " OK!" << std::endl;
	}

	std::cout << "Using graph_hard.txt" << std::endl;
	Graph<std::string> g3;
	readFromFile(g3, "graph_hard.txt");
	data = {"A","K","L","Q","T","Z"};
	correct = {"A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z","K,J,I,H,G,F,E,D,B,A,C,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z","L,C,A,B,D,E,F,G,H,I,J,K,O,N,M,P,Q,R,S,T,U,V,W,X,Y,Z","Q,P,K,J,I,H,G,F,E,D,B,A,C,L,M,N,O,U,S,R,T,V,W,X,Y,Z","T,S,R,Q,P,K,J,I,H,G,F,E,D,B,A,C,L,M,N,O,U,V,W,X,Y,Z","Z,W,V,U,H,G,F,E,D,B,A,C,L,K,J,I,O,N,M,P,Q,R,S,T,Y,X"};
	for(int i = 0; i < data.size(); ++i)
	{
		std::cout << "  Running depthFirstSearch(" << data[i] << "), ..." << std::flush;
		if (correct[i] != g3.depthFirstSearch(data[i]))
		{
			std::cout << "Your depthFirstSearch(" << data[i] << ") returns the incorrect traversing." << std::endl;
			std::cout << "Should be: " << correct[i] << std::endl;
			std::cout << "But is: " << g3.depthFirstSearch(data[i]) << std::endl;
			return false;
		}
		std::cout << " OK!" << std::endl;
	}

	std::cout << "All DFS tests OK!" << std::endl;
	return true;
}

int main(int argc, char const *argv[])
{
	if(!DFSTests())
		return 1;
	return 0;
}