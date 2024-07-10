#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int>& vis) {
    vis[node] = 1;
    
    for(auto it : adj[node]) {
        if(!vis[it]) {
            dfs(it, adj, vis);
        }
    }
}

int main()
{
    int n, m; cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++) {
        int x, y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    vector<int> vis(n+1, 0);
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({1, 1});
    vis[1] = 1;
    int f = 0;
    vector<int> par(n+1);
    
    while(!pq.empty()) {
        int steps = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if(node == n) {
            f = 1;
            cout<<steps<<endl;
            break;
        }
        
        for(auto it : adj[node]) {
            if(!vis[it]) {
                par[it] = node;
                vis[it] = 1;
                pq.push({steps+1, it});
            }
        }
    }
    
    if(!f) cout<<"IMPOSSIBLE"<<endl;
    else {
        int node = n;
        vector<int> ans;
        while(node != 1) {
            ans.push_back(node);
            node = par[node];
        }
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        for(auto it : ans) cout<<it<<" ";
        cout<<endl;
    }

    return 0;
}