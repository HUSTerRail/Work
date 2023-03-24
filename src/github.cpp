//============================================================================
// Name        : League_building.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <vector>
#include <map>

//目前唯一想到的方法是采用递归的方法

class Solution{
public:
	void find(int n, int t, vector<string>& nums, map<char, int>& map_count, map<char, int>& map_price){
		for(int i = 0; i < nums[t].size(); i++){

		}
	}
};

int main() {
	Solution solve;
	int n;
	int num;
	string s;
	cin >> n;
	vector<string> nums;
	for(int i = 0; i < n; i++){
		cin >> s;
		nums.push_back(s);
	}
	map<char, int> map_count;
	map<char, int> map_price;
	cin >> map_count['A'];
	cin >> map_price['A'];
	cin >> map_count['B'];
	cin >> map_price['B'];
	cin >> map_count['C'];
	cin >> map_price['C'];
	solve.find(n, 0, nums, map_count, map_price);
	return 0;
}
