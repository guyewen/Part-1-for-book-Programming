// Example on page 105 about switch-statment
#include <iostream>

using namespace std;

int main()
{
    constexpr double cm_per_inch = 2.54; // number of centimeters in an inch
    double length = 1;                   // length in inches or centimeters
    char unit = 'a';                     // a space is not a unit

    cout << "Please enter a lenght followed by a unit (c or i)" << endl;
    cin >> length >> unit;

    // Use switch statment rather than if statment here
    switch (unit) {  // the unit in () is the value to be compared with the value in the following cases
    case 'i':
        cout << length << "in == " << cm_per_inch*length << "cm\n";
        break;
    case 'c':
        cout << length << "cm == " << length/cm_per_inch << "in\n";
        break;
    default:
        cout << "Sorry, I don't know a unit called '" << unit << "'\n";
        break;
    }
}
