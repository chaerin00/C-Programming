#include<iostream>
#include<string>
using namespace std;

int main() {
	string a;
	cout << "숫자로 변환할 단어를 입력해주세요(0~4): ";
	cin >> a;
	if (a == "zero")
		cout <<'\n'<< a << "---->" << 0<< '\n';
	else if (a == "one")
		cout << '\n'<< a << "---->" << 1<< '\n';
	else if (a == "two")
		cout << '\n'<< a << "---->" << 2<< '\n';
	else if (a == "three")
		cout << '\n'<<a << "---->" << 3<< '\n';
	else if (a == "four")
		cout << '\n'<< a << "---->" << 4<< '\n';
	else
		cout << "\n저는 그런 말을 배운 기억이 없습니다.\n";

}