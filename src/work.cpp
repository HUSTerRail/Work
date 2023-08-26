#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int findMaxLengthSubarray(const vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> prefixSum(n + 1, 0);
    unordered_map<int, int> sumIndexMap;
    sumIndexMap[0] = 0;
    int maxLength = -1;
    int currentSum = 0;

    for (int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
        currentSum += nums[i];

        if (sumIndexMap.find(currentSum - k) != sumIndexMap.end()) {
            maxLength = max(maxLength, i + 1 - sumIndexMap[currentSum - k]);
        }

        if (sumIndexMap.find(currentSum) == sumIndexMap.end()) {
            sumIndexMap[currentSum] = i + 1;
        }
    }

    return maxLength;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int maxLength = findMaxLengthSubarray(nums, k);
    cout << maxLength << endl;

    return 0;
}
