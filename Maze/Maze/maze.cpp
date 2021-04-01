#include<fstream>
#include<iostream>
#include<vector>
#include<string>

using namespace std;
class NoRect {};
class NoS {};
class NoX {};
class UncorrectS{};
class UncorrectX{};
class NoRoute{};


class Maze {
	int r, c, curR, curC,d;
	int count = 0;
	vector<string>map;
	void readMap(string filename);
	void setCurrentPosition();
	void initialize(string filename);
	int nextR();
	int nextC();
	int nextRR();
	int nextRC();
	void moveToNext();
	void findpath();
	void turnRight();
	void turnLeft();
public:
	void play(string str);
};
void Maze::readMap(string filename) {
	ifstream is(filename);
	string firstline;
	getline(is, firstline);
	int lineLength = firstline.length();
	is.close();

	ifstream ifs(filename);
	while (!ifs.eof()) {
		string line;
		getline(ifs, line);
		if (lineLength != line.length())
			throw NoRect();
		map.push_back(line);
	}
};
void Maze::setCurrentPosition() {
	r = map.size();
	c = map[0].length();
	bool existX=false;
	int XR, XC;
	bool existS=false;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == 's') {
				curR = i;
				curC = j;
				existS = true;
				break;
			}
			if (map[i][j] == 'x') {
				XR = i;
				XC = j;
				existX = true;
				break;
			}
		}
	}
	if (existX == false)
		throw NoX();
	if (existS == false)
		throw NoS();

	if (curR == 0)d = 's';
	else if (curC == 0)d = 'e';
	else if (curR == (r - 1))d = 'n';
	else if (curC == (c - 1))d = 'w';
	else throw UncorrectS();

	if ((XR != 0 && XR != (r - 1)) && (XC != 0 && XC != (c - 1)))
		throw UncorrectX();
};
void Maze::initialize(string filename) {
	readMap(filename);
	setCurrentPosition();
};
int Maze::nextR() {
	switch (d) {
	case 'n':
		return curR - 1;
	case 's':
		return curR + 1;
	case 'e':
	case 'w':
		return curR;
	}
};
int Maze::nextC() {
	switch (d) {
	case 'e':
		return curC + 1;
	case 'w':
		return curC - 1;
	case 'n':
	case 's':
		return curC;
	}
};
int Maze::nextRR() {
	switch (d) {
	case 'e':
		return curR+1;
	case 'w':
		return curR -1;
	case 'n':
		return curR - 1;
	case 's':
		return curR +1;
	}
};
int Maze::nextRC() {
	switch (d) {
	case 'n':
		return curC + 1;
	case 's':
		return curC - 1;
	case 'e':
		return curC + 1;
	case 'w':
		return curC - 1;
	}

};
void Maze::moveToNext() {
	int next[3];
	next[0] = map[curR][curC];
	int nextR = this->nextR();
	int nextC = this->nextC();
	next[1] = map[nextR][nextC];
	int nextRR = this->nextRR();
	int nextRC = this->nextRC();
	next[2] = map[nextRR][nextRC];

	if (next[1] != '#' && next[2] == '#') {
		map[curR][curC] = '*';
		curR = this->nextR();
		curC = this->nextC();
		count = 0;
	}
	else if (next[1] == '#' && next[2] == '#') {
		map[curR][curC] = '*';
		turnLeft();
		count++;
	}
	else if (next[1] != '#' && next[2] != '#') {
		map[curR][curC] = '*';
		turnRight();
		count = 0;
	}

	if (count > 5)
		throw NoRoute();

};
void Maze::turnRight() {
	switch (d) {
	case 'e':{
		curR = curR + 1;
		curC = curC + 1;
		d = 's';
		break;
	}
	case 'w': {
		curR = curR - 1;
		curC = curC - 1;
		d = 'n';
		break;
	}

	case 'n': {
		curR = curR - 1;
		curC = curC + 1;
		d = 'e';
		break;
	}
	case 's': {
		curR = curR + 1;
		curC = curC - 1;
		d = 'w';
		break;
	}
	}
};
void Maze::turnLeft() {
	switch (d) {
	case 'n': {
		d = 'w';
		break;
	}
	case 's': {
		d = 'e';
		break;
	}
	case 'e': {
		d = 'n';
		break;
	}
	case 'w': {
		d = 's';
		break;
	}
	}

};
void Maze::findpath() {
	while (map[curR][curC] != 'x') {
		moveToNext();
		for (int i = 0; i < r; i++) {
			cout << map[i] << endl;
		}
		cout << endl;
	}
};
void Maze::play(string filename) {
	initialize(filename);
	for (int i = 0; i < r; i++) {
		cout << map[i] << endl;
	}
	cout << "--------start----------\n";
	findpath();
}

int main() {
	Maze mymaze;
	try { mymaze.play("5BY5.txt"); }
	catch (NoRect) {
		cout << "NoRect Maze" << endl;
	}
	catch (NoX) {
		cout << "NoX" << endl;
	}
	catch (NoS) {
		cout << "NoS" << endl;
	}
	catch (UncorrectS) {
		cout << "UncorrectS" << endl;
	}
	catch (UncorrectX) {
		cout << "UncorrectX" << endl;
	}
	catch (NoRoute) {
		cout << "NoRoute" << endl;
	}
	cout << "------------------------------------" << endl;
	//mymaze.play("12BY12.txt");
}