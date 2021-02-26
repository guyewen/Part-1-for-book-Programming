//Chapter 4 Drill 7
#include <iostream> // for cout & cin
// #include <vector> // to use vector
#include <algorithm> // to use find()
using namespace std; // for cout & cin

int main()
{
    constexpr double m = 100;
    constexpr double in = 2.54;
    constexpr double ft = 12 * in;

    cout << "Please enter a value (number) and a unit (m, cm, in, ft):" << endl;

    double value;
    string unit;

    while (cin >> value >> unit) {
        if (unit == "m") {
            cout << value << " " << unit << " = " << value * m << " cm" << endl;
        }
        else if (unit == "in") {
            cout << value << " " << unit << " = " << value * in << " cm" << endl;
        }
        else if (unit == "ft") {
            cout << value << " " << unit << " = " << value * ft << " cm" << endl;
        }
        else if (unit == "cm") {
            cout << value << " " << unit << " = " << value << " cm" << endl;
        }
        else {
            cout << "I do not know this unit!" << endl;
        }
    }

}
