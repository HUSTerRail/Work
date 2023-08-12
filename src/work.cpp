#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> cake(n, vector<int>(m));
    int totalSum = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> cake[i][j];
            totalSum += cake[i][j];
        }
    }

    int halfTotalSum = totalSum / 2;

    // DP array to store whether the sum can be reached using the cake pieces
    vector<vector<bool>> dp(halfTotalSum + 1, vector<bool>(2, false));

    dp[0][0] = dp[0][1] = true;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = halfTotalSum; k >= cake[i][j]; --k) {
                dp[k][0] = dp[k][0] || dp[k - cake[i][j]][0];
                dp[k][1] = dp[k][1] || dp[k - cake[i][j]][1];
            }
        }
    }

    int minDifference = totalSum;

    for (int i = 0; i <= halfTotalSum; ++i) {
        if (dp[i][0] || dp[i][1]) {
            int s1 = i;
            int s2 = totalSum - i;
            minDifference = min(minDifference, abs(s1 - s2));
        }
    }

    cout << minDifference << endl;

    return 0;
}
