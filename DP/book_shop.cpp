#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main() {
    int n; cin>>n;
    int x; cin>>x;
    vector<int> price(n), pages(n);
    for (int i=0;i<n;i++) cin>>price[i];
    for (int i=0;i<n;i++) cin>>pages[i];

    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));

    for(int ind=n-1;ind>=0;ind--) {
        for(int k=0;k<=x;k++) {
            dp[ind][k] = dp[ind+1][k];
            if(price[ind] <= k) {
                dp[ind][k] = max(dp[ind][k], pages[ind] + dp[ind+1][k-price[ind]]);
            }
        }
    }

    cout<<dp[0][x]<<endl;

    return 0;
}