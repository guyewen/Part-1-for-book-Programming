/*
    Drill for Chapter 7

    calculator08buggy.cpp

    Helpful comments removed.

    We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/

#include "std_lib_facilities.h"

struct Token {
    char kind;
    double value;
    string name;
    Token(char ch) :kind(ch), value(0) { }
    Token(char ch, double val) :kind(ch), value(val) { }
    Token(char ch, string s) :kind(ch), name(s) { } // Error No.1 for Drill 1, missing this token type
};

class Token_stream {
    bool full;
    Token buffer;
public:
    Token_stream() :full(0), buffer(0) { }

    Token get();
    void unget(Token t) { buffer = t; full = true; }

    void ignore(char);
};

const char let = 'L';
const char quit = 'q';
const char print = ';';
const char number = '8';
const char name = 'a';
const string sqrt_key = "sqrt"; // drill 07
const char squrt = 'Q'; // drill 07
const string pow_key = "pow"; // drill 09
const char power = 'P'; // drill 09

Token Token_stream::get()
{
    if (full) { full = false; return buffer; }
    char ch;
    cin >> ch;
    switch (ch) {
    case '(':
    case ')':
    case '+':
    case ',': // for pow function, drill 09
    case '-':
    case '*':
    case '/':
    case '%':
    case print:       // for "print"
    case quit:       // for "quit" // Error No.5, missing here
    case '=':
        return Token(ch);
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
    {	cin.unget();
        double val;
        cin >> val;
        return Token(number, val);
    }
    default:
        if (isalpha(ch)) {
            string s;
            s += ch;
            while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch; // Error No.2 for Drill 1, should be +=, not =
            cin.unget();
            if (s == "let") return Token(let);
            if (s == "quit") return Token(quit); // Error No.4, should be Token(quit), not Token(name)
            if (s == sqrt_key) { // drill 07
                return Token{squrt};
            }
            if (s == pow_key) { // drill 09
                return Token{power};
            }
            return Token(name, s);
        }
        error("Bad token");
    }
}

void Token_stream::ignore(char c)
{
    if (full && c == buffer.kind) {
        full = false;
        return;
    }
    full = false;

    char ch;
    while (cin >> ch)
        if (ch == c) return;
}

struct Variable {
    string name;
    double value;
    Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> names;

double get_value(string s)
{
    for (int i = 0; i < names.size(); ++i)
        if (names[i].name == s) return names[i].value;
    error("get: undefined name ", s);
}

void set_value(string s, double d)
{
    for (int i = 0; i < names.size(); ++i) // Error No.3 for drill 1, change <= to <
        if (names[i].name == s) {
            names[i].value = d;
            return;
        }
    error("set: undefined name ", s);
}

bool is_declared(string s)
{
    for (int i = 0; i < names.size(); ++i)
        if (names[i].name == s) return true;
    return false;
}

// function to define a variable with name and value, add {var, val} to vector var_table
double define_name(string var, double val) // for Drill 6
{
    if (is_declared(var)) error(var," declared twice");
    names.push_back(Variable{var,val});
    return val;
}

Token_stream ts;

double expression();

double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':
    {	double d = expression();
        t = ts.get();
        if (t.kind != ')') error("')' expected"); // Error No.6, change ( to ) in the error message
        return d; // Error No.7, this line is missing
    }
    case '-':
        return -primary();
    case number:
        return t.value;
    case name:
        return get_value(t.name);
        // for drill 07, sqrt function
    case squrt:
    {
        //get next char after 'sqrt' if not '(' then error
        t = ts.get();
        if (t.kind != '(') {
            error("'(' expected");
        }

        //if expression is less than 0 print an error
        double d = expression();
        if (d < 0)
            error("Cannot square root negative integers");

        //get next char after expression, if not ')' then error
        t = ts.get();
        if (t.kind != ')')
            error("')' expected");

        //return square root of the expression taken from the tokenstream
        return sqrt(d);
    }
        // for drill 09, power function, pow(x,i) = x^i
    case power:
    {
        //get next char after 'sqrt' if not '(' then error
        t = ts.get();
        if (t.kind != '(') {
            error("'(' expected");
        }

        double x = expression(); // read or calculate the first parameter x in pow(x,i)

        //get next char after 'expression' if not ',' then error
        t = ts.get();
        if (t.kind != ',')
            error("',' expected");

        double i = expression();  // read or calculate the second parameter i in pow(x,i)

        // test if parameter i is integer, if not error message, optional
        if (i - floor(i) != 0) {
            error("i parameter must be integer for pow(x,i)");
        }

        //get next char after expression, if not ')' then error
        t = ts.get();
        if (t.kind != ')')
            error("')' expected");

        // return expression using pow() from <cmath>
        return pow(x, i);
    }
    default:
        error("primary expected");
    }
}

double term()
{
    double left = primary();
    while (true) {
        Token t = ts.get();
        switch (t.kind) {
        case '*':
            left *= primary();
            break;
        case '/':
        {	double d = primary();
            if (d == 0) error("divide by zero");
            left /= d;
            break;
        }
        case '%': // Error No.8, the whole part for handling % is missing
        {
            double d = primary();
            if (d == 0) error("divide by zero");
            left = fmod(left, d);
            t = ts.get();
            break;
        }
        default:
            ts.unget(t);
            return left;
        }
    }
}

double expression()
{
    double left = term();
    while (true) {
        Token t = ts.get();
        switch (t.kind) {
        case '+':
            left += term();
            break;
        case '-':
            left -= term();
            break;
        default:
            ts.unget(t);
            return left;
        }
    }
}

double declaration()
{
    Token t = ts.get();
    if (t.kind != 'a') error("name expected in declaration");
    string name = t.name;
    if (is_declared(name)) error(name, " declared twice");
    Token t2 = ts.get();
    if (t2.kind != '=') error("= missing in declaration of ", name);
    double d = expression();
    names.push_back(Variable(name, d));
    return d;
}

double statement()
{
    Token t = ts.get();
    switch (t.kind) {
    case let:
        return declaration();
    default:
        ts.unget(t);
        return expression();
    }
}

void clean_up_mess()
{
    ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
    while (true) try {
        cout << prompt;
        Token t = ts.get();
        while (t.kind == print) t = ts.get();
        if (t.kind == quit) return;
        ts.unget(t);
        cout << result << statement() << endl;
    }
    catch (runtime_error& e) {
        cerr << e.what() << endl;
        clean_up_mess();
    }
}

int main()

try {
    define_name("k",1000); // for Drill 6
    calculate();
    return 0;
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    char c;
    while (cin >> c && c != ';');
    return 1;
}
catch (...) {
cerr << "exception\n";
char c;
while (cin >> c && c != ';');
return 2;
}
