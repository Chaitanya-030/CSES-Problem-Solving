#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

vector<vector<int>> dp(1e6+1, vector<int>(2, 0));

int main()
{
    dp[0][0] = 1;
    dp[0][1] = 1;
    for(int i = 1; i < 1e6; i++){
        dp[i][0] = (2LL * dp[i-1][0] + dp[i-1][1]) % mod;
        dp[i][1] = (4LL * dp[i-1][1] + dp[i-1][0]) % mod;
    }
    
    
    // 0 means starting with width 2 grid
    // 1 means starting with 2 width 1 grid
    for(int i = 1; i < 1e6; i++){
        dp[i][0] = (2LL * dp[i-1][0] + dp[i-1][1]) % mod;
        dp[i][1] = (4LL * dp[i-1][1] + dp[i-1][0]) % mod;
    }
    
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        cout<<(dp[n-1][0] + dp[n-1][1])%mod<<endl;
    }

    return 0;
}