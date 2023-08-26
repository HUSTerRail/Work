#include <bits/stdc++.h>
using namespace std;



int main() {
    int n,k, input;
    cin >> n >> k;
    int tmp = 0;
    int sum = 0;
    int length = 0;
    int max_length = 0;
    vector<int>nums;
    for(int i=0; i<n; i++){
            cin >> input;
            sum += input;
            nums.push_back(sum);
    }

    for(int i=0; i<n; i++){
        if(nums[i]%k == 0 && nums[i]/k == i+1){
            length = i+1;
        }else if(nums[i] > (i+1)*k){
            for(int j=0; j<i; j++){
                tmp = nums[i]-nums[j];
                if(tmp % k == 0 && tmp/k == (i-j)){
                    length = i-j;
                }
            }
        }
        if(length>max_length){
            max_length = length;
        }
    }
    if(max_length == 0){
        cout<<"-1"<<endl;
    }else{
         cout << max_length<<endl;
    }
   
    return 0;


}
