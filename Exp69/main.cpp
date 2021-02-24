// Example on page 69, compare two strings with if statment

#include "std_lib_facilities.h"

int main()
{
    cout << "Please enter two names" << endl;
    string first;
    string second;
    cin >> first >> second;
    if(first == second)
        cout << "That's the same name twice" << endl;
    if(first < second)
        cout << first << " is alphabetically before " << second << endl;
    if(first > second)
        cout << first << " is alphabetically after " << second << endl;
}
