// Example on page 80, Unsafe conversion

#include "std_lib_facilities.h"

int main()
{
    int a = 20000;
    char c = a; // Try to put a large int into a small char, unsafe conversion
    int b = c;
    if (a != b) // != means not equal
        cout << "Oops!: " << a << " != " << b << endl;
    else
        cout << "Wow! We have large characters" << endl;
}
