#include <bits/stdc++.h>
using namespace std;

void Distance(const string &string1, const string &string2, int &ins, int &del, int &sub) {
    int m = string1.length();
    int n = string2.length();
    
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for (int i = 0; i <= m; ++i) dp[i][0] = i;
    for (int j = 0; j <= n; ++j) dp[0][j] = j;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            int cost = (string1[i-1] == string2[j-1]) ? 0 : 1;
            dp[i][j] = min({dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + cost});
        }
    }

    int i = m, j = n;
    ins = 0, del = 0, sub = 0;
    while (i > 0 || j > 0) {
        if (i > 0 && j > 0 && dp[i][j] == dp[i-1][j-1] + (string1[i-1] != string2[j-1])) {
            if (string1[i-1] != string2[j-1]) {
                ++sub;
            }
            --i;
            --j;
        } else if (i > 0 && dp[i][j] == dp[i-1][j] + 1) {
            ++del;
            --i;
        } else {
            ++ins;
            --j;
        }
    }
}

int main() {
    string string1, string2;
    getline(cin, string1);
    getline(cin, string2);
    int ins, del, sub;
    Distance(string1, string2, ins, del, sub);
    cout << ins << endl;
    cout << del << endl;
    cout << sub << endl;
    return 0;
}
