#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	
	double cost;

	cout << "Enter the amount to be withdrawn from your card:" << endl;
	cin >> cost;

	if (cost <= 0) {

		cout << "Invalid input. Withdrawn amount must be a non-negative value." << endl;
	}

	else if (30 - cost < 20) {

		cout << "Transaction Failed!" << endl;
	}

	else if (30 - cost >= 20) {

		cout << fixed << setprecision(2) << "Transaction Successful! Your balance is $" << 30 - cost << endl;
	}
}
