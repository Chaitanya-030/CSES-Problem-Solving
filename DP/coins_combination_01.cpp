#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007;

// ll solve(int n, ll x, vector<ll>& dp, vector<ll>& arr, ll sum) {
//     if(sum == x) return 1;
//     if(dp[sum] != -1) return dp[sum];
    
//     ll ans = 0;
//     for(int i=0;i<n;i++) {
//         if(sum + arr[i] <= x) {
//             ll ans = solve(n, x, dp, arr, sum+arr[i]);
//             if(ans != 1e9) {
//                 mini = min(mini, 1+ans);
//             }
//         }
//     }
//     return dp[sum] = mini;
// }

int main()
{
    int n; cin>>n;
    int x; cin>>x;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int> dp(x+1, 0); 
    
    dp[0] = 1;
    
    for(int i=1;i<=x;i++) {
        for(int j=0;j<n;j++) {
            if(arr[j] <= i) {
                dp[i] = (dp[i] + dp[i-arr[j]])%mod;
            }
        }
    }
    
    cout<<dp[x]<<endl;
    
    return 0;
}