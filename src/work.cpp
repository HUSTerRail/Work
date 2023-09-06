#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <climits>

using namespace std;

int minWoods(const vector<int>& woods, int length) {
    vector<int> dp(length + 1, INT_MAX);  // 初始化为最大值
    dp[0] = 0;  // 0长度不需要任何木材
    for (int i = 0; i <= length; ++i) {
        if (dp[i] != INT_MAX) {
            for (int wood : woods) {
                if (i + wood <= length) {
                    dp[i + wood] = min(dp[i + wood], dp[i] + 1);
                }
            }
        }
    }
    return dp[length] == INT_MAX ? -1 : dp[length];
}

int main() {
    string line1, line2;
    getline(cin, line1);
    getline(cin, line2);
    
    istringstream iss(line1);
    vector<int> woods;
    int temp;
    while (iss >> temp) {
        woods.push_back(temp);
    }
    
    int length = stoi(line2);
    
    cout << minWoods(woods, length) << endl;
    return 0;
}
