    #include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& vis, int n, int m) {
    vis[i][j] = 1;
    
    for(int k=0;k<4;k++) {
        int ni = i + dx[k];
        int nj = j + dy[k];
        if(ni >= 0 && ni < n && nj >= 0 && nj < m && !vis[ni][nj] && grid[i][j] == '.') {
            dfs(ni, nj, grid, vis, n, m);
        }
    }
}

int main()
{
    int n, m; cin>>n>>m;
    vector<vector<char>> grid(n, vector<char>(m));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>grid[i][j];
        }
    }
    
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(!vis[i][j] && grid[i][j] == '.') {
                cnt++;
                dfs(i, j, grid, vis, n, m);
            }
        }
    }
    
    cout<<cnt<<endl;

    return 0;
}