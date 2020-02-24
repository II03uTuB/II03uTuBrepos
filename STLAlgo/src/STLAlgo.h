#ifndef STLALGO_STLALGO_H
#define STLALGO_STLALGO_H


#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <list>
#include <vector>
#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <cmath>


using namespace std;


string ReverseWord(string& reverseString);

string FindThirdWord(string& stringForSearch);

int FindMostShort(string& stringForSearch);

string ConvertOctToHex(const string& number);

string FindSentenceInFile(string &fileName, unsigned count); 

#endif //STLALGO_STLALGO_H
