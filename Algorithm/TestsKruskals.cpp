//#include "Graph.hpp"
//#include <algorithm>
//#include <fstream>
//#include <string>
//#include <iostream>
//#include <vector>
//#include <tuple>
//
//bool check_mst_edges(std::vector<std::tuple<std::string, std::string, int>> &mst, std::vector<std::tuple<std::string, std::string, int>> correct_mst)
//{
//	for(int i = 0; i < mst.size(); ++i)
//	{
//		if(std::find(correct_mst.begin(), correct_mst.end(), mst[i]) == correct_mst.end())
//		{
//			std::tuple<std::string, std::string, int> tup(std::get<1>(mst[i]), std::get<0>(mst[i]), std::get<2>(mst[i]));
//			if(std::find(correct_mst.begin(), correct_mst.end(), tup) == correct_mst.end())
//				return false;
//			else
//				correct_mst.erase(std::find(correct_mst.begin(), correct_mst.end(), tup));
//		}
//		else
//			correct_mst.erase(std::find(correct_mst.begin(), correct_mst.end(), mst[i]));
//	}
//	return true;
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
//std::string getEdges(std::vector<std::tuple<std::string, std::string, int>> edges)
//{
//	std::string ret = "";
//	ret += "(" + std::get<0>(edges[0]) + "," + std::get<1>(edges[0]) + "," + std::to_string(std::get<2>(edges[0])) + ")";
//	for(int i = 1; i < edges.size(); ++i)
//		ret += ",(" + std::get<0>(edges[i]) + "," + std::get<1>(edges[i]) + "," + std::to_string(std::get<2>(edges[i])) + ")";
//	return ret;
//}
//
//bool KruskalTests()
//{
//	std::cout << "Starting tests of Kruskals algorithm" << std::endl;
//	Graph<std::string> g;
//
//	std::cout << "Starting easier graph tests (graph_easy.txt) ... "  << std::flush;
//	readFromFile(g, "graph_easy.txt");
//	int cost = 0;
//	std::vector<std::tuple<std::string, std::string, int>> mst;
//	g.kruskals(mst, cost);
//	std::vector<std::tuple<std::string, std::string, int>> correct_mst = {{"C", "D", 2}, {"A", "B", 3}, {"A", "D", 4}};
//	if (cost != 9 || !check_mst_edges(mst, correct_mst))
//	{
//		std::cout << "The total cost of the MST is incorrect." << std::endl;
//		std::cout << "It should be 9, but is " << cost << std::endl;
//		std::cout << "The selected edges should be " << getEdges(correct_mst) << std::endl;
//		std::cout << "The selected edges are " << getEdges(mst) << std::endl;
//		std::cout << "The graph used is located in graph_easy.txt" << std::endl;
//		return false;
//	}
//	std::cout << " OK!" << std::endl;
//
//	Graph<std::string> g2;
//	std::cout << "Starting medium graph tests (graph_medium.txt) ... " << std::flush;
//	readFromFile(g2, "graph_medium.txt");
//	cost = 0;
//	mst = std::vector<std::tuple<std::string, std::string, int>>();
//	g2.kruskals(mst, cost);
//	correct_mst = {{"H", "G", 1}, {"C", "I", 2}, {"G", "F", 2}, {"A", "B", 4}, {"I", "G", 6}, {"C", "D", 7}, {"A","H",8}, {"D", "E", 9}};
//	if (cost != 39 || !check_mst_edges(mst, correct_mst))
//	{
//		std::cout << "The total cost of the MST is incorrect." << std::endl;
//		std::cout << "It should be 39, but is " << cost << std::endl;
//		std::cout << "The selected edges should be " << getEdges(correct_mst) << std::endl;
//		std::cout << "The selected edges are " << getEdges(mst) << std::endl;
//		std::cout << "The graph used is located in graph_medium.txt" << std::endl;
//		return false;
//	}
//	std::cout << " OK!" << std::endl;
//
//	Graph<std::string> g3;
//	std::cout << "Starting harder graph tests (graph_hard.txt) ... "  << std::flush;
//	readFromFile(g3, "graph_hard.txt");
//	cost = 0;
//	mst = std::vector<std::tuple<std::string, std::string, int>>();
//	g3.kruskals(mst, cost);
//	correct_mst = {{"H","I",5},{"B","D",5},{"U","H",8},{"B","A",10},{"J","I",10},{"E","F",10},{"Y","Q",11},{"P","L",12},{"O","K",14},{"G","H",15},{"D","C",15},{"J","K",15},{"K","P",17},{"L","C",17},{"G","F",20},{"L","M",25},{"N","M",30},{"P","Q",45},{"Q","R",50},{"Z","W",55},{"S","R",55},{"T","S",60},{"U","V",70},{"V","W",75},{"W","X",80}};
//
//	if (cost != 729 || !check_mst_edges(mst, correct_mst))
//	{
//		std::cout << "The total cost of the MST is incorrect." << std::endl;
//		std::cout << "It should be 729, but is " << cost << std::endl;
//		std::cout << "The selected edges should be " << getEdges(correct_mst) << std::endl;
//		std::cout << "The selected edges are " << getEdges(mst) << std::endl;
//		std::cout << "The graph used is located in graph_hard.txt" << std::endl;
//		return false;
//	}
//	std::cout << " OK!" << std::endl;
//
//	std::cout << "All Kruskal tests OK!" << std::endl;
//	return true;
//}
//
//int main(int argc, char const *argv[])
//{
//	if(!KruskalTests())
//		return 1;
//	return 0;
//}