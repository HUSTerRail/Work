//============================================================================
// Name        : MiHaYou1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	for(int i = 1; i < s.size(); i++){
		if(s[i] < s[i-1])
		{
			char temp = s[i];
			s[i] = s[i-1];
			s[i-1] = temp;
			break;
		}
	}
	cout << s;
	return 0;
}
