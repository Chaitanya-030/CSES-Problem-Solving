#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int dp[20][2][2][2];

ll solve(string& num, int n, int even, int lz, int tight) {
    if(n == 0) return 1;
    if(dp[n][even][lz][tight] != -1) return dp[n][even][lz][tight];

    if(even) {
        vector<int> digits = {0, 2, 4, 6, 8};
        int ub = tight ? (num[num.size() - n] - '0'): 9;
        ll ans = 0;
        for(auto dig : digits) { 
            if(dig <= ub) ans += solve(num, n-1, 0, 0, (tight && dig==ub));
        }
        return ans;
    }
    else {
        vector<int> digits = {1, 3, 5, 7, 9};
        int ub = tight ? (num[num.size() - n] - '0'): 9;
        ll ans = 0;
        if(lz == 1) {
            ans += solve(num, n-1, 0, 1, 0);
        }
        for(auto dig : digits) { 
            if(dig <= ub) ans += solve(num, n-1, 1, 0, (tight && dig==ub));
        }
        return dp[n][even][lz][tight] = ans;
    }
}

int main() {
    ll l, r; cin>>l>>r;
    string b = to_string(r);
    string a = to_string(l-1);
    memset(dp, -1, sizeof(dp));
    ll ans1 = solve(b, b.size(), 0, 1, 1);
    memset(dp, -1, sizeof(dp));
    ll ans2 = solve(a, a.size(), 0, 1, 1);
    cout<<ans1 - ans2<<endl;

    return 0;
}