#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	vector<double> d;
	double t=1,sum=0;
	while (cin>>t&&t!=0) {
		d.push_back(t);
		sum += t;

	}
	sort(d.begin(), d.end());
	cout << "smallest:" << d[0] << endl;
	cout << "greatest:" << d[d.size()-1] << endl;
	cout << "mean:" << sum/(d.size()) << endl;



}