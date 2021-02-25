#include <iostream>

using namespace std;

int main()
{
    constexpr double cm_per_inch = 2.54; // number of centimeters in an inch
    double length = 1;                   // length in inches or centimeters
    char unit = ' ';                     // a space is not a unit

    cout << "Please enter a lenght followed by a unit (c or i)" << endl;
    cin >> length >> unit;
    if (unit == 'i') {
        cout << length << " in == " << cm_per_inch * length << " cm" << endl;
    }
    else if (unit == 'c') {
        cout << length << " cm == " << length / cm_per_inch << " in" << endl;
    }
    else {
        cout << "Sorry, I don't know a unit called '" << unit << "'." << endl;
    }
}
