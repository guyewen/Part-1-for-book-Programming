//Chapter 4 Drill 9-11
#include <iostream> // for cout & cin
#include <vector> // to use vector
#include <algorithm> // to use find()
#include <string> // to use to_strin()
using namespace std; // for cout & cin

int main()
{
    constexpr double m = 100;
    constexpr double in = 2.54;
    constexpr double ft = 12 * in;

    cout << "Please enter a value (number) and a unit (m, cm, in, ft):" << endl;

    double value; // for input value
    string unit; // for input unit

    double centermeter = 0; // used to covert all units to cm
    double sum = 0; // to track the sum

    double min_value = 10000; // initial min
    double max_value = 0; // initial max
    vector <string> units = {"m", "in", "ft", "cm"}; // valid units
    vector <string> data; // to store entered unit

    // Loop every time with a value and a unit entered
    while (cin >> value >> unit) {
        // covert all unit to cm
        if (unit == "m") {
            centermeter = value * m;
        }
        else if (unit == "in") {
            centermeter = value * in;
        }
        else if (unit == "ft") {
            centermeter = value * ft;
        }
        else if (unit == "cm") {
            centermeter = value;
        }

        // Update the sum, store the value and unit, if unit is valid (in the vector of units)
        if (find(units.begin(), units.end(), unit) != units.end()){
            sum += centermeter;
            string data1 = to_string(value) + " " + unit;
            data.push_back(data1); // store value and unit this loop
        }
        else {
            cout << unit << " is not a valid unit!" << endl;
        }

        if (centermeter < min_value) {
            min_value = centermeter;
        }

        if (centermeter > max_value) {
            max_value = centermeter;
        }

        // Print out the min, max and sum
        cout << "the largest number is " << max_value << " cm" << endl
             << "the smallest number is " << min_value << " cm" << endl
             << "the total cm is " << sum << " cum" << endl;

    }

    // print out all entries
    sort(data.begin(), data.end());
    cout << endl;
    for (int i=0; i < data.size(); ++i ) {
        cout << data[i] << endl;
    }

}
