//Example on page 116, about function print out squre, type void

#include <iostream> // for cout & cin

using namespace std; // for cout & cin


// When used as a function return type, the void keyword specifies that the function does not return a value.
void print_square(int v)
{
    cout << v << '\t' << v*v << '\n';
}
int main()
{
    for (int i = 0; i<100; ++i) {
        print_square(i);
    }
}
