//Chapter 4 Drill 6
#include <iostream> // for cout & cin
// #include <vector> // to use vector
#include <algorithm> // to use find()
using namespace std; // for cout & cin

int main()
{
    cout << "Type any integer:" << endl;

    double val;
    double min_val = 0;
    double max_val = 0;
    while (cin >> val) {
        cout << val;
        if (val >= max_val) {
            max_val = val;
            cout << " is the largest number so far." << endl;
        }
        else if (val <= min_val) {
            min_val = val;
            cout << " is the smallest number so far." << endl;
        }
        else {
            cout << endl;
        }
    }

}
