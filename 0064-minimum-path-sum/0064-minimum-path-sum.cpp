class Solution {
public:
    int solve(vector<vector<int>>& g,int i,int j,vector<vector<int>>&dp){
        if(i==0&&j==0)return g[0][0];  
        if(i<0||j<0)return INT_MAX;
        if(dp[i][j]!=-1)return dp[i][j];
        else {
            return dp[i][j]= g[i][j]+min(solve(g,i-1,j,dp),solve(g,i,j-1,dp));
        }

    }
    int minPathSum(vector<vector<int>>& g) {
        int n=g.size();
        int m=g[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(g,n-1,m-1,dp);
    }
};