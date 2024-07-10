#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int solve(int node, vector<int> adj[], int n, vector<int>& vis, vector<int>& teams, int col) {
    vis[node] = 1;
    if(col == 0) teams[node] = 1;
    else teams[node] = 2;
    
    for(auto it : adj[node]) {
        if(!vis[it]) {
            if(!solve(it, adj, n, vis, teams, !col)) return 0;
        }
        else {
            if(col == 0) {
                if(teams[it] == 1) return 0;
            }
            else {
                if(teams[it] == 2) return 0;
            }
        }
    }
    return 1;
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
    vector<int> teams(n+1, 0);
    int mini = 1;
    for(int i=1;i<=n;i++) {
        if(!vis[i]) {
            int x = solve(i, adj, n, vis, teams, 0);
            mini = min(x, mini);
        }
    }
    
    if(mini == 0) cout<<"IMPOSSIBLE"<<endl;
    else {
        for(int i=1;i<=n;i++) {
            cout<<teams[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}