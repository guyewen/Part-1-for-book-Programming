//Example on page 109, about while statment

#include <iostream> // for cout & cin
#include <cmath> // for activate pow(x, y)

using namespace std; // for cout & cin

int main()
{
    int i = 0; // start from 0, must define and initialize i, otherwise error
    while (i < 100) {
        cout << i << '\t' << pow(i, 2.0) << endl; // '\t' is for tab
                                                  //pow(x, y): calculate the x^y, need #include <cmath> to use the pow(x, y)
        ++i;                                      // increase i by 1 every time, you may also use i+=1
    }
}
