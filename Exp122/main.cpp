#include <iostream> // for cout & cin
#include <vector> // to use vector
#include <algorithm> // to use sort()
using namespace std; // for cout & cin

int main()
{
    vector <double> temps;
    cout << "Please enter any temperatures and stop with #" << endl;

    // this for loop will collect double until the new entrance is not double
    for (double temp; cin >> temp; ) { // cin >> temp is the loop condition, the loop will continue if it is true (input is double)
        temps.push_back(temp);
    }

    // may use a while loop instead of for loop
    /*
    double temp;
    while (cin>>temp) // read
        temps.push_back(temp);
    */

    cout << endl << "Total " << temps.size() << " temperature points are entered." << endl
         << "They are: " << endl;

    for (double y : temps) // for each x in v
        cout << endl << y << endl;

    double sum = 0;
    for (double x : temps) {
        sum += x; // sum up the temperature
    }
    cout << "Average temperature: " << sum/temps.size() << endl;

    // compute median temperature:
    sort(temps.begin(), temps.end()); // need #include <algorithm>, also need range of vector, e.g. sort(v.begin(), v.end())
    cout << "Median temperature: " << temps[temps.size()/2] << endl;
}
