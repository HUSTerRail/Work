#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<stdio.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    vector<vector<long long>> dp(n+1,vector<long long>(k,-10000000000));  // dp[i][j]  表示前i个数字中   sum%k=j   的最大和   

    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
       //每引入一个数 查询每个余数情况
        for(int j=0;j<k;j++)
        {
              dp[i][j]=max(dp[i-1][j],dp[i-1][(k+j-arr[i]%k)%k]+arr[i]);
        }
    }
    //最终结果是  所有数字中 余数为0的 最大和
    if(dp[n][0]<=0)
        cout<<-1<<endl;
    else
        cout<<dp[n][0]<<endl;
}
