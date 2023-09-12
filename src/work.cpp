#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 1e5 + 5;

int n, k;
int a[N], b[N];
int parent[N];

int find(int x) {
    return parent[x] == x ? x : parent[x] = find(parent[x]);
}

bool check(int L) {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (abs(a[i] - a[j]) + abs(b[i] - b[j]) <= L) {
                int u = find(i);
                int v = find(j);
                if (u != v) {
                    parent[u] = v;
                }
            }
        }
    }

    int groups = 0;
    for (int i = 1; i <= n; i++) {
        if (parent[i] == i) {
            groups++;
        }
    }

    return groups <= k;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    int left = 0, right = 2e5 + 10;
    int ans = -1;
    while (left <= right) {
        int mid = (left + right) >> 1;
        if (check(mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}
