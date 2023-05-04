#include "bits/stdc++.h"
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> s(n);
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> s[i] >> a[i];
    }

    int max_value = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (s[j].find(s[i]) != string::npos) {
                max_value = max(max_value, a[i] + a[j]);
            }
        }
    }
    cout << max_value << endl;
    return 0;
}
