#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m; cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++) {
        int x, y; cin>>x>>y;
        adj[x].push_back(y);
    }
    
    vector<int> indegree(n+1, 0);
    for(int i=1;i<=n;i++) {
        for(auto it : adj[i]) {
            indegree[it]++;
        }
    }
    
    queue<int> q;
    for(int i=1;i<=n;i++) {
        if(indegree[i] == 0) q.push(i);
    }
    
    vector<int> ans;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        
        ans.push_back(node);
        
        for(auto it : adj[node]) {
            indegree[it]--;
            if(indegree[it] == 0) {
                q.push(it);
            }
        }
    }
    
    if(ans.size() != n) cout<<"IMPOSSIBLE"<<endl;
    else {
        for(auto it  :ans) cout<<it<<" ";
    }

    return 0;
}