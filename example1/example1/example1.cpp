#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int main() {
	vector<string> v;
	for (string s; cin >> s && s != "quit";)
		v.push_back(s);
	sort(v.begin(), v.end());
	vector<string> w2;
	if (0 < v.size()) {
		w2.push_back(v[0]);
		for (int i = 1; i < v.size(); ++i) {
			if (v[i - 1] != v[i])
				w2.push_back(v[i]);
		}
	}
	for (string x : w2)
		cout << x << endl;
}