#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int min_ops = 1e9;  // 初始化最小操作次数为一个非常大的值
    int MAX = INT_MIN;
    for(int i = 0; i < n; i++){
        MAX = max(arr[i], MAX);
    }
    for (int target = arr[0]; target < MAX; target *= 2) {  // 第一个元素有可能降低到的最低值
        int ops = 0;
        int max_val = target;
        for (int i = 0; i < n; ++i) {
            int val = arr[i], cnt = 0;

            while (val > max_val) {  // 使元素尽可能降低到最低水平
                val /= 2;
                ++cnt;
            }
            while (val * 2 <= max_val) {  // 使元素尽可能增大到最高水平
                val *= 2;
                ++cnt;
            }
            ops += cnt;
            max_val = max(max_val, val);  // 更新可能的最大值
        }
        min_ops = min(min_ops, ops);
    }
    cout << min_ops << endl;
    return 0;
}

