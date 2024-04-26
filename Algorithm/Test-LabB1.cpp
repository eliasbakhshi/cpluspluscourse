//#include "Stack.h"
//#include "QueueLinkedList.h"
//#include "QueueCircularArray.h"
//#include <iostream>
//#include <string>
//
//bool testingStack()
//{
//	std::cout << "STACK TEST" << std::endl<<std::endl;
//	std::cout << "Testing Stack with datatype int, using default constructor.... " << std::endl;
//	Stack<int> iStack;
//
//	std::cout << "New element should be empty .... ";
//	if (!iStack.is_empty())
//	{
//		std::cout << " but was not" << std::endl;
//		return false;
//	}
//	std::cout << std::endl;
//
//
//	std::cout << "Pushing integers 10,20 and 30....: ";
//	for (int i = 1; i <= 3; i++)
//	{
//		iStack.push(i * 10);
//	}
//	std::cout<<std::endl;
//
//	std::string resStr;
//	std::string controlStr = "30,30 20,20 10,10 ";
//	std::cout << "Using peek and pop on stack until empty .....";
//	while (!iStack.is_empty())
//	{
//		resStr+=std::to_string(iStack.peek());
//		resStr+="," + std::to_string(iStack.pop()) + " ";
//	}
//	if (resStr != controlStr)
//	{ 
//		std::cout <<" expected "<<controlStr << " but got  " << resStr << std::endl;
//		return false;
//	}
//	std::cout << std::endl;
//
//	
//	std::cout << "Mixing push and pop  ......  ";
//	for (int i = 1; i < 5; i++)
//		iStack.push(i * 11);
//	for (int i = 1; i < 3; i++)
//		iStack.pop();
//	for (int i = 5; i < 8; i++)
//		iStack.push(i * 11);
//	resStr = "";
//	while (!iStack.is_empty())
//		resStr += std::to_string(iStack.pop()) + " ";
//	controlStr = "77 66 55 22 11 ";
//	if (resStr != controlStr)
//	{
//		std::cout << " expected " << controlStr << " but got  " << resStr << std::endl;
//		return false;
//	}
//	std::cout << std::endl;
//
//
//	std::cout << "Using peek on empty stack ";
//	try
//	{
//		iStack.peek();
//		std::cout << ".... expected exception but exception was not thrown !" << std::endl;
//		return false;
//	}
//	catch (std::exception e)
//	{
//		std::cout << "expecting exception..... ";
//	}
//	std::cout <<std::endl;
//	
//	std::cout << "Using pop on empty stack ";
//	try
//	{
//		iStack.pop();
//		std::cout << "... expected exception but exception was not thrown !" << std::endl;
//		return false;
//	}
//	catch (std::exception e)
//	{
//		std::cout << "expecting exception..... ";
//	}
//	std::cout << std::endl;
//
//	std::cout << "Testing Stack with datatype string, using constructor with initial capacity .... " << std::endl;
//	Stack<std::string> sStack(2);
//
//	std::cout << "Testing expanding internal array pushinh A, B, C and D .... ";
//	sStack.push("A");
//	sStack.push("B");
//	sStack.push("C");
//	sStack.push("D");
//
//	resStr = "";
//	controlStr = "DCBA";
//
//	while (!sStack.is_empty())
//	{
//		resStr += sStack.pop();
//	}
//	if (resStr != controlStr)
//	{
//		std::cout << " expected " << controlStr << " but got  " << resStr << std::endl;
//		return false;
//	}
//	std::cout << std::endl;
//	return true;
//}
//
//bool testingQueue()
//{
//	std::cout << "QUEUE TEST" << std::endl << std::endl;
//	std::cout << "Testing Queue with datatype int .... " << std::endl;
//	Queue<int> iQueue;
//
//	std::cout << "New element should be empty .... ";
//	if (!iQueue.is_empty())
//	{
//		std::cout << " but was not" << std::endl;
//		return false;
//	}
//	std::cout << std::endl;
//
//
//	std::cout << "Engueueing integers 10,20 and 30....: ";
//	for (int i = 1; i <= 3; i++)
//	{
//		iQueue.enqueue(i * 10);
//	}
//	std::cout << std::endl;
//
//	std::string resStr;
//	std::string controlStr = "10,10 20,20 30,30 ";
//	std::cout << "Using peek and dequeue until empty .....";
//	while (!iQueue.is_empty())
//	{
//		resStr += std::to_string(iQueue.peek());
//		resStr += "," + std::to_string(iQueue.dequeue()) + " ";
//	}
//	if (resStr != controlStr)
//	{
//		std::cout << " expected " << controlStr << " but got  " << resStr << std::endl;
//		return false;
//	}
//	std::cout << std::endl;
//
//	std::cout << "Mixing enqueue and dequeu  ......  ";
//	for (int i = 1; i < 5; i++)
//		iQueue.enqueue(i * 11);
//	for (int i = 1; i < 3; i++)
//		iQueue.dequeue();
//	for (int i = 5; i < 8; i++)
//		iQueue.enqueue(i * 11);
//	resStr = "";
//	while (!iQueue.is_empty())
//		resStr += std::to_string(iQueue.dequeue()) + " ";
//	controlStr = "33 44 55 66 77 ";
//	if (resStr != controlStr)
//	{
//		std::cout << " expected " << controlStr << " but got  " << resStr << std::endl;
//		return false;
//	}
//	std::cout << std::endl;
//
//	std::cout << "Using peek on empty queue ";
//	try
//	{
//		iQueue.peek();
//		std::cout << ".... expected exception but exception was not thrown !" << std::endl;
//		return false;
//	}
//	catch (std::exception e)
//	{
//		std::cout << "expecting exception..... ";
//	}
//	std::cout << std::endl;
//
//	std::cout << "Using dequeue on empty queue ";
//	try
//	{
//		iQueue.dequeue();
//		std::cout << "... expected exception but exception was not thrown !" << std::endl;
//		return false;
//	}
//	catch (std::exception e)
//	{
//		std::cout << "expecting exception..... ";
//	}
//	std::cout << std::endl;
//
//	std::cout << "Testing Queue with datatype string .... " << std::endl;
//	Queue<std::string> sQueue;
//
//	std::cout << "Engueueing A, B, C and D.... ";
//	sQueue.enqueue("A");
//	sQueue.enqueue("B");
//	sQueue.enqueue("C");
//	sQueue.enqueue("D");
//
//	resStr = "";
//	controlStr = "ABCD";
//
//	while (!sQueue.is_empty())
//	{
//		resStr += sQueue.dequeue();
//	}
//	if (resStr != controlStr)
//	{
//		std::cout << " expected " << controlStr << " but got  " << resStr << std::endl;
//		return false;
//	}
//	std::cout << std::endl;
//	return true;
//}
//
//int main()
//{
//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
//	if (!testingStack())
//	{
//		std::cout << "TEST DID NOT PASS" << std::endl;
//		return 1;
//	}
//	std::cout << std::endl << "TEST PASSED" << std::endl;
//	std::cout << "****************************************** " << std::endl;
//	
//	if (!testingQueue())
//	{
//		std::cout << "TEST DID NOT PASS" << std::endl;
//		return 2;
//	}
//	std::cout << std::endl << "TEST PASSED" << std::endl;
//	std::cout << "****************************************** " << std::endl;
//
//	return 0;
//}