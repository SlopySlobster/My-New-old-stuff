#include<iostream>

using namespace std;


class planet {
private:
	string mass;
	int moons;
	int rings;
	char type;
	bool life;

public:
	planet();
	planet(int m, int r, char t, bool l);
	void printInfo();
	void captureMoon();
	void shredMoon();
	void growLife();
	void getHitByAsteriod();
	void hasLife();
};


int main() {
	planet Earth;
	Earth.printInfo();
	Earth.captureMoon();
	Earth.shredMoon();
	Earth.growLife();
	Earth.getHitByAsteriod();
	Earth.hasLife();

}

planet::planet() {
	mass = 5.9;
	moons = 1;
	rings = 0;
	type = 'r';
	life = true;

}

void planet::printInfo() {
	cout << "Heres the info about me: " << endl;
	cout << "My mass is " << mass << endl;
	cout << "I have " << moons << " moons" << endl;
	cout << "I have " << rings << " rings" << endl;
	if (type == 'r')
		cout << "I am a rocky planet" << endl;
	else if (type == 'i')
		cout << "I am an ice planet" << endl;
	else if (type == 'g')
		cout << "I am a gas planet" << endl;

	if (life == true)
		cout << "I have life" << endl;
	else
		cout << "I don't have life" << endl;

}

void planet::captureMoon() {
	cout << "Put a number to add to your moon collection  " << endl;
	cin >>  moons;
	cout << "Your moon total is now: " << moons << endl;
}
void planet::shredMoon() {
	cout << "Put a number to shred your moons  " << endl;
	cin >> moons;
	cout << "Your moon total is now: " << moons << endl;

}
void planet::growLife() {
	cout << "Do you want to add life to your planet?  " << endl;
	cin >> life;
	if (life == 'y')
		life = true;
	

}
void planet::getHitByAsteriod() {
	cout << "Do you want to save your planet?  " << endl;
	cin >> life;
	if (life == 'y')
		life = true;
	else 
		life = false;
	cout << "Your planet got hit by an asteriod" << endl;

}
void planet::hasLife() {
	cout << "Your planet" << endl;

	if (life == true)
		cout << " has life" << endl;
	else
		cout << " does not have life" << endl;

}
