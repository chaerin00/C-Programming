#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

ostream& operator<<(ostream &os, vector<int> &s) {
	for (int i : s) {
		os << i << " ";
	}
	return os;
}
vector<int> delete_same(vector<int>& input) {
	vector<int>result;
	for (int i = 1; i < input.size(); i++) {
		if (input[i-1] != input[i])
			result.push_back(input[i-1]);
	}
	result.push_back(input[input.size()-1]);
	return result;
}

int main() {
	vector<int> s;
	cout << "변수 입력(-1이면 종료)"<<endl;
	int i = 0;
	while (cin >> i&&i != -1) {
		s.push_back(i);
	}
	cout << s<<endl;
	s=delete_same(s);
	cout << s << endl;
	sort(s.begin(), s.end());
	cout << s<<endl;

}