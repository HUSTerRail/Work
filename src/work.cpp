#include <bits/stdc++.h>
  222
using namespace std;

pair<int, int> findRange(const vector<int>& nums, int sn) {
    int n = nums.size();
    int found = -1;
    for (int i = 0; i < n; ++i) {
        if (nums[i] == sn) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        return {-1, -1};  // Not found
    }

    int start = found, end = found;

    // Find start
    int i = 0;
    while (nums[start] == sn) {
        start = (start - 1 + n) % n;
        i++;
        if(i > n){
        	return {0, n - 1};
        }
    }
    start = (start + 1) % n;  

    // Find end
    while (nums[end] == sn) {
        end = (end + 1) % n;
    }
    end = (end - 1 + n) % n;  // Adjust to the last position of sn

    return {start, end};
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    int sn;
    cin >> sn;

    auto [start, end] = findRange(nums, sn);

    cout << start << " " << end << endl;

    return 0;
}
