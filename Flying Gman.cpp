#include<iostream>

using namespace std;


int a = 0;


class gman {
private:
	int xPosition;
	int yPosition;
	char derectionx;
	char derectiony;
public:
	void setPosition(int x, int y);
	void setthem();
	void thex();
	void they();
	void print();
	void movex();
	void movey();

};

int main() {
	gman g1;
	gman g2;

  
	g1.setPosition(400, 400);
	g2.setPosition(200, 600);
	g1.setthem();
	g2.setthem();

	do {

		g1.print();
		g2.print();

		g1.thex();
		g2.thex();
		
		g1.they();
		g2.they();

		g1.movex();
		g2.movex();

		g1.movey();
		g2.movey();


	} while ( a != -542865902869032809 );

}

void gman::setPosition(int x, int y) {
	xPosition = x;
	yPosition = y;
}

void gman::setthem() {
	 derectionx = 'r';
	 derectiony = 'u';
}

void gman::thex() {
	if (xPosition <= 0)
		derectionx = 'r';
	else if (xPosition >= 800)
		derectionx = 'l';
}

void gman::they(){
	 if ( yPosition >= 800)
		derectiony = 'd';
	else if ( yPosition <= 0)
		derectiony = 'u';
}

void gman::movex() {

	if (derectionx == 'r')
		xPosition += 5;
	else if (derectionx == 'l')
		xPosition -= 5;

}

void gman::movey(){

	if (derectiony == 'u')
		yPosition += 5;
	else if (derectiony == 'd')
		yPosition -= 5;
}

void gman::print() {
	cout << "THE GMAN IS FLYING AT " << xPosition << " " << yPosition << " QUICKLY WE NEED TO FOLLOW HIM SO WE CAN FIND HL3!!!" << endl;

	if (derectionx == 'r' && derectiony == 'u')
		cout << "The GMAN IS GOING RIGHT AND UP!!!" << endl;
	else if (derectionx == 'r' && derectiony == 'd')
		cout << "The GMAN IS GOING RIGHT AND DOWN!!!" << endl;
	else if (derectionx == 'l' && derectiony == 'u')
		cout << "The GMAN IS GOING LEFT AND UP!!!" << endl;
	else if (derectionx == 'l' && derectiony == 'd')
		cout << "The GMAN IS GOING LEFT AND DOWN!!!" << endl;
}
