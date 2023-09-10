#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<string> strs;
vector<vector<int>> adjMatrix;
vector<bool> visited;

int longestCommonSubstring(const string& s1, const string& s2) {
    int l1 = s1.size();
    int l2 = s2.size();
    vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0));
    int maxLen = 0;

    for (int i = 1; i <= l1; ++i) {
        for (int j = 1; j <= l2; ++j) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                maxLen = max(maxLen, dp[i][j]);
            }
        }
    }
    return maxLen;
}

void dfs(int node) {
    visited[node] = true;
    for (int i = 0; i < n; ++i) {
        if (!visited[i] && adjMatrix[node][i]) {
            dfs(i);
        }
    }
}

int countGroups() {
    fill(visited.begin(), visited.end(), false);
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i);
            count++;
        }
    }
    return count;
}

int main() {
    cin >> n >> k;
    strs.resize(n);
    adjMatrix.resize(n, vector<int>(n, 0));
    visited.resize(n, false);

    for (int i = 0; i < n; ++i) {
        cin >> strs[i];
    }

    vector<int> deleteOrder(n);
    for (int i = 0; i < n; ++i) {
        cin >> deleteOrder[i];
        deleteOrder[i]--;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (longestCommonSubstring(strs[i], strs[j]) >= k) {
                adjMatrix[i][j] = adjMatrix[j][i] = 1;
            }
        }
    }

    cout << countGroups() << endl;
    for (int i = 0; i < n; ++i) {
        strs[deleteOrder[i]] = "";
        for (int j = 0; j < n; ++j) {
            adjMatrix[deleteOrder[i]][j] = adjMatrix[j][deleteOrder[i]] = 0;
        }
        cout << countGroups() - i - 1 << endl;
    }

    return 0;
}
