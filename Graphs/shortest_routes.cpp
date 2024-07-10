#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dx[4] = {0, 1, 0, -1};
ll dy[4] = {1, 0, -1, 0};

int main()
{
    ll n, m; cin>>n>>m;
    vector<pair<ll, ll>> adj[n+1];
    for(ll i=0;i<m;i++) {
        ll x, y, z; cin>>x>>y>>z;
        adj[x].push_back({y, z});
    }
    
    vector<ll> dist(n+1, 1e18);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    vector<int> vis(n+1, 0);
    
    while(!pq.empty()) {
        ll d = pq.top().first;
        ll node = pq.top().second;
        pq.pop();
        
        if(vis[node]) continue;
        vis[node] = 1;
        
        for(auto it : adj[node]) {
            if(d + it.second < dist[it.first]) {
                dist[it.first] = d + it.second;
                pq.push({dist[it.first], it.first});
            }
        }
    }
    
    for(ll i=1;i<=n;i++) cout<<dist[i]<<" ";
    cout<<endl;
 
    return 0;
}