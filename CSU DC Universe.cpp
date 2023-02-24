#include <iostream>
using namespace std;
int main() {
	int num1;
	int num2;
	cout << "Two Numbers please!: " << endl;
	cin >> num1;
	cin >> num2;
	cout << num1 << " Divided by " << num2 << " is "<<endl;
	if (num2 != 0)
		cout << num1 / num2;
	else if (num2 == 0)
		cout << "ERROR!" << endl;
	if (num1 <= num2) {
		cout << endl<< "Here are your numbers in order: ";
		cout << num1 << " " << num2 << endl;
	}
	if (num2 < num1) {
		cout <<endl<< "Here are your numbers in order: ";
		cout << num2 << " " << num1 << endl;
	}
	if (num1 == 13 || num2 == 13)
		cout <<endl<< "Bad Luck you got 13" << endl;

	if (num1 % 2 == 0)
		cout << "Even: " << num1 << endl;
	else
		cout << "Odd: " << num1 << endl;
	if (num2 % 2 == 0)
		cout << "Even: " << num2 << endl;
	else
		cout << "Odd: " << num2 << endl;
}
