#include<iostream>
using namespace std;

int main() {
	int a, b, c;
	cout << "첫번째 숫자를 입력해주세요:";
	cin >> a;
	cout << "두번째 숫자를 입력해주세요:";
	cin >> b;
	cout << "세번째 숫자를 입력해주세요:";
	cin >> c;

	if (a <= b) {
		if (a <= c) {
			cout << " " << a;
			if (b <= c)
				cout << " " << b << " " << c;
			else
				cout << " " << c <<" "<< b;
		}
		else {
			cout << " " << c;
			if (b <= a)
				cout << " " << b << " " << a;
			else
				cout << " " << a << " " << b;
		}
	}
	else {
		if (b <= c) {
			cout << " " << b;
			if (a <= c)
				cout << " " << a << " " << c;
			else
				cout << " " << c << " "<<a;
		}
		else {
			cout << " " << c;
			if (b <= a)
				cout << " " << b << " " << a;
			else
				cout << " " << a << " " << b;
		}
	}
}