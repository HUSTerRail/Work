//============================================================================
// Name        : hell1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int func(string s, int longth){
		int result = 0;
		int flag = 1;
		int flag2 = 0;
		for(int i = 0; i < longth; i++){
			if( flag == 1 && s[i] == '1'){
				flag = 0;
				result += 1;
			}else{
				flag = 1;

			}
		}
		return result;
	}

};

int main() {
	Solution solve;
	int n,longth;
	string str;
	cin >> n;

	int result = 0;
	for(int i = 0; i<n; i++){
		cin >> longth >> str;
		result = solve.func(str, longth);
		cout<<result<<endl;
	}

	return 0;
};

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int func(string s, int longth){
		int result = 0;
		int flag = 0;
		int flag2 = 0;
		for(int i = 0; i < longth-1; i++){
			if( s[i] == '1'){
				flag = 1;
				result += 1;
				flag2 = i;
				break;
			}
		}
		if(flag == 1){
			for(int i = flag2; i < longth-1; i++){y
				if( s[i] == '0' && s[i+1] == '1'){
					result += 1;
				}
			}
		}

		return result;
	}

};

int main() {
	Solution solve;
	int n,longth;
	string str;
	cin >> n;

	int result = 0;
	for(int i = 0; i<n; i++){
		cin >> longth >> str;
		result = solve.func(str, longth);
		cout<<result<<endl;
	}

	return 0;
};
