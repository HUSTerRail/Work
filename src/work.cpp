#include <iostream>
#include <vector>
#include <algorithm>

const int MOD = 1000000007;

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    // 排序数组，以便后续计算
    std::sort(arr.begin(), arr.end());

    // 创建一个二维动态规划数组dp，dp[i][j]表示前i个数中选择j个数，满足两两之间互为倍数的方案数
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(k + 1, 0));

    // 初始化第一列，当选择0个数时，方案数为1
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 1;
    }

    // 填充动态规划数组
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            // 不选第i个数
            dp[i][j] = dp[i - 1][j];

            // 选第i个数
            for (int m = 0; m < i; ++m) {
                // 检查arr[i-1]是否是arr[m]的倍数，如果是，则可以将arr[i-1]加入方案中
                if (arr[i - 1] % arr[m] == 0) {
                    dp[i][j] = (dp[i][j] + dp[m][j - 1]) % MOD;
                }
            }
        }
    }

    // 计算删除方案的总数
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = (ans + dp[i][k]) % MOD;
    }

    std::cout << ans << std::endl;

    return 0;
}
