#include<iostream>
#include<algorithm>
using namespace std;

//global variables (Usualy bad)
void shop();
string Items[10];
int turns = 0;


int main() {

	
	//local variables
	int room = 1;
	string input;

	cout << " You are wake up in a cofen in a huge church. You see the doors open and you see a silowet behind a closed gate in the distance walking away, you have to get out! " << endl << endl;

	do {
		if (input == "Items" || "items")
			for (int i = 0; i < 5; i++)
				cout << Items[i] << endl;
		switch (room) {
		case 1:
			cout << " You look around the church. it's dusty, like it's abandond fo years. The benches are very worn down and looks like it will break if you try to sit on them. seems like the only way out is to the north. " << endl;
			cin >> input;
			if (input == "N")
				room = 2;
			else if (input == "p") {
				cout << " You found a shop under one of the curtands! " << endl;
				shop();
			}
			else
				cout << "You can't go there " << endl;
			break;
		case 2:
			cout << " You go trough the doors. The church seems to have a grave yard, you see a huge gate in front preventing you from escaping the grave yard. There are some pathes on you east and west " << endl;
			cin >> input;
			if (input == "W")
				room = 3;
			else if (input == "E")
				room = 5;
			else
				cout << "You can't go there " << endl;
			break;
		case 3:
			cout << "  " << endl;
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
			else if (input.compare("pick up") == 0)
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
			break;
		case 7:
			cout << " " << endl;
			cin >> input;
			if (input == "N")
				room = 6;

			else if (input == "W")
				room = 8;
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
			else
				cout << "You can't go there " << endl;
			break;
		case 9:
			if (input == "E")
				room = 8;
			if (input.compare("pick up") == 0)
				Items[0] = " Wing key ";
			else 
				cout << "You can't go there " << endl;
			break;
		}
	
	
	} while (input != "q");


}



//*Write a function named "shop" that for the moment, takes no parametersand returns nothing.The function starts with a loop, and an NPC shopkeeper welcomes the player.The shopkeeper offers 3 - 4 items for sale, and asks the user if they'd like to buy something or quit. If the user selects an item, the shopkeeper places it in their inventory. 
void shop() {
	string input;
	do {
		cout << " Hoi I'm Tem, welcom to the tem shop " << endl;
		cout << " press c to buy cheap trash ($1), t for trash($12), and e for expensive trash($500) " << endl;
		cout << " press g for gold and m for money " << endl;
		cout << " press q for quit" << endl;
		cin >> input;
		if (input == "c" || input == "t" || input == "e") {
			Items[4] = "trash";
			cout << " You got trash... for some reason " << endl;
		}
		else if (input == "g") {
			Items[5] = "gold";
			cout << " The gold is very heavy " << endl;
		}
		else if (input == "m") {
			Items[6] = "money";
			cout << " You got $10 " << endl;
		}
	} while (input != "q");
}
