#include<iostream>
#include<vector>
#include<string>

class Node {
	Node* left, * right;
	vector<char>chars;
	int count;
	Node(char c, count);
	Node(Node* a, Node* b);
	int getCount();
};
class Huffman {
	vector<Node*>forest;
	string encode(string& str);
};
int main() {
	Huffman myhuff;
	string original = "Hello";

}