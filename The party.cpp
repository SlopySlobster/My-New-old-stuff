#include<iostream>
#include<Windows.h>
#include<ctime>
using namespace std;

void Monster();
void Shop();
//void Item();

void Battle(int MonsterHealth, char num);
string items[5];

int health = 500;
int money = 200;
int input;

int main() {
	srand(time(NULL));
	while (1) {
		Monster();
		//Item();
		system("pause");
	}
}




void Monster() {
	int MonsterHealth = 0;
	int MonsterDamage = 0;

		

		int num = rand() % 100 + 1;

		if (num <= 10) {
			cout << " spooky scary skeletons, and shivers down your spine! " << endl << endl;
			MonsterHealth = 150;
			num = 1;

			//health -= 20;
			//cout << " your health is now " << health << endl;
		}
		else if (num <= 15) {
			cout << " a creaper whants to give you a hug, and explode! " << endl << endl;
			MonsterHealth = 40;
			num = 2;
			
			//health -= 200;
			//cout << " your health is now " << health << endl;
		}
		else if (num <= 40) {
			cout << " The zombies, were coming! " << endl << endl;
			MonsterHealth = 70;
			num = 3;
			//health -= 30;
			//cout << " your health is now " << health << endl;
		}
		else if (num <= 60) {
			cout << " The itse bitse spider went up, then cralded to you! " << endl << endl;
			MonsterHealth = 60;
			num = 4;
			//health -= 10;
			//cout << " your health is now " << health << endl;
		}
		else if (num <= 80) {
			cout << " someone jumping in a porabala is coming to you, they must be a withch! " << endl << endl;
			MonsterHealth = 100;
			num = 5;
			//health -= 60;
			//cout << " your health is now " << health << endl;
		}

		Battle(MonsterHealth, num);

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


void Battle(int MonsterHealth, char num) {
	int damage;
	int turn = 0;
	while (MonsterHealth > 0 && health > 0) {
		if (num == 1)
			damage = rand() % 10 + 5;
		else if (num == 3)
			damage = rand() % 20 + 5;
		else if (num == 4)
			damage = rand() % 20 + 10;
		else if (num == 5)
			damage = rand() % 35 + 5;

		//keep going


		if (num==2 && turn == 0)
			cout << "ssssssssssss...." << endl;
		else if (num==2 && turn == 1) {
			cout << "BOOM" << endl;
			cout << " The creature attacked you! You took 350 damage. " << endl;
			health -= 350;
			cout << "You have " << health << " health left " << endl;
		}
		else {
			cout << " The creature attacked you! You took " << damage << " damage. " << endl;
			health -= damage;
			cout << "You have " << health << " health left " << endl;
		}

		//your attack sequence
		cout << "You can " << endl;
		cin >> input;
		if (input == 's')
			damage = rand() % 26 + 20;
		else if (input == 'a')
			damage = rand() % 51 + 10;
		else if (input == 'l')
			damage = 35;
		else
			cout << " you can't do that " << endl;
		cout << "you hit the monster for " << damage << " damage " << endl;
		MonsterHealth -= damage;
		cout << " The monster has " << MonsterHealth << " Health " << endl;

		turn++;
	}
	if (MonsterHealth <= 0)
		cout << " You deffeded the monster. " << endl;
	else
		cout << " YOU DIED " << endl;


}


void Shop() {

}
