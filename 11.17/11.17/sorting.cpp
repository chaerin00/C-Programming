#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<math.h>
using namespace std;

class Sorting {
public:
	virtual void sort(vector<int> &nums) = 0;
	void print(vector<int> &nums) {
		for (int n : nums) {
			cout << n << " ";
		}
		cout << endl;
	}
};


class Counting : public Sorting {
public:
	void sort(vector<int> &nums) {
		int count[10] = { 0,0,0,0,0,0,0,0,0,0 };
		int index[10] = { 0,0,0,0,0,0,0,0,0,0 };
		for (int n : nums)count[n]++;
		for(int i = 1; i < 10; i++)index[i] = index[i - 1] + count[i - 1];
		
	
		vector<int>result = nums;
		for (int n : nums) {
			result[index[n]]= n;
			index[n]++;	
		}
		nums = result;
	}
};

class Radix : public Sorting {
public:
	void sort(vector<int>& nums) {
		int place = 1;
		while (place < 5) {
			int count[10] = { 0,0,0,0,0,0,0,0,0,0 };
			int index[10] = { 0,0,0,0,0,0,0,0,0,0 };
			for (int n : nums) {
				n = (n % (int)pow(10,place))/pow(10,place-1);
				count[n]++;
			}
			for (int i = 1; i <10; i++)index[i] = index[i - 1] + count[i - 1];


			vector<int>result = nums;
			for (int n : nums) {
				int temp = n;
				n = (n % (int)pow(10, place)) / pow(10, place - 1);
				result[index[n]] = temp;
				index[n]++;
			}
			this->print(result);
			place++;

			nums = result;
		}
		
		
	}

};
int main() {
	int type, max, count, d;
	vector<int>nums;
	string filename;
	Sorting* sort;

	cout << "Give a file name be sorted:" << endl;
	cin >> filename;
	ifstream ifs{ filename };
	int n;
	while (ifs>>n) {
		nums.push_back(n);
	}
	ifs.close();

	cout << "Select you algotithm: 1.Couting 2.Radix" << endl;
	cin >> type;
	if (type == 1)sort = new Counting();
	else sort = new Radix();

	(*sort).print(nums);
	(*sort).sort(nums);
	cout << "Initial Values" << endl;
	sort->print(nums);

	

}