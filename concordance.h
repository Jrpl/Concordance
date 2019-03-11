#ifndef CONCORDANCE_H
#define CONCORDANCE_H
#include "string"
#include "word.h"
#include <vector>

using namespace std;

class Concordance {
private:
	vector<Word> _wordCollection;

public:
	void addToCollection(Word word);
	void sortCollection();
	void saveCollection(string fileName);
	void removeNonWords();
	void moveItemToBack(size_t itemIndex);
	void clearCollection();
	Word getIndex(ptrdiff_t index);
	typedef vector<Word>::iterator iterator;
	iterator begin() { return _wordCollection.begin(); }
	iterator end() { return _wordCollection.end(); }
};

#endif