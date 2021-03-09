// Example on page 232 - 233, use const char to replace '8', 'q', ';'...
// Example on page 234, move the calcualtion loop out of main as a independent void function
// Example on page 239, recovering from errors, clean_up_mess() function, and ts.ignore() function
// This is example code from Chapter 6.7 "Trying the second version" of
// "Software - Principles and Practice using C++" by Bjarne Stroustrup
//

#include "./std_lib_facilities.h"

//------------------------------------------------------------------------------

class Token { // user defined type token
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
};

const char number = '8';
const char quit = 'q';
const char print = ';';
const string prompt = "> ";
const string result = "= "; // used to indicate that what follows is a result

//------------------------------------------------------------------------------
/*
Token get_token()    // read a token from cin
{
    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)
    switch (ch) {
 //not yet   case ';':    // for "print"
 //not yet   case 'q':    // for "quit"
    case '(': case ')': case '+': case '-': case '*': case '/':
        return Token(ch);        // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        {
            cin.putback(ch);         // put digit back into the input stream
            double val;
            cin >> val;              // read a floating-point number
            return Token('8',val);   // let '8' represent "a number"
        }
    default:
        error("Bad token");
    }
}
*/
//------------------------------------------------------------------------------

class Token_stream { // user defined type token with two funtions
public:
    Token get();            // get a Token
    void putback(Token t);  // put a Token back
    void ignore(char c);    // discard characters up to and including a c, example on page 239
private:
    bool full {false};      // is there a Token in the buffer?
    Token buffer = {'0'};           // where we store a 'putback' Token
};

void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;         // copy t to buffer
    full = true;        // buffer is now full
}

Token Token_stream::get()
{
    if (full) { // if there is a token putback as buffer, first read this token
        full = false;
        return buffer;
    }
    char ch;
    cin >> ch;

    switch (ch) {
    case print:       // for "print"
    case quit:       // for "quit"
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/':
    case '%': // for Exp231, remainder
        return Token{ch};   // let each character represent itself
    case '.':
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    {
        cin.putback(ch);
        double val;
        cin >> val;
        return Token{number, val};
    }
    default:
        error("Bad Token");
    }
}

void Token_stream::ignore(char c) // .ignore() function, example on page 239
// c represents the kind of Token
{
    // first look in buffer:
    if (full && c==buffer.kind) {
        full = false;
        return;
    }
    full = false;
    // now search input:
    char ch = 0;
    while (cin>>ch)
        if (ch==c) return;
}

//------------------------------------------------------------------------------

Token_stream ts;      // provides get() and putback()

//------------------------------------------------------------------------------

double expression();  // read and evaluate a Expression

//------------------------------------------------------------------------------

double term();        // read and evaluate a Term

//------------------------------------------------------------------------------

// Read a number or a (...), e.g 1+2*3-(2+1)
// The first 3 number, 1, 2, 3 will go to case '8'
// When ( is read, the code knows it is also a primary, then it will look for an expresion, e.g. 2+1, then look for a ).
double primary()     // read and evaluate a Primary
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':    // handle '(' expression ')'
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')') error("')' expected");
        return d;
    }
    case number:         // we use '8' to represent a number
        return t.value;  // return the number's value
    case '-':            // Added for Exp230, handle negative number
        return - primary();
    case '+':            // Added for Exp230, handle negative number
        return primary();
    default:
        error("primary expected");
    }
}
//------------------------------------------------------------------------------
// clean_up_mess() function, for example on page 239

void clean_up_mess()
{
    ts.ignore(print);
}

//------------------------------------------------------------------------------

// Function for calculation loop, example on page 234
void calculate() // expression evaluation loop
{
    while (cin)
        try {
        cout << prompt; // print prompt
        Token t = ts.get();
        while (t.kind == print) {
            t = ts.get(); // first discard all "prints"
        }

        if (t.kind == quit) {
            return;
        }
        ts.putback(t);
        cout << result << expression() << endl;
    }
    // Example on page 239, Recovering from errors, clean_up_mess() function
    catch (exception& e) {
        cerr << e.what() << endl;
        clean_up_mess();
    }
}

//------------------------------------------------------------------------------

int main()
try {

    // Error handling on page 228, for input 1+2;q
    /*while (cin) {
        cout << prompt; // print prompt
        Token t = ts.get();
        while (t.kind == print) {
            t = ts.get(); // eat ';'
        }

        if (t.kind == quit) {
            keep_window_open();
            return 0;
        }
        ts.putback(t);
        cout << result << expression() << endl;
    }*/

    // Example on page 234, moving the calcuation loop out of main
    calculate();
    keep_window_open("~0");
}

catch (...) {
cerr << "exception \n";
keep_window_open ("~2");
return 2;
}

//------------------------------------------------------------------------------

// calculate all the adjacent + and -, e.g. 1+2+3-4*5+6*3/8
// we have 5 terms in the example above, 1, 2, 3, 4*5 and 6*3/8
double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token
    while(true) {
        switch(t.kind) {
        case '+':
            left += term();    // evaluate another Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate another Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t);
            return left;       // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------

// calculate all the adjacent * and /, e.g. 1+2+3-4*5+6*3/8
// we have 5 terms in the example above, 1, 2, 3, 4*5 and 6*3/8
// First 3 will go to default anre return value directly
// 4*5 and 6*3/8 contains 2 and 3 primarys and will be first calculated and then returned as a term
double term()
{
    double left = primary();
    Token t = ts.get();     // get the next token

    while(true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
        {
            double d = primary();
            if (d == 0) error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        case '%': // for Exp231, remainder
        {
            double d = primary();
            if (d == 0) error("divide by zero");
            left = fmod(left, d);
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);
            return left;
        }
    }
}

//------------------------------------------------------------------------------
