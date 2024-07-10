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
    vector<vector<char>> par(n, vector<char>(m));
    
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
    q.push({0, x, y});
    vis[x][y] = 1;
    int f = 0;
    par[x][y] = '/';
    
    int dstx, dsty;
    
    while(!q.empty()) {
        int i = q.top()[1];
        int j = q.top()[2];
        int steps = q.top()[0];
        q.pop();
        
        if(grid[i][j] == 'B') {
            f = 1;
            dstx = i;
            dsty = j;
            cout<<"YES"<<endl;
            cout<<steps<<endl;
            break;
        }
        
        for(int k=0;k<4;k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            
            if(ni >= 0 && ni < n && nj >= 0 && nj < m && !vis[ni][nj] && (grid[ni][nj] == '.' || grid[ni][nj] == 'B')) {
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
        int i = dstx, j = dsty;
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