#include<iostream>
using namespace std;

int main() {
	int a, b;
	cout << "ù��° ���ڸ� �Է����ּ���: ";
	cin >> a;
	cout << "�ι�° ���ڸ� �Է����ּ���: ";
	cin >> b;

	if (a <= b) {
		cout << "largest:" << b << "\nsmallest: " << a;
	}

	cout << "\nsum:" << a + b;
	cout << "\ndifference:" << b - a;
	cout << "\nproduct:" << a * b;

	if (a == 0) {
		cout << "\n0���δ� ���� �� �����ϴ�.";
	}
	else {
		cout << "\nratio:" << (float)b / a<<'\n';
	}
}