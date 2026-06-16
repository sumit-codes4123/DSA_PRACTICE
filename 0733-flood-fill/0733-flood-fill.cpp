class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>&ans,vector<vector<int>>&images,int nc,int dr[],int dc[],int ic){
        ans[row][col]=nc;
        int n=images.size();
        int m=images[0].size();
        for(int i=0;i<4;i++){
            int nr=row+dr[i];
            int ncol=col+dc[i];
            if(nr>=0&&nr<n&&ncol>=0&&ncol<m&&images[nr][ncol]==ic&&ans[nr][ncol]!=nc){
                dfs(nr,ncol,ans,images,nc,dr,dc,ic);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newcolor) {
        int ic=image[sr][sc];
        vector<vector<int>>ans=image;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        dfs(sr,sc,ans,image,newcolor,dr,dc,ic);
        return ans;
    }
};