#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main()
{
    int n, m; cin>>n>>m;
    int x, y;
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
    
    vector<vector<int>> tm(n, vector<int>(m, 1e9));
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> par(n, vector<int>(m));
    par[x][y] = '/';
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j] == 'M') {
                pq.push({0, i, j});
                tm[i][j] = 0;
                vis[i][j] = 1;
            }
        }
    }
    
    while(!pq.empty()) {
        int t = pq.top()[0];
        int i = pq.top()[1];
        int j = pq.top()[2];
        pq.pop();
        
        for(int k=0;k<4;k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            
            if(ni >= 0 && nj >= 0 && ni < n && nj < m && !vis[ni][nj] && (grid[ni][nj] == '.' || grid[ni][nj] == 'A')) {
                pq.push({t+1, ni, nj});
                tm[ni][nj] = t + 1;
                vis[ni][nj] = 1;
            }
        }
    }
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            vis[i][j] = 0;
        }
    }
    
    queue<vector<int>> q;
    q.push({0, x, y});
    vis[x][y] = 1;
    
    int f = 0, fx = -1, fy = -1;
    
    while(!q.empty()) {
        int steps = q.front()[0];
        int i = q.front()[1];
        int j = q.front()[2];
        q.pop();
        
        if(i == 0 || j == 0 || i == n-1 || j == m-1) {
            f = 1;
            fx = i;
            fy = j;
            cout<<"YES"<<endl;
            cout<<steps<<endl;
            break;
        }
        
        for(int k=0;k<4;k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            
            if(ni >= 0 && nj >= 0 && ni < n && nj < m && !vis[ni][nj] && grid[ni][nj] == '.' && steps+1 < tm[ni][nj]) {
                if(k == 0) par[ni][nj] = 'R';
                else if(k == 1) par[ni][nj] = 'D';
                else if(k == 2) par[ni][nj] = 'L';
                else par[ni][nj] = 'U';
                
                q.push({steps+1, ni, nj});
                vis[ni][nj] = 1;
            }
        }
    }
    
    if(!f) cout<<"NO"<<endl;
    else {
        string s = "";
        int i = fx, j = fy;
        while(par[i][j] != '/') {
            s += par[i][j];
            if(par[i][j] == 'R') {
                j--;
            }
            else if(par[i][j] == 'D') {
                i--;
            }
            else if(par[i][j] == 'L') {
                j++;
            }
            else {
                i++;
            }
        }
        reverse(s.begin(), s.end());
        cout<<s<<endl;
    }
 
    return 0;
}