//#include "Graph.hpp"
//#include <algorithm>
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
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
//bool BFSTests()
//{
//	std::cout << "Starting tests of BFS" << std::endl;
//	std::cout << std::endl;
//
//	std::cout << "Using graph_easy.txt" << std::endl;
//	Graph<std::string> g;
//	readFromFile(g, "graph_easy.txt");
//	std::vector<std::string> data = {"A","B","C","D"};
//	std::vector<std::string> correct = {"A,B,D,C","B,A,C,D","C,B,D,A","D,A,C,B"};
//	for(int i = 0; i < data.size(); ++i)
//	{
//		std::cout << "  Running breadthFirstSearch(" << data[i] << "), ..." << std::flush;
//		if (correct[i] != g.breadthFirstSearch(data[i]))
//		{
//			std::cout << "Your breadthFirstSearch(" << data[i] << ") returns the incorrect traversing." << std::endl;
//			std::cout << "Should be: " << correct[i] << std::endl;
//			std::cout << "But is: " << g.breadthFirstSearch(data[i]) << std::endl;
//			return false;
//		}
//		std::cout << " OK!" << std::endl;
//	}
//
//	std::cout << "Using graph_medium.txt" << std::endl;
//	Graph<std::string> g2;
//	readFromFile(g2, "graph_medium.txt");
//	data = {"A","B","I","F","G"};
//	correct = {"A,B,H,C,G,I,D,F,E","B,A,C,H,D,I,G,E,F","I,C,G,H,B,D,F,A,E","F,D,E,G,C,H,I,B,A","G,F,H,I,D,E,A,B,C"};
//	for(int i = 0; i < data.size(); ++i)
//	{
//		std::cout << "  Running breadthFirstSearch((" << data[i] << "), ..." << std::flush;
//		if (correct[i] != g2.breadthFirstSearch(data[i]))
//		{
//			std::cout << "Your breadthFirstSearch(" << data[i] << ") returns the incorrect traversing." << std::endl;
//			std::cout << "Should be: " << correct[i] << std::endl;
//			std::cout << "But is: " << g2.breadthFirstSearch(data[i]) << std::endl;
//			return false;
//		}
//		std::cout << " OK!" << std::endl;
//	}
//
//	std::cout << "Using graph_hard.txt" << std::endl;
//	Graph<std::string> g3;
//	readFromFile(g3, "graph_hard.txt");
//	data = {"A","K","L","Q","T","Z"};
//	correct = {"A,B,C,D,L,E,K,M,P,F,J,O,N,Q,G,I,R,Y,H,S,X,Z,U,T,W,V","K,J,L,O,P,I,C,M,N,Q,H,A,B,D,R,Y,G,U,E,S,X,Z,F,T,V,W","L,C,K,M,P,A,B,D,J,O,N,Q,E,I,R,Y,F,H,S,X,Z,G,U,T,W,V","Q,P,R,Y,K,L,O,S,X,Z,J,C,M,N,T,U,W,I,A,B,D,H,V,E,G,F","T,S,U,R,H,V,Q,G,I,W,P,Y,F,J,X,Z,K,L,O,E,C,M,N,D,A,B","Z,W,Y,V,X,Q,U,P,R,H,S,T,K,L,O,G,I,J,C,M,N,F,A,B,D,E"};
//	for(int i = 0; i < data.size(); ++i)
//	{
//		std::cout << "  Running breadthFirstSearch(" << data[i] << "), ..." << std::flush;
//		if (correct[i] != g3.breadthFirstSearch(data[i]))
//		{
//			std::cout << "Your breadthFirstSearch(" << data[i] << ") returns the incorrect traversing." << std::endl;
//			std::cout << "Should be: " << correct[i] << std::endl;
//			std::cout << "But is: " << g3.breadthFirstSearch(data[i]) << std::endl;
//			return false;
//		}
//		std::cout << " OK!" << std::endl;
//	}
//
//	std::cout << "All BFS tests OK!" << std::endl;
//	return true;
//}        
//
//int main(int argc, char const *argv[])
//{
//	if(!BFSTests())
//		return 1;
//	return 0;
//}