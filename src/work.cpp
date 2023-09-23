#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
    int maxX = 0, maxY = 0;
    for (const auto& tower : towers) {
        maxX = max(maxX, tower[0]);
        maxY = max(maxY, tower[1]);
    }
    
    pair<int, int> bestCoord = {0, 0};
    int bestSignal = INT_MIN;
    
    for (int x = 0; x <= maxX; ++x) {
        for (int y = 0; y <= maxY; ++y) {
            int curSignal = 0;
            
            for (const auto& tower : towers) {
                int dx = x - tower[0], dy = y - tower[1];
                double distance = sqrt(dx * dx + dy * dy);
                
                if (distance <= radius) {
                    curSignal += floor(tower[2] / (1 + distance));
                }
            }
            
            if (curSignal > bestSignal) {
                bestSignal = curSignal;
                bestCoord = {x, y};
            }
        }
    }
    
    return {bestCoord.first, bestCoord.second};
}

int main() {
    int n, radius;
    char ch;
    cin >> n >> ch >> radius;

    vector<vector<int>> towers(n, vector<int>(3));
    for (int i = 0; i < n; ++i) {
        cin >> towers[i][0] >> ch >> towers[i][1] >> ch >> towers[i][2];
    }

    vector<int> res = bestCoordinate(towers, radius);
    cout << res[0] << "," << res[1] << endl;
    return 0;
}
