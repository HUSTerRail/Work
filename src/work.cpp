#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int getMaxHeight(int n, int a, int b) {
    if (abs(a - b) > n - 1) {
        return -1; 
    }
    int big = max(a, b);
    int small = min(a, b);
    int count = n - 2 - big + small;
    int res = big;
    res += count/2 + count%2;
    res = max(big, res);
    return res;
}

int main() {
    int T;
    cin >> T;
    vector<int> results;
    
    for (int i = 0; i < T; ++i) {
        int n, a, b;
        cin >> n >> a >> b;
        results.push_back(getMaxHeight(n, a, b));
    }
    
    for (int res : results) {
        cout << res << endl;
    }
    
    return 0;
}
