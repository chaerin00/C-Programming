#include<iostream>
using namespace std;

class sevenSeg {
	int num;
	char seg[15] = { ' ','-',' ','|',' ','|',' ','-',' ','|',' ','|',' ','-' ,' ' };
public:
	sevenSeg(int n);
	friend ostream& operator<<(ostream& os, sevenSeg k);
	friend sevenSeg operator+(sevenSeg k1, sevenSeg k2);
	void printLine(int k) {
		cout << seg[k] << seg[k + 1] << seg[k + 2];
	}
};
sevenSeg::sevenSeg(int n) {
	
	if (n == 0)
		seg[7] = ' ';
	if (n == 1)
		seg[1] = seg[3] = seg[7] = seg[9] = seg[13] = 0;
	if (n == 2)
		seg[3] = seg[11] = ' ';
	if (n ==3)
		seg[3] = seg[9] = ' ';
	if (n == 4)
		seg[1] = seg[9] = seg[13] = ' ';
	if (n == 5)
		seg[5]=seg[9] = ' ';
	if (n == 6)
		seg[5] = ' ';
	if (n == 7)
		seg[3] = seg[7] = seg[9] = seg[13] = ' ';
	if (n == 9)
		seg[9] = ' ';
	num = n;
}
ostream& operator<<(ostream& os, sevenSeg k) {
	for (int i = 0; i < 5; i++)
		k.printLine(i*3);
	//os << " "<<k.seg[0]<< endl << k.seg[1] << " " << k.seg[2] << endl 
		//<< " " << k.seg[3] << endl << k.seg[4] <<" "<< k.seg[5] << endl << " " << k.seg[6]<<endl;
	return os;
}
sevenSeg operator+(sevenSeg k1, sevenSeg k2) {
	int sum = k1.num + k2.num;
	if (sum > 9)
		sum -= 10;
	sevenSeg c(sum);

	return c;
}

class SevenSegs {
	int n;
	vector<sevenSeg> segs;
	void sync() {
		for (int t = n; t != 0; t = t/10) {
			segs.push_back(sevenSeg(t % 10));
		}
	}
public:
	SevenSegs();
	SevenSegs(int a);

	friend SevenSegs operator+(const SevenSegs& a, const SevenSegs& b);
	friend ostream& operator <<(ostream& os, const SevenSegs& x) {
		for (int i = 0; i < 5; i++) {
			for (int j = x.segs.size()-1; j > =0; j--) {
				x.segs[j].printLine(i);
				os << ' ';

			}
			os << endl;
		}
		return os;
	}
};
SevenSegs::SevenSegs(int a) {
	n = a;
	sync();


	segs.push_back(first);
	segs.push_back(second);

}
SevenSeg operator+(const SevenSegs& a, const SevenSegs& b) {
	return SevenSegs(a.n, b.n);
}
int main() {
	sevenSeg a(3);
	sevenSeg b(4);
	sevenSeg c = a + b;
	cout << a << endl;
	cout << b<< endl;
	cout << c  << endl;
}