#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Coupon {
    int b, c;
};

bool cmp(const Coupon& a, const Coupon& b) {
    return a.b > b.b;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> prices(n);
    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }
    
    vector<Coupon> coupons(m);
    for (int i = 0; i < m; ++i) {
        cin >> coupons[i].b >> coupons[i].c;
    }
    
    sort(coupons.begin(), coupons.end(), cmp);
    
    long long totalCost = 0;
    int couponIndex = 0;
    
    for (int i = 0; i < n; ++i) {
        if (couponIndex < m && prices[i] >= coupons[couponIndex].b) {
            totalCost += max(prices[i] - coupons[couponIndex].c, 0);
            ++couponIndex;
        } else {
            totalCost += prices[i];
        }
    }
    
    cout << totalCost << endl;
    
    return 0;
}
