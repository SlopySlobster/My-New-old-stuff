#include<iostream>
#include<string>

using namespace std;

void greeting();
void gesture();
int calc_winner(int throw1, int throw2);
int throwing(string thrower, string opponent);

string gestures[5] = { "Rock", "Paper", "Scissors", "Lizard", "Spock" };
int winloss[5][5] = {
	2,0,1,1,0,
	1,2,0,0,1,
	0,1,2,1,0,
	0,1,0,2,1,
	1,0,1,0,2
};

int main() {
	greeting();
	string name1;
	string name2;

	cout << "Please enter Player 1's name: ";
	cin >> name1;
	cout << endl;
	cout << "Please enter Player 2's name: ";
	cin >> name2;

	int throw1 = throwing(name1, name2);
	int throw2 = throwing(name2, name1);

	int winner = calc_winner(throw1, throw2);

	while (winner == 2) {
		cout << "It's a tie; both players will throw again." << endl;
		throw1 = throwing(name1, name2);
		throw2 = throwing(name2, name1);
		winner = calc_winner(throw1, throw2);
	}
	if (winner == 1) {
		cout << gestures[throw1] << "defeats" << gestures[throw2] << "." << endl;
		cout << name1 << "defeats" << name2 + "." << endl;
	}
	else {
		cout << gestures[throw2] << "defeats" << gestures[throw1] << "." << endl;
		cout << name2 << "defeats" << name1 + "." << endl;
	}
}

void greeting() {
	cout << "welcome to rock paper scisors" << endl;

}

void gesture() {
	cout << "Your choices are:" << endl;
	cout << "(0) Rock, (1) Paper, (2) Scissors" << endl;

}

int throwing(string thrower, string opponent) {
	int the_throw;
	cout << "It is" << thrower << "'s turn." << endl;
	gesture();
	cout << "No peeking, " << opponent << "." << endl;
	cout << thrower << ", what is your throw? " << endl;
	cin >> the_throw;

	while (the_throw < 0 || the_throw >= sizeof(gestures)) {
		cout << "Invalid choice; try again" << endl;
		cout << thrower << ", what is your throw? " << endl;
		cin >> the_throw;
	}
	cout << thrower<< "throws"<< gestures[the_throw] << "." << endl;
	return(the_throw);

}

int calc_winner(int throw1, int throw2) {
	return(winloss[throw1][throw2]);
}
