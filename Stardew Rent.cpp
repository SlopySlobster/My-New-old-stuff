#include <iostream>

using namespace std;

double calculateFarmArea(double length, double width) {

	if (length < 0) {

		return 0;
	}

	else if (width < 0) {

		return 0;
	}

	else {

		double area = length * width;
		return area;
	}
}

double calculateSeedCost(double area, char seed_grade) {
	if (area < 0) {
		return 0;
	}

	else if (seed_grade == 'A') {

		double cost = area * 7.5;
		return (cost);
	}

	else if (seed_grade == 'B') {

		double cost = area * 12.5;
		return (cost);
	}
	else if (seed_grade == 'C') {

		double cost = area * 27.5;
		return (cost);
	}

	else {

		return 0;
	}

}

double calculateSowingTime(double area, char machine_type) {
	if (area < 0) {
		return 0;
	}

	else if(machine_type == 'W'){
	
		double time_taken = (area / 5) * 12;
		return (time_taken);
	}

	else if (machine_type == 'X') {

		double time_taken = (area / 3) * 10;
		return (time_taken);
	}
	else if (machine_type == 'Y') {

		double time_taken = (area / 2) * 5;
		return (time_taken);
	}

	else if (machine_type == 'Z') {

		double time_taken = (area / 7) * 15;
		return (time_taken);
	}

	else {

		return 0;
	}

}

int main() {

	int choice;

	cout << "1. Calculate Farm Area" << endl;
	cout << "2. Calculate Seeds Cost" << endl;
	cout << "3. Estimate Sowing Time" << endl;
	cout << "4. Exit" << endl;

	cin >> choice;

	if (choice == 1) {

		double input1;
		double input2;

		cout << "Enter length of the farmland in ft:" << endl;
		cin >> input1;

		cout << "Enter width of the farmland in ft:" << endl;
		cin >> input2;

		double area = calculateFarmArea(input1, input2);

		if (area == 0)
		{
			cout << "Length or width is invalid. Area cannot be calculated." << endl;
		}
		else
		{
			cout << "The area is: " << area << " sq ft." << endl;
		}

	}

	else if (choice == 2) {

		double input3;
		char input4;

		cout << "Enter area of the farmland in sq ft:" << endl;
		cin >> input3;

		cout << "Enter the grade of seed to be used:" << endl;
		cin >> input4;

		double cost = calculateSeedCost(input3, input4);

		if (cost == 0)
		{
			cout << "Area or seed grade is invalid. Cost cannot be calculated." << endl;
		}
		else
		{
			cout << "The cost is: $" << cost << endl;
		}

	}

	else if (choice == 3) {

		double input5;
		char input6;

		cout << "Enter area of the farmland in sq ft:" << endl;
		cin >> input5;

		cout << "Enter the type of sowing machine to be used:" << endl;
		cin >> input6;

		double time_taken = calculateSowingTime(input5, input6);

		if (time_taken == 0)
		{
			cout << "Area or machine type is invalid. Time cannot be calculated." << endl;
		}
		else
		{
			cout << "The time taken is: " << time_taken << " minutes." << endl;
		}

	}
	
	else if (choice == 4) {

		cout << "You have chosen to exit. Thank you!" << endl;

	}

	else {

		cout << "Menu choice is invalid." << endl;

	}

}
