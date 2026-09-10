class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    bool dfs(vector<vector<char>>&b,int i,int j,string& w,int ind){
        if(ind==w.size()-1){
            return true;
        }
        char temp=b[i][j];
        b[i][j]='#';
        for(int k=0;k<4;k++){
            int nr=i+dx[k];
            int nc=j+dy[k];
            if(nr >= 0 && nr < b.size() && 
                nc >= 0 && nc < b[0].size() && 
                b[nr][nc] == w[ind + 1]){
                    if(dfs(b,nr,nc,w,ind+1))return true;

            }
        }
        b[i][j]=temp;
        return false;
    }

    bool exist(vector<vector<char>>& b, string w) {
        int n=b.size();
        int m=b[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(b[i][j]==w[0]){
                    if(dfs(b,i,j,w,0))return true;
                }
            }
        }
        return false;
    }
};