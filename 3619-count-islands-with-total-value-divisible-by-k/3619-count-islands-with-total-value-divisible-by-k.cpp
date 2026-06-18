class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    long long  dfs(int n,int m ,int r,int c,vector<vector<int>>&g,vector<vector<int>>&vis){
        vis[r][c]=1;
        long long sum=g[r][c];
        for(int d=0;d<4;d++){
            int nr=r+dr[d];
            int nc=c+dc[d];
            if(nr>=0&&nr<n&&nc>=0&&nc<m&&!vis[nr][nc]&&g[nr][nc]>0){
                sum+=dfs(n,m,nr,nc,g,vis);
            }
        }
        return sum;
    }
    int countIslands(vector<vector<int>>& g, int k) {
        int n=g.size();
        int m=g[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]>0&&!vis[i][j]){
                    long long l=dfs(n,m,i,j,g,vis);
                    if(l%k==0)cnt++;
                }
            }
        }return cnt;
    }
};