#include<iostream>
using namespace std;

int main() {
	int a;

	cout << "숫자를 입력하세요: ";
	cin >> a;

	if (a % 2 == 0)
		cout << a << "는 짝수입니다.\n";
	else
		cout << a << "는 홀수입니다.\n";
}