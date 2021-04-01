#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Hangman {
	vector<char>goal;
	vector<char>userAnswer;
	vector<char>graphic = { '-','-' ,'-' ,'\n',' ','|',' ','\n',' ','o',' ','\n','<','|','>','\n','<',' ','>' };
	int score = 0;
	int failscore = 0;
public:
	void start();
	void play();
	void checkAnswer(char c);
	void showgraphic(int score);
	void showUserAnswer();
	void showScore();
};
void Hangman::showUserAnswer() {
	for (int i = 0; i < userAnswer.size(); i++)
		cout << userAnswer[i];
	cout << endl;
};
void Hangman::showScore() {
	cout << score << endl;
};
void Hangman::start() {
	string goalString = "seed";
	for (int i = 0; i < goalString.size(); i++) {
		goal.push_back(goalString[i]);
	}
	for (int i = 0; i < goalString.size(); i++) {
		userAnswer.push_back('_');
	}

};
void Hangman::play() {
	start();
	while (score < goal.size() && failscore < 7) {
		cout << "answer: ";
		char c;
		cin >> c;
		checkAnswer(c);
		cout << "score: ";
		showScore();
		cout << endl;
		showUserAnswer();
		showgraphic(failscore);
	}
};
void Hangman::checkAnswer(char c) {
	bool correct = false;
	int i = 0;
	for (i = 0; i < goal.size(); i++) {
		if (goal[i] == c) {
			correct = true;
			score++;
			goal[i] = '_';
			userAnswer[i] = c;
		}
	}
	if (!correct) {
		failscore++;
	}
};
void Hangman::showgraphic(int score) {
	int graphicNum = -1;
	switch (score)
	{
	case 0: {
		graphicNum = 4;
		break;
	}
	case 1: {
		graphicNum = 8;
		break;
	}
	case 2: {
		graphicNum = 12;
		break;
	}
	case 3: {
		graphicNum = 13;
		break;
	}
	case 4: {
		graphicNum = 14;
		break;
	}
	case 5: {
		graphicNum = 16;
		break;
	}
	case 6: {
		graphicNum = 17;
		break;
	}
	case 7: {
		graphicNum = 19;
		break;
	}
	default:
		break;
	}
	if (graphicNum == -1) {
		cout<<"You Fail!\n";
	}
	else {
		for (int i = 0; i < graphicNum; i++) {
			cout << graphic[i];
		}
	}
	cout << endl << endl;
};
int main() {
	Hangman user;
	user.play();
}