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

int main()
{
	char again = 'y';
	do {
		int selection;
		string line, word, fileName;
		int currentLine = 1;
		Concordance words;

		cout << "This program will read through the selected file and create an output file that contains a concordance of the words in the original file." << endl;
		cout << "Please type a number associated to one of the files below or type 0 to close the program:" << endl;
		cout << "[1] Modest Proposal" << endl;
		cout << "[2] Apology" << endl;
		cout << "[3] Wizard Of Oz" << endl;
		cout << "[4] Moby Dick" << endl;
		cout << "[5] Short Story" << endl;
		cin >> selection;
		cout << "Generating concordance file..." << endl;

		// Stream selected file
		ifstream infile;
		switch (selection) {
		case 1: infile.open("C:\\Users\\Justin\\Documents\\txtFiles\\ModestProposal_W.txt");
			fileName = "ModestProposal";
			break;
		case 2: infile.open("C:\\Users\\Justin\\Documents\\txtFiles\\Apology_W.txt");
			fileName = "Apology";
			break;
		case 3: infile.open("C:\\Users\\Justin\\Documents\\txtFiles\\WizardOfOz_W.txt");
			fileName = "WizardofOz";
			break;
		case 4: infile.open("C:\\Users\\Justin\\Documents\\txtFiles\\MobyDick_W.txt");
			fileName = "MobyDick";
			break;
		case 5: infile.open("C:\\Users\\Justin\\Documents\\txtFiles\\ShortHistory_W.txt");
			fileName = "ShortHistory";
			break;
		case 0: again = 'n';
			break;
		default: cout << "Please input a number associated to one of the files." << endl;
			break;
		}

		// Read file line by line
		while (getline(infile, line)) {

			// Increment the current line for each line
			currentLine++;

			// Read each word in the line
			istringstream sentence(line);
			while (sentence >> word) {

				// Transform each word to lower case
				transform(word.begin(), word.end(), word.begin(), ::tolower);

				// Remove leading and trailing special characters from each word
				const char *Char2Cut = "!\"#'()*+,-./:;<>?@[]_`{|}~";
				word.erase(word.find_last_not_of(Char2Cut) + 1).erase(0, word.find_first_not_of(Char2Cut));

				// If the word is already in the words vector, only add the current line
				auto it = find_if(words.begin(), words.end(), [&word](Word& obj) {return obj.getWord() == word; });

				if (it != words.end()) {
					// found element. it is an iterator to the first matching element.
					auto index = distance(words.begin(), it);
					words.getIndex(index).setLineNumber(currentLine);
				}

				// If the word isn't in the vector, add the word and current line
				else {
					Word temp(word, currentLine);
					words.addToCollection(temp);
				}
			}
		}

		words.removeNonWords();
		words.sortCollection();
		if (again == 'y') {
			words.saveCollection(fileName);
		}
		else {

		}
		words.clearCollection();

	} while (again == 'y');

	return 0;
}
