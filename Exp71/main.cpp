// Example on page 71, detect repeated words

#include "std_lib_facilities.h"

int main()
{
    cout << "Pease enter a diiferent word" << endl;
    string previous = " ";
    string current;
    while (cin >> current){
        if(previous == current)
            cout << "Repeated word " << current << endl;
        previous = current;
    }
}
