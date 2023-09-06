#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int maxGold(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<vector<int>>> visited(m, vector<vector<int>>(n, vector<int>(2, 0)));
    queue<vector<int>> q;  // [x, y, used_skill, gold]
    q.push({0, 0, 0, grid[0][0]});
    int maxGold = 0;

    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        int x = curr[0], y = curr[1], used_skill = curr[2], gold = curr[3];

        maxGold = max(maxGold, gold);
        for (auto dir : directions) {
            int newX = x + dir[0];
            int newY = y + dir[1];
            if (newX >= 0 && newX < m && newY >= 0 && newY < n) {
                if (grid[newX][newY] != -1 && !visited[newX][newY][used_skill]) {
                    q.push({newX, newY, used_skill, gold + grid[newX][newY]});
                    visited[newX][newY][used_skill] = 1;
                } else if (grid[newX][newY] == -1 && !used_skill && !visited[newX][newY][1]) {
                    q.push({newX, newY, 1, gold});
                    visited[newX][newY][1] = 1;
                }
            }
        }
    }
    return maxGold;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }
    cout << maxGold(grid) << endl;
    return 0;
}
