#include<iostream>
#include<stack>
#include<string>
using namespace std;

class Token{
public:
	char kind;
	double value;
	Token(char c, int n) {
		switch (c) {
		case '+':
			kind = '+';
			break;
		case '-':
			kind = '-';
			break;
		case '*':
			kind = '*';
			break;
		case '/':
			kind = '/';
			break;
		case ')':
			kind = ')';
			break;
		case '(':
			kind = '(';
		case '8':
			kind = '8';
			value = n;
			break;
		}
	}
	Token() {
		kind = 0;
		value = 0;
	}

};

class Calculator {
protected:
	stack <Token> ts;
	void tokenize(string line);
	double expression();
	double term();
	double primary();
public:
	double calculate(string s) {
		tokenize(s);
		return expression();
	};
};
void Calculator::tokenize(string line) {
	int i = 0; int j = 0;
	for (; j < line.length(); j++) {
		switch (line[j]) {
		case '+':
		case '-':
		case '*':
		case '/':
		case '(':
		case ')':
			if (i < j)
				ts.push(Token('8', stoi(line.substr(i, j-i))));
			ts.push(Token(line[j], 0));
			i = j + 1;
			break;
		case ' ':
			if (i < j)
				ts.push(Token('8', stoi(line.substr(i, j-i))));
			i = j + 1;
			break;
		}
	}
	if (i < j)
		ts.push(Token('8', stoi(line.substr(i, j-i))));
}
double Calculator::expression() {
	double right = term();
	if (!ts.empty()) {
		Token t = ts.top();
		ts.pop();
		switch (t.kind) {
		case '+':
			right = expression() + right; break;
		case '-':
			right = expression() - right; break;
		default:
			ts.push(t);
		}
	}
	return right;
}
double Calculator::term() {
	double right = primary();

	if (!ts.empty()) {
		Token t = ts.top();
		ts.pop();
		switch (t.kind) {
		case '*':
			right = term() * right;
			break;
		case '/':
			right = term() / right;
			break;
		default:
			ts.push(t);
		}
	}
	return right;
}
double Calculator::primary() {
	Token t = ts.top();
	ts.pop();
	return t.value;
}
class NewCal :public Calculator {
	double primary() {
		double value = 0;
		Token t = ts.top();
		ts.pop();
		if (t.kind == '8')
			return t.value;
		else if (t.kind == ')') {
			double value = expression();
			ts.pop();
		}
	}
};


int main() {
	double cal = 0;
	string line;
	NewCal mycal;
	while (true) {
		cout << "수식을 입력하세요:\n";
		getline(cin, line);
		if (line == "q")break;
		double val = mycal.calculate(line);
		cout <<"결과:"<< val << endl<<endl;
	}
}