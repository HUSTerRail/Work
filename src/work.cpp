#include<bits/stdc++.h>
using namespace std;

long long n; // 秘钥数字
string m; // 加密后字符串
char k; // 运算符

bool check(long long x) {
    int last = x % 10;
    x /= 10;
    while (x > 0) {
        if (x % 10 != last) {
            return false;
        }
        x /= 10;
    }
    return true;
}

int main() {
    cin >> m >> n >> k;
    long long ans = -1;
    for (int i = 0; i < m.size(); i++) {
        long long x = 0;
        for (int j = i; j < m.size(); j++) {
            x = x * 10 + m[j] - '0';
            long long res;
            if (k == '+') {
                res = x + n;
            } else if (k == '-') {
                res = x - n;
            } else if (k == '*') {
                if (n >= 1000) { // 乘数大于等于 1000，不需要计算
                    continue;
                }
                res = x * n;
            }
            if (check(res)) { // 满足条件
                ans = max(ans, x);
            }
        }
    }
    cout << ans << endl;
    return 0;
}

