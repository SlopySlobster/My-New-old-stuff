#include<iostream>
#include<string>

using namespace std;

int split(string input_string, char separator, string arr[], const int ARR_SIZE) {

    if (input_string.empty()) {
        return 0;

    }

    int arr_index = 0;
    string temp = "";

    for (unsigned int i = 0; i < input_string.length(); i++) {
        if (input_string[i] == separator) {

            if (arr_index < ARR_SIZE) {

                arr[arr_index] = temp;
                arr_index++;
                temp = "";

            }

            else {
                return -1;

            }

        }

        else {
            temp += input_string[i];

        }

    }

    if (arr_index < ARR_SIZE) {
        arr[arr_index] = temp;
        arr_index++;

    }
    else {
        return -1;

    }

    if (arr_index == 1 && temp == input_string) {
        return 1;

    }

    return arr_index;
}

int main() {

    string testcase = "Bangkok,Berlin,Birmingham,Bogota,Busan,Baton,Rouge,Beaumont,Boise,Budapest";
    char separator = ',';
    const int ARR_SIZE = 5;
    string arr[ARR_SIZE];

    int num_splits = split(testcase, separator, arr, ARR_SIZE);
    cout << "Function returned value: " << num_splits << endl;
    for (int i = 0; i < ARR_SIZE; i++) {
        cout << "arr[" << i << "]:" << arr[i] << endl;

    }

}
