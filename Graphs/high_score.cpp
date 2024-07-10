#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n, m; cin>>n>>m;
    vector<pair<ll, ll>> adj[n+1];
    for(int i=0;i<m;i++) {
        ll x, y, z; cin>>x>>y>>z;
        adj[x].push_back({y, z});
    }
    
    vector<ll> dist(n+1, -1e10);
    dist[1] = 0;
    for(int i=0;i<n-1;i++) {
        for(int j=1;j<=n;j++) {
            if(dist[j] != -1e10) {
                for(auto it : adj[j]) {
                    int v = it.first;
                    int w = it.second;
                    if(dist[j] + w > dist[v]) {
                        dist[v] = dist[j] + w; 
                    }
                }
            }
        }
    }
    
    int f = 1;
    for(int i=1;i<=n;i++) {
        if(dist[i] != -1e10) {
            for(auto x : adj[i]) {
                int v = x.first;
                int w = x.second;
                if(dist[i] + w > dist[v]) {
                    queue<ll> q;
                    q.push(i);
                    vector<ll> vis(n+1, 0);
                    while(!q.empty()) {
                        int node = q.front();
                        q.pop();
                        if(node == n) {
                            f = 0;
                            cout<<-1<<endl;
                            exit(0);
                        }
                        vis[node] = 1;
                        for(auto it : adj[node]) {
                            if(!vis[it.first]) {
                                q.push(it.first);
                            }
                        }
                    }
                }
            }
        }
    }
    
    if(f) cout<<dist[n]<<endl;
    
    
    
    return 0;
}