#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void generate_s(vector<int>&nums, int k, int i, int sum, int &max_sum){
    if(i>= nums.size()){
        return;
    }
    sum += nums[i];
    if(sum%k == 0 && sum > max_sum){
        max_sum = sum;
    }
    generate_s(nums, k, i+1, sum, max_sum);

    sum -=nums[i];
    generate_s(nums, k, i+1, sum, max_sum);
}
int main() {
    int n, k, input;
    cin >> n >> k;
    vector<int>nums;


    for (int i = 0; i < n; ++i) {
        cin >>input;
        nums.push_back(input);
    }

    int max_sum = 0;
    generate_s(nums, k, 0, 0, max_sum);

    
    if(max_sum == 0){
        cout << "-1"<<endl;
    }else{
        cout << max_sum << endl;
    }
    

    return 0;
}
