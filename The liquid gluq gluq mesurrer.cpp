#include <iostream>

using namespace std;

int calculateVolume(int area, int height) {

	int volume = 0.5 * area * height;
	return(volume);

}

void displayVolume(int volume) {

	cout << "The volume of the prism is: " << volume << endl;
	return;

}

int compareVolume(int area_1, int height_1, int area_2, int height_2) {

    int volume_1 = calculateVolume(area_1, height_1);
    int volume_2 = calculateVolume(area_2, height_2);

    if (volume_1 > volume_2)
    {
        cout << "The first prism has greater volume" << endl;
    }
    else if (volume_2 > volume_1)
    {
        cout << "The second prism has greater volume" << endl;
    }
    else
    {
        cout << "Both prisms have equal volume" << endl;
    }

    return 0;

}

int main() {

	int area_1 = 3;
	int height_1 = 7;
	int area_2 = 5;
	int height_2 = 18;

    //Calculate and display the volume of the first prism
    int volume_1 = calculateVolume(area_1, height_1);
    displayVolume(volume_1);

    //Calculate and display the volume of the second prism
    int volume_2 = calculateVolume(area_2, height_2);
    displayVolume(volume_2);

    //Decide which prism has larger volume
    compareVolume(area_1, height_1, area_2, height_2);


}
