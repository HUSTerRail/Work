#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

const int maxn = 1e3 + 5;
int a[maxn], b[maxn], n, k;

bool check(int mid) {
    vector<bool> vis(n, false);
    int cnt = 0;

    for (int i = 0; i < n; ++i) {
        if (vis[i]) continue;

        vis[i] = true;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v = 0; v < n; ++v) {
                if (!vis[v] && abs(a[u]-a[v]) + abs(b[u]-b[v]) <= mid) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        ++cnt;
    }

    return cnt >= k;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    int l = 0, r = 2e4, ans = -1; 
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << endl;
    return 0;
}
