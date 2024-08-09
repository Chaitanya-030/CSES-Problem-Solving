#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(ll A, ll B) {
    vector<vector<int> > dp(A + 1, vector<int>(B + 1, 1e9));
    for (int i = 0; i <= A; i++) {
        for (int j = 0; j <= B; j++) {
            if (i == j) {
                dp[i][j] = 0;
            }
            else {
                for (int k = 1; k < j; k++) {
                    dp[i][j]
                        = min(dp[i][j],
                              dp[i][k] + dp[i][j - k] + 1);
                }
                for (int k = 1; k < i; k++) {
                    dp[i][j]= min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
                }
            }
        }
    }
    return dp[A][B];
}

int main() {
    int a, b; cin>>a>>b;
    cout << solve(a, b) << "\n";
}