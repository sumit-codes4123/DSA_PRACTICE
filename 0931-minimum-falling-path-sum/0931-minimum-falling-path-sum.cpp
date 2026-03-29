class Solution {
public:
    int solve(int i,int j, vector<vector<int>>&m, vector<vector<int>>&dp){
        if(j<0||j>=m[0].size())return 1e9;
        if(i==0)return m[0][j];
        if(dp[i][j]!=1e9 )return dp[i][j];
        int c=m[i][j]+solve(i-1,j,m,dp);
        int l=m[i][j]+solve(i-1,j-1,m,dp);
        int r=m[i][j]+solve(i-1,j+1,m,dp);
        return dp[i][j]=min(c,min(l,r));
    }
    int minFallingPathSum(vector<vector<int>>& m) {
        int n=m.size();
        int k=m[0].size();
        int mini=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(k,1e9 ));
        for(int i=0;i<k;i++){
            mini=min(mini,solve(n-1,i,m,dp));
        } return mini;
    }
};