class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int mod = 1e9 + 7;
        vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(m + 1, vector<long long>(k, 0)));  
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i == 1 && j == 1) {
                    dp[i][j][grid[0][0] % k] = 1;
                    continue;
                }
                int value = grid[i - 1][j - 1] % k;
                for (int r = 0; r < k; r++) {
                    int prev = (r - value + k) % k;
                    dp[i][j][r] = (dp[i - 1][j][prev] + dp[i][j - 1][prev]) % mod;
                }
            }
        }
        return dp[n][m][0];
    }
};
