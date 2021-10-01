#include<iostream>
using namespace std;

int main() {
	//variables to hold onto each princess' score:
	int Bugsbunny = 0;
	int Wanerbrothers = 0;
	int Cuphead = 0;
	int Mario = 0;
	int Sans = 0;

	char choice; //variable to hold user input

	cout << "Welcome to the Disney quiz!" << endl;

	//question 1
	cout << "What do you like to eat? carrots(a) sandwich(b) booze(c) mushrooms(d) dogs, as in hotdogs(e) " << endl;
	cin >> choice;
	if (choice == 'a')
		Bugsbunny = Bugsbunny + 1; //long way to add one
	else if (choice == 'b')
		Wanerbrothers += 1; //shorter way to add one
	else if (choice == 'c')
		Cuphead++; //shortest way to add one
	else if (choice == 'd')
		Mario++;
	else if (choice == 'e')
		Sans++;
	else
		cout << "not an option, dummy" << endl;

	cout << " What do you like to do? Run(a) Joke(b) Shoot(c) Jump(d) Nothing(e) " << endl;
	cin >> choice;
	if (choice == 'a')
		Bugsbunny = Bugsbunny + 1; //long way to add one
	else if (choice == 'b')
		Wanerbrothers += 1; //shorter way to add one
	else if (choice == 'c')
		Cuphead++; //shortest way to add one
	else if (choice == 'd')
		Mario++;
	else if (choice == 'e')
		Sans++;
	else
		cout << "not an option, dummy" << endl;

	cout << " What  " << endl;
	cin >> choice;
	if (choice == 'a')
		Bugsbunny = Bugsbunny + 1; //long way to add one
	else if (choice == 'b')
		Wanerbrothers += 1; //shorter way to add one
	else if (choice == 'c')
		Cuphead++; //shortest way to add one
	else if (choice == 'd')
		Mario++;
	else if (choice == 'e')
		Sans++;
	else
		cout << "not an option, dummy" << endl;

	//more questions go here!

	//check which princess has the biggest score
	//the symbol "&&" means AND
	if (Bugsbunny >= Wanerbrothers && Bugsbunny >= Cuphead && Bugsbunny >= Mario && Bugsbunny >= Sans)
		cout << " You are like Bugsbunny, you know who has the power to hunt him? SANS! your going to have a bad time " << endl;
	else if (Wanerbrothers >= Bugsbunny && Wanerbrothers >= Cuphead && Wanerbrothers >= Mario && Wanerbrothers >= Sans)
		cout << " You are wacky like the Wanerbrothers, you know who is also wacky? SANS! your going to have a bad time " << endl;
	else if (Cuphead >= Bugsbunny && Cuphead >= Wanerbrothers && Cuphead >= Mario && Cuphead >= Sans)
		cout << " You are an alcolholic like Cuphead, you know who just drinks ketchup? SANS! you going to have a bad time " << endl;
	else if (Mario >= Bugsbunny && Mario >= Wanerbrothers && Mario >= Cuphead && Mario >= Sans)
		cout << " You like mushrooms like Mario, you know who dosen't need to eat drugs to be powerfull? SANS! your going to gave a bad time " << endl;
	else if (Sans >= Bugsbunny && Sans >= Wanerbrothers && Sans >= Cuphead && Sans >= Mario)
		cout << " YEA, LETS GO SANS!, your going to have a good time! " << endl;
}
