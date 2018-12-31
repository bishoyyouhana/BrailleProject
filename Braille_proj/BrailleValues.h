#pragma once
#ifndef BRAILLE_PROJ_H
#define BRAILLE_PROJ_H

#include"stdafx.h"
#include <string>
#include <sstream> 
using namespace std;
int brailleLetters[];
int brailleNumber[];
int braillePunctuation[];
int brailleDecimalPoint[];
int brailleSpace[];
int braillePreIdentifires[];
char getPunctuation(int number);
string ConvertToString(int number);
char getAlphabet(char theLetter);
int translate(char x, int type, int typePrev);

#endif