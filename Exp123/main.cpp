//Example on page 123, vector for string, use ctrl + z to stop
#include <iostream> // for cout & cin
#include <vector> // to use vector
#include <algorithm> // to use sort()
using namespace std; // for cout & cin

int main()
{
    cout << "Please enter any words:" << endl;

    vector <string> words;
    for (string word; cin>>word;) {
        words.push_back(word);
    }

    cout << endl << "Number of words: " << words.size() << endl;

    sort(words.begin(), words.end());

    for (int i=0; i<words.size(); ++i) {
        if (i==0 || words[i-1] != words[i]) {
            cout << words[i] << endl;
        }
    }
}
