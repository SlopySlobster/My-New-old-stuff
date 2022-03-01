#include<iostream>
using namespace std;

int reverse(int x);

int main() {
	int number;
	cout << "enter your number" << endl;
	cin >> number;
	reverse(number);
}

int reverse(int x) {

	do {

		cout << x % 10;

		x = x / 10;

	} while (x > 0);
	return 0;
}
