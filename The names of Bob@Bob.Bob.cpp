#include<iostream>
using namespace std;

int NUMBearS[10];
string Names[5];

int main() {
bool HasCoolFriend = false;
string f1;
string f2;
string f3;
string f4;
string f5;
srand(time(NULL));

for(int i = 0; i < 10; i++){
int num = rand() % 51 + 50;
NUMBearS[i] = num;
}
for (int i = 0; i < 10; i++)
cout << NUMBearS[i] << " | ";
cout << endl << endl;
cout << "Give us 5 of your friends names." << endl;
cin >> f1;
cout << endl;
cin >> f2;
cout << endl;
cin >> f3;
cout << endl;
cin >> f4;
cout << endl;
cin >> f5;
Names[0] = f1;
Names[1] = f2;
Names[2] = f3;
Names[3] = f4;
Names[4] = f5;
for (int i = 0; i < 5; i++)
cout << Names[i] << " | ";
cout << endl;
for (int i = 0; i < 5; i++)
if (Names[i] == "Alejandro")
HasCoolFriend = true;
if (HasCoolFriend == true)
cout << "You have cool friends" << endl;
else
cout << "Get cooler friends...like Alejandro" << endl;
}
