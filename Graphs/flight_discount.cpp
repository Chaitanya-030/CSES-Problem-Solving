#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n, m; cin>>n>>m;
    vector<pair<ll, ll>> adj[n+1];
    for(int i=0;i<m;i++) {
        ll x, y, z; cin>>x>>y>>z;
        adj[x].push_back({y, z});
    }
    
    vector<ll> full(n+1); 
    vector<ll> disc(n+1);
    
    for(int i=1;i<=n;i++) {
        full[i] = 1e18;
        disc[i] = 1e18;
    }
    
    priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> pq;
    // {price, {dst, coupon}}
    pq.push({0, {1, 0}});
    
    while(!pq.empty()) {
        ll d = pq.top().first;
        ll node = pq.top().second.first;
        ll isCoupon = pq.top().second.second;
        pq.pop();
        
        if(isCoupon == 1 && disc[node] < d) continue;
        if(isCoupon == 0 && full[node] < d) continue;
        
        for(auto it : adj[node]) {
            ll v = it.first;
            ll wt = it.second;
            
            if(isCoupon == 0) { // coupon not used
                if(d + wt/2 < disc[v]) {
                    disc[v] = d + wt/2;
                    pq.push({disc[v], {v, 1}});
                }
                
                if(d + wt < full[v]) {
                    full[v] = d + wt;
                    pq.push({full[v], {v, 0}});
                }
            }
            
            if(isCoupon == 1) { // coupon used
                if(d + wt < disc[v]) {
                    disc[v] = d + wt;
                    pq.push({disc[v], {v, 1}});
                }
            }
        }
    }
    
    cout<<disc[n]<<endl;

    return 0;
}