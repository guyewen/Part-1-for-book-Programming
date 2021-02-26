//Chapter 4 Drill 1
#include <iostream> // for cout & cin
// #include <vector> // to use vector
// #include <algorithm> // to use find()
using namespace std; // for cout & cin

int main()
{
    cout << "Type two integers:" << endl;

    int val1, val2;
    while (cin >> val1 >> val2) {
        cout << "The sum of " << val1 << " and " << val2 << " is " << val1+val2 << endl;
    }

}
