#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

ll dp[20][10][2][2];
ll solve(string& number, int n, int x, int lz, int tight) {
    if(n == 0) return 1;
    
    if(x != -1 && dp[n][x][lz][tight] != -1) return dp[n][x][lz][tight];
    
    int lb = 0;
    int ub = tight ? (number[number.size() - n] - '0') : 9;
    
    ll ans = 0;
    for(int dig=lb;dig<=ub;dig++) {
        if(dig == x && lz == 0) continue; // 100, 1100, 4400
        ans += solve(number, n-1, dig, (lz && dig == 0), (tight && dig == ub));
    }
    return dp[n][x][lz][tight] = ans;
}

int main() {
    ll a, b; cin>>a>>b;
    string s = to_string(a-1);
    string t = to_string(b);
    memset(dp, -1, sizeof(dp));
    ll ans1 = solve(t, t.size(), -1, 1, 1);
    memset(dp, -1, sizeof(dp));
    ll ans2 = solve(s, s.size(), -1, 1, 1);
    cout<<ans1-ans2<<endl;
    
    return 0;
}