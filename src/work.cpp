#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 计算吸引度
int calculateAttraction(int likes, int dislikes) {
    return abs(likes - dislikes);
}

int main() {
    int n;
    cin >> n;

    vector<int> likes(n);
    vector<int> dislikes(n);

    for (int i = 0; i < n; i++) {
        cin >> likes[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> dislikes[i];
    }

    int maxAttraction = 0;

    // 枚举所有可能的组合
    for (int i = 0; i < (1 << n); i++) {
        int totalLikes = 0;
        int totalDislikes = 0;

        // 计算当前组合的点赞数和点踩数
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                totalLikes += likes[j];
                totalDislikes += dislikes[j];
            }
        }

        int attraction = calculateAttraction(totalLikes, totalDislikes);
        maxAttraction = max(maxAttraction, attraction);
    }

    cout << maxAttraction << endl;

    return 0;
}
