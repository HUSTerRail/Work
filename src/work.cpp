#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int res = 0;
    for(int i = 1; i < n; i++) {
        int cur = a[i];
        int cnt = 0;
        while(cur > a[0]) {
            cur /= 2;
            cnt++;
        }
        while(cur < a[0]) {
            cur *= 2;
            cnt++;
        }
        res = max(res, cnt);
    }

    cout << res << endl;
    return 0;
}
