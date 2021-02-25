//Example on page 113 - 114, define and call funtion square(i)

#include <iostream> // for cout & cin

using namespace std; // for cout & cin

// Function must be defined outside the int main()
int square(int x) // return the square of x
{
return x*x;
}

int main()
{
    cout << square(2) << '\n'; // print 4
    cout << square(10) << '\n'; // print 100
}
