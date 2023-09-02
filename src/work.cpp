#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> goods(n);
    multiset<pair<int, int>> coupons; 
    for (int i = 0; i < n; ++i) {
        cin >> goods[i];
    }
    for (int i = 0; i < m; ++i) {
        int bi, ci;
        cin >> bi >> ci;
        coupons.insert({bi, ci});
    }
    sort(goods.begin(), goods.end(), greater<int>());
    long long totalCost = 0; 
    for (int price : goods) {
        auto it = coupons.lower_bound({price, 0});
        if (it != coupons.end()) {
            totalCost += price - it->second;
            coupons.erase(it);
        } else {
            totalCost += price;
        }
    }
    cout << totalCost << endl;
    return 0;
}
