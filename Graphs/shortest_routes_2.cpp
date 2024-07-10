#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n, m, q; cin>>n>>m>>q;
    vector<vector<ll>> cost(n+1, vector<ll>(n+1, 1e18));
    for(int i=1;i<=n;i++) cost[i][i] = 0;
    for(ll i=0;i<m;i++) {
        ll x, y, z; cin>>x>>y>>z;
        cost[x][y] = min(cost[x][y], z);
        cost[y][x] = min(cost[y][x], z);
    }
    
    for(int via=1;via<=n;via++) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                cost[i][j] = min(cost[i][j], cost[i][via] + cost[via][j]);
            }
        }
    }
    
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(cost[i][j] == 1e18) {
                cost[i][j] = -1;
            }
        }
    }
    
    vector<int> ans;
    while(q--) {
        ll x, y; cin>>x>>y;
        // if(cost[x][y] == 0) cout<<-1<<endl;
        cout<<cost[x][y]<<endl; 
        
        // ans.push_back(cost[x][y]);
    }
    
    // for(auto it : ans) cout<<it<<" ";
    
    return 0;
}