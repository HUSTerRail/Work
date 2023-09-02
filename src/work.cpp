#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }

    int total = 0;

    // Compute the sum of all rectangle areas ending at (i, j)
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = a[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
            total += a[i][j];
        }
    }

    int min_diff = INT_MAX;

    // Iterate over all possible squares to find the optimal cut
    for (int len = 1; len <= min(n, m); ++len) {
        for (int i = len; i <= n; ++i) {
            for (int j = len; j <= m; ++j) {
                // Calculate the sum of the square ending at (i, j) with length len
                int square_sum = dp[i][j] - dp[i - len][j] - dp[i][j - len] + dp[i - len][j - len];
                int other_sum = total - square_sum;
                min_diff = min(min_diff, abs(square_sum - other_sum));
            }
        }
    }

    cout << min_diff << endl;

    return 0;
}
