#include<iostream>
#include<algorithm>
using namespace std;

//global variables (Usualy bad)

string Items[5];
int turns = 0;


int main() {


	//local variables
	int room = 1;
	string input;
	bool inroom = false;
	string invent = input;
	cout << " You wake up in a cofen in a huge church. You see the doors open and you see a silhouette behind a closed gate in the distance walking away, you have to get out! " << endl << endl;

	do {
		
		
		if (invent == "Items" || "items")
			for (int i = 0; i < 5; i++)
				cout << Items[i] << endl;
		switch (room) {
		case 1:
			cout << " You look around the church. it's dusty, like it's abandoned for years. The benches are very worn down and look like they will break if you try to sit on them. seems like the only way out is to the north. " << endl;
			cin >> input;
			if (input == "N")
				room = 2;
			else if (input == "inventory" || input == "Inventory") {
				cout << "Entering imventory." << endl;
			}
			else
				cout << "You can't go there " << endl;
			break;
		case 2:
			if (inroom == true) {
				cout << " You are back at the entrance of the church with the gate. You can go to the east or west paths. " << endl;
				inroom = true;
			}
			else if (inroom == false) {
				cout << " You go through the doors. The church seems to have a graveyard, you see a huge gate in front preventing you from escaping the graveyard. While you were watching the area the church door's close and lock themselves.There are some paths on you east and west " << endl;
				inroom = true;
			}
			cin >> input;
			if (input == "W")
				room = 3;
			else if (input == "E")
				room = 5;
			else if (input == "inventory" || input == "Inventory") {
				cout << "Entering imventory." << endl;
			}
			else
				cout << "You can't go there " << endl;
			break;
		case 3:
			cout << " The graves on the west side seem to be mostly intact, you see that the people who died are from the 19th century; meaning that the church is old. You can go south or can go back west to the entrance. " << endl;
			cin >> input;
			if (input == "E")
				room = 2;
			else if (input == "S")
				room = 4;
			else if (input == "inventory" || input == "Inventory") {
				cout << "Entering imventory." << endl;
			}
			else
				cout << "You can't go there " << endl;
			break;
		case 4:
			cout << " The is a huge pile of ruble in the middle of the road preventing you from continueing. You can go back north " << endl;
			cin >> input;
			if (input == "N")
				room = 3;
			else if (input.compare("pick up") == 0)
				Items[0] = "rusty key";
			else if (input == "inventory" || input == "Inventory") {
				cout << "Entering imventory." << endl;
			}
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
			else if (input == "inventory" || input == "Inventory") {
				cout << "Entering imventory." << endl;
			}
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
			else if (input == "inventory" || input == "Inventory") {
				cout << "Entering imventory." << endl;
			}
			else
				cout << "You can't go there" << endl;
			break;
		case 7:
			cout << " " << endl;
			cin >> input;
			if (input == "N")
				room = 6;

			else if (input == "W")
				room = 8;
			else if (input == "inventory" || input == "Inventory") {
				cout << "Entering imventory." << endl;
			}
			else
				cout << "You can't go there " << endl;
			break;
		case 8:
			cout << " " << endl;
			cin >> input;
			if (input == "E")
				room = 7;
			else if (input == "W")
				room = 9;
			else if (input == "inventory" || input == "Inventory") {
				cout << "Entering imventory." << endl;
			}
			else
				cout << "You can't go there " << endl;
			break;
		case 9:
			if (input == "E")
				room = 8;
			if (input.compare("pick up") == 0)
				Items[0] = " Wing key ";
			else if (input == "inventory" || input == "Inventory") {
				cout << "Entering imventory." << endl;
			}
			else
				cout << "You can't go there " << endl;
			break;
		}


	} while (input != "q");


}
