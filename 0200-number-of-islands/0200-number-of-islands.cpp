class Solution {
public:
    void dfs(int n,int m,int i,int j,vector<vector<char>>&g){
        if(i<0||i>=n||j<0||j>=m||g[i][j]=='0')return;
        g[i][j]='0';
        dfs(n,m,i-1,j,g); 
        dfs(n,m,i+1,j,g); 
        dfs(n,m,i,j-1,g); 
        dfs(n,m,i,j+1,g); 
    }
    int numIslands(vector<vector<char>>& g) {
        int n=g.size();
        int m=g[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]=='1'){
                    cnt++;
                    dfs(n,m,i,j,g);
                }
            }
        }
        return cnt;
    }
};