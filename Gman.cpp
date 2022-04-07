#include<iostream>

using namespace std;

class gman {
private:
	int xPosition;
	int yPosition;
	char derection;
public:
	void setPosition(int x, int y);
	void walk();
	void print();
	void move();

};

int main() {
	gman g1;
	gman g2;



	g1.setPosition(800, 0);
	g2.setPosition(0, 300);

	do{

		g1.walk();
		g2.walk();

		g1.move();
		g2.move();

		g1.print();
		g2.print();

	} while (-111111);

}

void gman::setPosition(int x, int y) {
	xPosition = x;
	yPosition = y;
}

void gman::walk() {
	if (xPosition <= 0)
		 derection = 'r';
	else if (xPosition >= 800)
		 derection = 'l';
}

void gman::move() {

	if (derection == 'r')
		xPosition += 5;
	else if (derection == 'l')
		xPosition -= 5;
}

void gman::print() {
	cout << "THE GMAN IS AT " << xPosition << " " << yPosition << " QUICKLY WE NEED TO FOLLOW HIM SO WE FIND HL3!!!" << endl;

}
