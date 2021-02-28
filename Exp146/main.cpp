//TRY THIS on page 146, error reporting
#include <iostream> // for cout & cin
#include <vector> // to use vector
#include <algorithm> // to use find()
#include <cmath> // use round() function
#include "std_lib_facilities.h"
using namespace std; // for cout & cin

int area(int length, int width) // calculate area of a rectangle
{
    // The if loop will report error if the input of length and width is non-positive
    // This warning also covers the framed_area() function which calls the area() function
    if (length <= 0 || width <= 0) {
        error("Non-positive area() argument!");
    }
    return length*width;
}

int framed_area(int x, int y) // calculate area within frame
{
    return area(x-2,y-2);
}


int main()
{
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
