class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& m) {
        int n = m.size();
        int k = m[0].size();
        vector<vector<int>> dp(n, vector<int>(k, 1e9));
        for (int i = 0; i < k; i++) {
            dp[0][i] = m[0][i];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < k; j++) {
                int up = dp[i - 1][j];
                int left = (j > 0) ? dp[i - 1][j - 1] : 1e9;
                int right = (j < k - 1) ? dp[i - 1][j + 1] : 1e9;

                dp[i][j] = m[i][j] + min({up, left, right});
            }
        }
        int mini = INT_MAX;
        for (int j = 0; j < k; j++)
            mini = min(mini, dp[n - 1][j]);
        return mini;
    }
};
// class Solution {
// public:    RECURSION WITH MEMORIZATION
//     int solve(int i,int j, vector<vector<int>>&m, vector<vector<int>>&dp){
//         if(j<0||j>=m[0].size())return 1e9;
//         if(i==0)return m[0][j];
//         if(dp[i][j]!=1e9 )return dp[i][j];
//         int c=m[i][j]+solve(i-1,j,m,dp);
//         int l=m[i][j]+solve(i-1,j-1,m,dp);
//         int r=m[i][j]+solve(i-1,j+1,m,dp);
//         return dp[i][j]=min(c,min(l,r));
//     }
//     int minFallingPathSum(vector<vector<int>>& m) {
//         int n=m.size();
//         int k=m[0].size();
//         int mini=INT_MAX;
//         vector<vector<int>>dp(n,vector<int>(k,1e9 ));
//         for(int i=0;i<k;i++){
//             mini=min(mini,solve(n-1,i,m,dp));
//         } return mini;
//     }
// };