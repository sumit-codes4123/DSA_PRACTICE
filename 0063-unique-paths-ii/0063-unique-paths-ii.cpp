class Solution {
public: // TABULIZATION DP
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        int n = o.size();
        int m = o[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(o[i][j]==1)dp[i][j]=0;
                else if(i==0&&j==0)dp[i][j]=1;
                else{
                    int a=0,b=0;
                    if(i>0) a=dp[i-1][j];
                    if(j>0) b=dp[i][j-1];
                    dp[i][j]=a+b;
                }
            }
        }return dp[n-1][m-1];
    }
};
// class Solution {
// public: // RECURSION WITH MEMORIZATION
//     int solve(vector<vector<int>>& o, int i, int j, int n, int m,
//               vector<vector<int>>& dp) {
//         if (i > n || j > m)
//             return 0;
//         if (o[i][j] == 1)
//             return 0;
//         if (dp[i][j] != -1)
//             return dp[i][j];
//         if (i == n && j == m)
//             return 1;
//         return dp[i][j] = solve(o, i + 1, j, n, m,dp) + solve(o, i, j + 1, n, m,dp);
//     }
//     int uniquePathsWithObstacles(vector<vector<int>>& o) {
//         int n = o.size();
//         int m = o[0].size();
//         vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
//         return solve(o, 0, 0, n - 1, m - 1, dp);
//     }
// };
// int solve(vector<vector<int>>& o, int i, int j, int n, int m) {
//     if (i > n || j > m)    SIMPLE RECURSION
//         return 0;
//     if (o[i][j] == 1)
//         return 0;
//     if (i == n && j == m)
//         return 1;
//     return solve(o, i + 1, j, n, m) + solve(o, i, j + 1, n, m);
// }