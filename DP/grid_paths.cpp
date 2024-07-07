#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007;

int dp[1001][1001];

int solve(int n, vector<vector<char>>& grid, int i, int j) {
    if(i >= n || j >= n) return 0;
    if(grid[i][j] == '*') return 0;
    if(i == n-1 && j == n-1) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    
    int down = solve(n, grid, i+1, j);
    int right = solve(n, grid, i, j+1);
    
    return dp[i][j] = (right + down)%mod;
}

int main()
{
    int n; cin>>n;
    vector<vector<char>> grid(n, vector<char>(n));
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>grid[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    
    cout<<solve(n, grid, 0, 0)<<endl;
    
    
    return 0;
}