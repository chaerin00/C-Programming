#include<iostream>
using namespace std;

int main() {
	int a;

	cout << "���ڸ� �Է��ϼ���: ";
	cin >> a;

	if (a % 2 == 0)
		cout << a << "�� ¦���Դϴ�.\n";
	else
		cout << a << "�� Ȧ���Դϴ�.\n";
}