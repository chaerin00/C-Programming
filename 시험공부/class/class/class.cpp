#include<iostream>

using namespace std;


class Date {
protected:
	int y, m, d;
public:
	static int n;
	friend ostream& operator<<(ostream& os, Date& D);
	Date(int x, int y, int z);
	Date();
	//virtual void time(void) = 0;
};
ostream& operator<<(ostream& os, Date& D) {
	os << "year: " << D.y << endl << "month: " << D.m << endl
		<< "day: " << D.d << endl << "this is " << D.n << "th day\n";
	return os;
}
Date::Date(int x, int y, int z) {
	this->y = x;
	this->m = y;
	this->d = z;
	n++;
}
Date::Date() {
	this->y = 0;
	this->m = 0;
	this->d = 0;
	n++;
}

class Now : public Date {
	int hour, second;
public:
	Now(int x,int y) {
		this->hour = x;
		this->second = y;
	}
	friend ostream& operator<<(ostream& os, Now& n) {
		os << "year: " << n.y << endl << "month: " << n.m << endl
			<< "day: " << n.d << endl << "this is " << n.n << "th day\n"
			<< "hour: " << n.hour << endl << "minute: " << n.second << endl;
		return os;
	}
};

int Date::n = 0;
int main() {
	
	Date today(2020, 10, 21);
	cout << today;
	Date yesterday(2020, 10, 20);
	cout << yesterday;
	Date tomorrow(2020, 10, 22);
	cout << tomorrow;

	Now now(18, 8);
	cout << now;


}