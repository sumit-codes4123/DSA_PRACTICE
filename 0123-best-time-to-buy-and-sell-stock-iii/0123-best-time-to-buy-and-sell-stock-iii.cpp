class Solution {
public:
    int solve(int i,int buy,int c,vector<int>&p,int n, vector<vector<vector<int>>>&dp){
        if(i==n||c==0)return 0;
        if(dp[i][buy][c]!=-1)return dp[i][buy][c];
        if(buy==1){
            return dp[i][buy][c]= max(-p[i]+solve(i+1,0,c,p,n,dp),0+solve(i+1,1,c,p,n,dp));
        }
        else{
            return  dp[i][buy][c]=  max(p[i]+solve(i+1,1,c-1,p,n,dp),0+solve(i+1,0,c,p,n,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,1,2,prices,n,dp);
    }
};