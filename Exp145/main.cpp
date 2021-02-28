//Example on page 145, error reporting
#include <iostream> // for cout & cin
#include <vector> // to use vector
#include <algorithm> // to use find()
#include <cmath> // use round() function
//#include <cstdlib> // For srand() and rand()
//#include <ctime> // For time()
using namespace std; // for cout & cin

char ask_user(string question)
{
cout << question << "? (yes or no)\n";
string answer = " ";
cin >> answer;
if (answer =="y" || answer=="yes") return 'y';
if (answer =="n" || answer=="no") return 'n';
return 'b'; // ‘b’ for “bad answer”
}


int main()
{
    string question;
    getline(cin, question); // get the whole line of input for string quesiton.

    char val = ask_user(question);
    cout << val << endl;

}
