#include<iostream>
#include <string>
using namespace std;

class Gate {
protected:
	virtual bool output(bool a = true, bool b = true) = 0;
	virtual string name() = 0;
public:
	void printTruthTable();
};

void Gate::printTruthTable() {
	cout << this->name() << endl;
	cout << "-------------------------" << endl;
	cout << "X Y R" << endl;
	cout << "1 1 " << this->output(true, true) << endl;
	cout << "1 0 " << this->output(true, false) << endl;
	cout << "0 1 " << this->output(false, true) << endl;
	cout << "0 0 " << this->output(false, false) << endl;
	
};
class And : public Gate {
protected:
	bool output(bool a, bool b);
	string name() {
		return "AND";
	}

};
class Or : public Gate {
protected:
	bool output(bool a, bool b);
	string name() {
		return "OR";
	}

};
class Not : public Gate {
protected:
	bool output(bool a, bool b);
	string name() {
		return "NOT";
	}
public:
	void printTruthTable();

};
bool And::output(bool a, bool b) {
	return a && b;
}
bool Or::output(bool a, bool b) {
	return a || b;
}
bool Not::output(bool a, bool b) {
	return ~a;
}
void Not::printTruthTable() {
	cout << this->name() << endl;
	cout << "-------------------------" << endl;
	cout << "X R" << endl;
	cout << "1 " << this->output(true,true) << endl;
	cout << "0 " << this->output(false,true) << endl;
};

int main() {
	And a;
	Or b;
	Not c;
	a.printTruthTable();
	b.printTruthTable();
	c.printTruthTable();

}