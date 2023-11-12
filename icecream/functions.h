#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#endif

using namespace std;
void getNames(string tempArr[], int array_length);
void getScores(string icecreams[], float icecreamsScores[], int totalAmount);
string* readFile(string filename);
int* countFilerows(string filename);
bool saveToFile(string filename, string names[], float scores[], int length);
string* splitString(string str, char ch);
void showScore();
void scoreIcecreams();