#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

int solve(int n, vector<int>& dp, int curr) {
    if(curr == n) return 1;
    if(dp[curr] != -1) return dp[curr];
    
    int ans = 0;
    for(int i=1;i<=6;i++) {
        if(curr + i <= n) {
            ans += solve(n, dp, curr+i)%mod;
            ans = ans%mod;
        }
    }
    return dp[curr] = ans%mod;
}

int main()
{
    int n; cin>>n;
    vector<int>dp(n, -1);
    cout<<solve(n, dp, 0)<<endl;
    return 0;
}