#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int dates[] = { 1776, 1922, 1792, 1804, 1809, 1870, 1821 };
	int score = 0;
	int input;

	cout << "Welcome to the country founder quiz. " << endl;
	cout << "I will ask you what time a country was founded and you have to type the year it was founded." << endl;
	cout << "Only input the year of when the country was founded. Do not put the month/day." << endl;

	cout << "First question: When was the United States of America founded?" << endl;
	cin >> input;
	if (input == dates[0]) { //help by Kevin
		cout << "Correct" << endl;
		score += 1;
	}
	else
		cout << "Incorrect, The answer is 1776" << endl;

	cout << "Second question: When was the United Kingdom founded?" << endl;
	cin >> input;
	if (input == dates[1]) { //help by Kevin
		cout << "Correct" << endl;
		score += 1;
	}
	else
		cout << "Incorrect, The answer is 1922" << endl;

	cout << "Third question: When was the First French Republic founded?" << endl;
	cin >> input;
	if (input == dates[2]) { //help by Kevin
		cout << "Correct" << endl;
		score += 1;
	}
	else
		cout << "Incorrect, The answer is 1792" << endl;

	cout << "Fourth question: When was the First French Empire founded?" << endl;
	cin >> input;
	if (input == dates[3] || input == dates[4]) { //help by Kevin
		cout << "Correct" << endl;
		score += 1;
	}
	else
		cout << "Incorrect, The answer is 1804 or 1809" << endl;

	cout << "Fifth question: When was the Third French Republic founded?" << endl;
	cin >> input;
	if (input == dates[5]) { //help by Kevin
		cout << "Correct" << endl;
		score += 1;
	}
	else
		cout << "Incorrect, The answer is 1870" << endl;

	cout << "Sixth question: When was Mexico founded?" << endl;
	cin >> input;
	if (input == dates[6]) { //help by Kevin
		cout << "Correct" << endl;
		score += 1;
	}
	else
		cout << "Incorrect, The answer is 1821" << endl;

	cout << "The quiz has finished. Your score is " << score << " out of 6" << endl;
}
