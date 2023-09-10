#include <bits/stdc++.h>
using namespace std;

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
