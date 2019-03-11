#include "pch.h"
#include "word.h"
#include "concordance.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <iterator>
#include <algorithm>

using namespace std;

void Concordance::addToCollection(Word word) {
	_wordCollection.push_back(word);
}

Word Concordance::getIndex(ptrdiff_t index) {
	return _wordCollection.at(index);
}

void Concordance::sortCollection() {
	sort(_wordCollection.begin(), _wordCollection.end(), [](Word& lhs, Word& rhs) {
		return lhs.getWord() < rhs.getWord();
	});
}

void Concordance::moveItemToBack(size_t itemIndex)
{
	auto it = _wordCollection.begin() + itemIndex;
	rotate(it, it + 1, _wordCollection.end());
}

void Concordance::removeNonWords() {
	for (int i = 0; i < _wordCollection.size(); i++)
	{
		string word = _wordCollection[i].getWord();
		for (int j = 0; j < word.length(); j++) {
			if (!isalpha(word[j]) || isblank(word[j])) {
				moveItemToBack(i);
				_wordCollection.pop_back();
				if (i > 0) {
					i--;
				}
				else {

				}
			}
			else {

			}
		}
	}
}

void Concordance::clearCollection() {
	_wordCollection.clear();
}

void Concordance::saveCollection(string fileName) {
	ofstream outfile;
	outfile.open(fileName + "_concordance.txt", ios::out);

	for (int i = 0; i < _wordCollection.size(); i++) {
		ostringstream oss;
		vector<int> temp = _wordCollection[i].getLineNumbers();

		// Get number of occurances
		int occurance = static_cast<int>(temp.size());

		// Convert all but the last element to avoid a trailing ","
		copy(temp.begin(), temp.end() - 1, ostream_iterator<int>(oss, ","));

		// Now add the last element with no delimiter
		oss << temp.back();

		// Print each word with number of occurances and line numbers
		outfile << _wordCollection[i].getWord() << "(" << occurance << "): " << oss.str() << endl;
	}
	outfile.close();
	cout << "Concordance file generated." << endl;
}