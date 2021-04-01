#include <iostream>
#include <cmath>

using namespace std;

class Point {
	float x, y;
public:
	Point();
	Point(float a, float b);
	float length();
	friend ostream& operator<<(ostream& os, Point&p);
	friend int operator*(Point p1, Point p2);

};
Point::Point() {
	x = 0;
	y = 0;
}
Point::Point(float a, float b) {
	x = a;
	y = b;
}
float Point::length() {
	return sqrt(x *x + y *y);
}

ostream& operator<<(ostream& os, Point& p) {
	os << "(" << p.x << "," << p.y << ")" << endl;
	return os;
}
int operator*(Point p1, Point p2) {
	return p1.x * p2.x + p1.y * p2.y;
}

int main() {
	Point A;
	Point B(3.0, 4.0);
	Point C(1, 1);
	cout << A << endl;
	cout << B << endl;
	cout << A.length() << endl;
	cout << B.length() << endl;
	cout << (C * B) << endl;


}
