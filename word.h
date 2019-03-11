#ifndef WORD_H
#define WORD_H
#include "string"
#include "vector"

using namespace std;

class Word {
private: 
	string _word;
	vector<int> _lineNumbers;
public:
	void setWord(string word);
	string getWord();
	void setLineNumber(int number);
	vector<int> getLineNumbers();
	Word (string word, int number);
	Word() {};
};

#endif