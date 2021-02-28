//Example on page 147, throw and catch to handle errors
#include <iostream> // for cout & cin
#include <vector> // to use vector
#include <algorithm> // to use find()
#include <cmath> // use round() function
// #include "std_lib_facilities.h"
using namespace std; // for cout & cin

class Bad_area{}; // Define a "user-defined" type called Bad_area for providing sth to throw from area()

int area(int length, int width) // calculate area of a rectangle
{
    // The if loop will report error if the input of length and width is non-positive
    // This warning also covers the framed_area() function which calls the area() function
    if (length <= 0 || width <= 0) {
        // Rather than directly handle the error, e.g. in Exp146
        // We just detect error here with "throw" without knowing who will cath and what it will do
        throw Bad_area{};
    }
    return length*width;
}

int framed_area(int x, int y) // calculate area within frame
{
    return area(x-2,y-2);
}


int main()
// Use Try must have a Catch
try {
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
}
// If the input is non-positive, means it catches the Bad_area thrown by area(), then the error will be handled here
catch (Bad_area) {
    cout << "Oops! Bad arguments to area()!" << endl;
}
