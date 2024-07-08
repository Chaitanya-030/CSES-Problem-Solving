// you have to find the cnt of all the n digit numbers which are less than R (who has a sum of digits equal to X) --> condition

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int dp[100][201][2];

int solve(string& num, int x, int n, int tight) {
    if(x < 0) return 0;
    if(n == 1) {
        if(x >= 0 && x <= 9) return 1;
        return 0;
    }

    if(dp[n][x][tight] != -1) return dp[n][x][tight];

    int lb = 0;
    int ub = tight ? num[num.size() - n] - '0': 9; 
    int ans = 0;
    for(int dig=lb;dig<=ub;dig++) {
        ans += solve(num, x-dig, n-1, (tight && dig==ub));
    }
    return dp[n][x][tight] = ans;
}

int main() {
    int r; cin>>r;
    int x; cin>>x;
    string num = to_string(r);
    memset(dp, -1, sizeof(dp));
    cout<<solve(num, x, num.size(), 1);

    return 0;
}