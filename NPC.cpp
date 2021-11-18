#include<iostream>
#include<Windows.h>
#include<ctime>
using namespace std;

void NPC(int );

int main() {
	srand(time(NULL));
	while (1) {
		NPC();
		system("pause");
	}
}

int input;
int main() {

	int room = 1;

	cout << "you enter a house " << endl;
	do {

		switch (room) {
		case 1:
			cout << " you are in room 1 " << " you can go to the next room 'n' " << endl;
			cin >> input;
			if (input == 'n')
				room = 2;
			else
				cout << " press n " << endl;
			break;
		case 2:
			cout << " you are in room 2 " << " you can go to the next room 'n' " << endl;
			cin >> input;
			if (input == 'n')
				room = 3;
			else
				cout << " press n " << endl;
			break;
		case 3:
				cout << " you are in the last room " << endl;
		}
	}

}

//function definition

void NPC(int x) {
	int num;
	string People[3];
	if (x == 0) {
		cout << " There is an old lady in the room " << endl;
		num = rand() % 3+1;
		if (num == 1) {
			cout << " 'Hello my child. I made some cokies. please take some.' she shows you a tray of cokies, the cokies are all bured, You don't take any " << endl;
			cout << " 'TAKE THEM!' you take all the cokies ";
		}
		else if (x == 2) {
			cout << " an old lady is in the room " << endl;
			cout << " 'Spirits away. Spirits away!' she then starts to hit you. you proced to tell her you are not a spirit. she stops hiting you but is looks at you closely. " << endl;
		}


		}


}
