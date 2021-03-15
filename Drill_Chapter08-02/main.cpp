// Chapter 8, drill 02
// use.cpp

#include "my.h"

int main()
{

    //-------------------------------------------------------------------------------------------------------------------------------------//

    //int x=7;
    //int y=9;

    //swap_v(x,y); // will print out 9,7 and 7,9, since x, y are swaped in the function, but x, y themselves are not changed (pass-by-value)
    //swap_r(x,y); // will print out 9,7 and 9,7 since x, y is not only switched in the function, but also updated in the main (pass-by-reference)
    //swap_cr(x,y); // will print out 9,7 and 7,9, since x, y are swaped in the function, but x, y themselves are not cahnged since (pass-by-const-reference)

    //swap_v(7,9); // will print out 9,7, since switched in the function
    //swap_r(7,9); // Can not compile, since the input must be a int varaible to refere to (pass-by-reference)
    //swap_cr(7,9); // Can compile, since (pass-by-const-reference) can refer to constant, will print 9,7

    //cout << x << '\t' << y << endl;

    //-------------------------------------------------------------------------------------------------------------------------------------//

    //const int cx=7;
    //const int cy=9;

    //swap_v(cx,cy); // will print out 9,7 and 7,9, since x, y are swaped in the function, but x, y themselves are not changed (pass-by-value)
    //swap_r(cx,cy); // Can not compile, since the input for (pass-by-reference) can not be const variable
    //swap_cr(cx,cy); // will print out 9,7 and 7,9, since x, y are swaped in the function, but x, y themselves are not cahnged since (pass-by-const-reference)

    //swap_v(7.7,9.9); // will print out 9,7, since double is narrow down to int
    //swap_r(7.7,9.9); // Can not compile, since the input must be a int varaible to refere to (pass-by-reference)
    //swap_cr(7.7,9.9); // will print out 9,7, since double is narrow down to int

    //cout << cx << '\t' << cy << endl;

    //-------------------------------------------------------------------------------------------------------------------------------------//

    double dx=7.7;
    double dy=9.9;

    //swap_v(dx,dy); // will print out 9,7 and 7.7,9.9, since double is narrow down to int in the function
    //swap_r(dx,dy); // Can not compile, since the input for (pass-by-reference) has wrong type
    //swap_cr(dx,dy); // will print out 9,7 and 7.7,9.9, since double is narrow down to int in the function

    //swap_v(7.7,9.9); // will print out 9,7 since double is narrow down to int in the function
    //swap_r(7.7,9.9); // Can not compile, since the input must be a int varaible to refere to (pass-by-reference)
    //swap_cr(7.7,9.9); // will print out 9,7 since double is narrow down to int in the function

    cout << dx << '\t' << dy << endl;

}
