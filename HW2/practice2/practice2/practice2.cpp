#include<iostream>
#include<string>
using namespace std;

int main() {
	double o1, o2,result;
	string op;


	cin >> op;
	cin >> o1;
	cin >> o2;

	if (op == "+") 
		cout << o1 + o2 << endl;
	else if (op == "-")
		cout << o1 - o2 << endl;
	else if (op == "*")
		cout << o1 * o2 << endl;
	else if (op == "/") {
		if (o2 == 0)return 0;
		cout << o1 / o2 << endl;
	}


}
