#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007


int solve(int n, int arr[], int ind, int target, vector<vector<int>>& dp) {
    if(ind >= n) {
        if(target == 0) {
            return 1;
        }
        return 0;
    }
    
    if(dp[ind][target] != -1) return dp[ind][target];
    
    int take = 0;
    if(arr[ind] <= target) take = solve(n, arr, ind+1, target-arr[ind], dp)%mod;
    int nottake = solve(n, arr, ind+1, target, dp)%mod;
    
    return dp[ind][target] = (take + nottake)%mod;
}

int main() {
    int n; cin>>n;
    int sum = n*(n+1)/2;
    int arr[n];
    for(int i=0;i<n;i++) arr[i] = i+1;
    vector<vector<int>> dp(n+1, vector<int>(sum/2+1, -1));
    
    if(sum%2 != 0) cout<<0<<endl;
    else cout<<solve(n, arr, 0, sum/2, dp)/2<<endl;
    
    return 0;
}