#include<iostream>
using namespace std;

int main() {
	const double cm_per_inch = 2.54;
	int length = 1;
	while (length != 0) {
		cout << "please enter a length in inchese:";
		cin >> length;
		cout << length << "in.=" << cm_per_inch * length << "cm.\n";
	}
}