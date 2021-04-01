#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Node {
	Node* left, *right;
	vector<char>chars;
	int count;
public:
	Node(char c, int count);
	Node(Node* a, Node* b);
	int getCount();
	bool isIn(char c);
	Node* getLeft();
	Node* getRight();
	void incCount();
	char getFirst();
	bool isLeaf();
};
class Huffman {
	vector<Node*>queue;
	void initialize(string& str);
	void makeTree();
	void sortQueue();
	string findCode(char c);
public:
	string encode(string& str);
	string decode(string& str);
};
Node::Node(char c, int count) {
	this->count = count;
	chars.push_back(c);
	left = NULL;
	right = NULL;
};
Node::Node(Node* a, Node* b) {
	chars.reserve(a->chars.size() + b->chars.size());
	chars.insert(chars.end(), a->chars.begin(), a->chars.end());
	chars.insert(chars.end(), b->chars.begin(), b->chars.end());
	count = a->count + b->count;
	left = a;
	right = b;
};
int Node::getCount() {
	return count;
};
bool Node::isIn(char c) {
	for (char m : chars)
		if (m == c)return true;
	return false;
}
Node* Node::getLeft() {
	return left;
};
Node* Node::getRight() {
	return right;
};
void Node::incCount() {
	count++;
}
char Node::getFirst() {
	return chars[0];
}
bool Node::isLeaf(){
	if (left == NULL && right == NULL)
		return true;
	else
		return false;
}
string Huffman::encode(string& str) {
	initialize(str);
	makeTree();
	string res = "";
	for (int i = 0; i < str.length(); i++)
		res += findCode(str[i]);
	return res;	
};
string Huffman::decode(string& str) {
	string res = "";
	Node* node = queue[0];
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '0')
			node = node->getLeft();
		else
			node = node->getRight();
		if (node->isLeaf()) {
			res += node->getFirst();
			node = queue[0];
		}
	}
	return res;
};
void Huffman::initialize(string& str) {
	queue.clear();
	for (int i = 0; i < str.length(); i++) {
		int j;
		for (j = 0; j < queue.size(); j++) {
			if (queue[j]->getFirst() == str[i]) {
				queue[j]->incCount();
				break;
			}
		}
		if (j == queue.size()) {
			Node* tmp = new Node(str[i], 1);
			queue.push_back(tmp);
		}
	}
	sortQueue();
}
void Huffman::makeTree() {
	Node* first;
	Node* second;
	Node* third;

	while (queue.size() > 1) {
		first = queue.back();
		queue.pop_back();
		second = queue.back();
		queue.pop_back();
		third = new Node(first, second);
		queue.push_back(third);
		sortQueue();		
	}
}
string Huffman::findCode(char c) {
	string res = "";
	for (Node* node = queue[0]; !(node->isLeaf());) {
		if (node->getLeft()->isIn(c)) {
			node = node->getLeft();
			res += "0";
		}
		else {
			node = node->getRight();
			res += "1";
		}
	}
	return res;
};
void Huffman::sortQueue() {
	int least = queue[0]->getCount();
	for (int i = 1; i < queue.size(); i++) {
		if (least > queue[i]->getCount()){
			Node* tmp = queue[i];
			queue[i] = queue[i - 1];
			queue[i - 1] = tmp;
		}
	}
};
int main() {
	Huffman myhuff;
	string original = "Hello";
	string encoded = myhuff.encode(original);
	string decoded = myhuff.decode(encoded);
	cout << original << endl;
	cout << encoded << endl;
	cout << decoded << endl;

}