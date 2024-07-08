#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int dp[5001][5001];

int solve(string& s, string& t, int n, int m) {
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(i == 0) {
                dp[i][j] = j; 
            } 
            else if(j == 0) {
                dp[i][j] = i; 
            } 
            else if(s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1]; 
            } 
            else {
                dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1],dp[i-1][j-1]});
            }
        }
    }
    return dp[n][m];
}

int main()
{
    string s, t; cin>>s>>t;
    int n = s.size();
    int m = t.size();
    // memset(dp, -1, sizeof(dp));
    memset(dp, 0, sizeof(dp));
    
    cout<<solve(s, t, n, m);

    return 0;
}