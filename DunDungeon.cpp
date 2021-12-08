#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

//global variables (Usualy bad)

string Items[5];
int turns = 20;


int main() {


	//local variables
	int room = 1;

	string input;
	bool inroom = false;
	string invent = input;
	cout << " You wake up in a cofen in a huge church. You see the doors open and you see a silhouette behind a closed gate in the distance walking away, you have to get out! " << endl << endl;

	do {
		//turns -= 1;
		cout << "You have " << turns << " turns left " << endl;

		if (invent == "Items" || "items")
			for (int i = 0; i < 5; i++)
				cout << Items[i] << endl;
		switch (room) {
		case 1:
			cout << " You look around the church. it's dusty, like it's abandoned for years. The benches are very worn down and look like they will break if you try to sit on them. seems like the only way out is to the north. " << endl;
			getline(cin, input);
			if (input.compare("go north") == 0) {
				room = 2;
				turns -= 1;
			}
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
			getline(cin, input);
			if (input.compare("go west")) {
				room = 3;
				turns -= 1;
			}
			else if (input.compare("go east")) {
				room = 5;
				turns -= 1;
			}
			else if (input == "inventory" || input == "Inventory") {
				cout << "Entering imventory." << endl;
			}
			else
				cout << "You can't go there " << endl;
			break;
		case 3:
			cout << " The graves on the west side seem to be mostly intact, you see that the people who died are from the 18th century; meaning that the church is old. You can go south or can go back west to the entrance. " << endl;
			getline(cin, input);
			if (input.compare("go east")) {
				room = 2;
				turns -= 1;
			}
			else if (input.compare("go south")) {
				room = 4;
				turns -= 1;
			}
			else if (input == "inventory" || input == "Inventory") {
				cout << "Entering imventory." << endl;
			}
			else
				cout << "You can't go there " << endl;
			break;
		case 4:
			cout << " There is a huge pile of rubble in the middle of the road preventing you from continuing. You can go back north " << endl;
			getline(cin, input);
			if (input.compare("go north")) {
				room = 3;
				turns -= 1;
			}
			else if (input.compare("pick up") == 0)
				Items[0] = "rusty key";
			else if (input == "inventory" || input == "Inventory") {
				cout << "Entering imventory." << endl;
			}
			else
				cout << "You can't go there " << endl;
			break;
		case 5:
			cout << " The graves on the east side are very worn out, you can't tell what they say other than the date '1917'. you can go south or go back west. " << endl;
			getline(cin, input);
			if (input.compare("go west")) {
				room = 2;
				turns -= 1;
			}
			else if (input.compare("go south")) {
				room = 6;
				turns -= 1;
			}
			else if (input == "inventory" || input == "Inventory") {
				cout << "Entering imventory." << endl;
			}
			else
				cout << "You can't go there " << endl;
			break;
		case 6:
			cout << " there is a small gate preventing you from going to the other side, looks like you need a key " << endl;
			cin >> input;
			if (input.compare("go north")) {
				room = 5;
				turns -= 1;
			}
			if (input.compare("go south")) {
				if (Items[0].compare("key") != 0)
					cout << " You tried to break open the door but it won't buge. You need a key " << endl;

				else
					room = 7;
				turns -= 1;
			}
			else if (input == "inventory" || input == "Inventory") {
				cout << "Entering imventory." << endl;
			}
			else
				cout << "You can't go there" << endl;
			break;
		case 7:
			cout << " This side of the gate had a small garden. You see that most of the plants are dead and spoiled but you notice that a small potato is still edible. You can go back north or go west. " << endl;
			getline(cin, input);
			if (input.compare("go north")) {
				room = 6;
				turns -= 1;
			}

			else if (input.compare("go west")) {
				room = 8;
				turns -= 1;
			}
			else if (input == "inventory" || input == "Inventory") {
				cout << "Entering imventory." << endl;
			}
			else
				cout << "You can't go there " << endl;
			break;
		case 8:
			cout << " This part of the path is baron, there is nothing here. You can go west or east " << endl;
			getline(cin, input);
			if (input.compare("go east")) {
				room = 7;
				turns -= 1;
			}
			else if (input.compare("go west")) {
				room = 9;
				turns -= 1;
			}
			else if (input == "inventory" || input == "Inventory") {
				cout << "Entering imventory." << endl;
			}
			else
				cout << "You can't go there " << endl;
			break;
		case 9:
			cout << " You see that there is an incinerator that is turned on. Suddenly a ghost apears! " << endl;
			cout << " He says ' You wish to get out of this place before ending like me... very well. I will give you the key out of here' " << endl;
			cout << " 'But I feel a bit lonely and bored so You'll have to answer something first. If you answer me incorrect; this incinerator will seal you fate' " << endl;
			cout << " 'My question is: What side of the grave is younger? The left or right?' " << endl;

			if (input.compare("go east")) {
				room = 8;
				turns -= 1;
			}
			if (input.compare("pick up") == 0)
				Items[0] = " Wing key ";
			else if (input == "inventory" || input == "Inventory") {
				cout << "Entering imventory. " << endl;
			}
			else
				cout << "You can't go there " << endl;
			break;
		case 10:
			cout << " You exited the gate, the only way foward is the forest. you dicide that you are not going to go back to the church. " << endl;

		}


	} while (input != "q" && turns > 0);

	if (turns <= 0) {
		cout << " You fell to the ground unable to bear the hunger. You weren't able to escape and you died " << endl;
	}

}
