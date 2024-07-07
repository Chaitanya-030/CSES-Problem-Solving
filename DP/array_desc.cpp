#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007;

bool valid(int x, int m) {
    if(x >= 1 && x <= m) return true;
    return false;
}

int main()
{
    int n; cin>>n;
    int m; cin>>m;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i=1;i<=m;i++) {
        if(arr[0] == i || arr[0] == 0) {
            dp[1][i] = 1;
        }
    }
    
    for(int i=2;i<=n;i++) {
        for(int k=1;k<=m;k++) {
            if(arr[i-1] != 0 && arr[i-1] != k) {
                dp[i][k] = 0;
                continue;
            }
            for(int prev=k-1;prev<=k+1;prev++) {
                if(!valid(prev, m)) continue;
                dp[i][k] = (dp[i][k] + dp[i-1][prev])%mod;
            }
        }
    }
    
    int ans = 0;
    for(int i=1;i<=m;i++) {
        ans += dp[n][i]%mod;
        ans = ans%mod;
    }
    
    cout<<ans<<endl;
    
    return 0;
}