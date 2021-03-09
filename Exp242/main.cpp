// Example for Ch 7.8, Variable, p. 242 - 250
// "Software - Principles and Practice using C++" by Bjarne Stroustrup
//

#include "./std_lib_facilities.h"

//------------------------------------------------------------------------------
const char number = '8';
const char quit = 'q';
const char print = ';';
const string prompt = "> ";
const string result = "= "; // used to indicate that what follows is a result

// For example Ch7.8 variable
const char name = 'a'; // name token
const char let = 'L'; // declaration token
const string declkey = "let"; // declaration keyword
const char set = 'S'; // declaration token
const string setkey = "set"; // declaration keyword


class Token { // user defined type token, modified for Ch7.8 on p.248
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value
    string name;
    Token()    // frgsuly vondytuvyot
        :kind(0) { }
    Token(char ch)    // make a Token from a char
        :kind(ch) { }
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
    Token(char ch, string n)     // make a Token from a char and a string
        :kind(ch), name(n) { }
};

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
    case '=': // for Ch7.8
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
    default: // modified for example in Ch7.8
        if (isalpha(ch)) {
            string s;
            s += ch;
            while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) {
                s+=ch;
            }
            cin.putback(ch);
            if (s == declkey) {
                return Token{let}; // declaration keyword
            }
            if (s == setkey) {
                return Token{set}; // declaration keyword
            }
            return Token{name,s};
        }
        error("Bad token");
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
// Example for Ch 7.8, Variable

class Variable { // Define a new class for Variable
public:
    string name;
    double value;
};

vector <Variable> var_table;

// define get_value() function to read the value of Variable based on its name
double get_value (string s)
{
    for (const Variable & v:var_table) // go through every Variable in vector var_table
        if (v.name == s) return v.value;
    error("get: undefined variable ", s);
}

// define void function set_value
void set_value(string s, double d) // set the Variable named s to d
{
    for (Variable & v : var_table)
        if (v.name == s) {
            v.value = d;
            return;
        }
    error("set: undefined variable ", s);
}

// Check if a variable is already declared, bool function returns true or false
bool is_declared(string var)
{
    for (const Variable& v : var_table) {
        if (v.name == var) {
            return true;
        }
    }
    return false;
}

// function to define a variable with name and value, add {var, val} to vector var_table
double define_name(string var, double val)
{
    if (is_declared(var)) error(var," declared twice");
    var_table.push_back(Variable{var,val});
    return val;
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
    case name:
        return get_value(t.name); // for example in Ch7.8
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

// function of declaration, for Example Ch 7.8, page 246
double declaration()
// assume we have seen "let”
// handle: name = expression
// declare a variable called "name” with the initial value "expression”
{
    Token t = ts.get();
    if (t.kind != name) {
        error ("name expected in declaration");
    }
    string var_name = t.name;
    Token t2 = ts.get();
    if (t2.kind != '=') {
        error("= missing in declaration of ", var_name);
    }
    double d = expression();
    define_name(var_name,d);
    return d;
}

//------------------------------------------------------------------------------

// function of declaration, for Example Ch 7.8, self added
double reset_value()
// assume we have seen "set"
// reset the value of the variable based on name
{
    Token t = ts.get();
    if (t.kind != name) {
        error ("name expected in declaration");
    }
    string var_name = t.name;
    Token t2 = ts.get();
    if (t2.kind != '=') {
        error("= missing in declaration of ", var_name);
    }
    double d = expression();
    set_value(var_name,d);
    return d;
}

//------------------------------------------------------------------------------

// Define the function of statement(), for Example in Ch 7.8 Variable
double statement()
{
    Token t = ts.get();
    switch (t.kind) {
    case let:
        return declaration();
    case set:
        return reset_value();
    default:
        ts.putback(t);
        return expression();
    }
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
        cout << result << statement() << endl;
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

    // modified for example in Ch7.8 on p.250
    define_name("pi",3.1415926535);
    define_name("e",2.7182818284);

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
