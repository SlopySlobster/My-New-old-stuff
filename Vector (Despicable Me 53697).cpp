#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

	vector <int> num;
	vector <int>::iterator numi;

	srand(time(NULL));


	for (int i = 0; i < 20; i++) {
		num.push_back(rand() % 5000);
		cout << num[i] << " " << endl;

	}



	random_shuffle(num.begin(), num.end());
		cout << endl << "shuffled:" << endl;
	for (int i = 0; i < 20; i++)
		cout << num[i] << " ";


	


	sort(num.begin(), num.end());
	cout << endl << "sorded:" << endl;
	for (int i=0; i<20;i++)
	cout << num[i] << " ";

	

}
