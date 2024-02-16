#include <iostream>

using namespace std;

char encryptUpper(char letter, int shift_value) {

	if (65 <= letter && letter <= 90) {

		char new_letter = letter + shift_value;

		if (33 <= new_letter && new_letter <= 126) {

			return (new_letter);
		}

		else {

			return (letter);
		}

	}

	else {

		return (letter);
	}

}

int main() {

	char input1;
	int input2;

	cout << "Enter an uppercase letter to encrypt:" << endl;
	cin >> input1;

	cout << "Enter the encryption value:" << endl;
	cin >> input2;

	char output = encryptUpper(input1, input2);

	cout << "Letter " << input1 << " was encrypted to " << output << endl;
	
}
