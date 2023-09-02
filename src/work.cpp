#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static bool cmp(const pair<int, int> a1, const pair<int, int> a2){
    return a1.second > a2.second;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> goods(n);
    vector<pair<int, int>> coupons(m);

    for (int i = 0; i < n; ++i) {
        cin >> goods[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> coupons[i].first >> coupons[i].second;
    }

    sort(goods.begin(), goods.end(), greater<int>());
    sort(coupons.begin(), coupons.end(), cmp);

    long long totalCost = 0; 
    int j = 0;  

    for (int i = 0; i < n; ++i) {
        while (j < m && coupons[j].first > goods[i]) {
            ++j;
        }
        if (j < m && coupons[j].first <= goods[i]) {
            totalCost += goods[i] - coupons[j].second;
        } else {
            totalCost += goods[i];
        }
    }
    cout << totalCost << endl;
    return 0;
}
