class Solution {
public:  

    int minPathSum(vector<vector<int>>& g) {
        int n=g.size();
        int m=g[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0&&j==0) dp[i][j]=g[i][j];
                else{
                    int a=INT_MAX,b=INT_MAX;
                    if(i>0)a=dp[i-1][j];
                    if(j>0)b=dp[i][j-1];
                    dp[i][j]=g[i][j]+min(a,b);
                }
            }
        }return dp[n-1][m-1];
    }
};
// class Solution {
// public:   RECURSION WITH MEMORIZATION
//     int solve(vector<vector<int>>& g,int i,int j,vector<vector<int>>&dp){
//         if(i==0&&j==0)return g[0][0];  
//         if(i<0||j<0)return INT_MAX;
//         if(dp[i][j]!=-1)return dp[i][j];
//         else {
//             return dp[i][j]= g[i][j]+min(solve(g,i-1,j,dp),solve(g,i,j-1,dp));
//         }

//     }
//     int minPathSum(vector<vector<int>>& g) {
//         int n=g.size();
//         int m=g[0].size();
//         vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
//         return solve(g,n-1,m-1,dp);
//     }
// };