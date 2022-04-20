#include<iostream>
#include<algorithm>
using namespace std;


int room = 1;
string item[] = { "bad key" "good key" "rock" "The New Windows 11" };

int main() {

	char input;

	do {
		switch (room) {
		case 1:
			cout << "you are in room one. you can go (s)outh" << endl;
			cin >> input;
			if (input == 's')
				room = 3;
			else
				cout << "You can't go there " << endl;
			break;

		case 2:

			if (item[0].compare("bad key") == 0) {
				cout << "youre now in room two. you can go (e)ast" << endl;
				cin >> input;
				if (input == 'e')
					room = 3;
				else
					cout << "You can't go there " << endl;
				break;
			}

			if (item[0].compare("bad key") != 0) {
				cout << "youre now in room two. There seem to be a key, (p)ick it up. you can go (e)ast" << endl;
				cin >> input;
				if (input == 'e')
					room = 3;
				else if (input == 'p') {
					item[0] = "bad key";
					cout << "You got the bad key" << endl;
				}
				else
					cout << "You can't go there " << endl;
				break;
			}		
		case 3:
			cout << "youre now in room three. you can go (n)orth, (e)ast, (s)outh or (w)est. the south is blocked by a gate with a key lock" << endl;
			cin >> input;
			if (input == 'n')
				room = 1;
			else if (input == 'e')
				//if statement cehcking if you have key
				room = 4;
			else if (input == 's' && item[0] == "bad key")
				room = 5;
			else if (input == 'w')
				room = 2;
			else
				cout << "You can't go there " << endl;
			break;

		case 4:
			cout << "youre now in room four. you can go (w)ast" << endl;
			cin >> input;
			if (input == 'w')
				room = 3;
			else
				cout << "You can't go there " << endl;
			break;
		case 5:

			if (item[3].compare("The New Windows 11") == 0) {
				cout << "youre now in room five. you can go (n)orth" << endl;
				cin >> input;
				if (input == 'n')
					room = 3;
				else
					cout << "You can't go there " << endl;
				break;
			}

			else if (item[3].compare("The New Windows 11") != 0) {
				cout << "youre now in room five. you can go (n)orth... Hold on! what is that? You should (p)ick it up" << endl;
				cin >> input;
				if (input == 'n')
					room = 3;
				else if (input == 'p') {
					cout << "NOOOOOO NOT THE WINDOWS 11!!!" << endl;


					item[3] = "The New Windows 11";
				}
				else
					cout << "You can't go there " << endl;
				break;
			}
		}
		
	} while (1);

}
