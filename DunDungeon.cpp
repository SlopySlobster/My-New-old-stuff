#include<iostream>
using namespace std;
int main() {

	int room = 1;
	char input;

	cout << " You are wake up in a cofen in a huge church. You see the doors open and you see a silowet behind a closed gate in the distance walking away, you have to get out! " << endl << endl;

	do {
		switch (room) {
		case 1:
			cout << " You look around the church. it's dusty, like it's abandond fo years. The benches are very worn down and looks like it will break if you try to sit on them. seems like the only way out is to the north. " << endl;
			cin >> input;
			if (input == 'N')
				room = 2;
			else
				cout << "You can't go there " << endl;
			break;
		case 2:
			cout << " You go trough the gates. You can see " << endl;
			cin >> input;
			if (room == 'W')
				room = 3;
			else if (room == 'E')
				room = 5;
			else
				cout << "You can't go there " << endl;
			break;
		case 3:
			cout << " " << endl;
			cin >> input;
			if (room == 'E')
				room = 2;
			else if (room == 'S')
				room = 4;
			else
				cout << "You can't go there " << endl;
			break;

		case 4:
			cout << " " << endl;
			cin >> input;
			if (room == 'N')
				room = 3;
			else
				cout << "You can't go there " << endl;
			break;
		case 5:
			cout << " " << endl;
			cin >> input;
			if (room == 'W')
				room = 2;
			else if (room == 'S')
				room = 6;
			else
				cout << "You can't go there " << endl;
			break;
		}
	
	
	} while (input != 'q');


}
