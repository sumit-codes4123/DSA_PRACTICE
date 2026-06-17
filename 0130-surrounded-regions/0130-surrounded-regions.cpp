class Solution {
public:

    void dfs(int r,int c,vector<vector<int>>&vis,vector<vector<char>>&b,int dr[],int dc[] ){
        vis[r][c]=1;
        int n=b.size();
        int m=b[0].size();
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0&&nr<n&&nc>=0&&nc<m&&vis[nr][nc]!=1&&b[nr][nc]=='O'){
                dfs(nr,nc,vis,b,dr,dc);
            }
        }
        
    }
    void solve(vector<vector<char>>& b) {
        int n=b.size();
        int m=b[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        for(int i=0;i<m;i++){
            if(!vis[0][i]&&b[0][i]=='O'){
                dfs(0,i,vis,b,dr,dc);
            }
            if(!vis[n-1][i]&&b[n-1][i]=='O'){
                dfs(n-1,i,vis,b,dr,dc);
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i][0]&&b[i][0]=='O'){
                dfs(i,0,vis,b,dr,dc);
            }
            if(!vis[i][m-1]&&b[i][m-1]=='O'){
                dfs(i,m-1,vis,b,dr,dc);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j]&&b[i][j]=='O'){
                    b[i][j]='X';
                }
            }
        }
    }
};