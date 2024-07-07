#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007;

int solve(int n, int x, vector<int>& price, vector<int>& pages, int ind, vector<vector<int>>& dp) {
    if(ind >= n) return 0;
    if(dp[ind][x] != -1) return dp[ind][x];
    
    int nottake = solve(n, x, price, pages, ind+1, dp);
    int take = 0;
    if(price[ind] <= x) {
        take = pages[ind] + solve(n, x-price[ind], price, pages, ind+1, dp); 
    }
    
    return dp[ind][x] = max(take, nottake);
}

int main()
{
    int n; cin>>n;
    int x; cin>>x;
    vector<int> price(n), pages(n);
    for(int i=0;i<n;i++) cin>>price[i];
    for(int i=0;i<n;i++) cin>>pages[i];
    
    vector<vector<int>> dp(n+1, vector<int>(x+1, -1));
    
    cout<<solve(n, x, price, pages, 0, dp)<<endl;
    
    return 0;
}