#include<iostream>
using namespace std;

int main() {
	int a, b;
	cout << "첫번째 숫자를 입력해주세요: ";
	cin >> a;
	cout << "두번째 숫자를 입력해주세요: ";
	cin >> b;

	if (a <= b) {
		cout << "largest:" << b << "\nsmallest: " << a;
	}

	cout << "\nsum:" << a + b;
	cout << "\ndifference:" << b - a;
	cout << "\nproduct:" << a * b;

	if (a == 0) {
		cout << "\n0으로는 나눌 수 없습니다.";
	}
	else {
		cout << "\nratio:" << (float)b / a<<'\n';
	}
}