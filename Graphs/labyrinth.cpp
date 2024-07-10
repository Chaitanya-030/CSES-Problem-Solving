#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main()
{
    int x = -1, y = -1;
    int n, m; cin>>n>>m;
    vector<vector<char>> grid(n, vector<char>(m));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>grid[i][j];
            if(grid[i][j] == 'A') {
                x = i;
                y = j;
            }
        }
    }
    
    vector<vector<int>> vis(n, vector<int>(m, 0));
    
    priority_queue<pair<vector<int>, string>, vector<pair<vector<int>, string>>, greater<pair<vector<int>, string>>> q;
    q.push({{0, x, y}, ""});
    vis[x][y] = 1;
    int f = 0;
    
    while(!q.empty()) {
        int i = q.top().first[1];
        int j = q.top().first[2];
        int steps = q.top().first[0];
        string s = q.top().second;
        
        q.pop();
        
        if(grid[i][j] == 'B') {
            f = 1;
            cout<<"YES"<<endl;
            cout<<steps<<endl;
            cout<<s<<endl;
            break;
        }
        
        for(int k=0;k<4;k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            
            if(ni >= 0 && ni < n && nj >= 0 && nj < m && !vis[ni][nj] && (grid[ni][nj] == '.' || grid[ni][nj] == 'B')) {
                if(k == 0) s += 'R';
                else if(k == 1) s += 'D';
                else if(k == 2) s += 'L';
                else s += 'U';
                
                q.push({{steps+1, ni, nj}, s});
                vis[ni][nj] = 1;
                s.pop_back();
            }
        }
    }
    
    if(!f) cout<<"NO"<<endl;

    return 0;
}