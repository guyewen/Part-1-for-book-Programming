// Chapter 9, Drill 2 - 9.7.1 - with enum class
#include <iostream> // for cout & cin
#include <vector> // to use vector
#include <algorithm> // to use find()
#include <cmath> // use round() function
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
#include "std_lib_facilities.h"
using namespace std; // for cout & cin

//---------------------------------------------------------------------------------------------------------
// Enumeration for month, see 9.5
enum class Month
{
    jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

// Forward declaration, the function help to translate number to Month
Month returnMonth(int month);

// Define Class Date with struct
class Date{
public:
    Date (int y, Month m, int d); // Constructor - check for valid date
    void add_day(int n); // increase the Date by N days
    int year() const {return y;}   // Function read year, non-modifiying
    Month month() const {return m;}  // Function read month, non-modifiying
    int day() const {return d;}    // Function read day, non-modifiying
private:
    int y, d; // year, day
    Month m; // month
};

// Declear today and tomorrow, must be initialized compare to 9.4.1 due to contructor defined in the class
Date today (1986, Month::dec, 31);
Date tomorrow (today);

//Date Constructor - initialise the day and check valid
Date::Date (int y, Month m, int d) {

    if (y<1900 || y>2021) { // Interval of year
        error("Invalid year!");
    }
    else if (m < Month::jan || m > Month::dec) { // Interval of month
        error("Invalid month!");
    }
    else if (d<1 || d>31) { // Interval of day
        error("Invalid day!");
    }
    else if (m==Month::feb && d>28) { // Max day for Feb, leap year is not considered
        error("Invalid day!");
    }
    else if ((m==Month::apr || m==Month::jun || m==Month::sep || m==Month::nov) && d>30) { // Max day for Feb, leap year is not considered
        error("Invalid day!");
    }
    else { // Initialize the Date today
        Date::y = y;
        Date::m = m;
        Date::d = d;
        cout << "Initial date: " << Date::y << " " << static_cast<int>(Date::m) << " " << Date::d << endl;
    }
}

//increase date by n days
void Date::add_day(int n) {
    // Increase the date by 1 every time and check if it is the last day of month or year
    for (int i=0; i<n; ++i) {
        bool end_month = false; // Reset the binary for the last day of a month
        bool end_year = false; // Reset the binary for the last day of a year

        // List all the last days of month from Jan to Nov, exclude Dec
        if ((Date::m==Month::feb && Date::d==28) || ((Date::m==Month::apr || Date::m==Month::jun || Date::m==Month::sep || Date::m==Month::nov) && Date::d==30) || (Date::m != Month::dec && Date::d==31)) {
            end_month = true;
        }

        if (Date::m==Month::dec && Date::d==31) {
            end_year = true;
        }

        // Update dd.d, dd.m, dd.y based on whether it is the last day of month or year
        if (end_month) {
            Date::d = 1;
            int mon = static_cast<int>(Date::m) + 1; // static_cast<int> transfer Month to Int
            Date::m = returnMonth(mon);
        }
        else if (end_year) {
            Date::d = 1;
            Date::m = Month::jan;
            Date::y += 1;
        }
        else {
            Date::d += 1;
        }
    }

    cout << "Increased date: " << Date::y << " " << static_cast<int>(Date::m) << " " << Date::d << endl;
}

// Function to translate int to Month
Month returnMonth(int month)
{
    // Switch to return correct type of Month
    switch (month)
    {
    case 1:
        return Month::jan;
        break;
    case 2:
        return Month::feb;
        break;
    case 3:
        return Month::mar;
        break;
    case 4:
        return Month::apr;
        break;
    case 5:
        return Month::may;
        break;
    case 6:
        return Month::jun;
        break;
    case 7:
        return Month::jul;
        break;
    case 8:
        return Month::aug;
        break;
    case 9:
        return Month::sep;
        break;
    case 10:
        return Month::oct;
        break;
    case 11:
        return Month::nov;
        break;
    case 12:
        return Month::dec;
        break;
    default:
        error("Invalid Month");
    }
}

// Print to screen, define operator <<
// Since year(), month(), day() is non-modifiying, you can use const Date, see 9.7.4
ostream& operator << (ostream& os, const Date& dd)
{
    return os << "Year: " << dd.year() << ", " << "Month: " << static_cast<int>(dd.month()) << ", " << "Day: " << dd.day() << endl;
}

//---------------------------------------------------------------------------------------------------------

int main()
try
{
    tomorrow.add_day(2);
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
