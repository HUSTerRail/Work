#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {-1, 1, 0, 0};  // 上、下、左、右
const int dy[4] = {0, 0, -1, 1};

int minPasses(vector<vector<int>>& matrix, int m, int n) {
    int res = INT_MAX;
    bool found = false;
    for (int i = 0; i < m; i++) {
        if (matrix[i][0] == 1) {
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            queue<pair<pair<int, int>, int>> q;
            q.push({{i, 0}, 0});
            visited[i][0] = true;
            while (!q.empty()) {
                auto [coord, passes] = q.front();
                q.pop();
                for (int j = 0; j < 4; j++) {
                    int x = coord.first + dx[j];
                    int y = coord.second + dy[j];
                    if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y] && matrix[x][y] == 1) {
                        if (y == n - 1) {
                            res = min(res, passes + 1);
                            found = true;
                        } else {
                            q.push({{x, y}, passes + 1});
                            visited[x][y] = true;
                        }
                    }
                }
            }
        }
    }
    return found ? res : -1;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];

    cout << minPasses(matrix, m, n) << endl;
    return 0;
}
