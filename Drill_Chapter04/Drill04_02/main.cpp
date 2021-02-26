//Chapter 4 Drill 2
#include <iostream> // for cout & cin
// #include <vector> // to use vector
#include <algorithm> // to use find()
using namespace std; // for cout & cin

int main()
{
    cout << "Type two integers:" << endl;

    int val1, val2;
    while (cin >> val1 >> val2) {
        if (val1 != val2) {
            cout << "the smaller number is " << min({val1, val2}) << endl;
            cout << "the larger number is " << max({val1, val2}) << endl;
        }
        else {
            cout << val1 << " = " << val2 << endl;
        }
    }

}
