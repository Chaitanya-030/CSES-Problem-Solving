#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

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
    int cnt = 0;
    vector<int> ans;
    for(int i=1;i<=n;i++) {
        if(!vis[i]) {
            ans.push_back(i);
            dfs(i, adj, vis);
            cnt++;
        }
    }
    
    int sz = ans.size();
    cout<<cnt-1<<endl;
    for(int i=0;i<sz-1;i++) {
        cout<<ans[i]<<" "<<ans[i+1]<<endl;
    }
    

    return 0;
}