#include <iostream>
#include <vector>

using namespace std;


int main() {
    int k, m, n;
    cin >> k >> m >> n;

    if(k<(m+n)){
        cout << "-1" << endl;
        return 0;
    }else{
        vector<vector<int>>dp(m+1, vector<int>(n+1, 1));
        for(int i=1; i<=m; i++){
            for(int j = 1; j<=n; j++){
                // cout << dp[i-1][j] <<endl;
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        cout << dp[m][n] << endl;
    }
 

    return 0;
}
