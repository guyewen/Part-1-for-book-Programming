// Drill in Chapter 3 on page 83, Program a letter

#include "std_lib_facilities.h"

int main()
{
    cout << "Please enter receiver's first name" << endl; // Asking for first name
    string first_name;
    cin >> first_name;

    cout << "Please enter receiver's last name" << endl; // Asking for last name
    string last_name;
    cin >> last_name;

    cout << "Please enter receiver's sex (m or f)" << endl; // Asking for sex
    char sex;
    cin >> sex;

    cout << "Name of a common friend" << endl; // Asking for friend name
    string friend_name;
    cin >> friend_name;

    string title = " "; // Use which title based on sex
    if (sex == 'm') {
        title = "Mr.";
    }
    else if (sex == 'f') {
        title = "Miss";
    }
    else {
        title = "Friend";
    }

    cout << "Receiver's age" << endl; // Asking for age
    int age;
    cin >> age;


    // Test of letter starting here
    cout << endl
         << "Dear " << title << " " << last_name << ",\n" << endl
         << "How are you? I am fine. I miss you " << first_name << "." << endl
         << "Have you seen " << friend_name << " lately?" << endl
         << "I hear you just had your " << age << " years birthday. ";

    if (age <= 0 || age >= 100) { // && is the OR operator
        cout << "You must be kidding me!" << endl;
    }
    else if (age > 0 && age < 12) { // && is the AND operator
        cout << "Next year you will be " << age+1 << "." << endl;
    }
    else if (age == 17) {
        cout << "Next year you will be able to vote!" << endl;
    }
    else if (age > 70) {
        cout << "I hope you are enjoying your retirement!" << endl;
    }
    else {
        cout << "I hope you are enjoying your life!" << endl;
    }

    cout << endl << "Best Regards," << endl << "Yewen Gu" << endl;

}
