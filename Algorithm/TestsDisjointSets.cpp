//#include "DisjointSets.hpp"
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
//bool DisjointSetTests()
//{
//	std::cout << "Starting tests for DisjointSet" << std::endl << std::endl;
//	DisjointSets<std::string> ds; 
//
//	std::cout << "Using makeSet() to create sets [A, B, ..., I, J]" << std::endl;
//	std::vector<std::string> names = {"A","B","C","D","E","F","G","H","I", "J"};
//	for(int i = 0; i < names.size(); ++i)
//		ds.makeSet(names[i]);
//
//	std::cout << "Using findSet() to verify their existance ... "  << std::flush;
//	std::vector<std::string> results;
//	for(int i = 0; i < names.size(); ++i)
//		results.push_back(ds.findSet(names[i]));
//	if (names != results)
//	{
//		std::cout << "The created sets are incorrect." << std::endl;
//		std::cout << "Should be: " << getVector(names) << std::endl;
//		std::cout << "Yours are: " << getVector(results) << std::endl;
//		return false;
//	}
//	std::cout << "OK!" << std::endl;
//
//	std::cout << "Using unionSet('A', 'B') ... "  << std::flush;
//	ds.unionSet("A","B");
//	results = std::vector<std::string>();
//	for(int i = 0; i < names.size(); ++i)
//		results.push_back(ds.findSet(names[i]));
//
//	std::vector<std::string> unions = {"A","A","C","D","E","F","G","H","I", "J"};
//	if (results != unions)
//	{
//		std::cout << "The created sets are incorrect." << std::endl;
//		std::cout << "Should be: " << getVector(unions) << std::endl;
//		std::cout << "Yours are: " << getVector(results) << std::endl;
//		return false;
//	}
//	std::cout << "OK!" << std::endl;
//
//	std::cout << "Using unionSet('B', 'C') ... "  << std::flush;
//	ds.unionSet("B","C");
//	results = std::vector<std::string>();
//	for(int i = 0; i < names.size(); ++i)
//		results.push_back(ds.findSet(names[i]));
//	unions = {"A","A","A","D","E","F","G","H","I", "J"};
//	if (results != unions)
//	{
//		std::cout << "The created sets are incorrect." << std::endl;
//		std::cout << "Should be: " << getVector(unions) << std::endl;
//		std::cout << "Yours are: " << getVector(results) << std::endl;
//		return false;
//	}
//	std::cout << "OK!" << std::endl;
//
//	std::cout << "Using unionSet('D', 'C') ... " << std::flush;
//	ds.unionSet("D","C");
//	results = std::vector<std::string>();
//	for(int i = 0; i < names.size(); ++i)
//		results.push_back(ds.findSet(names[i]));
//	unions = {"D","D","D","D","E","F","G","H","I", "J"};
//	if (results != unions)
//	{
//		std::cout << "The created sets are incorrect." << std::endl;
//		std::cout << "Should be: " << getVector(unions) << std::endl;
//		std::cout << "Yours are: " << getVector(results) << std::endl;
//		return false;
//	}
//	std::cout << "OK!" << std::endl;
//
//	std::cout << "Using unionSet('E', 'F') ... "  << std::flush;
//	ds.unionSet("E","F");
//	results = std::vector<std::string>();
//	for(int i = 0; i < names.size(); ++i)
//		results.push_back(ds.findSet(names[i]));
//	unions = {"D","D","D","D","E","E","G","H","I", "J"};
//	if (results != unions)
//	{
//		std::cout << "The created sets are incorrect." << std::endl;
//		std::cout << "Should be: " << getVector(unions) << std::endl;
//		std::cout << "Yours are: " << getVector(results) << std::endl;
//		return false;
//	}
//	std::cout << "OK!" << std::endl;
//
//	std::cout << "Using unionSet('G', 'H') ... "  << std::flush;
//	ds.unionSet("G","H");
//	results = std::vector<std::string>();
//	for(int i = 0; i < names.size(); ++i)
//		results.push_back(ds.findSet(names[i]));
//	unions = {"D","D","D","D","E","E","G","G","I", "J"};
//	if (results != unions)
//	{
//		std::cout << "The created sets are incorrect." << std::endl;
//		std::cout << "Should be: " << getVector(unions) << std::endl;
//		std::cout << "Yours are: " << getVector(results) << std::endl;
//		return false;
//	}
//	std::cout << "OK!" << std::endl;
//
//	std::cout << "Using unionSet('I', 'E') ... "  << std::flush;
//	ds.unionSet("I","E");
//	results = std::vector<std::string>();
//	for(int i = 0; i < names.size(); ++i)
//		results.push_back(ds.findSet(names[i]));
//	unions = {"D","D","D","D","I","I","G","G","I", "J"};
//	if (results != unions)
//	{
//		std::cout << "The created sets are incorrect." << std::endl;
//		std::cout << "Should be: " << getVector(unions) << std::endl;
//		std::cout << "Yours are: " << getVector(results) << std::endl;
//		return false;
//	}
//	std::cout << "OK!" << std::endl;
//
//	std::cout << "Using unionSet('G', 'F') ... "  << std::flush;
//	ds.unionSet("G","F");
//	results = std::vector<std::string>();
//	for(int i = 0; i < names.size(); ++i)
//		results.push_back(ds.findSet(names[i]));
//	unions = {"D","D","D","D","G","G","G","G","G", "J"};
//	if (results != unions)
//	{
//		std::cout << "The created sets are incorrect." << std::endl;
//		std::cout << "Should be: " << getVector(unions) << std::endl;
//		std::cout << "Yours are: " << getVector(results) << std::endl;
//		return false;
//	}
//	std::cout << "OK!" << std::endl;
//
//	std::cout << "Using unionSet('D', 'G') ... "  << std::flush;
//	ds.unionSet("D","G");
//	results = std::vector<std::string>();
//	for(int i = 0; i < names.size(); ++i)
//		results.push_back(ds.findSet(names[i]));
//	unions = {"D","D","D","D","D","D","D","D","D", "J"};
//	if (results != unions)
//	{
//		std::cout << "The created sets are incorrect." << std::endl;
//		std::cout << "Should be: " << getVector(unions) << std::endl;
//		std::cout << "Yours are: " << getVector(results) << std::endl;
//		return false;
//	}
//	std::cout << "OK!" << std::endl;
//
//
//
//	std::cout << "All DisjointSet tests OK!" << std::endl;
//	return true;
//}
//
//
//int main(int argc, char const *argv[])
//{
//	if(!DisjointSetTests())
//		return 1;
//	return 0;
//}