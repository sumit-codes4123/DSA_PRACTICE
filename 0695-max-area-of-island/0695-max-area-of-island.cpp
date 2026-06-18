class Solution {
public:
        int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    int dfs(int n, int m, int r, int c, vector<vector<int>>& g, vector<vector<int>>& vis) {
        vis[r][c] = 1;
        long long sum = g[r][c];
        
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && g[nr][nc] > 0) {
                sum += dfs(n, m, nr, nc, g, vis);
            }
        }
        return sum;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int maxi=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0&&!vis[i][j]){
                    int s=dfs(n,m,i,j,grid,vis);
                    maxi=max(maxi,s);
                }
            }
        }return maxi;
    }
};