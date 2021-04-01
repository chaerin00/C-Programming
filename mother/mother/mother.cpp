#include<iostream>
using namespace std;

class mother {
public:
	mother() {
		cout << "mother:no\n";
	}
	mother(int a) {
		cout << "mother:int\n";
	}
	~mother() {
		cout << "mother\n";
	}
};
class daughter :public mother {
public:
	daughter(int a) {
		cout << "daugher: int\n";
	}
	~daughter() {
		cout << "daugher\n";
	}
};
class son :public mother {
public:
	son(int a) :mother(a) {
		cout << "son:int \n\n";
	}
	~son() {
		cout << "son\n";
	}
};

int main() {
	daughter cl(0);
	son jh(0);
	return 0;
}