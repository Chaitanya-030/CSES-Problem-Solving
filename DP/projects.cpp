#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

vector<ll> temp;
 
int f(ll val) {
    int ind = upper_bound(temp.begin(), temp.end(), val) - temp.begin();
    return ind;
}
 
ll solve(int n, vector<vector<ll>>& arr, int ind, vector<ll>& dp) {
    if(ind >= n) return 0;
    if(dp[ind] != -1) return dp[ind];
    
    int nxt = f(arr[ind][1]);
    ll take = arr[ind][2]  + solve(n, arr, nxt, dp);
    ll nottake = solve(n, arr, ind+1, dp);
    
    return dp[ind] = max(take, nottake);
}
 
int main() {
    int n; cin>>n;
    vector<vector<ll>> arr;
    vector<ll> dp(n+1, -1);

    for(int i=0;i<n;i++) {
        ll x, y, z; cin>>x>>y>>z;
        arr.push_back({x, y, z});
    }
    sort(arr.begin(), arr.end());
    for(int i=0;i<n;i++) temp.push_back(arr[i][0]);

    ll ans = solve(n, arr, 0, dp);
    cout<<ans<<endl;
    
    return 0;
}