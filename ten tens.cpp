#include<iostream>
using namespace std;
int main() {
	//for (int i = 0; i <= 5; i++)
		//cout << i << " ";

	int sum = 0;

	int input;
	cout << " enter your ten numbers to get your average " <<endl;

	for (int i = 0; i < 10; i++) {
		cin >> input;
		sum += input;

	}
	
	cout << " your average is " << sum / 10 << endl;
}
