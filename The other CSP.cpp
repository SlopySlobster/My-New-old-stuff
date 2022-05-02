#include <iostream>
#include <Windows.h>//from stackoverflow.com
using namespace std; 

int main()
{
	char input;
	string input2;
	int score = 0;

	cout << "Hello, welcome to the button presser test." << endl;
	cout << "This test will have you press the 'a' button as many times as possible for five seconds." << endl;
	cout << "After five seconds, I will tell you how many times you pressed the button. " << endl;
	cout << "Press enter to begin." << endl;
	cin >> input2;

    int counter = 5; //amount of seconds, 
    Sleep(1000);//from stackoverflow.com
    while (counter >= 1)
    {
        cout << "\rTime remaining: " << counter << flush;//from stackoverflow.com
        Sleep(1000);//from stackoverflow.com
        counter--;//from stackoverflow.com
    }
	

	while (score < 10) {
		cin >> input;
		if (input == 'a')
			score += 1;
	}

	cout << "Your score is " << score << "." << endl;
}
