#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n, m, k; cin>>n>>m>>k;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 1});
    vector<vector<ll>> dist(n+1, vector<ll>(k, 1e18));
    vector<pair<ll, ll>> adj[n+1];
    for(ll i=0;i<m;i++) {
        ll x, y, z; cin>>x>>y>>z;
        adj[x].push_back({y, z});
    }
    
    dist[1][0] = 0; // best path to 1, dist[1][1] --> second best path to 1
    
    while(!pq.empty()) {
        ll node = pq.top().second;
        ll wt = pq.top().first;
        pq.pop();
        
        if(dist[node][k-1] < wt) continue;
        
        for(auto it : adj[node]) {
            ll v = it.first;
            ll c = it.second;
            
            if(dist[v][k-1] > c+wt) {
                dist[v][k-1] = c+wt;
                pq.push({dist[v][k-1], v});
                sort(dist[v].begin(), dist[v].end());
            }
        }
    }
    
    for(ll i=0;i<k;i++) {
        cout<<dist[n][i]<<" ";
    }

    return 0;
}