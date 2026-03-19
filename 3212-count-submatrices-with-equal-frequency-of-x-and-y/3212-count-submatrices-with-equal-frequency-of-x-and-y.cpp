class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
       vector<int>X(m,0),Y(m,0) ;
       int cnt=0;
       for(int i=0;i<n;i++){
        int rx=0,ry=0;
        for(int j=0;j<m;j++){
            if(grid[i][j]=='X') rx++;
            else if(grid[i][j]=='Y')ry++;
            X[j]+=rx;
            Y[j]+=ry;
            if(X[j]>0 && X[j]==Y[j]) cnt++;
        }
       }return cnt;
    }
};