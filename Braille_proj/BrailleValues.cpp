#include"stdafx.h"
#include <string>
#include <sstream> 
#include"BrailleValues.h"
using namespace std;

int brailleLetters[] = {100000 ,110000 , 100100,100110 ,100010 ,110100 ,110110 ,110010 ,010100 ,010110,101000 ,111000,101100 ,101110 ,101010,111100,111110,111010,011100,011110,101001,111001,010111,101101,101111,101011};//1    change to vector
int brailleNumber[] = {100000,110000,100100,100110,100010,110100,110110,110010,010100};//4     
int braillePunctuation[] = {010011,010000,011000,010010,001100,011001,011010,001110,001111,011010,010010,001010,011001,001011,001000,110001,001110,011011,011011,001001};//5  change to vector

int brailleDecimalPoint[] = { 0,1 };//3
int brailleSpace[] = { 0,1 };//0

int braillePreIdentifires[] = {000001,001111,000011}; 
//capital letter, number, letter,
char getPunctuation(int number) {
	char punctuation[] = {'.',',',';',':','/','?','!','@','#','+','-','*','"','"','\'','<','>','(',')','_'};
	for (int i = 0;i < 26;i++) {
		if (punctuation[i] == number) { return i; }
	}
	throw 6;
}

string ConvertToString(int number) {
	string Result;      
	ostringstream convert;   // stream used for the conversion
	convert << number;      // insert the textual representation of 'Number' in the characters in the stream
	Result = convert.str();
	return Result;
}

char getAlphabet(char theLetter) { //to avoid creating 2d vectors
	char letter[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	for (int i = 0;i<26;i++) {
		if (letter[i] == theLetter) { return i; }
	}
	throw 6;
}

int translate(char x, int type, int typePrev) {
	if (type == 3) { return brailleDecimalPoint[1]; }
	if (type == 0) { return brailleSpace[1];}
	switch (type) {
	case 1:
		if (typePrev == 4) { return stoi(ConvertToString(braillePreIdentifires[2]) + ConvertToString(brailleLetters[getAlphabet(x)])); }
		return brailleLetters[getAlphabet(x)];
	case 4:
		if (typePrev == 1) { return stoi(ConvertToString(braillePreIdentifires[1]) + ConvertToString(brailleLetters[getAlphabet(x)])); }
		return brailleNumber[int(x)] ;
	case 5:
		return brailleLetters[getPunctuation(x)];
		
	case 2:
		return stoi(ConvertToString(braillePreIdentifires[0])+ ConvertToString(brailleLetters[getAlphabet(x)]));
	}
	throw 5;
}
/*
if (checkType(content[i]) == 1 && checkType(content[i + 1] == 2)) { characterTypes.push_back(7); } // small to capital
if (checkType(content[i]) == 1 && checkType(content[i + 1] == 4)) { characterTypes.push_back(9); }    // letter to number
if (checkType(content[i]) == 4 && checkType(content[i + 1] == 1)) { characterTypes.push_back(8); }// number to letter
*/