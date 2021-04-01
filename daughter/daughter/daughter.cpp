#include<iostream>
#include<vector>
#include<string>
using namespace std;

class find_alphabet {
	string S;
	vector<int>result;
public:
	find_alphabet(string s);
	vector<char> slice_string();
	void print_result(vector<char>input);
};
find_alphabet::find_alphabet(string s) {
	S = s;
}

vector <char> find_alphabet::slice_string(){
	vector <char> result;
	for (char x : S) {
		result.push_back(x);
	}
	return result;
}
void find_alphabet::print_result(vector<char>input) {
	for (int j = 0; j < 26; j++)
		result.push_back(-1);
	for (int i = 0; i < input.size();i++) {
		int X = input[i] - 97;
		cout << X << endl;
		if (result[X] == -1)
			result[X] = i;
		else
			continue;
	}
	for (int k = 0; k < 26; k++)
		cout << result[k] << " ";
}
int main() {
	string s;
	cin >> s;
	find_alphabet q(s);
	q.print_result(q.slice_string());
}