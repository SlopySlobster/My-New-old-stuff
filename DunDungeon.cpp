#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

//global variables (Usualy bad)

string Items[5];
string Person[3];
int turns = 20;
int Health = 1;



int main() {


	//local variables
	int room = 1;

	string input;
	bool inroom = false;
	bool gotpotato = false;
	string invent = input;
	cout << " You wake up in a cofen in a huge church. You see the doors open and you see a silhouette behind a closed gate in the distance walking away, you have to get out! " << endl << endl;
	cout << " As you get up you start feeling very hungry. You better get out quicly before you starve " << endl;

	do {
		cout << "You have " << turns << " turns left " << endl;

		if (invent == "Items" || "items")
			for (int i = 0; i < 5; i++)
				cout << Items[i] << endl;
		switch (room) {
		case 1:
			cout << " You look around the church. it's dusty like it's abandoned for years. The benches are very worn down and look like they will break if you try to sit on them. seems like the only way out is to the north. " << endl;
			getline(cin, input);
			if (input.compare("go north") == 0) {
				room = 2;
				turns -= 1;
			}
			else if (input == "inventory" || input == "Inventory") {
				cout << "Entering inventory." << endl;
			}
			if (Items[1].compare("potato") == 0 && input.compare("eat potato") == 0) {
				turns += 5;
				Items[1] = "";
			}
			else
				cout << "You can't go there " << endl;
			break;
		case 2:
			if (inroom == true) {
				cout << " You are back at the entrance of the church with the gate. You can go to the east or west paths. If you have the key to exit the church go north " << endl;
				inroom = true;
			}
			else if (inroom == false) {
				cout << " You go through the doors. The church seems to have a graveyard, you see a huge gate in front preventing you from escaping the graveyard. While you were watching the area the church doors close and locked themselves. There are some paths on your east and west " << endl;
				inroom = true;
			}
			getline(cin, input);
			if (input.compare("go west") == 0) {
				room = 3;
				turns -= 1;
			}
			else if (input.compare("go east") == 0) {
				room = 5;
				turns -= 1;
			}
			if (input.compare("go north") == 0) {
				if (Items[4].compare("Wing Key") != 0) {
					cout << " The gate is very tall and sturdy, it looks like you need a special key " << endl;
				}
				else {
					room = 10;
					turns -= 1;
				}
			}
			else if (input == "inventory" || input == "Inventory") {
				cout << "Entering inventory." << endl;
			}
			if (Items[1].compare("potato") == 0 && input.compare("eat potato") == 0) {
				turns += 5;
				Items[1] = "";
			}
			else
				cout << "You can't go there " << endl;
			break;
		case 3:
			cout << " The graves on the west side seem to be mostly intact, you see that the people who died are from the 18th century; meaning that the church is old. You can go south or can go back west to the entrance. " << endl;
			getline(cin, input);
			if (input.compare("go east") == 0) {
				room = 2;
				turns -= 1;
			}
			else if (input.compare("go south") == 0) {
				room = 4;
				turns -= 1;
			}
			else if (input == "inventory" || input == "Inventory") {
				cout << "Entering inventory." << endl;
			}
			if (Items[1].compare("potato") == 0 && input.compare("eat potato") == 0) {
				turns += 5;
				Items[1] = "";
			}
			else
				cout << "You can't go there " << endl;
			break;
		case 4:
			if (Items[0].compare("rusty key") == 0) {
				cout << " There is a huge pile of rubble in the middle of the road preventing you from continuing. You can go back north " << endl;
			}
			else if (Items[0].compare("rusty key") != 0) {
				cout << "A side of the chuch seems to have colapse and a huge pile of rubble in the way. You see that there is a small rusty key that says 'side gate' " << endl;
			}

			getline(cin, input);
			if (input.compare("go north") == 0) {
				room = 3;
				turns -= 1;
			}
			else if (input.compare("pick up") == 0)
				Items[0] = "rusty key";
			else if (input == "inventory" || input == "Inventory") {
				cout << "Entering inventory." << endl;
			}
			if (Items[1].compare("potato") == 0 && input.compare("eat potato") == 0) {
				turns += 5;
				Items[1] = "";
			}
			else
				cout << "You can't go there " << endl;
			break;
		case 5:
			cout << " The graves on the east side are very worn out, you can't tell what they say other than the date '1917'. you can go south or go back west. " << endl;
			getline(cin, input);
			if (input.compare("go west") == 0) {
				room = 2;
				turns -= 1;
			}
			else if (input.compare("go south") == 0) {
				room = 6;
				turns -= 1;
			}
			else if (input == "inventory" || input == "Inventory") {
				cout << "Entering inventory." << endl;
			}
			if (Items[1].compare("potato") == 0 && input.compare("eat potato") == 0) {
				turns += 5;
				Items[1] = "";
			}
			else
				cout << "You can't go there " << endl;
			break;
		case 6:
			cout << " there is a small gate preventing you from going to the other side, looks like you need a key " << endl;
			getline(cin, input);
			if (input.compare("go north") == 0) {
				room = 5;
				turns -= 1;
			}
			if (input.compare("go south") == 0) {
				if (Items[0].compare("rusty key") != 0) {
					cout << " You tried to break open the gate but it won't buge. You need a key " << endl;
				}
				else {
					room = 7;
					turns -= 1;
				}
			}
			else if (input == "inventory" || input == "Inventory") {
				cout << "Entering inventory." << endl;
			}
			if (Items[1].compare("potato") == 0 && input.compare("eat potato") == 0) {
				turns += 5;
				Items[1] = "";
			}
			else
				cout << "You can't go there" << endl;
			break;
		case 7:
			cout << " This side of the gate had a small garden. You see that most of the plants are dead and spoiled but you notice that a small potato is still edible. You can go back north or go west. " << endl;
			getline(cin, input);


			if (gotpotato == false) {
				if (input.compare("pick up") == 0)
					Items[1] = "potato";
				gotpotato = true;
			}


			if (input.compare("go north") == 0) {
				room = 6;
				turns -= 1;
			}


			else if (input.compare("go west") == 0) {
				room = 8;
				turns -= 1;
			}
			else if (input == "inventory" || input == "Inventory") {
				cout << "Entering inventory." << endl;
			}
			if (Items[1].compare("potato") == 0 && input.compare("eat potato") == 0) {
				turns += 5;
				Items[1] = "";
			}
			else
				cout << "You can't go there " << endl;
			break;
		case 8:
			cout << " This part of the path is baron, there is nothing here. You can go west or east " << endl;
			getline(cin, input);
			if (input.compare("go east") == 0) {
				room = 7;
				turns -= 1;
			}
			else if (input.compare("go west") == 0) {
				room = 9;
				turns -= 1;
			}
			else if (input == "inventory" || input == "Inventory") {
				cout << "Entering inventory." << endl;
			}
			if (Items[1].compare("potato") == 0 && input.compare("eat potato") == 0) {
				turns += 5;
				Items[1] = "";
			}
			else
				cout << "You can't go there " << endl;
			break;
		case 9:
			if (Items[4].compare("Wing Key") != 0) {
				cout << " You see that there is an incinerator that is turned on. Suddenly a ghost apears! " << endl;
				cout << " He says ' You wish to get out of this place before ending like me... very well. I will give you the key out of here' " << endl;
				cout << " 'But I feel a bit lonely and bored so You'll have to answer something first. If you answer me incorrect; this incinerator will seal your fate' " << endl;
				cout << " 'My question is: What side of the grave is younger? The west or east?' " << endl;
	

				getline(cin, input);
				if (input.compare("East") == 0 || input.compare("east") == 0 || input.compare("east side") == 0 || input.compare("East side") == 0) {
					cout << " 'Correct' says the ghost, then the incinerator turns off and you look inside the incinerator, Inside there was a key in the shape of wings. When you looked up the ghost was gone " << endl;
					cout << " You took the Wing Key and know it's for the gate entrance " << endl;
					Items[4] = "Wing Key";
				}
				else
					Health -= 100;
			}
			else if (Items[4].compare("Wing Key") == 0)
				cout << "There is no reason to be here. You can go east. " << endl;
			
			getline(cin, input);
			if (input.compare("go east") == 0) {
				room = 8;
				turns -= 1;
			}
			else if (input == "inventory" || input == "Inventory") {
				cout << "Entering inventory. " << endl;
			}
			else
				cout << "You can't go there " << endl;
			break;
		case 10:
			cout << " You exited the gate, the only way foward is the forest. you dicide that you are not going to go back to the church. " << endl;
			getline(cin, input);
			if (input.compare("go north") == 0)
				room = 11;
			if (Items[1].compare("potato") == 0 && input.compare("eat potato") == 0) {
				turns += 5;
				Items[1] = "";
			}
			else if (input == "inventory" || input == "Inventory") {
				cout << "Entering inventory. " << endl;
			}
			else
				cout << "You can't go there " << endl;
			break;
		case 11:
			cout << "While you were going thorue the woods the old man suddenly stops you!" << endl;
			cout << "He say'Don't wory, I won't kill you. I see you are not a worty decoration in this place. Now go away' You then ran away and escaped the forest. " << endl;
			input = "q";
			break;
		}//end switch


	} while (input != "q" && turns > 0 && Health > 0);

	if (turns <= 0) {
		cout << " You fell to the ground unable to bear the hunger. You weren't able to escape and you died " << endl;
	}
	else if (Health <= 0) {
		cout << " The incinerator exploded and you were burned badly. The ghost then says 'Now I won't be lonely anymore.' you died. " << endl;
	}

}


void NPC(int x) {
	string Person[3];

	
}
