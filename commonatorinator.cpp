#include<iostream>
#include<string>

using namespace std;

void mostPopularWord(string words[], const int WORDS_SIZE) {

	string curent;
	string mostpopularword="";
	int higest = 0;

	for (int i = 0; i < WORDS_SIZE; i++) {
		int amout = 0;

		for (int j = 0; j < WORDS_SIZE; j++) {
			
			if (words[i] == words[j]) {
				amout++;

			}

		}

		if (amout >= higest) {
			higest = amout;	
			mostpopularword = words[i];

		}

	}

	cout << "The most popular word: " << mostpopularword << endl;
	cout << "Frequency: " << higest << endl;
	cout << "Found at pos: ";

	for (int i = 0; i < WORDS_SIZE; i++) {

		if (words[i] == mostpopularword) {
			cout << i << " ";

		}

	}
	cout << endl;

}

int main() {

	const int WORDS_SIZE = 5;
	string words[WORDS_SIZE] = { "apple", "corn", "corn", "apple", "lettuce" };

	mostPopularWord(words, WORDS_SIZE);

}
