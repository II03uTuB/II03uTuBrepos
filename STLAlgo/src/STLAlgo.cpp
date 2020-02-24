#include "STLAlgo.h"


string ConvertOctToHex(const string& number)
{
	auto beginNumber = number.begin();
	if (number[0] == '-')
	{
		advance(beginNumber, 1);
	}

	if (number.length() == 0 || count_if(beginNumber, number.end(), [](char element)
		{
			return element < '0' || element > '7';
		}) != 0)
	{
		return "";
	}

	int value = 0;
	int degree = 0;
	for_each(number.rbegin(), number.rend(), [&value, &degree] (const char& element)
	{
		value += (static_cast<int>(element) - 48) * pow(8, degree++);
	});

	ostringstream stream;
	stream << hex << value;

	return stream.str();
}


string FindThirdWord(string& stringForSearch)
{
	int countWords = 0;
	istringstream stream(stringForSearch);
	ostringstream newString;
	string buffer;
	while(true)
	{
		if (stream.peek() == -1)
		{
			break;
		}
		stream >> buffer;
		if(countWords % 2 == 0 && countWords != 0)
		{
			newString << buffer + " ";
			countWords = 0;
		}
		else
		{
			++countWords;
		}
		buffer.clear();
	}
	
	return newString.str();
}


int FindMostShort(string& stringForSearch)
{
	int wordPositiion = 1;
	istringstream stream(stringForSearch);
	string buffer;
	vector<string> answer;
	stream >> buffer;
	answer.push_back(buffer);
	if(stringForSearch.length() == 0)
	{
		return -1;
	}
	while (true)
	{
		if (stream.peek() == -1)
		{
			break;
		}
		stream >> buffer;
		if (buffer < answer[0])
		{
			answer[0] = buffer;
			++wordPositiion;
		}
	}
	return wordPositiion;
}



string ReverseWord(string& reverseString)
{

	size_t firstWord = reverseString.find(' ');
	size_t lastWord = reverseString.rfind(' ');

	string leftString = reverseString.substr(0, firstWord);
	string rightString = reverseString.substr(lastWord + 1);

	reverseString.replace(lastWord + 1, reverseString.length() - lastWord, leftString);
	reverseString.replace(0, firstWord, rightString);

	return reverseString;
}
bool isEndOfSentence(char symbol) 
{
    static char separator[] {".!?\0"};
    return strchr(separator, symbol) != nullptr;
}

bool isEndOfWord(char symbol) 
{
    static char separator[] {" \"'<>[]{}():;, +=^&%$#@-\n .!?\0"};
    return strchr(separator, symbol) != nullptr;
}

string FindSentence(string text, unsigned count) 
{

    bool isCurrentSimbolEndOfWord = false;
    bool isPrevioseSimbolEndOfWord = false;
    bool isCurrentSimbolEndOfSentence = false;
    bool isSentenceStart = true;
    size_t wordBegin = 0;
    size_t sentenceBegin = 0;
    vector <string> words;

    for (auto i = 0; i <= text.length(); ++i) 
	{
        isCurrentSimbolEndOfWord = isEndOfWord(text[i]);
        isCurrentSimbolEndOfSentence = isEndOfSentence(text[i]);

        if (isPrevioseSimbolEndOfWord && !isCurrentSimbolEndOfWord) 
		{
            wordBegin = i;
            isSentenceStart = true;
        }
        if (!isPrevioseSimbolEndOfWord && isCurrentSimbolEndOfWord) 
		{
            words.push_back(text.substr(wordBegin, i - wordBegin));
        }
        if (isSentenceStart && isCurrentSimbolEndOfSentence) 
		{
            while (isEndOfWord(text[i])) 
			{
                ++i;
            }
            if (words.size() != count) 
			{

                text.replace(sentenceBegin, i - sentenceBegin, "");
                i -= (i - sentenceBegin);
            }
            sentenceBegin = i;
            words.clear();
            isSentenceStart = false;
        }
        isPrevioseSimbolEndOfWord = isCurrentSimbolEndOfWord;
    }

    return text;
}

string FindSentenceInFile(string &fileName, unsigned count) 
{
	ifstream iStream(fileName);
    if (!iStream.is_open())
	{
        throw "NULL";
	}

    string text;
    getline(iStream, text, static_cast<char>(-1));

    text = FindSentence(text, count);

    iStream.close();

	return text.c_str();
}
