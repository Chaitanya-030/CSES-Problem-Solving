#include <bits/stdc++.h>
using namespace std;

int cycle(int node, int n, vector<int>& vis, vector<int> adj[], vector<int>& par) {
    vis[node] = 1;
    for(auto it : adj[node]) {
        if(!vis[it]) {
            vis[it] = 1;
            par[it] = node;
            if(cycle(it, n, vis, adj, par)) return 1;
        }
        else if(par[node] != it) {
            int start = node;
            int end = it;
            vector<int> ans;
            ans.push_back(start);
            while(start != end) {
                start = par[start];
                ans.push_back(start);
            }
            ans.push_back(node); // start == end
            cout<<ans.size()<<endl;
            for(auto it : ans) cout<<it<<" ";
            return 1;
        }
    }
    return 0;
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
    
    int f = 0;
    vector<int> vis(n+1), par(n+1);
    for(int i=1;i<=n;i++) {
        if(!vis[i]) {
            if(cycle(i, n, vis, adj, par)) {
                f = 1;
                break;
            }
        }
    }
    
    if(!f) cout<<"IMPOSSIBLE"<<endl;
 
    return 0;
}