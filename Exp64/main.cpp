// Example on page 64, read name and age

#include "std_lib_facilities.h"

int main()
{
    cout << "Please enter your first name and age" << endl;
    string first_name; // string variable
    double age; // integer variable
    cin >> first_name; // read a string to the variable first_name
    cin >> age; // read an integer to variable age
    cout << "Hello, " << "Mr. " + first_name << " (age " << age*12 << " months)" << endl;
}
