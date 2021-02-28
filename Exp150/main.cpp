//Example on page 150 to test if the input is a double
#include <iostream> // for cout & cin
#include <vector> // to use vector
#include <algorithm> // to use find()
#include <cmath> // use round() function
#include "std_lib_facilities.h"
using namespace std; // for cout & cin

double some_function(double d)
{
cin >> d;
if (!cin) error("couldn't read a double in 'some_function()'");
return d + 1;
}


int main()
{
    cout << "Please enter a double:" << endl;

    double val = 0;
    val = some_function(val);

    cout << val << endl;
}

