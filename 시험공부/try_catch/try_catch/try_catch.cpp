#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

ostream& operator<<(ostream &os, vector<int> &s) {
	for (int i : s)
		os<< i << " ";
	return os;
}
class Bad_area{};

int area(int x, int y) {
	if (x <= 0 || y <= 0)throw Bad_area{};
	return x * y;
}

int main() {
	int x, y;
	cout << "°¡·Î ¼¼·Î ÀÔ·Â:" << endl;
	cin >> x;
	cin >> y;
	try {
		cout<<area(x,y);
		
	}
	catch(Bad_area){
		cerr << "Æ²·Ç¶ä" << endl;
	}
}