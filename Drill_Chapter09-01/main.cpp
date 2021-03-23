// Chapter 9, Drill 1 - 9.4.1
#include <iostream> // for cout & cin
#include <vector> // to use vector
#include <algorithm> // to use find()
#include <cmath> // use round() function
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
#include "std_lib_facilities.h"
using namespace std; // for cout & cin

//---------------------------------------------------------------------------------------------------------
// Define tyep Date with struct
struct Date{
    int y; // year
    int m; // month
    int d; // day
};

// Declear today and tomorrow
Date today;
Date tomorrow;

// Function to initialize the Date
void init_day (Date& dd, int y, int m, int d) {

    if (y<1900 || y>2021) { // Interval of year
        error("Invalid year!");
    }
    else if (m<1 || m>12) { // Interval of month
        error("Invalid month!");
    }
    else if (d<1 || d>31) { // Interval of day
        error("Invalid day!");
    }
    else if (m==2 && d>28) { // Max day for Feb, leap year is not considered
        error("Invalid day!");
    }
    else if ((m==4 || m==6 || m==9 || m==11) && d>30) { // Max day for Feb, leap year is not considered
        error("Invalid day!");
    }
    else { // Initialize the Date today
        dd.y = y;
        dd.m = m;
        dd.d = d;
        cout << "Initial date: " << dd.y << " " << dd.m << " " << dd.d << endl;
    }
}

//increase date by n days
void add_day(const Date& tt, Date& dd, int n) {
    dd = tt; // Copy tt (today) to dd (tomorrow)

    // Increase the date by 1 every time and check if it is the last day of month or year
    for (int i=0; i<n; ++i) {
        bool end_month = false; // Reset the binary for the last day of a month
        bool end_year = false; // Reset the binary for the last day of a year

        // List all the last days of month from Jan to Nov, exclude Dec
        if ((dd.m==2 && dd.d==28) || ((dd.m==4 || dd.m==6 || dd.m==9 || dd.m==11) && dd.d==30) || (dd.m != 12 && dd.d==31)) {
            end_month = true;
        }

        if (dd.m==12 && dd.d==31) {
            end_year = true;
        }

        // Update dd.d, dd.m, dd.y based on whether it is the last day of month or year
        if (end_month) {
            dd.d = 1;
            dd.m += 1;
        }
        else if (end_year) {
            dd.d = 1;
            dd.m = 1;
            dd.y += 1;
        }
        else {
            dd.d += 1;
        }
    }

    cout << "Increased date: " << dd.y << " " << dd.m << " " << dd.d << endl;
}

// Print to screen, define operator <<
ostream& operator << (ostream& os, const Date& dd)
{
 return os << "Year: " << dd.y << ", " << "Month: " << dd.m << ", " << "Day: " << dd.d << endl;
}

//---------------------------------------------------------------------------------------------------------

int main()
try
{
    init_day(today, 1986, 12, 30);
    add_day(today, tomorrow, 2);

    cout << endl
         << "Today is: " << today << endl
         << "Tomorrow is: " << tomorrow << endl;

}
catch (runtime_error e) {	// this code is to produce error messages; it will be described in Chapter 5
    cout << e.what() << '\n';
    keep_window_open("~");	// For some Windows(tm) setups
}
catch (...) {	// this code is to produce error messages; it will be described in Chapter 5
cout << "exiting\n";
keep_window_open("~");	// For some Windows(tm) setups
}
