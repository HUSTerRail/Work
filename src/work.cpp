#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> cake(n, vector<int>(m));
    vector<int> rowSum(n, 0);
    vector<int> colSum(m, 0);

    int total = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> cake[i][j];
            total += cake[i][j];
            rowSum[i] += cake[i][j];
            colSum[j] += cake[i][j];
        }
    }

    int half = total / 2;

    int minDiff = total;

    int s1 = 0;
    for (int i = 0; i < n; i++) {
        s1 += rowSum[i];
        int s2 = total - s1;
        minDiff = min(minDiff, abs(s1 - s2));
        if (s1 > half) break; 
    }

    s1 = 0;
    for (int j = 0; j < m; j++) {
        s1 += colSum[j];
        int s2 = total - s1;
        minDiff = min(minDiff, abs(s1 - s2));
        if (s1 > half) break; 
    }

    cout << minDiff << endl;
    return 0;
}

