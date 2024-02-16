#include <iostream>

using namespace std;

int manageFeeder(int feeder, int days_since_last_fill) {

	if (days_since_last_fill < 0) {

		return(-1);

	}

	else if (feeder == 1) {

		int amount1 = (33 - 2 * days_since_last_fill)/2;

		if (amount1 < 0) {
			amount1 = 0;
		}

		return(amount1);

	}

	else if (feeder == 2) {

		int amount2 = (27 - 4 * days_since_last_fill)/4;

		if (amount2 < 0) {
			amount2 = 0;
		}

		return(amount2);

	}

	else if (feeder == 3) {

		int amount3 = (16 - 3 * days_since_last_fill)/3;

		if (amount3 < 0) {
			amount3 = 0;
		}

		return(amount3);

	}

	else {

		return 0;
	}

}

int main() {

	int feeding;
	int days;

	cout << "1. Check Feeder 1" << endl;
	cout << "2. Check Feeder 2" << endl;
	cout << "3. Check Feeder 3" << endl;
	cout << "4. Check All Feeders" << endl;

	cout << "Enter your choice:" << endl;
	cin >> feeding;

	if (feeding == 1) {

		cout << "How many days ago was feeder 1 filled?" << endl;
		cin >> days;

		int output1 = manageFeeder(feeding, days);

		if (output1 < 0) {

			cout << "Invalid input for days_since_last_fill!" << endl;

		}

		else if (output1 == 0) {

			cout << "Feeder 1 is currently empty and should be filled immediately." << endl;
		}

		else {

			cout << "Feeder 1 will need to be filled in " << output1 << " days." << endl;
		}

	}

	else if (feeding == 2) {

		cout << "How many days ago was feeder 2 filled?" << endl;
		cin >> days;

		int output1 = manageFeeder(feeding, days);

		if (output1 < 0) {

			cout << "Invalid input for days_since_last_fill!" << endl;

		}

		else if (output1 == 0) {

			cout << "Feeder 2 is currently empty and should be filled immediately." << endl;
		}

		else {

			cout << "Feeder 2 will need to be filled in " << output1 << " days." << endl;
		}

	}

	else if (feeding == 3) {

		cout << "How many days ago was feeder 3 filled?" << endl;
		cin >> days;

		int output1 = manageFeeder(feeding, days);

		if (output1<0) {

			cout << "Invalid input for days_since_last_fill!" << endl;

		}

		else if (output1 == 0) {

			cout << "Feeder 3 is currently empty and should be filled immediately." << endl;
		}

		else {

			cout << "Feeder 3 will need to be filled in " << output1 << " days." << endl;
		}

	}

	else if (feeding == 4) {

		cout << "How many days ago were all the feeders filled?" << endl;
		cin >> days;

		int output1 = manageFeeder(1, days);
		int output2 = manageFeeder(2, days);
		int output3 = manageFeeder(3, days);

		if (output1 < 0) {

			cout << "Invalid input for days_since_last_fill!" << endl;

		}

		else if (output1 == 0) {

			cout << "Feeder 1 is currently empty and should be filled immediately." << endl;
		}

		else {

			cout << "Feeder 1 will need to be filled in " << output1 << " days." << endl;
		}

		if (output2 < 0) {

			cout << "Invalid input for days_since_last_fill!" << endl;

		}

		else if (output2 == 0) {

			cout << "Feeder 2 is currently empty and should be filled immediately." << endl;
		}

		else {

			cout << "Feeder 2 will need to be filled in " << output2 << " days." << endl;
		}

		if (output3 < 0) {

			cout << "Invalid input for days_since_last_fill!" << endl;

		}

		else if (output3 == 0) {

			cout << "Feeder 3 is currently empty and should be filled immediately." << endl;
		}

		else {

			cout << "Feeder 3 will need to be filled in " << output3 << " days." << endl;
		}


	}

	else {

		cout << "Invalid menu choice!" << endl;

	}

}
