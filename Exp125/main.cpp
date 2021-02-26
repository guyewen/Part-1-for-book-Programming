//TRY THIS on page 125, vector for string, pick out disliked words
#include <iostream> // for cout & cin
#include <vector> // to use vector
#include <algorithm> // to use find()
using namespace std; // for cout & cin

int main()
{
    vector <string> dislike_words {"shit", "fuck", "cao"};
    vector <string> ok_words;
    vector <string> not_ok_words;

    cout << "Please enter any words you like:" << endl;

    // enter all liked words
    vector <string> like_words;
    for (string like_word; cin >> like_word;) {
        like_words.push_back(like_word);
    }

    cout << endl << "Number of liked words: " << like_words.size() << endl;


    for (int i=0; i < like_words.size(); ++i) { // go through all the liked words
        // find function is used like: find(vec.begin(), vec.end(), item), it returns true if vector contains the item and false otherwise
        // find function needs #include <algorithm>
        // vec.end() returns a special iterator, it can also mean "no match" or "no element"
        // != vec.end() hence means not no match or not no element, == vec.end() is the opposit, means no match found
        if (find(dislike_words.begin(), dislike_words.end(), like_words[i]) != dislike_words.end()) {
            not_ok_words.push_back(like_words[i]);
        }
        else {
            ok_words.push_back(like_words[i]);
        }
    }

    // Print out the OK words
    cout << endl << "Number of OK words: " << ok_words.size() << endl
         << "The OK words are: " << endl;

    sort(ok_words.begin(), ok_words.end());

    for (int k=0; k < ok_words.size(); ++k) {
        if (k==0 || ok_words[k-1] != ok_words[k]) {
            cout << ok_words[k] << endl;
        }
    }

    // Print out the Not-OK words
    cout << endl << "Number of Not-OK words: " << not_ok_words.size() << endl
         << "The Not-OK words are: " << endl;
    for (string l : not_ok_words) {
        cout << l << endl;
    }

    // can not use switch statment to replace, since it is string type

}
