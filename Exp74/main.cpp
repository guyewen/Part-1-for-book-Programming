// Example on page 74, find repeated words

#include "std_lib_facilities.h"

int main()
{
    cout << "Pease enter a word or sentence" << endl;
    int number_of_words = 0;
    string previous = " "; // Initialize string variable previous
    string current;        // Initialize string variable previous
    while (cin >> current){  // While statment, excute the command within {} if the condition in () is true
        ++number_of_words; // Increase variable number_of_words by 1 every time while statment is excuted
        // number_of_words += 1; // This works the same as ++number_of_words;
        if(previous == current) // IF statment, excute if the condtion in () is true
            cout << "Word number: " << number_of_words
                 << " is repeated: " << current << endl;
        previous = current;
    }
}
