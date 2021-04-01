#include<iostream>
using namespace std;
class Cpolygon {
protected:
	int width, height;
public:
	void set_values(int a,int b) {
		width = a; height = b;
	};
};
class CReactangle :public Cpolygon {
public:
	int area() {
		return (width * height);
	};
};
class CTriangle :public Cpolygon {
public :
	int area() {
		return (width * height / 2);
	}
};
int main() {
	CReactangle rect;
	CTriangle tri;
	rect.set_values(4, 5);
	tri.set_values(4, 5);
	cout << rect.area() << endl;
	cout << tri.area() << endl;

	return 0;
}
