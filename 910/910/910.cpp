#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int prime(int a) {
	int result = 0;
	for (int j = 1; j < a+1; j++) {
		if (a % j == 0)
			result++;//���⼭ return �ϰ� �����
	}
	return result;
}//bool �����ϰ� ����

int main() {
	int t;
	cin >> t;
	cout << "���\n";
	for (int i = 1; i < t + 1; i++) {
		if (prime(i) == 2)
			cout << i << endl;
	}
}