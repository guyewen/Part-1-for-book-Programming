//Example on page 151 - 152, about throw and catch errors
#include <iostream> // for cout & cin
#include <vector> // to use vector
#include <algorithm> // to use find()
#include <cmath> // use round() function
// #include "std_lib_facilities.h"
using namespace std; // for cout & cin

// Define function error() for throw runtime_error
void error(string s)
{
    throw runtime_error(s);
}

int area(int length, int width) // calculate area of a rectangle
{
    if (length <= 0 || width <= 0) {
        // To call the function error() when runtime error occour
        error("Runtime error!");
    }
    return length*width;
}

int framed_area(int x, int y) // calculate area within frame
{
    return area(x-2,y-2);
}


int main()
try {
    // Example for runtime_error
    int x;
    int y;
    int z;

    cout << "Please enter the value for x, y and z:" << endl;
    cin >> x >> y >> z;

    int area1 = area(x,y);
    int area2 = framed_area(x,z);
    int area3 = framed_area(y,z);
    double ratio = double(area1)/area3;

    cout << "Area1 = " << area1 << ", Area 2 = " << area2
         << ", Area 3 = " << area3 << ", Ratio = " << ratio << endl;

    // Example for range error
    cout << "Please enter the number of elements in a vector:" << endl;
    vector<int> v; // a vector of ints
    for (int x; cin>>x; )
        v.push_back(x); // set values
    for (int i = 0; i<=v.size(); ++i) // print values
        cout << "v[" << i <<"] == " << v[i] << '\n';

    return 0;
}

// Catch throw from runtime error
catch (runtime_error& e) {
cerr << "runtime error: " << e.what() << '\n';
//keep_window_open();
return 1;
}

// Catch throw from other error, such as range error in this example
catch (...) { // catch all other exceptions
cerr << endl << "Exception: something went wrong\n";
return 2;
}

