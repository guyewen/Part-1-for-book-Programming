// Example on page 60

#include "std_lib_facilities.h"

int main()
{
    cout << "Please enter your first name (followed by 'enter'):\n";
    string first_name; // define a string type variable named "first_name"
    cin >> first_name; // read input into defined variable "first_name"
    cout << "Hello, " << first_name << "!\n" << endl; // output Hello + first_name
    return 0;
}
