// Chapter 8, drill 03, namespace
#include <iostream> // for cout & cin
#include <vector> // to use vector
#include <algorithm> // to use find()
#include <cmath> // use round() function
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
#include "std_lib_facilities.h"
using namespace std; // for cout & cin

namespace X {
double var;
void print() {
    cout << "X: " << var << endl;
}
}

namespace Y {
double var;
void print() {
    cout << "Y: " << var << endl;
}
}

namespace Z {
double var;
void print() {
    cout << "Z: " << var << endl;
}
}

int main()
{
    // Did not using namespace X, so you need X::
    X::var=7;
    X::print(); //print X's var

    using namespace Y; // No longer need Y::
    var=9;
    print(); //print Y's var

    // To maksure the var and print for Z only exist inside the {}
    {
        using Z::var;
        using Z::print;
        var = 11;
        print(); //print Z's var
    }

    print(); //print Y's var, without the {} above, this will be print Z
    X::print(); //print X's var

}
