#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#endif

using namespace std;

// Functions
void getNames(string tempArr[], int array_length);
void getScores(string icecreams[], float icecreamsScores[], int totalAmount);
string* readFile(string filename);
int* countFilerows(string filename);
bool saveToFile(string filename, string names[], float scores[], int length);
string* splitString(string str, char ch);
bool is_number(string str);
int get_int(string message);
float get_float(string message);
string get_string(string message, bool acceptEmptyString = false);

// Menu parts
void showScore();
void scoreIcecreams();