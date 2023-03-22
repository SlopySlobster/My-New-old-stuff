#include <iostream>
#include <random>
using namespace std;
//-------------------------------------

class cutlery {
private:
	int type;
	bool isClean;

public:
	cutlery();
	void use();
	void wash();
	void info();


};



//-------------------------------------

int main() {
	srand(NULL);
	cutlery Denji;
	cutlery Sol;
	cutlery Aki;
	Denji.info();
	Denji.use();
	Denji.info();
	Denji.wash();
	Denji.info();
	Sol.use();
	Sol.info();
	Sol.wash();
	Sol.info();
	Aki.wash();
	Aki.info();

	


}

//-------------------------------------
cutlery::cutlery() {
	type = rand() % 3;
	isClean = true;

}

void cutlery::wash() {
	isClean = true;
}

void cutlery::use() {
	isClean = false;
}

void cutlery::info() {
	cout << "Your current cutlery is:" << endl;
	if (type == 0) {
		if (isClean == true)
			cout << "A clean fork" << endl;
		if (isClean == false)
			cout << "A dirty fork" << endl;
	}
	if (type == 1) {
		if (isClean == true)
			cout << "A clean spoon" << endl;
		if (isClean == false)
			cout << "A dirty spoon" << endl;
	}
	if (type == 2) {
		if (isClean == true)
			cout << "A clean knife" << endl;
		if (isClean == false)
			cout << "A dirty knife" << endl;
	}

}
