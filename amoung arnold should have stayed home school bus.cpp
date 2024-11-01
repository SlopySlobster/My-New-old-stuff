#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void compareAttendanceSheet(string first_attendance_file, string second_attendance_file) {

    const int MAX_SIZE = 30;
    string first_list[MAX_SIZE];
    string second_list[MAX_SIZE];
    int first_count = 0;
    int second_count = 0;

    ifstream file_in_first(first_attendance_file);

    if (file_in_first.fail()) {
        cout << "Failed to open attendance files" << endl;
        return;
    }

    ifstream file_in_second(second_attendance_file);

    if (file_in_second.fail()) {
        cout << "Failed to open attendance files" << endl;
        return;
    }

    while (getline(file_in_first, first_list[first_count])) {

        if (first_count < MAX_SIZE) {
            first_count++;

        }
    }

    while (getline(file_in_second, second_list[second_count])) {

        if (second_count < MAX_SIZE) {
            second_count++;

        }

    }

    bool missing_student = false;
    for (int i = 0; i < first_count; ++i) {
        bool found = false;
        for (int j = 0; j < second_count; ++j) {
            if (first_list[i] == second_list[j]) {
                found = true;
                break;
            }
        }
        if (found == false) {
            if (missing_student == false) {
                cout << "Students yet to board the bus are" << endl;
                missing_student = true;
            }
            cout << first_list[i] << endl;
        }
    }

    if (missing_student == false) {
        cout << "Every student has boarded the bus. It's time to leave." << endl;
    }

    file_in_first.close();
    file_in_second.close();

}

int main() {
    string first_attendance_file;
    string second_attendance_file;

    cout << "Enter the name of the first attendance file:" << endl;
    cin >> first_attendance_file;
    cout << "Enter the name of the second attendance file:" << endl;
    cin >> second_attendance_file;

    compareAttendanceSheet(first_attendance_file, second_attendance_file);

}
