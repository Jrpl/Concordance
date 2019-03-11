#include "pch.h"
#include "word.h"
#include <iostream>

using namespace std;

void Word::setWord(string word) {
	_word = word;
}

string Word::getWord() {
	return _word;
}

void Word::setLineNumber(int number) {
	_lineNumbers.push_back(number);
}

vector<int> Word::getLineNumbers() {
	return _lineNumbers;
}

Word::Word(string word, int number) {
	this->setWord(word);
	this->setLineNumber(number);
}