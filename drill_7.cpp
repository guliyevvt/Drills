
#include "std_lib_facilities.h"
#define k 1000

double expression();

class Token {
public:
	char kind;
	double value;
	Token(char ch)
		: kind(ch), value(0) {}
	Token(char ch, double val)
		: kind(ch), value(val) {}

};

class Token_stream {
public:
	Token_stream();
	Token get();
	void putback(Token t);
private:
	bool full;
	Token buffer;
};

Token_stream::Token_stream() : full(false), buffer(0) {}

void Token_stream::putback(Token t)
{
	if (full) error("Token_stream buffer full");
	buffer = t;
	full = true;
}

Token Token_stream::get()
{
	if (full)
	{
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;

	switch (ch) {
	case 's':case 'q':case 'r':case 't':
	case 'p':case 'o':case 'w': case ',':
	case 'x':           //x is instead of q, for exiting program
	case '=':           //= is instead of ;, for getting result
	case '(': case ')': case '+':
	case '-': case '*': case '/':
	case '%':
		return Token(ch);
	case '.':
	case '0': case '1': case '2': case '3':
	case '4': case '5': case '6': case '7':
	case '8': case '9':
	{
		cin.putback(ch);
		double val = 0;
		cin >> val;
		return Token('8', val);
	}
	default:
		error("Bad token");
		return 0;
	}
}

Token_stream ts;

double primary()
{
	Token t = ts.get();
	switch (t.kind)
	{

	case 's': {
		t = ts.get();
		if (t.kind != 'q') error("sqrt expected");
		t = ts.get();
		if (t.kind != 'r') error("sqrt expected");
		t = ts.get();
		if (t.kind != 't') error("sqrt expected");
		t = ts.get();
		if (t.kind != '(') error("'(' expected");

		double d = expression();
		if (d < 0) {
			error("square root for negative number!!");
		}

		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return sqrt(d);
	}

	case 'p': {
		t = ts.get();
		if (t.kind != 'o') error("pow expected");
		t = ts.get();
		if (t.kind != 'w') error("pow expected");
		t = ts.get();
		if (t.kind != '(') error("pow expected");


		double d1 = expression();
		t = ts.get();
		if (t.kind != ',') error("',' expected");
		double d2 = expression();

		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return pow(d1, d2);
	}

	case '(':
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return d;
	}
	case '8':
		return t.value;
	default:
		error("primary expected");
		return 0;
	}
}

double term()
{
	double left = primary();
	Token t = ts.get();
	while (true) {
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
		case '%':
			left = (int)left % (int)primary();
			t = ts.get();
			//error("operator \% can't use for double");
			break;

		default:
			ts.putback(t);
			return left;
		}
	}
}

double expression()
{
	double left = term();
	Token t = ts.get();
	while (true) {
		switch (t.kind) {
		case '+':
			left += term();
			t = ts.get();
			break;
		case '-':
			left -= term();
			t = ts.get();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}


int main()
try {
	// greeting 
	cout << "Welcome to our simple calculator\n";
	cout << "Please enter expressions using floating numbers\n";
	//operators 
	cout << "List of Operators:\n";
	cout << "For sum use->  '+'" << endl;
	cout << "For subtraction use->  '-'" << endl;
	cout << "For product use->  '*'" << endl;
	cout << "For quotient use->   '/'" << endl;
	cout << "Your expression:";
	double val = 0;

	while (cin)
	{
		Token t = ts.get();

		if (t.kind == 'x') break;    // x instead of q      
		if (t.kind == '=')           // = instead of ;       
			cout << "=" << val << endl;
		else
			ts.putback(t);

		val = expression();
	}

	return 0;

}
catch (exception& e) {
	cerr << e.what() << endl;
	return 1;
}
catch (...) {
	cerr << "exception\n";
	return 2;
}
