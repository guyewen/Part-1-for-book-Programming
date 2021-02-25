#include <iostream>

using namespace std;

int main()
{
    cout << "Please enter a digit:" << endl;
    // char a;
    int a;
    cin >> a;
    switch (a) {
    case 0: case 2: case 4: case 6: case 8: // to put all the cases with same results in one line
    // case '0': case '2': case '4': case '6': case '8':
        cout << a << " is an even number" << endl;
        break;
    case 1: case 3: case 5: case 7: case 9:
    // case '1': case '3': case '5': case '7': case '9':
        cout << a << " is an odd number" << endl;
        break;
    default:
        cout << a << " is not a digit" << endl;
        break;
    }
}
