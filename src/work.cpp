#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long int n;
    cin >> n;
    vector<long int> a(n);
    for(long int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long int res = 0;
    for(long int i = 1; i < n; i++) {
        long int cur = a[i];
        long int cnt = 0;
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
