#include<iostream>
#include<algorithm>
using namespace std;
int main() {

	string Items[10];
	

	int room = 1;
	string input;

	cout << " You are wake up in a cofen in a huge church. You see the doors open and you see a silowet behind a closed gate in the distance walking away, you have to get out! " << endl << endl;

	do {
		switch (room) {
		case 1:
			cout << " You look around the church. it's dusty, like it's abandond fo years. The benches are very worn down and looks like it will break if you try to sit on them. seems like the only way out is to the north. " << endl;
			cin >> input;
			if (input == "N")
				room = 2;
			else
				cout << "You can't go there " << endl;
			break;
		case 2:
			cout << " You go trough the gates. You can see " << endl;
			cin >> input;
			if (input == "W")
				room = 3;
			else if (input == "E")
				room = 5;
			else
				cout << "You can't go there " << endl;
			break;
		case 3:
			cout << " " << endl;
			cin >> input;
			if (input == "E")
				room = 2;
			else if (input == "S")
				room = 4;
			else
				cout << "You can't go there " << endl;
			break;

		case 4:
			cout << " " << endl;
			cin >> input;
			if (input == "N")
				room = 3;
			if (input.compare("pick up") == 0)
				Items[0] = "rusty key";
			else
				cout << "You can't go there " << endl;
			break;
		case 5:
			cout << " " << endl;
			cin >> input;
			if (input == "W")
				room = 2;
			else if (input == "S")
				room = 6;
			else
				cout << "You can't go there " << endl;
			break;
		case 6:
			cout << " " << endl;
			cin >> input;
			if (input == "N")
				room = 5;
			if (input.compare("go south")) {
				if (Items[0].compare("key") != 0)
					cout << " You tried to break open the door but it won't buge. You need a key " << endl;
				else
					room = 7;
			}
			else
				cout << "You can't go there" << endl;

		}
	
	
	} while (input != "q");


}
