#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007;

int main()
{
    int n; cin>>n;
    vector<int> dp(n+1, 1e9); 
    dp[0] = 0;
    
    for(int i=1;i<=n;i++) {
        string s = to_string(i);
        for(char c : s) {
            int digit = c - '0';
            if(digit != 0) {
                dp[i] = min(dp[i], 1 + dp[i-digit]);
            }
        }
    }
    
    cout<<dp[n]<<endl;
    
    
    return 0;
}