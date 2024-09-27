#include <iostream>
#include <cmath>
using namespace std;


int calculateTime(int target_size) {
	int size = 1;
	int time = 0;
	int growing = 1;

	while (size < target_size) {
		time += 1;
		size += growing;
		growing += 1;

	}

	return(time);
}

int main() {

	int ball1;
	int ball2;
	int ball3;

	
	cout << "Enter head size:" << endl;
	cin >> ball1;
	while (ball1 <= 0) {
		cout << "Please enter a positive integer for head size:" << endl;
		cin >> ball1;
	}
	int time1 = calculateTime(ball1);

	cout << "Enter mid-body size:" << endl;
	cin >> ball2;
	while (ball2 <= 0) {
		cout << "Please enter a positive integer for mid-body size:" << endl;
		cin >> ball2;
	}
	int time2 = calculateTime(ball2);

	cout << "Enter lower-body size:" << endl;
	cin >> ball3;
	while (ball3 <= 0) {
		cout << "Please enter a positive integer for lower-body size:" << endl;
		cin >> ball3;
	}
	int time3 = calculateTime(ball3);

	int totaltime = time1 + time2 + time3;

	cout << "Time to reach head size: " << time1 << " seconds" << endl;
	cout << "Time to reach mid-body size: " << time2 << " seconds" << endl;
	cout << "Time to reach lower-body size: " << time3 << " seconds" << endl;
	cout << "Total time to create the snowman: " << totaltime << " seconds" << endl;

}
