// Braille_project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include <fstream>
#include <string>
#include<vector>
using namespace std;

int checkType(char character) {
	try {
		if (int(character)) {
			throw 4;
		}
		if (char(character)) {
			throw 1;
		}
		if (double(character)) {
			throw 4;
		}
		if ((character)) {
			throw 4;
		}
	}
	catch (int e) {

	}
}
int main()
{
	vector<char> listOfCharacters;
	vector<int> characterTypes;
	/*0 space
	1 letter
	2 capital letter
	3 decimal point
	4 number
	5 punctuation
	6 switch from capital to small
	7 switch from small to capital
	8 switch from number to letter
	9 switch from letter to number*/
	string tempContent;
	string content;
	string x;
	cout << "enter name of file: ";
	cin >> x;
	ifstream inFile;
	inFile.open(x + ".txt");
	while (!inFile.eof()) {
		inFile >> tempContent;
		content += tempContent;
		content += " ";
	}
	for (int i = 0; i<content.size(); i++) {
		listOfCharacters.push_back(content[i]);
	}
	for (int i = 0;i < listOfCharacters.size();i++) {

	}
	for (unsigned int j = 0;j < listOfCharacters.size();j++) {
		cout << listOfCharacters.at(j);
	}

	system("pause");
	return 0;
}

