#include<vector>
#include<iostream>

using namespace std;

class Numbers {
	vector<int> values;
public:
	int getMin();
	int getMean();
	friend Numbers operator+(Numbers& x,Numbers&y) {
		Numbers c(x);
		for (int k : y.values)
			c.values.push_back(k);
		return c;
	}
	friend ostream& operator<<(ostream& os, const Numbers& x) {
		for (int i = 0; i < x.values.size() - 1; i++)
			os << x.values[i] << ",";
		os << x.values[x.values.size() - 1] << endl;
		return os;
	}
	Numbers(const vector<int>& v) /*:values{ v }*/ {

		values = v;
		/*for (int s : v) {
			values.push_back(s);
		}*/
	}
	
};
int Numbers::getMin() {
	int min = 100000;
	for (int s : Numbers::values) {
		if (s < min)
			min = s;
	}
	return min;

}
int Numbers::getMean() {
	int sum = 0;
	for (int s : Numbers::values) {
		sum += s;
	}
	return sum / Numbers::values.size();

}

int main() {
	const vector<int> a = { 1,2,3,4 };
	const vector<int> b = { 5,6,7,8 };
	Numbers A(a);
	Numbers B(b);
	Numbers C = A + B;
	cout << C.getMean() << endl;
	cout << C.getMin() << endl;
	cout << C;

}
