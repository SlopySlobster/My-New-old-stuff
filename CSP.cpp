#include<iostream>
#include<cstdio> //got this from linuxhint.com
#include<ctime> //got this from linuxhint.com
using namespace std;

int timer(int delay);


int main() {

	char input;
	int delay = 5;//got this from linuxhint.com
	
	int score = 0;

	cout << "Hello, welcome to the button presser test." << endl;
	cout << "This test will have you press the space button as many times as possible for five seconds." << endl;
	cout << "After five seconds, I will tell you how many times you pressed the button. " << endl;
	cout << "Press space to begin." << endl;
	cin >> input;
	
	do{
		cin >> input;
		if (input == 'a')
			score += 1;

	} while ((timer(delay)) > 0); //Help by kevin

	score += 1;

	cout << "Your score is " << score << "." << endl;

}

int timer(int delay) {

	delay *= CLOCKS_PER_SEC;

	clock_t now = clock();

	while (clock() - now < delay);

	return;
	
}
