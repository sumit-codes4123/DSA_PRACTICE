class Solution {
public: // RECURSION WITH MEMORIZATION
    int solve(vector<vector<int>>& o, int i, int j, int n, int m,
              vector<vector<int>>& dp) {
        if (i > n || j > m)
            return 0;
        if (o[i][j] == 1)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (i == n && j == m)
            return 1;
        return dp[i][j] = solve(o, i + 1, j, n, m,dp) + solve(o, i, j + 1, n, m,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        int n = o.size();
        int m = o[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(o, 0, 0, n - 1, m - 1, dp);
    }
};
// int solve(vector<vector<int>>& o, int i, int j, int n, int m) {
//     if (i > n || j > m)    SIMPLE RECURSION
//         return 0;
//     if (o[i][j] == 1)
//         return 0;
//     if (i == n && j == m)
//         return 1;
//     return solve(o, i + 1, j, n, m) + solve(o, i, j + 1, n, m);
// }