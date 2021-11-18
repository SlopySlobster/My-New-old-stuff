#include<iostream>
#include<Windows.h>
#include<ctime>
using namespace std;

void Monster();
//void Item();
void Battle(int MonsterHealth);
string items[5];

int main() {
	srand(time(NULL));
	while (1) {
		Monster();
		//Item();
		system("pause");
	}
}

int health = 500;

int input;
void Monster() {

	cout << " Your health is " << health << endl;

	while (input != 'q' || health != 0 && health > 0) {
		

		int num = rand() % 100 + 1;
		if (num <= 10) {
			cout << " spooky scary skeletons, and shivers down your spine! " << endl << endl;
			Battle(120 's');
			//health -= 20;
			//cout << " your health is now " << health << endl;
		}
		else if (num <= 15) {
			cout << " a creaper whants to give you a hug, and explode! " << endl << endl;
			Battle(40 'c');
			//health -= 200;
			//cout << " your health is now " << health << endl;
		}
		else if (num <= 40) {
			cout << " The zombies, were coming! " << endl << endl;
			Battle(70 'z');
			//health -= 30;
			//cout << " your health is now " << health << endl;
		}
		else if (num <= 60) {
			cout << " The itse bitse spider went up, then cralded to you! " << endl << endl;
			Battle(60 's');
			//health -= 10;
			//cout << " your health is now " << health << endl;
		}
		else if (num <= 80) {
			cout << " someone jumping in a porabala is coming to you, they must be a withch! " << endl << endl;
			Battle(100 'w');
			//health -= 60;
			//cout << " your health is now " << health << endl;
		}
		else
			cout << " you are alone " << endl << endl;

	}
}

//void Item() {
	//int num = rand() % 100 + 1;
	//if (num <= 30)
		//cout << " you found a companion cube! take care of it " << endl << endl;
	//else if (num <= 40)
		//cout << " you got a boring book to tier enimes " << endl << endl;
	//else if (num <= 80)
		//cout << " you got the best shoes! " << endl << endl;
	//else
		//cout<< " you got a tacticle shovle " <<endl << endl;

//}


void Battle(int MonsterHealth) {
	int damage;
	while (MonsterHealth > 0 && health > 0) {
		damage = rand() % 20;
		cout << " The skeleton trough a bone " << damage << " damage. " << endl;
		health -= damage;
		cout << "You have " << health << " health left " << endl;
		if()
		cout << "you hit the monster for " << damage << " damage " << endl;
		MonsterHealth -= damage;
		cout << " The monster has " << MonsterHealth << " damage " << endl;


	}
	if (MonsterHealth <= 0)
		cout << " You deffeded the monster. " << endl;
	else
		cout << " YOU DIED " << endl;


}
