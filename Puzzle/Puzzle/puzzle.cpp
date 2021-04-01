#include<iostream>
#include<math.h>
#include<fstream>
#include<string>
using namespace std;

int indexZero;
class Puzzle {
public:
	Puzzle(string s);
	int map[9];
	void move(char dir);
	bool isDone();
	void print();
	int findZero();
	friend ostream& operator<<(ostream& os, Puzzle P);
	friend ifstream& operator>>(ifstream& is, Puzzle& P);
};
class outOfRange {};
class noneDir {};

Puzzle::Puzzle(string s) {
	ifstream ifs{ s };
	for (int i = 0; i < 9; i++) {
		ifs >> map[i];
	}
}
ostream& operator<<(ostream& os, Puzzle P) {
	for (int i = 0; i < 9; i++) {
		os << P.map[i] << " ";
	}
	return os;
}
ifstream& operator>>(ifstream& is, Puzzle& P) {
	for (int i = 0; i < 9; i++) {
		is >> P.map[i];
	}
	return is;
}
void Puzzle::print() {
	for (int i = 0; i < 9; i++) {
		if ((i + 1) % 3 != 0) {
			cout << map[i] << " ";
		}
		else {
			cout << map[i] << endl;
		}
	}
	cout << endl;
}
void Puzzle::move(char dir) {
	int swap = 0;
	try {
		switch (dir) {
		case 'n':
			if (indexZero - 3 < 0) {
				throw outOfRange();
			}
			swap = map[indexZero - 3];
			map[indexZero - 3] = 0;
			map[indexZero] = swap;
			indexZero = indexZero - 3;
			break;
		case 'w':
			if (indexZero%3==0) {
				throw outOfRange();
			}
			swap = map[indexZero - 1];
			map[indexZero - 1] = 0;
			map[indexZero] = swap;
			indexZero = indexZero - 1;
			break;
		case 'e':
			if (indexZero % 3 ==2) {
				throw outOfRange();
			}
			swap = map[indexZero + 1];
			map[indexZero + 1] = 0;
			map[indexZero] = swap;
			indexZero = indexZero + 1;
			break;
		case 's':
			if (indexZero +3>9) {
				throw outOfRange();
			}
			swap = map[indexZero + 3];
			map[indexZero + 3] = 0;
			map[indexZero] = swap;
			indexZero = indexZero + 3;
			break;

		default:
			throw noneDir();
		}

	}
	catch (outOfRange) {
		cout << "움직일 수 없습니다.\n";
	}
	catch (noneDir) {
		cout << "올바른 방향을 입력하세요.\n";
	}
	
}
int Puzzle::findZero() {
	int i = 0;
	while (this->map[i] != 0)i++;
	return i;
}
bool Puzzle::isDone() {
	int goal[9] = { 1,2,3,8,0,4,7,6,5 };
	bool result;
	for (int i = 0; i < 9; i++) {
		if (goal[i] == map[i])
			result = true;
		else {
			result = false;
			return result;
		}
	}
	return result;
}
int main() {
	Puzzle mine("second.txt");
	indexZero = mine.findZero();
	char dir;
	while (!mine.isDone()) {
		mine.print();
		cout << "give me your decision: ";
		cin >> dir;
		mine.move(dir);

	}
	cout << "맞았습니다!\n";


}
