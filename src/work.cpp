#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int ans = 1e9;  // 初始化为一个大值

    for (int i = 1; i < n; ++i) {
        int cnt = 0;
        int cur = a[i];
        while (cur < a[0]) {
            cur *= 2;
            cnt++;
        }
        while (cur >= 2 * a[0]) {
            cur /= 2;
            cnt++;
        }
        ans = min(ans, cnt);
    }

    cout << ans + 1 << endl;

    return 0;
}
